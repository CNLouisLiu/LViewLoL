#pragma once
#include "BaseView.h"
#include "UI.h"

class SpellTrackerView : public BaseView {

public:
	void        OnSaveSettings(ConfigSet& configs);
	void        OnLoadSettings(ConfigSet& configs);
	const char* GetName();
	void        DrawSettings(LeagueMemoryReader& reader, UI& ui);
	void        DrawPanel(LeagueMemoryReader& reader, UI& ui);

	void        DrawWorldSpaceOverlay(LeagueMemoryReader& reader, ImDrawList* overlayCanvas, UI& ui);

private:
	void        DrawSpellTrackerOnChampions(LeagueMemoryReader& reader, UI& ui, ImDrawList* list);
	void        DrawSpellTrackerPanel(LeagueMemoryReader& reader);
	void        DrawWorldSpellButton(Spell& spell, float gameTime, ImDrawList* drawList, ImVec2& position);
	void        DrawPanelSpellButton(Spell& spell, float gameTime, bool useSpellName);

private:
	bool        showOverlayOnAllies = false;
	bool        showOverlayOnEnemies = true;
	bool        showPanel = true;

	bool        showAdvanced = false;

	const int widthSpellBtn = 17.f;
	const int heightSpellBtn = 12.f;
	const int spacingSpellBtn = 3.f;
	const int spacingLvlPill = 1.f;
	const int radiusLvlPill = 4.f;

};