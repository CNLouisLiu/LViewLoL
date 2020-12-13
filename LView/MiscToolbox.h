#pragma once
#include "imgui.h"
#include "Benchmark.h"
#include <map>

class BaseView;

struct MiscToolbox {
	/* Font sizes are not dynamic in imgui so we have to create separate fonts */
	ImFontConfig                       fontConfigSmall;
	ImFontConfig                       fontConfigNormal;
	ImFont*                            fontSmall;
	ImFont*                            fontNormal;

	/* Contains general benchmarking for the registered views */
	std::map<BaseView*, ViewBenchmark*>    viewBenchmarks;
	UIBenchmark*                       generalBenchmarks = new UIBenchmark();

	/* Canvas for primitive drawing */
	ImDrawList*                        canvas;
};