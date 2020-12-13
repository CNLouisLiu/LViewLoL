#include "IndicatorsView.h"
#include "Utils.h"

const char* IndicatorsView::GetName() {
	return "Indicators";
}
void IndicatorsView::DrawWorldSpaceOverlay(const MemSnapshot& snapshot, const MiscToolbox& toolbox) {

	if (showTurretRange) {
		for (auto it = snapshot.turrets.begin(); it != snapshot.turrets.end(); ++it) {
			if (snapshot.renderer->IsWorldPointOnScreen((*it)->position, 0, 0))
				snapshot.renderer->DrawCircleAt(toolbox.canvas, (*it)->position, 750 + snapshot.localChampion->targetRadius, false, 70, Colors::Cyan);
		}
	}

	if (showPlayerAtkRange) {

		for (auto it = snapshot.champions.begin(); it != snapshot.champions.end(); ++it) {
			Champion* champ = *it;

			if (!champ->IsEnemyTo(snapshot.localChampion))
				continue;
			float distance = League::Distance(champ->position, snapshot.localChampion->position);
			if (distance <= snapshot.localChampion->GetAttackRange())
				snapshot.renderer->DrawCircleAt(toolbox.canvas, champ->position, champ->targetRadius, false, 20, Colors::Red);
		}
		snapshot.renderer->DrawCircleAt(toolbox.canvas, snapshot.localChampion->position, snapshot.localChampion->GetAttackRange(), false, 70, Colors::Orange);
	}
}

void IndicatorsView::DrawSettings(const MemSnapshot& snapshot, const MiscToolbox& toolbox) {
	ImGui::Checkbox("Show Turret Range", &showTurretRange);
	ImGui::Checkbox("Show Basic Attack Range", &showPlayerAtkRange);
}

void IndicatorsView::OnSaveSettings(ConfigSet& configs) {
	BaseView::OnSaveSettings(configs);
}

void IndicatorsView::OnLoadSettings(ConfigSet& configs) {
	BaseView::OnLoadSettings(configs);
}