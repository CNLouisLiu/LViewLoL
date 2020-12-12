#pragma once
#include "BaseView.h"
#include "UI.h"

class SpellTrackerView : public BaseView {

public:
	void        OnSaveSettings(ConfigSet& configs);
	void        OnLoadSettings(ConfigSet& configs);
	const char* GetName();
	void        DrawSettings(LeagueMemoryReader& reader, UI& ui);

	void        DrawWorldSpaceOverlay(LeagueMemoryReader& reader, ImDrawList* overlayCanvas, UI& ui);

private:
	void        DrawSpellTrackerOnChampions(LeagueMemoryReader& reader, UI& ui, ImDrawList* list);
	void        DrawWorldSpellButton(Spell& spell, float gameTime, ImDrawList* drawList, ImVec2& position);

private:
	bool        showOverlayOnAllies;
	bool        showOverlayOnEnemies;
	bool        showOverlayOnSelf;

};