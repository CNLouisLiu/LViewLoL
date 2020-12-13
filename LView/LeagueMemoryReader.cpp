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
}

void LeagueMemoryReader::ReadRenderer() {
	high_resolution_clock::time_point readTimeBegin;
	duration<float, std::milli> readDuration;
	readTimeBegin = high_resolution_clock::now();
	
	DWORD rendererAddr = Mem::ReadPointer(hProcess, moduleBaseAddr + oRenderer);
	renderer.LoadFromMem(rendererAddr, moduleBaseAddr, hProcess);

	readDuration = high_resolution_clock::now() - readTimeBegin;
	benchmark.readRendererMs = readDuration.count();
}

void LeagueMemoryReader::ReadChampions() {
	high_resolution_clock::time_point readTimeBegin;
	duration<float, std::milli> readDuration;
	readTimeBegin = high_resolution_clock::now();

	ReadGameObjectList<Champion>(champions, &bufferChampion, numMaxChamps, oHeroList);
	localChampion = champions[0];

	readDuration = high_resolution_clock::now() - readTimeBegin;
	benchmark.readChampsMs = readDuration.count();
}

void LeagueMemoryReader::ReadTurrets() {
	high_resolution_clock::time_point readTimeBegin;
	duration<float, std::milli> readDuration;
	readTimeBegin = high_resolution_clock::now();

	ReadGameObjectList<GameObject>(turrets, &bufferGameObject, numMaxTurrets, oTurretList);
	for (auto it = turrets.begin(); it != turrets.end(); ++it) {
		GameObject* obj = *it;
		obj->type = GameObjectType::TURRET;
		obj->targetRadius = 100.f;
	}

	readDuration = high_resolution_clock::now() - readTimeBegin;
	benchmark.readTurretsMs = readDuration.count();
}

void LeagueMemoryReader::ReadMobs() {
	high_resolution_clock::time_point readTimeBegin;
	duration<float, std::milli> readDuration;
	readTimeBegin = high_resolution_clock::now();

	ReadGameObjectList<GameObject>(others, &bufferGameObject, numMaxMobs, oMinionList);

	// Filter minions e.g wards, jungle, minions etc
	minions.clear();
	jungle.clear();
	auto it = others.begin();
	while (it != others.end()) {
		GameObject* obj = *it;
		GameObjectType type = obj->type;
		if (type & GameObjectType::JUNGLE) {
			jungle.push_back(obj);
			it = others.erase(it);
		}
		else if (type & GameObjectType::MINION) {
			minions.push_back(obj);
			it = others.erase(it);
		}
		else
			++it;
	}

	readDuration = high_resolution_clock::now() - readTimeBegin;
	benchmark.readMinionsMs = readDuration.count();
}

void LeagueMemoryReader::FindHoveredObject() {
	
	Vector2 cursorPos = renderer.GetCursorPosition();
	float minDistance = std::numeric_limits<float>::infinity();
	float distance;
	hoveredObject = nullptr;

	for (auto it = idxToObjectMap.begin(); it != idxToObjectMap.end(); ++it) {
		distance = League::Distance(cursorPos, renderer.WorldToScreen(it->second->position));
		if (distance < minDistance && distance < it->second->targetRadius) {
			hoveredObject = it->second;
			minDistance = distance;
		}
	}
}

void LeagueMemoryReader::ReadStructs() {
	
	Mem::Read(hProcess, moduleBaseAddr + oGameTime, &gameTime, sizeof(float));

	if (gameTime > 1) {
		updatedThisFrame.clear();

		ReadChampions();
		ReadRenderer();
		ReadMobs();
		ReadTurrets();

		auto it = idxToObjectMap.begin();
		while (it != idxToObjectMap.end()) {
			if (updatedThisFrame.find(it->first) == updatedThisFrame.end())
				it = idxToObjectMap.erase(it);
			else
				++it;
		}

		FindHoveredObject();
	}
}