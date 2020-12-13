#pragma once
#include "BaseView.h"

class IndicatorsView : public BaseView {

public:
	const char*    GetName();
	void           DrawWorldSpaceOverlay(const MemSnapshot& snapshot, const MiscToolbox& toolbox);

	void           DrawSettings(const MemSnapshot& snapshot, const MiscToolbox& toolbox);
	void           OnSaveSettings(ConfigSet& configs);
	void           OnLoadSettings(ConfigSet& configs);

private:
	bool           showTurretRange;
	bool           showPlayerAtkRange;
};