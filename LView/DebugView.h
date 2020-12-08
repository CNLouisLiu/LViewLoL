#pragma once
#include "BaseView.h"


class DebugView : public BaseView {

	const char* GetName();
	void DrawSettings(LeagueProcessHook reader);
	void DrawPanel(LeagueProcessHook reader);
	void DrawOverlay(LeagueProcessHook reader, ImDrawList* overlayCanvas);

};