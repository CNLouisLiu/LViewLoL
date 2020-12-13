#include "IndicatorsView.h"
#include "Utils.h"

const char* IndicatorsView::GetName() {
	return "Indicators";
}
void IndicatorsView::DrawWorldSpaceOverlay(LeagueMemoryReader& reader, ImDrawList* overlayCanvas, UI& ui) {

	if (showTurretRange) {
		for (auto it = reader.turrets.begin(); it != reader.turrets.end(); ++it) {
			if (reader.renderer.IsWorldPointOnScreen((*it)->position, 0, 0))
				reader.renderer.DrawCircleAt(overlayCanvas, (*it)->position, 750 + reader.localChampion->targetRadius, false, 70, Colors::Cyan);
		}
	}

	if (showPlayerAtkRange) {
		for (auto it = reader.champions.begin(); it != reader.champions.end(); ++it) {
			Champion* champ = *it;

			if (champ->team == reader.localChampion->team)
				continue;
			float distance = League::Distance(champ->position, reader.localChampion->position);
			if (distance <= reader.localChampion->attackRange + 65)
				reader.renderer.DrawCircleAt(overlayCanvas, champ->position, champ->targetRadius, false, 20, Colors::Red);
		}
		reader.renderer.DrawCircleAt(overlayCanvas, reader.localChampion->position, reader.localChampion->attackRange + 65, false, 70, Colors::Orange);
	}
}

void IndicatorsView::DrawSettings(LeagueMemoryReader& reader, UI& ui) {
	ImGui::Checkbox("Show Turret Range", &showTurretRange);
	ImGui::Checkbox("Show Basic Attack Range", &showPlayerAtkRange);
}

void IndicatorsView::OnSaveSettings(ConfigSet& configs) {
	BaseView::OnSaveSettings(configs);
}

void IndicatorsView::OnLoadSettings(ConfigSet& configs) {
	BaseView::OnLoadSettings(configs);
}