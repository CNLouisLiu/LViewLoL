#include "LeagueProcessHook.h"
#include "windows.h"
#include "Utils.h"
#include "Structs.h"
#include "psapi.h"
#include <stdexcept>

bool LeagueProcessHook::IsHookedToProcess() {
	return Process::IsProcessRunning(pid);
}

void LeagueProcessHook::HookToProcess() {

	// Find the window
	HWND windowHandle = FindWindowA("RiotWindowClass", NULL);
	if (windowHandle == NULL) {
		throw WinApiException("League window not found");
	}

	// Get the process ID
	GetWindowThreadProcessId(windowHandle, &pid);
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

void LeagueProcessHook::ReadStructs() {
	
	// Read champs
	DWORD_PTR objManagerPtr = Mem::ReadPointer(hProcess, moduleBaseAddr + oObjManager, is64Bit);
	DWORD_PTR champListPtr = Mem::ReadPointer(hProcess, objManagerPtr + oChampionManagerChampionList, is64Bit);
	Mem::Read(hProcess, objManagerPtr + oChampionCount, &numChampions, 4);

	if (champListPtr != 0 && numChampions > 0 && numChampions < 11) {

		int i = 0;
		for (int i = 0; i < numChampions; ++i) {
			DWORD_PTR heroPtr = Mem::ReadPointer(hProcess, champListPtr + i * 4, is64Bit);

			if (heroPtr != 0) {
				champions[i].LoadFromMem(heroPtr, hProcess);
			}
		}
	}

	// Read renderer
	DWORD_PTR rendererAddr = Mem::ReadPointer(hProcess, moduleBaseAddr + oRenderer, is64Bit);
	renderer.LoadFromMem(rendererAddr, hProcess);

	//Read game time
	gameTime = Mem::ReadFloat(hProcess, moduleBaseAddr + oGameTime);
}