#ifndef LEAGUE_CHEAT_H
#define LEAGUE_CHEAT_H

#include "windows.h"
#include "Structs.h"
#include <list>

class LeagueMemoryReader {

public:
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
	Champion champions[10];
	int numChampions = 0;
	int localPlayerIdx = 0;

	Renderer renderer;
	float gameTime;

};
#endif