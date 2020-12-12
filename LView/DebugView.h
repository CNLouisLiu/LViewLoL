#pragma once
#include "BaseView.h"
#include "KeySelector.h"
#include "UI.h"


class DebugView : public BaseView {

public:
	const char*    GetName();
	void           DrawPanel(LeagueMemoryReader& reade, UI& uir);
	void           DrawWorldSpaceOverlay(LeagueMemoryReader& reader, ImDrawList* overlayCanvas, UI& ui);

	void           DrawSettings(LeagueMemoryReader& reader, UI& ui);
	void           OnSaveSettings(ConfigSet& configs);
	void           OnLoadSettings(ConfigSet& configs);
private:
	bool           showHoveredObject;
	KeySelector*   showHoveredObjectKeySelector;
};