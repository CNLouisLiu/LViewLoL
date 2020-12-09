#pragma once
#include "BaseView.h"
#include "UI.h"


class DebugView : public BaseView {

	const char* GetName();
	void DrawSettings(LeagueMemoryReader& reader, UI& ui);
	void DrawPanel(LeagueMemoryReader& reade, UI& uir);
	void DrawOverlay(LeagueMemoryReader& reader, ImDrawList* overlayCanva, UI& uis);

};