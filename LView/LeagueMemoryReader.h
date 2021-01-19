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

/// Class used to read from leagues process memory
class LeagueMemoryReader {

public:
         LeagueMemoryReader();

	/// Checks if leagues window is still active
	bool IsLeagueWindowActive();

	/// Checks to see if we have a league window stored
	bool IsHookedToProcess();

	/// Finds leagues window and stores it
	void HookToProcess();

	/// Creates an object with everything of iterest from the game
	void MakeSnapshot(MemSnapshot& ms);
private:

	// Process related
	HANDLE                      hProcess = NULL;
	DWORD                       pid      = 0;
	HWND                        hWindow  = NULL;
							   
	// Memory related		   
	DWORD_PTR                   moduleBaseAddr    = 0;
	DWORD                       moduleSize        = 0;
	BOOL                        is64Bit           = FALSE;

private:
	float                       minDistanceToCursor;

	/// Blacklisted objects that we don't need to read for performance reasons. Set key is the object's network id
	std::set<int>               blacklistedObjects;
	std::set<std::string>       blacklistedObjectNames;
	
	void                        ReadRenderer(MemSnapshot& snapshot);
	void                        ReadObjects(MemSnapshot& snapshot);
	void                        ReadMinimap(MemSnapshot& snapshot);
	void                        FindPlayerChampion(MemSnapshot& snapshot);
	void                        ClearMissingObjects(MemSnapshot& snapshot);
	void                        FindHoveredObject(MemSnapshot& ms);

};
