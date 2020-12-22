#include "LeagueMemoryReader.h"
#include "windows.h"
#include "Utils.h"
#include "Structs.h"
#include "psapi.h"
#include <limits>
#include <stdexcept>

bool LeagueMemoryReader::IsLeagueWindowActive() {
	HWND handle = GetForegroundWindow();

	DWORD h;
	GetWindowThreadProcessId(handle, &h);
	return pid == h;
}

bool LeagueMemoryReader::IsHookedToProcess() {
	return Process::IsProcessRunning(pid);
}

void LeagueMemoryReader::HookToProcess() {

	// Find the window
	hWindow = FindWindowA("RiotWindowClass", NULL);
	if (hWindow == NULL) {
		throw WinApiException("League window not found");
	}

	// Get the process ID
	GetWindowThreadProcessId(hWindow, &pid);
	if (pid == NULL) {
		throw WinApiException("Couldn't retrieve league process id");
	}

	// Open the process
	hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
	if (hProcess == NULL) {
		throw WinApiException("Couldn't open league process");
	}

	// Check architecture
	if (0 == IsWow64Process(hProcess, &is64Bit)) {
		throw WinApiException("Failed to identify if process has 32 or 64 bit architecture");
	}

	HMODULE hMods[1024];
	DWORD cbNeeded;
	if (EnumProcessModules(hProcess, hMods, sizeof(hMods), &cbNeeded)) {
		moduleBaseAddr = (DWORD_PTR)hMods[0];
	}
	else {
		throw WinApiException("Couldn't retrieve league base address");
	}

	numPerformedReads = 0;
}


void LeagueMemoryReader::ReadRenderer(MemSnapshot& ms) {
	high_resolution_clock::time_point readTimeBegin;
	duration<float, std::milli> readDuration;
	readTimeBegin = high_resolution_clock::now();
	
	DWORD rendererAddr = Mem::ReadPointer(hProcess, moduleBaseAddr + Offsets::Renderer);
	ms.renderer->LoadFromMem(rendererAddr, moduleBaseAddr, hProcess);

	readDuration = high_resolution_clock::now() - readTimeBegin;
	ms.benchmark->readRendererMs = readDuration.count();
}

void LeagueMemoryReader::ReadChampions(MemSnapshot& ms) {
	high_resolution_clock::time_point readTimeBegin;
	duration<float, std::milli> readDuration;
	readTimeBegin = high_resolution_clock::now();

	ReadGameObjectList<Champion>(ms.champions, numMaxChamps, Offsets::HeroList, ms);

	readDuration = high_resolution_clock::now() - readTimeBegin;
	ms.benchmark->readChampsMs = readDuration.count();
}

void LeagueMemoryReader::ReadTurrets(MemSnapshot& ms) {
	high_resolution_clock::time_point readTimeBegin;
	duration<float, std::milli> readDuration;
	readTimeBegin = high_resolution_clock::now();

	ReadGameObjectList<GameObject>(ms.turrets, numMaxTurrets, Offsets::TurretList, ms);
	for (auto it = ms.turrets.begin(); it != ms.turrets.end(); ++it) {
		GameObject* obj = *it;
		obj->type = GameObjectType::TURRET;
		obj->targetRadius = 100.f;
	}

	readDuration = high_resolution_clock::now() - readTimeBegin;
	ms.benchmark->readTurretsMs = readDuration.count();
}

void LeagueMemoryReader::ReadMobs(MemSnapshot& ms) {
	high_resolution_clock::time_point readTimeBegin;
	duration<float, std::milli> readDuration;
	readTimeBegin = high_resolution_clock::now();

	ReadGameObjectList<GameObject>(ms.others, numMaxMobs, Offsets::MinionList, ms);

	// Filter minions e.g wards, jungle, minions etc
	ms.minions.clear();
	ms.jungle.clear();
	auto it = ms.others.begin();
	while (it != ms.others.end()) {
		GameObject* obj = *it;
		GameObjectType type = obj->type;
		if (type & GameObjectType::JUNGLE) {
			ms.jungle.push_back(obj);
			it = ms.others.erase(it);
		}
		else if (type & GameObjectType::MINION) {
			ms.minions.push_back(obj);
			it = ms.others.erase(it);
		}
		else
			++it;
	}

	readDuration = high_resolution_clock::now() - readTimeBegin;
	ms.benchmark->readMobsMs = readDuration.count();
}

GameObject* LeagueMemoryReader::FindHoveredObject(MemSnapshot& ms) {
	
	Vector2 cursorPos = Input::GetCursorPosition();
	float minDistance = std::numeric_limits<float>::infinity();
	float distance;
	GameObject* hoveredObject = nullptr;

	for (auto it = ms.idxToObjectMap.begin(); it != ms.idxToObjectMap.end(); ++it) {
		distance = League::Distance(cursorPos, ms.renderer->WorldToScreen(it->second->position));
		if (distance < minDistance && distance < it->second->targetRadius) {
			hoveredObject = it->second;
			minDistance = distance;
		}
	}

	return hoveredObject;
}

void LeagueMemoryReader::MakeSnapshot(MemSnapshot& ms) {
	
	Mem::Read(hProcess, moduleBaseAddr + Offsets::GameTime, &ms.gameTime, sizeof(float));

	if (ms.gameTime > 2) {
		ms.updatedThisFrame.clear();

		ReadChampions(ms);
		ReadRenderer(ms);
		ReadMobs(ms);
		ReadTurrets(ms);
		
		ms.localChampion = ms.champions[0];

		// Clear up objects that were deleted in game
		auto it = ms.idxToObjectMap.begin();
		while (it != ms.idxToObjectMap.end()) {
			if (ms.updatedThisFrame.find(it->first) == ms.updatedThisFrame.end()) {
				delete it->second;
				it = ms.idxToObjectMap.erase(it);
			}
			else
				++it;
		}

		ms.hoveredObject = FindHoveredObject(ms);
	}
}