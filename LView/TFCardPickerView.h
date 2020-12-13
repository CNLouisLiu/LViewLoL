#pragma once
#include "BaseView.h"
#include "KeySelector.h"

class TFCardPickerView : public BaseView {

public:
	TFCardPickerView();
	const char*    GetName();

	void           OnSaveSettings(ConfigSet& configs);
	void           OnLoadSettings(ConfigSet& configs);

	void           DrawWorldSpaceOverlay(const MemSnapshot& snapshot, const MiscToolbox& toolbox);
	void           DrawSettings(const MemSnapshot& snapshot, const MiscToolbox& toolbox);

private:
	KeySelector    keyBlueCard;
	KeySelector    keyRedCard;
	KeySelector    keyYellowCard;

	bool           lookingForBlue;
	bool           lookingForRed;
	bool           lookingForYellow;

	const std::string yellowCardName = std::string("GoldCardLock");
	const std::string redCardName    = std::string("RedCardLock");
	const std::string blueCardName   = std::string("BlueCardLock");
};