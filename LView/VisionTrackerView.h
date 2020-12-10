#pragma once

#include "BaseView.h"
#include "UI.h"


class VisionTrackerView : public BaseView {

public:
	const char* GetName();
	void        DrawSettings(LeagueMemoryReader& reader, UI& ui);

	void        DrawMinimapOverlay(LeagueMemoryReader& reader, ImDrawList* overlayCanvas, UI& ui);
	void        DrawWorldSpaceOverlay(LeagueMemoryReader& reader, ImDrawList* overlayCanvas, UI& uis);

private:

	bool        showOverlayOnAllyWards;

};