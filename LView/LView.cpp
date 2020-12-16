#define BOOST_DEBUG_PYTHON 
#include "PyStructs.h"

#include <iostream>
#include "windows.h"
#include "Utils.h"
#include "Structs.h"
#include "LeagueMemoryReader.h"

#include <chrono>
#include "UI.h"
#include <map>
#include <list>

using namespace std::chrono;

int main()
{

	PyImport_AppendInittab("lview", &PyInit_lview);
	Py_Initialize();

	// Init UI and hook
	UI ui = UI();
	LeagueMemoryReader reader = LeagueMemoryReader();

	try {
		ui.Start();
	}
	catch (WinApiException exception) {
		std::cout << exception.GetErrorMessage() << std::endl;
	}

	float millisPerFrame = 10;
	float frameTimeLength;
	high_resolution_clock::time_point frameTimeBegin;
	duration<float, std::milli> diff;

	MemSnapshot memSnapshot;

	// Main loop
	while (true) {
	
		frameTimeBegin = high_resolution_clock::now();

		try {
			if (!reader.IsHookedToProcess()) {
				reader.HookToProcess();
				memSnapshot = MemSnapshot();
			}
			else {
				reader.MakeSnapshot(memSnapshot);
				if(memSnapshot.gameTime > 1)
					ui.Update(memSnapshot, reader.IsLeagueWindowActive());
			}
		}
		catch (WinApiException exception) {
			std::cout << exception.GetErrorMessage() << std::endl;
		}
		catch (std::runtime_error exception) {
			std::cout << exception.what() << std::endl;
		}

		diff = (high_resolution_clock::now() - frameTimeBegin);
		frameTimeLength = diff.count();
		if(frameTimeLength > 0 && frameTimeLength < millisPerFrame)
			Sleep((DWORD)(millisPerFrame - frameTimeLength));
	}

	Py_Finalize();
}