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

using namespace std::chrono;

/// Reads memory from League of Legends process using ReadProcessMemory
class LeagueMemoryReader {

public:
	LeagueMemoryReader() {
		bufferGameObject = new GameObject();
		bufferChampion = new Champion();
	}

	~LeagueMemoryReader() {
		delete bufferGameObject;
		delete bufferChampion;
	}

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

	// Buffers use for avoiding to reinstantiate game objects
	GameObject*                 bufferGameObject;
	Champion*                   bufferChampion;
	
	void                        ReadChampions(MemSnapshot& snapshot);
	void                        ReadRenderer(MemSnapshot& snapshot);
	void                        ReadMobs(MemSnapshot& snapshot);
	void                        ReadTurrets(MemSnapshot& snapshot);
	GameObject*                 FindHoveredObject(MemSnapshot& ms);

	template<typename T, typename std::enable_if<std::is_base_of<MemoryLoadable, T>::value>::type* = nullptr>
	void                        ReadGameObjectList(std::vector<T*>& readInto, DWORD numMaxObjects, DWORD baseAddr, MemSnapshot& snapshot);
};

template<typename T, typename std::enable_if<std::is_base_of<MemoryLoadable, T>::value>::type*>
void LeagueMemoryReader::ReadGameObjectList(std::vector<T*>& readInto, DWORD numMaxObjects, DWORD baseAddr, MemSnapshot& snapshot) {

	auto& idxToObjectMap = snapshot.idxToObjectMap;

	DWORD listManagerPtr = Mem::ReadPointer(hProcess, moduleBaseAddr + baseAddr);
	DWORD listPtr = Mem::ReadPointer(hProcess, listManagerPtr + 0x4);
	DWORD numObjects = 0;
	Mem::Read(hProcess, listManagerPtr + 0x8, &numObjects, 4);

	readInto.clear();
	if (listPtr == 0 || numObjects < 0 || numObjects > numMaxObjects) {
		numObjects = 0;
	}

	static DWORD pointers[500];
	Mem::Read(hProcess, listPtr, pointers, numObjects * sizeof(DWORD));

	for (size_t i = 0; i < numObjects; ++i) {

		if (pointers[i] == 0)
			break;

		int objIndex;
		Mem::Read(hProcess, pointers[i] + Offsets::ObjIndex, &objIndex, sizeof(int));

		T* obj;
		auto it = idxToObjectMap.find(objIndex);
		if (it == idxToObjectMap.end()) {
			obj = new T();
			obj->LoadFromMem(pointers[i], hProcess, true);
			idxToObjectMap[obj->objectIndex] = obj;
		}
		else {
			obj = (T*)it->second;
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