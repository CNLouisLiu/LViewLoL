#include "BenchmarkingView.h"
#include "UI.h"

const char* BenchmarkingView::GetName() {
	return "Benchmarking";
}

void BenchmarkingView::DrawPanel(LeagueMemoryReader& reader, UI& ui) {
	ImGui::Begin("Benchmarks");

	ImGui::DragFloat("Render Time", &ui.generalBenchmarks.renderTimeMs);
	ImGui::DragFloat("Process Time", &ui.generalBenchmarks.processTimeMs);

	if (ImGui::TreeNode("Memory Reader")) {
		ImGui::DragFloat("Read Champs (ms)", &reader.benchmark.readChampsMs);
		ImGui::DragFloat("Read Renderer (ms)", &reader.benchmark.readRendererMs);
		ImGui::DragFloat("Read Other objects (ms)", &reader.benchmark.readMinionsMs);
		ImGui::TreePop();
	}

	ImGui::Text("Cheat benchmarks");
	for (auto it = ui.viewBenchmarks.begin(); it != ui.viewBenchmarks.end(); ++it) {
		if (ImGui::TreeNode(it->first->GetName())) {

			ImGui::DragFloat("Draw Settings (ms)", &it->second.drawSettingsMs);
			ImGui::DragFloat("Draw Panels (ms)", &it->second.drawPanelMs);
			ImGui::DragFloat("Draw Overlay World (ms)", &it->second.drawWorldOverlayMs);
			ImGui::DragFloat("Draw Overlay Minimap (ms)", &it->second.drawMinimapOverlayMs);

			ImGui::TreePop();
		}
	}

	ImGui::End();
}