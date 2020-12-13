#include "BenchmarkingView.h"
#include "UI.h"

const char* BenchmarkingView::GetName() {
	return "Benchmarking";
}

void BenchmarkingView::DrawPanel(const MemSnapshot& snapshot, const MiscToolbox& toolbox) {
	ImGui::Begin("Benchmarks");

	float timeUI = toolbox.generalBenchmarks->renderTimeMs + toolbox.generalBenchmarks->renderTimeMs;
	float timeRenderer = snapshot.benchmark->readChampsMs + snapshot.benchmark->readRendererMs + snapshot.benchmark->readMobsMs + snapshot.benchmark->readTurretsMs;

	ImGui::BeginGroup();
	if (ImGui::CollapsingHeader("UI")) {
		ImGui::DragFloat("UI Render Time", &toolbox.generalBenchmarks->renderTimeMs);
		ImGui::DragFloat("Cheat UI Time", &toolbox.generalBenchmarks->processTimeMs);
	}
	else {
		ImGui::SameLine(ImGui::GetWindowWidth() - 100);
		ImGui::TextColored(Colors::Cyan, "%.2f ms", timeUI);
	}
	ImGui::EndGroup();

	ImGui::BeginGroup();
	if (ImGui::CollapsingHeader("Memory Reader")) {
		ImGui::DragFloat("Read Champs (ms)", &snapshot.benchmark->readChampsMs);
		ImGui::DragFloat("Read Renderer (ms)", &snapshot.benchmark->readRendererMs);
		ImGui::DragFloat("Read Turrets (ms)", &snapshot.benchmark->readTurretsMs);
		ImGui::DragFloat("Read Other objects (ms)", &snapshot.benchmark->readMobsMs);
	} else {
		ImGui::SameLine(ImGui::GetWindowWidth() - 100);
		ImGui::TextColored(Colors::Cyan, "%.2f ms", timeRenderer);
	}
	ImGui::EndGroup();

	ImGui::Text("Cheat benchmarks");
	for (auto it = toolbox.viewBenchmarks.begin(); it != toolbox.viewBenchmarks.end(); ++it) {

		float timeCheat = it->second->drawMinimapOverlayMs + it->second->drawPanelMs + it->second->drawSettingsMs + it->second->drawWorldOverlayMs;
		ImGui::BeginGroup();
		if (ImGui::CollapsingHeader(it->first->GetName())) {

			ImGui::DragFloat("Draw Settings (ms)", &(it->second->drawSettingsMs));
			ImGui::DragFloat("Draw Panels (ms)", &(it->second->drawPanelMs));
			ImGui::DragFloat("Draw Overlay World (ms)", &(it->second->drawWorldOverlayMs));
			ImGui::DragFloat("Draw Overlay Minimap (ms)", &(it->second->drawMinimapOverlayMs));
		}
		else {
			ImGui::SameLine(ImGui::GetWindowWidth() - 100);
			ImGui::TextColored(Colors::Cyan, "%.2f ms", timeCheat);
		}

		ImGui::EndGroup();
	}

	ImGui::End();
}