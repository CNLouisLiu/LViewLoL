#pragma once
#include "imgui.h"
#include "LeagueMemoryReader.h"

class UI;

class BaseView {
	
public:
	virtual const char* GetName() = 0;
	virtual void DrawSettings(LeagueMemoryReader& reader, UI& ui) = 0;
	virtual void DrawPanel(LeagueMemoryReader& reader, UI& ui) = 0;
	virtual void DrawOverlay(LeagueMemoryReader& reader, ImDrawList* overlayCanvas, UI& ui) = 0;

	bool enabled = true;
};