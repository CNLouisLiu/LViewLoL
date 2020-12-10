#pragma once

#include "BaseView.h"

class BenchmarkingView : public BaseView {

	const char* GetName();
	void        DrawPanel(LeagueMemoryReader& reader, UI& ui);
};