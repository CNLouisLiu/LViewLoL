#pragma once

#include "windows.h"
#include "Champion.h"
#include "GameObject.h"
#include "GameRenderer.h"
#include "Offsets.h"
#include "MemSnapshot.h"
#include <list>
#include <vector>
#include <set>
#include <chrono>
#include <queue>

using namespace std::chrono;

/// Reads memory from League of Legends process using ReadProcessMemory
class LeagueMemoryReader {

public:
	bool IsLeagueWindowActive();
	bool IsHookedToProcess();
	void HookToProcess();
	void MakeSnapshot(MemSnapshot& ms);
private:

	// Process related
	HANDLE                    hProcess = NULL;
	DWORD                     pid      = 0;
	HWND                      hWindow  = NULL;

	// Memory related
	DWORD_PTR                 moduleBaseAddr    = 0;
	DWORD                     moduleSize        = 0;
	BOOL                      is64Bit           = FALSE;

private:
	static const size_t         numMaxChamps  = 10;
	static const size_t         numMaxTurrets = 24;
	static const size_t         numMaxMobs    = 500;
	float                       minDistanceToCursor;
	
	void                        ReadChampions(MemSnapshot& snapshot);
	void                        ReadRenderer(MemSnapshot& snapshot);
	void                        ReadMobs(MemSnapshot& snapshot);
	void                        ReadTurrets(MemSnapshot& snapshot);
	void                        ReadMissiles(MemSnapshot& snapshot);
	std::shared_ptr<GameObject> FindHoveredObject(MemSnapshot& ms);

	template<typename T, typename std::enable_if<std::is_base_of<MemoryLoadable, T>::value>::type* = nullptr>
	void                        ReadGameObjectList(std::vector<std::shared_ptr<T>>& readInto, DWORD numMaxObjects, DWORD baseAddr, DWORD countOffset, DWORD listOffset, MemSnapshot& snapshot);
};

template<typename T, typename std::enable_if<std::is_base_of<MemoryLoadable, T>::value>::type*>
void LeagueMemoryReader::ReadGameObjectList(std::vector<std::shared_ptr<T>>& readInto, DWORD numMaxObjects, DWORD baseAddr, DWORD countOffset, DWORD listOffset, MemSnapshot& snapshot) {

	auto& idxToObjectMap = snapshot.idxToObjectMap;

	DWORD listManagerPtr = Mem::ReadPointer(hProcess, moduleBaseAddr + baseAddr);
	DWORD listPtr = Mem::ReadPointer(hProcess, listManagerPtr + listOffset);
	DWORD numObjects = 0;
	Mem::Read(hProcess, listManagerPtr + countOffset, &numObjects, 4);

	readInto.clear();
	if (listPtr == 0 || numObjects < 0 || numObjects > numMaxObjects) {
		numObjects = 0;
	}

	static DWORD pointers[500];
	Mem::Read(hProcess, listPtr, pointers, numObjects * sizeof(DWORD));

	for (size_t i = 0; i < numObjects; ++i) {

		if (pointers[i] == 0)
			break;

		short objIndex;
		Mem::Read(hProcess, pointers[i] + Offsets::ObjIndex, &objIndex, sizeof(short));

		std::shared_ptr<T> obj;
		auto it = idxToObjectMap.find(objIndex);
		if (it == idxToObjectMap.end()) {
			obj = std::shared_ptr<T>(new T());
			obj->LoadFromMem(pointers[i], hProcess, true);
			idxToObjectMap[obj->objectIndex] = obj;
		}
		else {
			obj = std::static_pointer_cast<T>(it->second);
			obj->LoadFromMem(pointers[i], hProcess, false);

			// If the object changed its id for whatever the fuck reason then we update the map with the new index
			if (objIndex != obj->objectIndex) {
				idxToObjectMap[obj->objectIndex] = obj;
			}
		}
		
		if (obj->isVisible) {
			obj->lastVisibleAt = snapshot.gameTime;
		}

		if (obj->objectIndex != 0) {
			readInto.push_back(obj);
			snapshot.updatedThisFrame.insert(obj->objectIndex);
		}
	}
}