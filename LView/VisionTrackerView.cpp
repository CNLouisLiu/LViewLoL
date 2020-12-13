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

void VisionTrackerView::DrawSettings(const MemSnapshot& snapshot, const MiscToolbox& toolbox) {

	ImGui::Checkbox("Track invisible stuff(Wards, Shaco Boxes, etc)##visionTracker.showInvisibles", &showInvisibles);
	ImGui::Checkbox("Track clones (Shaco, LeBlanc, etc)##visionTracker.showClones", &showClones);
}

void VisionTrackerView::DrawInvisibles(const MemSnapshot& snapshot, const MiscToolbox& toolbox) {
	Champion* localChampion = snapshot.localChampion;
	for (auto it = snapshot.others.begin(); it != snapshot.others.end(); ++it) {
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
			int expiresIn = (int)(obj->expiresIn + obj->lastVisibleAt - snapshot.gameTime);
			if (expiresIn <= 0)
				continue;
			text.append(std::to_string(expiresIn));
		}

		Vector2 screenPos = snapshot.renderer->WorldToScreen(obj->position);
		if (!snapshot.renderer->IsScreenPointOnScreen(screenPos))
			continue;
		toolbox.canvas->AddRectFilled(ImVec2(screenPos.x - 5.f, screenPos.y - 2.f), ImVec2(screenPos.x + text.length() * 8.f, screenPos.y + 15.f), Colors::White);
		toolbox.canvas->AddText(ImVec2(screenPos.x, screenPos.y), Colors::Red, text.c_str());
		if (radiusCircle > 0.f)
			snapshot.renderer->DrawCircleAt(toolbox.canvas, obj->position, radiusCircle, fillCircle, 30, colorCircle);

	}
}

void VisionTrackerView::DrawClones(const MemSnapshot& snapshot, const MiscToolbox& toolbox) {
	
	Champion* localChampion = snapshot.localChampion;
	for (auto it = snapshot.others.begin(); it != snapshot.others.end(); ++it) {
		GameObject* obj = *it;
		if (obj->IsOfTypes(CLONE) && obj->IsEnemyTo(localChampion)) {
			std::string text = obj->name;
			text.append("Clone");

			Vector2 screenPos = snapshot.renderer->WorldToScreen(obj->position);
			if (!snapshot.renderer->IsScreenPointOnScreen(screenPos))
				continue;
			toolbox.canvas->AddRectFilled(ImVec2(screenPos.x - 5.f, screenPos.y - 2.f), ImVec2(screenPos.x + text.length() * 8.f, screenPos.y + 15.f), Colors::White);
			toolbox.canvas->AddText(ImVec2(screenPos.x, screenPos.y), Colors::Red, text.c_str());
		}
	}
}

void VisionTrackerView::DrawWorldSpaceOverlay(const MemSnapshot& snapshot, const MiscToolbox& toolbox) {
	
	if (showInvisibles)
		DrawInvisibles(snapshot, toolbox);
	if (showClones)
		DrawClones(snapshot, toolbox);
}

void VisionTrackerView::DrawMinimapOverlay(const MemSnapshot& snapshot, const MiscToolbox& toolbox) {

	for (auto it = snapshot.others.begin(); it != snapshot.others.end(); ++it) {
		GameObject* ward = *it;
		if (ward->IsEnemyTo(snapshot.localChampion) && (ward->type == WARD || ward->type == WARD_PINK)) {
			Vector2 screenPos = snapshot.renderer->WorldToMinimap(ward->position);
			toolbox.canvas->AddCircle(ImVec2(screenPos.x, screenPos.y), 15.f, Colors::Red, 10);
		}
	}
}