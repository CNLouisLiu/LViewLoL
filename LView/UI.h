#pragma once
#include "windows.h"
#include "Structs.h"
#include "LeagueMemoryReader.h"
#include <list>
#include "BaseView.h"
#include <chrono>
#include <map>

using namespace std::chrono;

struct ViewBenchmark {
	float drawSettingsMs;
	float drawPanelMs;
	float drawWorldOverlayMs;
	float drawMinimapOverlayMs;
};

class UI {

public:
	UI(std::list<BaseView*> views);
	void Start();
	void Update(LeagueMemoryReader& reader);

private:
	HWND hWindow;

	Renderer renderer;
	std::list<BaseView*> views;

public:

	/* Font sizes are not dynamic in imgui so we have to create separate fonts */
	ImFontConfig fontConfigSmall;
	ImFontConfig fontConfigNormal;
	ImFont* fontSmall;
	ImFont* fontNormal;

	/* Contains general benchmarking for the registered views */
	std::map<BaseView*, ViewBenchmark> benchmarks;

};