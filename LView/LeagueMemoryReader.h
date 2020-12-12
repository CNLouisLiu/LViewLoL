#pragma once

#include "windows.h"
#include "Champion.h"
#include "GameObject.h"
#include "Renderer.h"
#include <list>
#include <vector>
#include <set>
#include <chrono>

using namespace std::chrono;

struct ReadBenchmark {
	float readChampsMs;
	float readRendererMs;
	float readMinionsMs;
};

class LeagueMemoryReader {

public:
	LeagueMemoryReader() {
		for (int i = 0; i < numMaxChamps; ++i)
			championsArray[i] = new Champion();
		bufferObject = new GameObject();
	}

	~LeagueMemoryReader() {
		for (int i = 0; i < numMaxChamps; ++i)
			delete championsArray[i];
		delete bufferObject;
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
	std::vector<GameObject*>    wards;
	std::vector<GameObject*>    minions;
	std::vector<GameObject*>    jungle;
	std::vector<GameObject*>    others;

	/* A map between the indexObject member of the object and the object itself */
	std::map<unsigned int, GameObject*>  idxToObjectMap;
	  
	Champion*                            localChampion;
	GameObject*                          hoveredObject;

	Renderer                             renderer;
	float                                gameTime;
	ReadBenchmark                        benchmark;

private:
	static const size_t         numMaxChamps = 10;
	static const size_t         numMaxMobs = 500;
	float                       minDistanceToCursor;

	Champion*                   championsArray[numMaxChamps];

	GameObject*                 bufferObject;
	
	void                        ReadChampions();
	void                        ReadRenderer();
	void                        ReadMinions();

};