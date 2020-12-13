#pragma once

#include "BaseView.h"
#include "UI.h"


class VisionTrackerView : public BaseView {

public:
	void        OnSaveSettings(ConfigSet& configs);
	void        OnLoadSettings(ConfigSet& configs);
	const char* GetName();
	void        DrawSettings(LeagueMemoryReader& reader, UI& ui);

	void        DrawMinimapOverlay(LeagueMemoryReader& reader, ImDrawList* overlayCanvas, UI& ui);
	void        DrawWorldSpaceOverlay(LeagueMemoryReader& reader, ImDrawList* overlayCanvas, UI& uis);

private:

	bool        showClones;
	bool        showInvisibles;

	void        DrawInvisibles(LeagueMemoryReader& reader, ImDrawList* overlayCanvas);
	void        DrawClones(LeagueMemoryReader& reader, ImDrawList* overlayCanvas);
};