#pragma once
#include "BaseView.h"
#include "UI.h"

class LastHitAssistView: public BaseView {
public:
	const char* GetName();
	void        DrawSettings(LeagueMemoryReader& reader, UI& ui);

	void        DrawWorldSpaceOverlay(LeagueMemoryReader& reader, ImDrawList* overlayCanvas, UI& uis);

private:
	bool        showSmiteLastHit;
	bool        showMinionLastHit;
};