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

	DWORD heroManagerPtr = Mem::ReadPointer(hProcess, moduleBaseAddr + oHeroList);
	DWORD champListPtr = Mem::ReadPointer(hProcess, heroManagerPtr + oHeroListHeroArray);
	DWORD numChampions = 0;
	Mem::Read(hProcess, heroManagerPtr + oHeroListNumChampions, &numChampions, 4);

	float distance;
	Vector2 cursorPosition = renderer.GetCursorPosition();

	champions.clear();
	if (champListPtr == 0 || numChampions < 0 || numChampions > numMaxChamps) {
		numChampions = 0;
	}

	for (size_t i = 0; i < numChampions; ++i) {
		DWORD heroPtr = Mem::ReadPointer(hProcess, champListPtr + i * 4);
		Champion* champ = championsArray[i];

		if (heroPtr == 0)
			break;

		champ->LoadFromMem(heroPtr, hProcess);
		if (champ->isVisible)
			champ->lastVisibleAt = gameTime;

		champions.push_back(champ);

		distance = League::Distance(renderer.WorldToScreen(champ->position), cursorPosition);
		if (distance < minDistanceToCursor && distance < champ->targetRadius) {
			minDistanceToCursor = distance;
			hoveredObject = champ;
		}
	}

	if (numChampions > 0)
		localChampion = championsArray[0];

	readDuration = high_resolution_clock::now() - readTimeBegin;
	benchmark.readChampsMs = readDuration.count();
}

void LeagueMemoryReader::ReadMinions() {
	high_resolution_clock::time_point readTimeBegin;
	duration<float, std::milli> readDuration;
	readTimeBegin = high_resolution_clock::now();

	DWORD mobManager = Mem::ReadPointer(hProcess, moduleBaseAddr + oMinionList);
	DWORD mobList = Mem::ReadPointer(hProcess, mobManager + oMinionListArray);
	DWORD numMobs = 0;
	Mem::Read(hProcess, mobManager + oMinionNumMinions, &numMobs, 4);
	
	float distance;
	Vector2 cursorPosition = renderer.GetCursorPosition();

	// Validate pointers
	if (mobList == 0 || numMobs < 0 || numMobs >= numMaxMobs) {
		numMobs = 0;
	}

	wards.clear();
	minions.clear();
	jungle.clear();
	others.clear();

	static DWORD pointers[numMaxMobs];
	Mem::Read(hProcess, mobList, pointers, sizeof(DWORD) * numMobs);
	for (size_t i = 0; i < numMobs; ++i) {
		if (pointers[i] == 0)
			break;
		GameObject* obj;

		// Load mob object
		bufferObject->LoadFromMem(pointers[i], hProcess, true);
		obj = bufferObject;

		auto it = idxToObjectMap.find(bufferObject->objectIndex);
		if (it == idxToObjectMap.end()) {
			idxToObjectMap[bufferObject->objectIndex] = bufferObject;
			bufferObject = new GameObject();
		}
		else {
			bufferObject->lastVisibleAt = it->second->lastVisibleAt;
			bufferObject = it->second;
			idxToObjectMap[it->second->objectIndex] = obj;
		}

		if (obj->isVisible) {
			obj->lastVisibleAt = gameTime;
		}

		// Check if the object is the closest we found relative to cursor so far
		distance = League::Distance(renderer.WorldToScreen(obj->position), cursorPosition);
		if (distance < minDistanceToCursor && distance < obj->targetRadius) {
			minDistanceToCursor = distance;
			hoveredObject = obj;
		}

		// Filter minions e.g wards, jungle, minions etc
		GameObjectType type = obj->type;
		if (type & GameObjectType::JUNGLE) {
			jungle.push_back(obj);
		}
		else if (type & GameObjectType::WARD) {
			wards.push_back(obj);
		}
		else if (type & GameObjectType::MINION) {
			minions.push_back(obj);
		}
		else
			others.push_back(obj);
	}

	readDuration = high_resolution_clock::now() - readTimeBegin;
	benchmark.readMinionsMs = readDuration.count();
}

void LeagueMemoryReader::ReadStructs() {
	
	Mem::Read(hProcess, moduleBaseAddr + oGameTime, &gameTime, sizeof(float));

	if (gameTime > 1) {

		hoveredObject = nullptr;
		minDistanceToCursor = std::numeric_limits<float>::infinity();
		
		ReadChampions();
		ReadRenderer();
		ReadMinions();
	}
}