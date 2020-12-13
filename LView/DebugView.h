#pragma once
#include "BaseView.h"
#include "KeySelector.h"
#include "UI.h"


class DebugView : public BaseView {

public:
	const char*    GetName();
	void           DrawPanel(const MemSnapshot& snapshot, const MiscToolbox& toolbox);
	void           DrawWorldSpaceOverlay(const MemSnapshot& snapshot, const MiscToolbox& toolbox);

	void           DrawSettings(const MemSnapshot& snapshot, const MiscToolbox& toolbox);
	void           OnSaveSettings(ConfigSet& configs);
	void           OnLoadSettings(ConfigSet& configs);
private:
	bool           showHoveredObject;
	KeySelector*   showHoveredObjectKeySelector;
};