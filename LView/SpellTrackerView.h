#pragma once
#include "BaseView.h"
#include "UI.h"

class SpellTrackerView : public BaseView {

public:
	const char* GetName();
	void DrawSettings(LeagueMemoryReader& reader, UI& ui);
	void DrawPanel(LeagueMemoryReader& reader, UI& ui);

	void DrawWorldSpaceOverlay(LeagueMemoryReader& reader, ImDrawList* overlayCanvas, UI& ui);

private:
	void DrawSpellTrackerOnChampions(LeagueMemoryReader& reader, ImDrawList* list);
	void DrawSpellTrackerPanel(LeagueMemoryReader& reader);
	void DrawSpellButton(Spell& spell, float gameTime, ImDrawList* drawList, ImVec2& position);
	void DrawSpellButton(Spell& spell, float gameTime, bool useSpellName);

private:
	bool showOverlayOnAllies = false;
	bool showOverlayOnEnemies = true;
	bool showPanel = true;

	bool showAdvanced = false;

};