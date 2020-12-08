#include "SpellTrackerView.h"


void DrawSpellButton(Spell& spell, float gameTime, bool useSpellName) {
	float remainingCooldown = spell.GetRemainingCooldown(gameTime);
	float hue = 0.25f; // GREEN
	if (remainingCooldown > 10.f)
		hue = 0.f;  // RED
	else if (remainingCooldown > 0.1f)
		hue = 0.125f; // YELLOW

	ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(hue, 1.f, 0.5f));
	std::string text;
	text.append((useSpellName ? spell.name : spell.GetTypeStr()));
	text.append(":");
	text.append(std::to_string((int)remainingCooldown));

	text.append((useSpellName ? 12 : 6) - text.length(), ' ');
	ImGui::Button(text.c_str());

	ImGui::PopStyleColor(1);
	ImGui::SameLine();
}

void DrawSpellButton(Spell& spell, float gameTime, ImDrawList* drawList, ImVec2& position) {
	float remainingCooldown = spell.GetRemainingCooldown(gameTime);
	float hue = 0.25f; // GREEN
	if (remainingCooldown > 10.f)
		hue = 0.f;  // RED
	else if (remainingCooldown > 0.1f)
		hue = 0.125f; // YELLOW

	drawList->AddRectFilled(ImVec2(position.x - 5, position.y), ImVec2(position.x + 25, position.y + 15), ImColor::HSV(hue, 1.f, 0.5f));
	if (remainingCooldown > 0.f)
		drawList->AddText(position, ImColor::HSV(0.f, 0.f, 1.f), std::to_string((int)remainingCooldown).c_str());
	else
		drawList->AddText(position, ImColor::HSV(0.f, 0.f, 1.f), spell.GetTypeStr());
}


void DrawSpellTrackerPanel(LeagueMemoryReader& reader) {
	ImGui::Begin("SpellTracker");
	for (int i = 0; i < reader.numChampions; ++i) {

		Champion it = reader.champions[i];
		if (it.team == reader.champions[reader.localPlayerIdx].team) // Skip allies
			continue;

		if (ImGui::TreeNode(it.name.c_str())) {

			ImGui::BeginGroup();
			DrawSpellButton(it.Q, reader.gameTime, false);
			DrawSpellButton(it.W, reader.gameTime, false);
			DrawSpellButton(it.E, reader.gameTime, false);
			DrawSpellButton(it.R, reader.gameTime, false);
			ImGui::EndGroup();

			ImGui::BeginGroup();
			DrawSpellButton(it.D, reader.gameTime, true);
			DrawSpellButton(it.F, reader.gameTime, true);
			ImGui::EndGroup();
			
			ImGui::TreePop();
		}
	}
	ImGui::End();
}

void SpellTrackerView::DrawSpellTrackerOnChampions(LeagueMemoryReader& reader, ImDrawList* list) {

	int localPlayerTeam = reader.champions[reader.localPlayerIdx].team;
	for (int i = 0; i < reader.numChampions; ++i) {
		Champion champ = reader.champions[i];
		if (!champ.isVisible)
			continue;
		if ((champ.team == localPlayerTeam && !showOverlayOnAllies) ||
			(champ.team != localPlayerTeam && !showOverlayOnEnemies))
			continue;

		Vector2 pos = reader.renderer.WorldToScreen(champ.position);
		ImVec2 imPos = ImVec2(pos.x - 60, pos.y);


		DrawSpellButton(champ.Q, reader.gameTime, list, imPos);
		imPos.x += 35;

		DrawSpellButton(champ.W, reader.gameTime, list, imPos);
		imPos.x += 35;

		DrawSpellButton(champ.E, reader.gameTime, list, imPos);
		imPos.x += 35;

		DrawSpellButton(champ.R, reader.gameTime, list, imPos);
		imPos.x += 35;
	}
}

void SpellTrackerView::DrawPanel(LeagueMemoryReader& reader) {
	if(showPanel)
		DrawSpellTrackerPanel(reader);
}

void SpellTrackerView::DrawOverlay(LeagueMemoryReader& reader, ImDrawList* overlayCanvas) {
	DrawSpellTrackerOnChampions(reader, overlayCanvas);
}

void SpellTrackerView::DrawSettings(LeagueMemoryReader& reader) {

	ImGui::Checkbox("Show Overlay on Allies###spellTrackerOverlayAlly", &showOverlayOnAllies);
	ImGui::Checkbox("Show Overlay on Enemies###spellTrackerOverlayEnemy", &showOverlayOnEnemies);
	ImGui::Checkbox("Show Spell Tracker Panel###spellTrackerPanel", &showPanel);
}

const char* SpellTrackerView::GetName() {
	return "Spell Tracker";
}