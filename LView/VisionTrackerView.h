#pragma once

#include "BaseView.h"
#include "UI.h"


class VisionTrackerView : public BaseView {

public:
	void        OnSaveSettings(ConfigSet& configs);
	void        OnLoadSettings(ConfigSet& configs);
	const char* GetName();
	void        DrawSettings(const MemSnapshot& snapshot, const MiscToolbox& toolbox);

	void        DrawMinimapOverlay(const MemSnapshot& snapshot, const MiscToolbox& toolbox);
	void        DrawWorldSpaceOverlay(const MemSnapshot& snapshot, const MiscToolbox& toolbox);

private:

	bool        showClones;
	bool        showInvisibles;

	void        DrawInvisibles(const MemSnapshot& snapshot, const MiscToolbox& toolbox);
	void        DrawClones(const MemSnapshot& snapshot, const MiscToolbox& toolbox);
};