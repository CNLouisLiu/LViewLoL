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
	configs.Set<int>("autoSmiteKey", toggleAutoSmite->GetSelectedKey());
}

void LastHitAssistView::OnLoadSettings(ConfigSet& configs) {
	BaseView::OnLoadSettings(configs);

	showSmiteLastHit = configs.Get<bool>("showSmiteLastHit", false);
	showMinionLastHit = configs.Get<bool>("showMinionLastHit", true);
	autoSmite = configs.Get<bool>("autoSmite", true);
	toggleAutoSmite = new KeySelector("Toggle Auto Smite##autoSmiteKey", (HKey)configs.Get<int>("autoSmiteKey", HKey::SPACE));
}

void LastHitAssistView::DrawSettings(const MemSnapshot& snapshot, const MiscToolbox& toolbox) {
	ImGui::Checkbox("Show when to smite##showSmiteLastHit", &showSmiteLastHit);
	ImGui::Checkbox("Show when to last hit##showMinionLastHit", &showMinionLastHit);
	ImGui::Checkbox("Autosmite##autoSmite", &autoSmite);
	toggleAutoSmite->DrawImGuiWidget();
}

void LastHitAssistView::DrawWorldSpaceOverlay(const MemSnapshot& snapshot, const MiscToolbox& toolbox) {
	
	if (Input::WasKeyPressed(toggleAutoSmite->GetSelectedKey()))
		autoSmite = autoSmite ^ true;
	 
	if (showMinionLastHit) {
		for (auto it = snapshot.minions.begin(); it != snapshot.minions.end(); ++it) {
			GameObject* minion = *it;

			// Skip dead/invisible/allied creeps
			if (minion->team == snapshot.localChampion->team || !minion->isVisible || minion->health <= 0.f)
				continue;

			if (League::EffectiveHP(minion->health, minion->armour) - snapshot.localChampion->GetBasicAttackDamage() <= 0.f) {
				if(snapshot.renderer->IsWorldPointOnScreen(minion->position))
					snapshot.renderer->DrawCircleAt(toolbox.canvas, minion->position, minion->gameplayRadius, false, 15, Colors::Cyan);
			}
		}
	}

	Spell* smite = snapshot.localChampion->GetSummonerSpell(SummonerSpellType::SMITE);
	if (smite == nullptr)
		return;

	if (showSmiteLastHit) {
		for (auto it = snapshot.jungle.begin(); it != snapshot.jungle.end(); ++it) {
			GameObject* mob = *it;

			if (!mob->isAlive || !mob->isVisible)
				continue;

			if (mob->IsOfTypes(SMITABLE, JUNGLE) && mob->health - smite->damage <= 0.f && snapshot.renderer->IsWorldPointOnScreen(mob->position)) {
				snapshot.renderer->DrawCircleAt(toolbox.canvas, mob->position, mob->targetRadius*0.8f, false, 15, Colors::Yellow);
			}
		}
	}

	if (autoSmite) {

		Vector2 screenPos = snapshot.renderer->WorldToScreen(snapshot.localChampion->position);
		toolbox.canvas->AddText(ImVec2(screenPos.x, screenPos.y), Colors::Yellow, "AutoSmiteOn");
		if(snapshot.hoveredObject != nullptr && snapshot.hoveredObject->IsOfTypes(SMITABLE, JUNGLE) && (snapshot.hoveredObject->health - smite->damage <= 0.f))
			smite->Trigger();
	}

}