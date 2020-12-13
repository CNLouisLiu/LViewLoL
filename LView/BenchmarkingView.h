#pragma once

#include "BaseView.h"

class BenchmarkingView : public BaseView {

	const char* GetName();
	void        DrawPanel(const MemSnapshot& snapshot, const MiscToolbox& toolbox);
};