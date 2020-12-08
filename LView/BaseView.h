#pragma once
#include "imgui.h"
#include "LeagueMemoryReader.h"

class BaseView {
	
public:
	virtual const char* GetName() = 0;
	virtual void DrawSettings(LeagueMemoryReader& reader) = 0;
	virtual void DrawPanel(LeagueMemoryReader& reader) = 0;
	virtual void DrawOverlay(LeagueMemoryReader& reader, ImDrawList* overlayCanvas) = 0;

	bool enabled = true;
};