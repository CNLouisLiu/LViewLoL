#pragma once
#include "imgui.h"
#include "LeagueMemoryReader.h"

class UI;

class BaseView {
	
public:
	virtual const char* GetName() = 0;
	virtual void        DrawSettings(LeagueMemoryReader& reader, UI& ui);
	virtual void        DrawPanel(LeagueMemoryReader& reader, UI& ui);

	virtual void        DrawMinimapOverlay(LeagueMemoryReader& reader, ImDrawList* overlayCanvas, UI& ui);
	virtual void        DrawWorldSpaceOverlay(LeagueMemoryReader& reader, ImDrawList* overlayCanvas, UI& ui);

	bool                enabled = true;
};