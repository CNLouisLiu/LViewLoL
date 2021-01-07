#pragma once

#include "windows.h"
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
         LeagueMemoryReader();
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
	float                       minDistanceToCursor;
	std::set<short>             blacklistedObjects;
	std::set<std::string>       blacklistedObjectNames;
	
	void                        ReadRenderer(MemSnapshot& snapshot);
	void                        ReadObjects(MemSnapshot& snapshot);
	void                        ReadMinimap(MemSnapshot& snapshot);
	void                        FindPlayerChampion(MemSnapshot& snapshot);
	void                        ClearMissingObjects(MemSnapshot& snapshot);
	void                        FindHoveredObject(MemSnapshot& ms);

};
