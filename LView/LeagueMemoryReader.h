#pragma once

#include "windows.h"
#include "Champion.h"
#include "GameObject.h"
#include "Renderer.h"
#include "Offsets.h"
#include <list>
#include <vector>
#include <set>
#include <chrono>

using namespace std::chrono;

struct ReadBenchmark {
	float readChampsMs;
	float readRendererMs;
	float readMinionsMs;
	float readTurretsMs;
};

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

	void ReadStructs();
	
private:

	// Process related
	HANDLE                    hProcess;
	DWORD                     pid;
	HWND                      hWindow;

	// Memory related
	DWORD_PTR                 moduleBaseAddr;
	DWORD                     moduleSize;
	BOOL                      is64Bit = FALSE;

public:
	/* Lists of objects by category */
	std::vector<Champion*>      champions;
	std::vector<GameObject*>    minions;
	std::vector<GameObject*>    jungle;
	std::vector<GameObject*>    turrets;
	std::vector<GameObject*>    others;

	/* A map between the indexObject member of the object and the object itself */
	std::map<unsigned int, GameObject*>  idxToObjectMap;
	/* Used to clear idxToObjectMap for objects that are no longer in game */
	std::set<unsigned int>               updatedThisFrame;
	  
	Champion*                            localChampion;
	GameObject*                          hoveredObject;

	Renderer                             renderer;
	float                                gameTime;
	ReadBenchmark                        benchmark;

private:
	static const size_t         numMaxChamps = 10;
	static const size_t         numMaxTurrets = 24;
	static const size_t         numMaxMobs = 500;
	float                       minDistanceToCursor;

	// Buffers use for avoiding to reinstantiate game objects
	GameObject*                 bufferGameObject;
	Champion*                   bufferChampion;
	
	void                        ReadChampions();
	void                        ReadRenderer();
	void                        ReadMobs();
	void                        ReadTurrets();
	void                        FindHoveredObject();

	template<typename T, typename std::enable_if<std::is_base_of<MemoryLoadable, T>::value>::type* = nullptr>
	void                        ReadGameObjectList(std::vector<T*>& readInto, T** bufferObject, DWORD numMaxObjects, DWORD baseAddr);
};

template<typename T, typename std::enable_if<std::is_base_of<MemoryLoadable, T>::value>::type*>
void LeagueMemoryReader::ReadGameObjectList(std::vector<T*>& readInto, T** bufferObject, DWORD numMaxObjects, DWORD baseAddr) {

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

	for (size_t i = 0; i <= numObjects; ++i) {

		if (pointers[i] == 0)
			break;
		
		unsigned int objIndex;
		Mem::Read(hProcess, pointers[i] + oObjIndex, &objIndex, sizeof(unsigned int));

		T* obj;
		auto it = idxToObjectMap.find(objIndex);
		if (it == idxToObjectMap.end()) {
			obj = new T();
			idxToObjectMap[objIndex] = obj;
		}
		else
			obj = (T*)it->second;

		obj->LoadFromMem(pointers[i], hProcess, true);
		
		if (obj->isVisible) {
			obj->lastVisibleAt = gameTime;
		}

		readInto.push_back(obj);
		updatedThisFrame.insert(obj->objectIndex);
	}
}