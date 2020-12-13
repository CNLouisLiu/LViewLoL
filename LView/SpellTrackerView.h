#pragma once
#include "BaseView.h"
#include "UI.h"

class SpellTrackerView : public BaseView {

public:
	void        OnSaveSettings(ConfigSet& configs);
	void        OnLoadSettings(ConfigSet& configs);
	const char* GetName();

	void        DrawSettings(const MemSnapshot& snapshot, const MiscToolbox& toolbox);
	void        DrawWorldSpaceOverlay(const MemSnapshot& snapshot, const MiscToolbox& toolbox);

private:
	void        DrawSpellTrackerOnChampions(const MemSnapshot& snapshot, const MiscToolbox& toolbox);
	void        DrawWorldSpellButton(Spell& spell, float gameTime, const MiscToolbox& toolbox, ImVec2& position);

private:
	bool        showOverlayOnAllies;
	bool        showOverlayOnEnemies;
	bool        showOverlayOnSelf;

};