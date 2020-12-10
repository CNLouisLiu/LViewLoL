#pragma once
#include "imgui.h"
#include "LeagueMemoryReader.h"
#include "ConfigSet.h"

class UI;

class BaseView {
	
public:

	/* This is called once before the first frame */
	virtual void        OnLoadSettings(ConfigSet& configs);

	/* This is called when the user requests to save settings*/
	virtual void        OnSaveSettings(ConfigSet& configs);

	/* This is the name that will be specified in the Settings window */
	virtual const char* GetName() = 0;

	/* Implement this to draw settings for your cheat */
	virtual void        DrawSettings(LeagueMemoryReader& reader, UI& ui);

	/* Implement this if your cheat needs additional imgui windows */
	virtual void        DrawPanel(LeagueMemoryReader& reader, UI& ui);

	/*Implement this if your cheat needs to draw on the minimap. overlayCanvas is a window covering the minimap */
	virtual void        DrawMinimapOverlay(LeagueMemoryReader& reader, ImDrawList* overlayCanvas, UI& ui);

	/* Implement this if your cheat needs to draw on the world space. overlayCanvas is a window covering the entire screen */
	virtual void        DrawWorldSpaceOverlay(LeagueMemoryReader& reader, ImDrawList* overlayCanvas, UI& ui);

	bool                enabled = true;
};