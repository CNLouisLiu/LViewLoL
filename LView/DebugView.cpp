#include "DebugView.h"


const char* DebugView::GetName() {
	return "Debug";
}

void DebugView::DrawSettings(LeagueProcessHook reader) {

}

void DebugView::DrawPanel(LeagueProcessHook reader) {

	ImGui::Begin("Debug");

	// Draw champs
	for (int i = 0; i < reader.numChampions; ++i) {
		Champion champ = reader.champions[i];
		if (ImGui::TreeNode(champ.name.c_str())) {
			int team = champ.team;
			ImGui::DragInt("Team", &team);
			ImGui::Checkbox("Is Visible", &champ.isVisible);
			ImGui::LabelText("Position", "X:%.2f Y:%.2f Z:%.2f", champ.position.x, champ.position.y, champ.position.z);

			ImGui::TreePop();
		}
	}

	ImGui::End();
}

void DebugView::DrawOverlay(LeagueProcessHook reader, ImDrawList* overlayCanvas) {

}