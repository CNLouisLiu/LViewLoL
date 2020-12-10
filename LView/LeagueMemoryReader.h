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
		for (int i = 0; i < numMaxMinions; ++i)
			minionsArray[i] = new GameObject();
	}

	~LeagueMemoryReader() {
		for (int i = 0; i < numMaxChamps; ++i)
			delete championsArray[i];
		for (int i = 0; i < numMaxMinions; ++i)
			delete minionsArray[i];
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
	std::vector<Champion*>    champions;
	std::vector<GameObject*>  wards;
	std::vector<GameObject*>  minions;
	std::vector<GameObject*>  others;
	Champion*                 localChampion;

	Renderer                  renderer;
	float                     gameTime;

	ReadBenchmark             benchmark;

private:
	static const size_t       numMaxChamps = 10;
	static const size_t       numMaxMinions = 500;
	size_t                    numMinions = 0;
	size_t                    numChampions = 0;

	Champion*                 championsArray[numMaxChamps];
	GameObject*               minionsArray[numMaxMinions];

	std::set<std::string>     wardNames = { "YellowTrinket", "JammerDevice", "SightWard" };

	void                      ReadChampions();
	void                      ReadRenderer();
	void                      ReadMinions();

};