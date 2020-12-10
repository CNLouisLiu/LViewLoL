#include "LastHitAssistView.h"
#define PI 3.14159265358979323846f

const char* LastHitAssistView::GetName() {
	return "Last Hit Assist";
}
void LastHitAssistView::DrawSettings(LeagueMemoryReader& reader, UI& ui) {
	ImGui::Checkbox("Show when to smite", &showSmiteLastHit);
	ImGui::Checkbox("Show when to hit minions", &showMinionLastHit);
}

void LastHitAssistView::DrawWorldSpaceOverlay(LeagueMemoryReader& reader, ImDrawList* overlayCanvas, UI& uis) {
	
	for (auto it = reader.minions.begin(); it != reader.minions.end(); ++it) {
		GameObject* minion = *it;
		if (minion->team == reader.localChampion->team || !minion->isVisible || minion->health < 0.1f)
			continue;

		if (League::EffectiveHP(minion->health, minion->armour) - reader.localChampion->GetBasicAttackDamage() <= 0.f) {
			reader.renderer.DrawCircleAt(overlayCanvas, minion->position, 50.f, false, 15, Colors::Cyan);
		}
	}
}