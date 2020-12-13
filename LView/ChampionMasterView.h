#pragma once
#include "BaseView.h"

class ChampionMasterView: public BaseView {

public:

	ChampionMasterView(std::map<std::string, std::list<BaseView*>> championViews);

	const char*    GetName();

	void           OnSaveSettings(ConfigSet& configs);
	void           OnLoadSettings(ConfigSet& configs);

	void           DrawPanel(const MemSnapshot& snapshot, const MiscToolbox& toolbox);
	void           DrawWorldSpaceOverlay(const MemSnapshot& snapshot, const MiscToolbox& toolbox);
    void           DrawMinimapOverlay(const MemSnapshot& snapshot, const MiscToolbox& toolbox);
	void           DrawSettings(const MemSnapshot& snapshot, const MiscToolbox& toolbox);

private:
	bool firstFrameElapsed = false;
	std::list<BaseView*> currentViews;
	std::map<std::string, std::list<BaseView*>> championViews;
};