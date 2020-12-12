#include "VisionTrackerView.h"

const char* VisionTrackerView::GetName() {
	return "Vision Tracker";
}

void VisionTrackerView::OnSaveSettings(ConfigSet& configs) {
	BaseView::OnSaveSettings(configs);

	configs.Set<bool>("showOverlayOnAllyWards", showOverlayOnAllyWards);
}

void VisionTrackerView::OnLoadSettings(ConfigSet& configs) {
	BaseView::OnLoadSettings(configs);

	showOverlayOnAllyWards = configs.Get<bool>("showOverlayOnAllyWards", false);
}

void VisionTrackerView::DrawSettings(LeagueMemoryReader& reader, UI& ui) {

	ImGui::Checkbox("Track ally wards##showOverlayOnAllyWards", &showOverlayOnAllyWards);
}

void VisionTrackerView::DrawWorldSpaceOverlay(LeagueMemoryReader& reader, ImDrawList* overlayCanvas, UI& uis) {
	
	for (auto it = reader.wards.begin(); it != reader.wards.end(); ++it) {
		GameObject* ward = *it;
		if (ward->health == 0.f)
			continue;
		if (!showOverlayOnAllyWards && ward->team == reader.localChampion->team)
			continue;

		std::string text;

		if (ward->type == WARD_PINK) {
			text.append("Pink");
		}
		else {
			text.append("Ward:");
			text.append(std::to_string((int)(ward->expiresIn + ward->lastVisibleAt - reader.gameTime)));
		}

		Vector2 screenPos = reader.renderer.WorldToScreen(ward->position);
		if (!reader.renderer.IsScreenPointOnScreen(screenPos))
			continue;
		overlayCanvas->AddRectFilled(ImVec2(screenPos.x - 5.f, screenPos.y - 2.f), ImVec2(screenPos.x + text.length() * 8.f, screenPos.y + 15.f), Colors::White);
		overlayCanvas->AddText(ImVec2(screenPos.x, screenPos.y), Colors::Red, text.c_str());
	}
}

void VisionTrackerView::DrawMinimapOverlay(LeagueMemoryReader& reader, ImDrawList* overlayCanvas, UI& ui) {

	for (auto it = reader.wards.begin(); it != reader.wards.end(); ++it) {
		GameObject* ward = *it;
		if (ward->team == reader.localChampion->team)
			continue;

		Vector2 screenPos = reader.renderer.WorldToMinimap(ward->position);
		overlayCanvas->AddCircle(ImVec2(screenPos.x, screenPos.y), 15.f, Colors::Red, 10);
	}
}