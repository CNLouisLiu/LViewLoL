#pragma once
#include "BaseView.h"


class DebugView : public BaseView {

	const char* GetName();
	void DrawSettings(LeagueMemoryReader& reader);
	void DrawPanel(LeagueMemoryReader& reader);
	void DrawOverlay(LeagueMemoryReader& reader, ImDrawList* overlayCanvas);

};