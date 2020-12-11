#include "LastHitAssistView.h"
#define PI 3.14159265358979323846f

const char* LastHitAssistView::GetName() {
	return "Last Hit Assist";
}

void LastHitAssistView::OnSaveSettings(ConfigSet& configs) {
	BaseView::OnSaveSettings(configs);

	configs.Set<bool>("showSmiteLastHit", showSmiteLastHit);
	configs.Set<bool>("showMinionLastHit", showMinionLastHit);
	configs.Set<bool>("autoSmite", autoSmite);
	configs.Set<int>("autoSmiteKey", toggleAutoSmite->GetKey());
}

void LastHitAssistView::OnLoadSettings(ConfigSet& configs) {
	BaseView::OnLoadSettings(configs);

	showSmiteLastHit = configs.Get<bool>("showSmiteLastHit", false);
	showMinionLastHit = configs.Get<bool>("showMinionLastHit", true);
	autoSmite = configs.Get<bool>("autoSmite", true);
	toggleAutoSmite = new KeySelector("Toggle Auto Smite##autoSmiteKey", (HKey)configs.Get<int>("autoSmiteKey", HKey::SPACE));
}

void LastHitAssistView::DrawSettings(LeagueMemoryReader& reader, UI& ui) {
	ImGui::Checkbox("Show when to smite##showSmiteLastHit", &showSmiteLastHit);
	ImGui::Checkbox("Show when to last hit##showMinionLastHit", &showMinionLastHit);
	ImGui::Checkbox("Autosmite##autoSmite", &autoSmite);
	toggleAutoSmite->Draw();
}

void LastHitAssistView::DrawWorldSpaceOverlay(LeagueMemoryReader& reader, ImDrawList* overlayCanvas, UI& uis) {
	
	if (Input::WasKeyPressed(toggleAutoSmite->GetKey()))
		autoSmite = autoSmite ^ true;
	 
	if (showMinionLastHit) {
		for (auto it = reader.minions.begin(); it != reader.minions.end(); ++it) {
			GameObject* minion = *it;

			// Skip dead/invisible/allied creeps
			if (minion->team == reader.localChampion->team || !minion->isVisible || minion->health <= 0.f)
				continue;

			if (League::EffectiveHP(minion->health, minion->armour) - reader.localChampion->GetBasicAttackDamage() <= 0.f) {
				if(reader.renderer.IsWorldPointOnScreen(minion->position))
					reader.renderer.DrawCircleAt(overlayCanvas, minion->position, minion->targetRadius*0.8f, false, 15, Colors::Cyan);
			}
		}
	}

	Spell* smite = reader.localChampion->GetSummonerSpell(SummonerSpellType::SMITE);
	if (smite == nullptr)
		return;

	if (showSmiteLastHit) {
		for (auto it = reader.jungle.begin(); it != reader.jungle.end(); ++it) {
			GameObject* mob = *it;

			if (mob->health <= 0.f || !mob->isVisible)
				continue;

			if (mob->IsOfTypes(SMITABLE, JUNGLE) && mob->health - smite->damage <= 0.f && reader.renderer.IsWorldPointOnScreen(mob->position)) {
				reader.renderer.DrawCircleAt(overlayCanvas, mob->position, mob->targetRadius*0.8f, false, 15, Colors::Yellow);
			}
		}
	}

	if (autoSmite) {

		Vector2 screenPos = reader.renderer.WorldToScreen(reader.localChampion->position);
		overlayCanvas->AddText(ImVec2(screenPos.x, screenPos.y), Colors::Yellow, "AutoSmiteOn");
		if(reader.hoveredJungle != nullptr && reader.hoveredJungle->IsOfTypes(SMITABLE, JUNGLE) && (reader.hoveredJungle->health - smite->damage <= 0.f))
			smite->Trigger();
	}

}