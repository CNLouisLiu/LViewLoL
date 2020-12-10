#include "LeagueMemoryReader.h"
#include "windows.h"
#include "Utils.h"
#include "Structs.h"
#include "psapi.h"
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

void LeagueMemoryReader::ReadStructs() {
	
	static int calls = 0;

	high_resolution_clock::time_point readTimeBegin;
	duration<float, std::milli> readDuration;

	//Read game time
	gameTime = Mem::ReadFloat(hProcess, moduleBaseAddr + oGameTime);

	if (gameTime > 0) {

		// Read champs
		readTimeBegin = high_resolution_clock::now();
		
		DWORD heroManagerPtr = Mem::ReadPointer(hProcess, moduleBaseAddr + oHeroList);
		DWORD champListPtr = Mem::ReadPointer(hProcess, heroManagerPtr + oHeroListHeroArray);
		Mem::Read(hProcess, heroManagerPtr + oHeroListNumChampions, &numChampions, 4);

		if (champListPtr != 0 && numChampions > 0 && numChampions < 11) {

			int i = 0;
			for (size_t i = 0; i < numChampions; ++i) {
				DWORD heroPtr = Mem::ReadPointer(hProcess, champListPtr + i * 4);

				if (heroPtr != 0) {
					champions[i]->LoadFromMem(heroPtr, hProcess);
				}
			}
		}

		readDuration = high_resolution_clock::now() - readTimeBegin;
		benchmark.readChampsMs = readDuration.count();

		// Read renderer
		readTimeBegin = high_resolution_clock::now();

		DWORD rendererAddr = Mem::ReadPointer(hProcess, moduleBaseAddr + oRenderer);
		renderer.LoadFromMem(rendererAddr, moduleBaseAddr, hProcess);

		readDuration = high_resolution_clock::now() - readTimeBegin;
		benchmark.readRendererMs = readDuration.count();

		// Read other game objects
		if (++calls % 20 == 0) {
			readTimeBegin = high_resolution_clock::now();

			if (calls % 1000 == 0)
				gameObjectPointersAvoid.clear();

			DWORD objManager = Mem::ReadPointer(hProcess, moduleBaseAddr + oObjManager);
			Mem::Read(hProcess, Mem::ReadPointer(hProcess, objManager + oObjManagerObjArray), gameObjectPointers, 3000 * sizeof(DWORD));

			numOtherObjects = 0;
			wards.clear();
			for (int i = 0; i < GAME_OBJECT_ARRAY_SIZE - 1; ++i) {
				DWORD ptrObj = gameObjectPointers[i];
				if (gameObjectPointersAvoid.find(ptrObj) == gameObjectPointersAvoid.end()) {

					if (numOtherObjects >= otherObjects.size()) {
						otherObjects.push_back(new GameObject());
					}
					GameObject* obj = otherObjects[numOtherObjects];
					obj->LoadFromMem(ptrObj, hProcess);


					if ((obj->team != 100 && obj->team != 200 && obj->team != 300) || obj->name.empty()) {
						gameObjectPointersAvoid.insert(ptrObj);
						continue;
					}
					
					numOtherObjects++;

					if (wardNames.find(obj->name) != wardNames.end()) {
						
						obj->expiryAt += gameTime;
						wards.push_back(obj);
					}
				}

			}

			readDuration = high_resolution_clock::now() - readTimeBegin;
			benchmark.readOtherObjectsMs = readDuration.count();
		}
	}
}