#include "DebugView.h"


const char* DebugView::GetName() {
	return "Debug";
}


void DrawSpell(Spell spell) {
	if (ImGui::TreeNode(spell.GetTypeStr())) {
		
		ImGui::Button(spell.name.c_str());
		ImGui::LabelText("Address Slot", "%#010x", spell.addressSlot);
		ImGui::DragFloat("Ready At", &spell.readyAt);
		ImGui::DragInt("Level", &spell.level);
		ImGui::DragFloat("Damage", &spell.damage);
		ImGui::TreePop();
	}
}

void DrawMatrix(float* matrix, int rows, int cols) {
	for (int i = 0; i < rows; ++i) {
		ImGui::BeginGroup();
		for (int j = 0; j < cols; ++j) {
			ImGui::Button(std::to_string(matrix[i*rows + j]).c_str());
			ImGui::SameLine();
		}
		ImGui::EndGroup();
	}
}

void DrawGameObject(GameObject* obj) {

	if (obj == nullptr) {
		ImGui::TextColored((ImVec4)Colors::Red, "nullptr");
		return;
	}

	ImGui::TextColored(Colors::Orange, obj->name.c_str());

	int team = obj->team;
	int type = (int)obj->type;
	ImGui::LabelText("Address", "%#010x", &obj->address);
	ImGui::DragInt("Type", &type);
	ImGui::DragFloat("Expiry At", &obj->expiryAt);
	ImGui::DragInt("Team", &team);
	ImGui::DragFloat("Health", &obj->health);
	ImGui::DragFloat("Radius", &obj->targetRadius);
	ImGui::Checkbox("Is Visible", &obj->isVisible);
	ImGui::LabelText("Position", "X:%.2f Y:%.2f Z:%.2f", obj->position.x, obj->position.y, obj->position.z);
}

void DrawGameObjects(std::vector<GameObject*> gameObjects) {

	int count = gameObjects.size();
	ImGui::DragInt("Count", &count);
	for (size_t i = 0; i < gameObjects.size(); ++i) {
		DrawGameObject(gameObjects[i]);
		ImGui::Separator();
	}
}

void DebugView::DrawPanel(LeagueMemoryReader& reader, UI& ui) {

	ImGui::Begin("Debug");

	ImGui::LabelText("GameTime", "%.2f", reader.gameTime);
	
	if (ImGui::TreeNode("Hovered Object")) {
		ImGui::Text("Hovered Champ");
		DrawGameObject(reader.hoveredChampion);

		ImGui::Text("Hovered Minion");
		DrawGameObject(reader.hoveredMinion);

		ImGui::Text("Hovered Jungle");
		DrawGameObject(reader.hoveredJungle);

		ImGui::TreePop();
	}

	// Draw renderer
	if (ImGui::TreeNode("Renderer")) {

		ImGui::DragInt("Width", &reader.renderer.width);
		ImGui::DragInt("Height", &reader.renderer.height);

		ImGui::Text("View Matrix");
		DrawMatrix(reader.renderer.viewMatrix, 4, 4);
		ImGui::Text("Projection Matrix");
		DrawMatrix(reader.renderer.projMatrix, 4, 4);
		ImGui::TreePop();
	}

	// Draw champs
	if (ImGui::TreeNode("Champions")) {
		for (auto it = reader.champions.begin(); it != reader.champions.end(); ++it) {
			Champion* champ = *it;
			if (ImGui::TreeNode(champ->name.c_str())) {
				int team = champ->team;
				ImGui::LabelText("Address", "%#010x", champ->address);
				ImGui::DragInt("Team", &team);

				ImGui::DragFloat("Current Health", &champ->currentHealth);
				ImGui::DragFloat("Base Atk", &champ->baseAttack);
				ImGui::DragFloat("Bonus Atk", &champ->bonusAttack);
				ImGui::DragFloat("Armour", &champ->armour);
				ImGui::DragFloat("Magic resist", &champ->magicResist);

				ImGui::Checkbox("Is Visible", &champ->isVisible);
				ImGui::LabelText("Position", "X:%.2f Y:%.2f Z:%.2f", champ->position.x, champ->position.y, champ->position.z);

				DrawSpell(champ->Q);
				DrawSpell(champ->W);
				DrawSpell(champ->E);
				DrawSpell(champ->R);
				DrawSpell(champ->D);
				DrawSpell(champ->F);

				ImGui::TreePop();
			}
		}
		ImGui::TreePop();
	}
	

	if (ImGui::TreeNode("Wards")) {
		DrawGameObjects(reader.wards);
		ImGui::TreePop();
	}

	if (ImGui::TreeNode("Minions")) {
		DrawGameObjects(reader.minions);
		ImGui::TreePop();
	}

	if (ImGui::TreeNode("Jungle")) {
		DrawGameObjects(reader.jungle);
		ImGui::TreePop();
	}

	if (ImGui::TreeNode("Others")) {
		DrawGameObjects(reader.others);
		ImGui::TreePop();
	}

	ImGui::End();
}