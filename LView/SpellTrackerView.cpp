#include "SpellTrackerView.h"

void SpellTrackerView::OnSaveSettings(ConfigSet& configs) {
	BaseView::OnSaveSettings(configs);

	configs.Set<bool>("showOverlayOnAllies", showOverlayOnAllies);
	configs.Set<bool>("showOverlayOnEnemies", showOverlayOnEnemies);
	configs.Set<bool>("showOverlayOnSelf", showOverlayOnSelf);
}

void SpellTrackerView::OnLoadSettings(ConfigSet& configs) {
	BaseView::OnLoadSettings(configs);

	showOverlayOnAllies = configs.Get<bool>("showOverlayOnAllies", false);
	showOverlayOnEnemies = configs.Get<bool>("showOverlayOnEnemies", true);
	showOverlayOnSelf = configs.Get<bool>("showOverlayOnSelf", false);
}

ImColor GetHsvColorBasedOnCooldown(float cooldown) {
	float hue = 0.25f; // GREEN
	if (cooldown > 10.f)
		hue = 0.f;  // RED
	else if (cooldown > 0.1f)
		hue = 0.125f; // YELLOW

	return ImColor::HSV(hue, 1.f, 0.5f);
}

void SpellTrackerView::DrawWorldSpellButton(Spell& spell, float gameTime, const MiscToolbox& toolbox, ImVec2& position) {
	float remainingCooldown = spell.GetRemainingCooldown(gameTime);

	// Draw button with cooldown
	toolbox.canvas->AddRectFilled(ImVec2(position.x - 5, position.y), ImVec2(position.x + 25, position.y + 13), GetHsvColorBasedOnCooldown(remainingCooldown));
	if (remainingCooldown > 0.f)
		toolbox.canvas->AddText(position, ImColor::HSV(0.f, 0.f, 1.f), std::to_string((int)remainingCooldown).c_str());
	else
		toolbox.canvas->AddText(position, ImColor::HSV(0.f, 0.f, 1.f), spell.GetTypeStr());

	// Draw level of skill below cooldown button
	ImVec2 pos = ImVec2(position.x, position.y);
	for (int i = 0; i < spell.level; ++i) {
		toolbox.canvas->AddRectFilled(ImVec2(position.x - 4 + i*5, position.y + 13), ImVec2(position.x + i*5, position.y + 15), ImColor::HSV(0.2f, 1.f, 1.f));
	}
}

void DrawSummonerSpellButton(Spell& spell, float gameTime, const MiscToolbox& toolbox, ImVec2& position) {
	float remainingCooldown = spell.GetRemainingCooldown(gameTime);

	// Draw button with cooldown
	ImGui::PushFont(toolbox.fontSmall);
	toolbox.canvas->AddRectFilled(ImVec2(position.x - 5, position.y), ImVec2(position.x + 60, position.y + 10), GetHsvColorBasedOnCooldown(remainingCooldown));
	
	std::string text = spell.name;
	if (remainingCooldown > 0.f) {
		text.append(" ");
		text.append(std::to_string((int)remainingCooldown));
	}

	toolbox.canvas->AddText(position, ImColor::HSV(0.f, 0.f, 1.f), text.c_str());
	ImGui::PopFont();
}

void SpellTrackerView::DrawSpellTrackerOnChampions(const MemSnapshot& snapshot, const MiscToolbox& toolbox) {

	for (auto it = snapshot.champions.begin(); it != snapshot.champions.end(); ++it) {
		Champion* champ = *it;
		if (!champ->isAlive || !champ->isVisible) // If champion is dead or not visible skip
			continue;
		if (champ == snapshot.localChampion && !showOverlayOnSelf)
			continue;

		bool isEnemy = champ->IsEnemyTo(snapshot.localChampion);
		if ((!isEnemy && champ != snapshot.localChampion && !showOverlayOnAllies) ||
         	(isEnemy && !showOverlayOnEnemies))
			continue;
		
		Vector2 pos = snapshot.renderer->WorldToScreen(champ->position);
		if (!snapshot.renderer->IsScreenPointOnScreen(pos))
			continue;

		ImVec2 imPos = ImVec2(pos.x - 60, pos.y);
		DrawWorldSpellButton(champ->Q, snapshot.gameTime, toolbox, imPos);
		imPos.x += 35;

		DrawWorldSpellButton(champ->W, snapshot.gameTime, toolbox, imPos);
		imPos.x += 35;

		DrawWorldSpellButton(champ->E, snapshot.gameTime, toolbox, imPos);
		imPos.x += 35;

		DrawWorldSpellButton(champ->R, snapshot.gameTime, toolbox, imPos);

		imPos.x -= 105;
		imPos.y -= 12;
		DrawSummonerSpellButton(champ->D, snapshot.gameTime, toolbox, imPos);
		imPos.x += 70;

		DrawSummonerSpellButton(champ->F, snapshot.gameTime, toolbox, imPos);
	}
}

void SpellTrackerView::DrawWorldSpaceOverlay(const MemSnapshot& snapshot, const MiscToolbox& toolbox) {
	DrawSpellTrackerOnChampions(snapshot, toolbox);
}

void SpellTrackerView::DrawSettings(const MemSnapshot& snapshot, const MiscToolbox& toolbox) {

	ImGui::Checkbox("Show Overlay on Allies##showOverlayOnAllies", &showOverlayOnAllies);
	ImGui::Checkbox("Show Overlay on Enemies##showOverlayOnEnemies", &showOverlayOnEnemies);
	ImGui::Checkbox("Show Overlay on Self", &showOverlayOnSelf);
}

const char* SpellTrackerView::GetName() {
	return "Spell Tracker";
}