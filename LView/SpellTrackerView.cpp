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

void SpellTrackerView::DrawWorldSpellButton(Spell& spell, float gameTime, ImDrawList* drawList, ImVec2& position) {
	float remainingCooldown = spell.GetRemainingCooldown(gameTime);

	// Draw button with cooldown
	drawList->AddRectFilled(ImVec2(position.x - 5, position.y), ImVec2(position.x + 25, position.y + 13), GetHsvColorBasedOnCooldown(remainingCooldown));
	if (remainingCooldown > 0.f)
		drawList->AddText(position, ImColor::HSV(0.f, 0.f, 1.f), std::to_string((int)remainingCooldown).c_str());
	else
		drawList->AddText(position, ImColor::HSV(0.f, 0.f, 1.f), spell.GetTypeStr());

	// Draw level of skill below cooldown button
	ImVec2 pos = ImVec2(position.x, position.y);
	for (int i = 0; i < spell.level; ++i) {
		drawList->AddRectFilled(ImVec2(position.x - 4 + i*5, position.y + 13), ImVec2(position.x + i*5, position.y + 15), ImColor::HSV(0.2f, 1.f, 1.f));
	}
}

void DrawSummonerSpellButton(Spell& spell, float gameTime, UI& ui, ImDrawList* drawList, ImVec2& position) {
	float remainingCooldown = spell.GetRemainingCooldown(gameTime);

	// Draw button with cooldown
	ImGui::PushFont(ui.fontSmall);
	drawList->AddRectFilled(ImVec2(position.x - 5, position.y), ImVec2(position.x + 60, position.y + 10), GetHsvColorBasedOnCooldown(remainingCooldown));
	
	std::string text = spell.name;
	if (remainingCooldown > 0.f) {
		text.append(" ");
		text.append(std::to_string((int)remainingCooldown));
	}

	drawList->AddText(position, ImColor::HSV(0.f, 0.f, 1.f), text.c_str());
	ImGui::PopFont();
}

void SpellTrackerView::DrawSpellTrackerOnChampions(LeagueMemoryReader& reader, UI& ui, ImDrawList* list) {

	for (auto it = reader.champions.begin(); it != reader.champions.end(); ++it) {
		Champion* champ = *it;
		if (!champ->isAlive || !champ->isVisible) // If champion is dead or not visible skip
			continue;
		if (champ == reader.localChampion && !showOverlayOnSelf)
			continue;

		bool isEnemy = champ->IsEnemyTo(reader.localChampion);
		if ((!isEnemy && champ != reader.localChampion && !showOverlayOnAllies) || 
         	(isEnemy && !showOverlayOnEnemies))
			continue;
		
		Vector2 pos = reader.renderer.WorldToScreen(champ->position);
		if (!reader.renderer.IsScreenPointOnScreen(pos))
			continue;

		ImVec2 imPos = ImVec2(pos.x - 60, pos.y);
		DrawWorldSpellButton(champ->Q, reader.gameTime, list, imPos);
		imPos.x += 35;

		DrawWorldSpellButton(champ->W, reader.gameTime, list, imPos);
		imPos.x += 35;

		DrawWorldSpellButton(champ->E, reader.gameTime, list, imPos);
		imPos.x += 35;

		DrawWorldSpellButton(champ->R, reader.gameTime, list, imPos);

		imPos.x -= 105;
		imPos.y -= 12;
		DrawSummonerSpellButton(champ->D, reader.gameTime, ui, list, imPos);
		imPos.x += 70;

		DrawSummonerSpellButton(champ->F, reader.gameTime, ui, list, imPos);
	}
}

void SpellTrackerView::DrawWorldSpaceOverlay(LeagueMemoryReader& reader, ImDrawList* overlayCanvas, UI& ui) {
	DrawSpellTrackerOnChampions(reader, ui, overlayCanvas);
}

void SpellTrackerView::DrawSettings(LeagueMemoryReader& reader, UI& ui) {

	ImGui::Checkbox("Show Overlay on Allies##showOverlayOnAllies", &showOverlayOnAllies);
	ImGui::Checkbox("Show Overlay on Enemies##showOverlayOnEnemies", &showOverlayOnEnemies);
	ImGui::Checkbox("Show Overlay on Self", &showOverlayOnSelf);
}

const char* SpellTrackerView::GetName() {
	return "Spell Tracker";
}