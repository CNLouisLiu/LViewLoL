#pragma once
#include "BaseView.h"
#include "UI.h"
#include "KeySelector.h"

class LastHitAssistView: public BaseView {
public:
	void         OnSaveSettings(ConfigSet& configs);
	void         OnLoadSettings(ConfigSet& configs);
	const char*  GetName();
	void         DrawSettings(const MemSnapshot& snapshot, const MiscToolbox& toolbox);

	void         DrawWorldSpaceOverlay(const MemSnapshot& snapshot, const MiscToolbox& toolbox);

private:
	KeySelector* toggleAutoSmite;

	bool         showSmiteLastHit;
	bool         showMinionLastHit;
	bool         autoSmite;
};