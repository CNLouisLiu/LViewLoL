#include "LeagueMemoryReader.h"
#include "windows.h"
#include "Utils.h"
#include "Structs.h"
#include "psapi.h"
#include <stdexcept>

bool LeagueMemoryReader::IsLeagueWindowActive() {
	HWND handle = GetForegroundWindow();

	DWORD h;
	GetWindowThreadProcessId(handle, &h);
	return pid == h;
}

bool LeagueMemoryReader::IsHookedToProcess() {
	return Process::IsProcessRunning(pid);
}

void LeagueMemoryReader::HookToProcess() {

	// Find the window
	hWindow = FindWindowA("RiotWindowClass", NULL);
	if (hWindow == NULL) {
		throw WinApiException("League window not found");
	}

	// Get the process ID
	GetWindowThreadProcessId(hWindow, &pid);
	if (pid == NULL) {
		throw WinApiException("Couldn't retrieve league process id");
	}

	// Open the process
	hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
	if (hProcess == NULL) {
		throw WinApiException("Couldn't open league process");
	}

	// Check architecture
	if (0 == IsWow64Process(hProcess, &is64Bit)) {
		throw WinApiException("Failed to identify if process has 32 or 64 bit architecture");
	}

	HMODULE hMods[1024];
	DWORD cbNeeded;
	if (EnumProcessModules(hProcess, hMods, sizeof(hMods), &cbNeeded)) {
		moduleBaseAddr = (DWORD_PTR)hMods[0];
	}
	else {
		throw WinApiException("Couldn't retrieve league base address");
	}
}

void LeagueMemoryReader::ReadStructs() {
	
	// Read champs
	DWORD_PTR objManagerPtr = Mem::ReadPointer(hProcess, moduleBaseAddr + oObjManager);
	DWORD_PTR champListPtr = Mem::ReadPointer(hProcess, objManagerPtr + oChampionManagerChampionList);
	Mem::Read(hProcess, objManagerPtr + oChampionCount, &numChampions, 4);

	if (champListPtr != 0 && numChampions > 0 && numChampions < 11) {

		int i = 0;
		for (int i = 0; i < numChampions; ++i) {
			DWORD_PTR heroPtr = Mem::ReadPointer(hProcess, champListPtr + i * 4);

			if (heroPtr != 0) {
				champions[i].LoadFromMem(heroPtr, hProcess);
			}
		}
	}

	// Read renderer
	DWORD_PTR rendererAddr = Mem::ReadPointer(hProcess, moduleBaseAddr + oRenderer);
	renderer.LoadFromMem(rendererAddr, hProcess);

	//Read game time
	gameTime = Mem::ReadFloat(hProcess, moduleBaseAddr + oGameTime);
}