#pragma once

#include "windows.h"
#include "Structs.h"
#include <list>
#include <vector>
#include <set>
#include <chrono>

using namespace std::chrono;

struct ReadBenchmark {
	float readChampsMs;
	float readRendererMs;
	float readOtherObjectsMs;
};

class LeagueMemoryReader {

public:
	LeagueMemoryReader() {
		gameObjectPointers = new DWORD[GAME_OBJECT_ARRAY_SIZE];

		for (int i = 0; i < 10; ++i)
			champions[i] = new Champion();
	}

	~LeagueMemoryReader() {
		delete[] gameObjectPointers;
	}

	bool IsLeagueWindowActive();
	bool IsHookedToProcess();
	void HookToProcess();

	void ReadStructs();
	
private:

	// Process related
	HANDLE hProcess;
	DWORD pid;
	HWND hWindow;

	// Memory related
	DWORD_PTR moduleBaseAddr;
	DWORD moduleSize;
	BOOL is64Bit = FALSE;

public:
	// Structs
	Champion* champions[10];
	std::vector<GameObject*> otherObjects;
	std::vector<GameObject*> wards;

	size_t numOtherObjects = 0;
	size_t numChampions = 0;
	int localPlayerIdx = 0;

	Renderer renderer;
	float gameTime;

	ReadBenchmark benchmark;

private:
	DWORD* gameObjectPointers;
	std::set<DWORD> gameObjectPointersAvoid; // Used to cull the number of ReadProcessMemory calls
	std::set<std::string> wardNames = { "YellowTrinket", "JammerDevice", "SightWard" };

};