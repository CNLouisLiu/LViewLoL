#pragma once

#include "BaseView.h"

class BenchmarkingView : public BaseView {

	const char* GetName();
	void DrawSettings(LeagueMemoryReader& reader, UI& ui);
};