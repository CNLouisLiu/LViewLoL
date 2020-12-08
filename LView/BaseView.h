#pragma once
#include "imgui.h"
#include "LeagueProcessHook.h"

class BaseView {
	
public:
	virtual const char* GetName() = 0;
	virtual void DrawSettings(LeagueProcessHook reader) = 0;
	virtual void DrawPanel(LeagueProcessHook reader) = 0;
	virtual void DrawOverlay(LeagueProcessHook reader, ImDrawList* overlayCanvas) = 0;

	bool enabled = true;
};