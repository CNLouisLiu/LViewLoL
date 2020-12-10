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
	float readMinionsMs;
};

class LeagueMemoryReader {

public:
	LeagueMemoryReader() {
		for (int i = 0; i < numMaxChamps; ++i)
			champions[i] = new Champion();
		for (int i = 0; i < numMaxMinions; ++i)
			minions[i] = new GameObject();
	}

	~LeagueMemoryReader() {
		for (int i = 0; i < numMaxChamps; ++i)
			delete champions[i];
		for (int i = 0; i < numMaxMinions; ++i)
			delete minions[i];
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
	// Structs
	static const size_t       numMaxChamps = 10;
	static const size_t       numMaxMinions = 500;
	 
	Champion*                 champions[numMaxChamps];
	GameObject*               minions[numMaxMinions];
	std::vector<GameObject*>  wards;
	std::vector<GameObject*>  others;
	 
	size_t                    numMinions = 0;
	size_t                    numOtherObjects = 0;
	size_t                    numChampions = 0;
	int                       localPlayerIdx = 0;

	Renderer                  renderer;
	float                     gameTime;

	ReadBenchmark             benchmark;

private:
	std::set<std::string>     wardNames = { "YellowTrinket", "JammerDevice", "SightWard" };

	void                      ReadChampions();
	void                      ReadRenderer();
	void                      ReadMinions();

};