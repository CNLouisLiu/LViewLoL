#define BOOST_DEBUG_PYTHON 
#include "PyStructs.h"

#include <iostream>
#include "windows.h"
#include "Utils.h"
#include "Structs.h"
#include "LeagueMemoryReader.h"
#include "Offsets.h"

#include <chrono>
#include "UI.h"
#include <map>
#include <list>

using namespace std::chrono;

int main()
{
	printf("[+] Loading offsets\n");
	Offsets::LoadFromConfigs();

	printf("[+] Initializing PyModule\n");
	PyImport_AppendInittab("lview", &PyInit_lview);
	Py_Initialize();

	printf("[+] Initialising imgui and directx UI\n\n");
	UI ui = UI();
	LeagueMemoryReader reader = LeagueMemoryReader();

	try {
		ui.Init();
	}
	catch (WinApiException exception) {
		std::cout << exception.GetErrorMessage() << std::endl;
	}

	float millisPerFrame = 10;
	float frameTimeLength;
	high_resolution_clock::time_point frameTimeBegin;
	duration<float, std::milli> diff;

	MemSnapshot memSnapshot;

	/* Flag for when to look for the league process */
	bool rehook = true;
	bool firstIter = true;

	printf("[i] Waiting for league process...\n");
	while (true) {
		frameTimeBegin = high_resolution_clock::now();

		try {
			// Try to find the league process and get its information necessary for reading
			if (rehook) {
				reader.HookToProcess();
				rehook = false;
				firstIter = true;
				memSnapshot = MemSnapshot();
				printf("[i] Found league process. The UI will appear when the game stars.\n");
			}
			else {

				if (!reader.IsHookedToProcess()) {
					rehook = true;
					printf("[i] League process is dead.\n");
					printf("[i] Waiting for league process...\n");
				}
				reader.MakeSnapshot(memSnapshot);

				// If the game started
				if (memSnapshot.gameTime > 2.f) {

					// Tell the UI that a new game has started
					if (firstIter) {
						ui.GameStart(memSnapshot);
						firstIter = false;
					}

					// Update the UI only if league window is not minimized and the game is not over
					ui.Update(memSnapshot, reader.IsLeagueWindowActive() && memSnapshot.champions.size() > 0);
				}
			}
		}
		catch (WinApiException exception) {
			// This should trigger only when we don't find the league process.
			rehook = true;
		}
		catch (std::runtime_error exception) {
			printf("[!] Unexpected error occured: \n [!] %s \n", exception.what());
			break;
		}

		diff = (high_resolution_clock::now() - frameTimeBegin);
		frameTimeLength = diff.count();
		if(frameTimeLength > 0 && frameTimeLength < millisPerFrame)
			Sleep((DWORD)(millisPerFrame - frameTimeLength));
	}

	Py_Finalize();
}