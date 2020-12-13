#include "VisionTrackerView.h"

const char* VisionTrackerView::GetName() {
	return "Vision Tracker";
}

void VisionTrackerView::OnSaveSettings(ConfigSet& configs) {
	BaseView::OnSaveSettings(configs);

	configs.Set<bool>("showInvisibles", showInvisibles);
	configs.Set<bool>("showClones", showClones);
}

void VisionTrackerView::OnLoadSettings(ConfigSet& configs) {
	BaseView::OnLoadSettings(configs);

	showInvisibles = configs.Get<bool>("showInvisibles", true);
	showClones = configs.Get<bool>("showClones", true);
}

void VisionTrackerView::DrawSettings(LeagueMemoryReader& reader, UI& ui) {

	ImGui::Checkbox("Track invisible stuff(Wards, Shaco Boxes, etc)##visionTracker.showInvisibles", &showInvisibles);
	ImGui::Checkbox("Track clones (Shaco, LeBlanc, etc)##visionTracker.showClones", &showClones);
}

void VisionTrackerView::DrawInvisibles(LeagueMemoryReader& reader, ImDrawList* overlayCanvas) {
	Champion* localChampion = reader.localChampion;
	for (auto it = reader.others.begin(); it != reader.others.end(); ++it) {
		GameObject* obj = *it;
		if (obj->health == 0.f || !obj->IsOfTypes(INVISIBLE))
			continue;
		if (!obj->IsEnemyTo(localChampion))
			continue;

		std::string text;

		ImColor colorCircle = Colors::Grey;
		float radiusCircle = 0.f;
		bool fillCircle = false;

		switch (obj->type) {
		case WARD_PINK:
			text.append("Pink");
			break;
		case WARD:
			text.append("Ward");
			break;
		case SHACO_BOX:
			text.append("ShacoShit");
			radiusCircle = 300.f;
			colorCircle = ImColor(255.f, 0.f, 0.f, 1.3f);
			break;
		case TEEMO_MUSHROOM:
			text.append("TeemoShit");
			radiusCircle = 150.f;
			colorCircle = ImColor(255.f, 0.f, 0.f, 1.f);
			break;
		default:
			continue;
		}

		// If expirable draw a timer for it
		if (obj->IsOfTypes(EXPIRABLE)) {
			text.append(":");
			int expiresIn = (int)(obj->expiresIn + obj->lastVisibleAt - reader.gameTime);
			if (expiresIn <= 0)
				continue;
			text.append(std::to_string(expiresIn));
		}

		Vector2 screenPos = reader.renderer.WorldToScreen(obj->position);
		if (!reader.renderer.IsScreenPointOnScreen(screenPos))
			continue;
		overlayCanvas->AddRectFilled(ImVec2(screenPos.x - 5.f, screenPos.y - 2.f), ImVec2(screenPos.x + text.length() * 8.f, screenPos.y + 15.f), Colors::White);
		overlayCanvas->AddText(ImVec2(screenPos.x, screenPos.y), Colors::Red, text.c_str());
		if (radiusCircle > 0.f)
			reader.renderer.DrawCircleAt(overlayCanvas, obj->position, radiusCircle, fillCircle, 30, colorCircle);

	}
}

void VisionTrackerView::DrawClones(LeagueMemoryReader& reader, ImDrawList* overlayCanvas) {
	
	Champion* localChampion = reader.localChampion;
	for (auto it = reader.others.begin(); it != reader.others.end(); ++it) {
		GameObject* obj = *it;
		if (obj->IsOfTypes(CLONE) && obj->IsEnemyTo(localChampion)) {
			std::string text = obj->name;
			text.append("Clone");

			Vector2 screenPos = reader.renderer.WorldToScreen(obj->position);
			if (!reader.renderer.IsScreenPointOnScreen(screenPos))
				continue;
			overlayCanvas->AddRectFilled(ImVec2(screenPos.x - 5.f, screenPos.y - 2.f), ImVec2(screenPos.x + text.length() * 8.f, screenPos.y + 15.f), Colors::White);
			overlayCanvas->AddText(ImVec2(screenPos.x, screenPos.y), Colors::Red, text.c_str());
		}
	}
}

void VisionTrackerView::DrawWorldSpaceOverlay(LeagueMemoryReader& reader, ImDrawList* overlayCanvas, UI& uis) {
	
	if (showInvisibles)
		DrawInvisibles(reader, overlayCanvas);
	if (showClones)
		DrawClones(reader, overlayCanvas);
}

void VisionTrackerView::DrawMinimapOverlay(LeagueMemoryReader& reader, ImDrawList* overlayCanvas, UI& ui) {

	for (auto it = reader.others.begin(); it != reader.others.end(); ++it) {
		GameObject* ward = *it;
		if (ward->IsEnemyTo(reader.localChampion) && (ward->type == WARD || ward->type == WARD_PINK)) {
			Vector2 screenPos = reader.renderer.WorldToMinimap(ward->position);
			overlayCanvas->AddCircle(ImVec2(screenPos.x, screenPos.y), 15.f, Colors::Red, 10);
		}
	}
}