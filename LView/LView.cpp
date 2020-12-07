// LView.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "windows.h"
#include "Utils.h"
#include "Structs.h"
#include "LeagueProcessHook.h"
#include <time.h>
#include "UI.h"

int main()
{
	// Init UI and hook
	UI ui = UI();
	LeagueProcessHook reader = LeagueProcessHook();

	try {
		ui.Start();
	}
	catch (WinApiException exception) {
		std::cout << exception.GetErrorMessage() << std::endl;
	}

	int millisPerFrame = 20;
	int frameTimeBegin, frameTimeLength;

	// Main loop
	while (true) {
	
		frameTimeBegin = time(0)*1000;

		try {
			if (!reader.IsHookedToProcess()) {
				reader.HookToProcess();
			}
			else {
				reader.ReadStructs();
				ui.Update(reader);
			}
		}
		catch (WinApiException exception) {
			std::cout << exception.GetErrorMessage() << std::endl;
		}
		catch (std::runtime_error exception) {
			std::cout << exception.what() << std::endl;
		}

		frameTimeLength = time(0) * 1000 - frameTimeBegin;
		if(frameTimeLength > 0 && frameTimeLength < millisPerFrame)
			Sleep(millisPerFrame- frameTimeLength);
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
