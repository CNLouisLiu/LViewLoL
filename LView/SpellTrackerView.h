#pragma once
#include "BaseView.h"

class SpellTrackerView : public BaseView {

public:
	const char* GetName();
	void DrawSettings(LeagueMemoryReader& reader);
	void DrawPanel(LeagueMemoryReader& reader);
	void DrawOverlay(LeagueMemoryReader& reader, ImDrawList* overlayCanvas);

private:
	void DrawSpellTrackerOnChampions(LeagueMemoryReader& reader, ImDrawList* list);

private:
	bool showOverlayOnAllies = false;
	bool showOverlayOnEnemies = true;
	bool showPanel = true;

};