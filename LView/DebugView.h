#pragma once
#include "BaseView.h"
#include "UI.h"


class DebugView : public BaseView {

public:
	const char* GetName();
	void        DrawPanel(LeagueMemoryReader& reade, UI& uir);
};