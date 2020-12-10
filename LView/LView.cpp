// LView.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "windows.h"
#include "Utils.h"
#include "Structs.h"
#include "LeagueMemoryReader.h"

#include "SpellTrackerView.h"
#include "HeroTrackerView.h"
#include "VisionTrackerView.h"
#include "BenchmarkingView.h"
#include "LastHitAssistView.h"
#include "DebugView.h"

#include <chrono>
#include "UI.h"

using namespace std::chrono;

int main()
{
	// Init scripts
	std::list<BaseView*> views;
	views.push_back(new SpellTrackerView());
	views.push_back(new HeroTrackerView());
	views.push_back(new VisionTrackerView());
	views.push_back(new LastHitAssistView());

	views.push_back(new BenchmarkingView());
	views.push_back(new DebugView());

	// Init UI and hook
	UI ui = UI(views);
	LeagueMemoryReader reader = LeagueMemoryReader();

	try {
		ui.Start();
	}
	catch (WinApiException exception) {
		std::cout << exception.GetErrorMessage() << std::endl;
	}

	float millisPerFrame = 20;
	float frameTimeLength;
	high_resolution_clock::time_point frameTimeBegin;
	duration<float, std::milli> diff;

	// Main loop
	while (true) {
	
		frameTimeBegin = high_resolution_clock::now();

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


		diff = (high_resolution_clock::now() - frameTimeBegin);
		frameTimeLength = diff.count();
		//std::cout << frameTimeLength << std::endl;
		//if(frameTimeLength > 0 && frameTimeLength < millisPerFrame)
		//	Sleep((DWORD)(millisPerFrame - frameTimeLength));
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
