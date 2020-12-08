#pragma once
#include "BaseView.h"

class SpellTrackerView : public BaseView {

public:
	const char* GetName();
	void DrawSettings(LeagueProcessHook reader);
	void DrawPanel(LeagueProcessHook reader);
	void DrawOverlay(LeagueProcessHook reader, ImDrawList* overlayCanvas);

private:
	void DrawSpellTrackerOnChampions(LeagueProcessHook reader, ImDrawList* list);

private:
	bool showOverlayOnAllies = false;
	bool showOverlayOnEnemies = true;
	bool showPanel = true;

};