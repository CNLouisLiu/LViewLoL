#pragma once
#include "BaseView.h"

class IndicatorsView : public BaseView {

public:
	const char*    GetName();
	void           DrawWorldSpaceOverlay(LeagueMemoryReader& reader, ImDrawList* overlayCanvas, UI& ui);

	void           DrawSettings(LeagueMemoryReader& reader, UI& ui);
	void           OnSaveSettings(ConfigSet& configs);
	void           OnLoadSettings(ConfigSet& configs);

private:
	bool           showTurretRange;
	bool           showPlayerAtkRange;
};