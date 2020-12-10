#include "BaseView.h"

void BaseView::OnLoadSettings(ConfigSet& configs) {
	enabled = configs.Get<bool>("enabled", false);
}

void BaseView::OnSaveSettings(ConfigSet& configs) {
	configs.Set<bool>("enabled", enabled);
}

void BaseView::DrawSettings(LeagueMemoryReader& reader, UI& ui) {};
void BaseView::DrawPanel(LeagueMemoryReader& reader, UI& ui) {};

void BaseView::DrawMinimapOverlay(LeagueMemoryReader& reader, ImDrawList* overlayCanvas, UI& ui) {};
void BaseView::DrawWorldSpaceOverlay(LeagueMemoryReader& reader, ImDrawList* overlayCanvas, UI& ui) {};
