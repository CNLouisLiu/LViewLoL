#include "BenchmarkingView.h"
#include "UI.h"

const char* BenchmarkingView::GetName() {
	return "Benchmarking";
}

void BenchmarkingView::DrawPanel(LeagueMemoryReader& reader, UI& ui) {
	ImGui::Begin("Benchmarks");

	float timeUI = ui.generalBenchmarks.renderTimeMs + ui.generalBenchmarks.renderTimeMs;
	float timeRenderer = reader.benchmark.readChampsMs + reader.benchmark.readRendererMs + reader.benchmark.readMobsMs + reader.benchmark.readTurretsMs;

	ImGui::BeginGroup();
	if (ImGui::CollapsingHeader("UI")) {
		ImGui::DragFloat("UI Render Time", &ui.generalBenchmarks.renderTimeMs);
		ImGui::DragFloat("Cheat UI Time", &ui.generalBenchmarks.processTimeMs);
	}
	else {
		ImGui::SameLine(ImGui::GetWindowWidth() - 100);
		ImGui::TextColored(Colors::Cyan, "%.2f ms", timeUI);
	}
	ImGui::EndGroup();

	ImGui::BeginGroup();
	if (ImGui::CollapsingHeader("Memory Reader")) {
		ImGui::DragFloat("Read Champs (ms)", &reader.benchmark.readChampsMs);
		ImGui::DragFloat("Read Renderer (ms)", &reader.benchmark.readRendererMs);
		ImGui::DragFloat("Read Turrets (ms)", &reader.benchmark.readTurretsMs);
		ImGui::DragFloat("Read Other objects (ms)", &reader.benchmark.readMobsMs);
	} else {
		ImGui::SameLine(ImGui::GetWindowWidth() - 100);
		ImGui::TextColored(Colors::Cyan, "%.2f ms", timeRenderer);
	}
	ImGui::EndGroup();

	ImGui::Text("Cheat benchmarks");
	for (auto it = ui.viewBenchmarks.begin(); it != ui.viewBenchmarks.end(); ++it) {

		float timeCheat = it->second.drawMinimapOverlayMs + it->second.drawPanelMs + it->second.drawSettingsMs + it->second.drawWorldOverlayMs;
		ImGui::BeginGroup();
		if (ImGui::CollapsingHeader(it->first->GetName())) {

			ImGui::DragFloat("Draw Settings (ms)", &it->second.drawSettingsMs);
			ImGui::DragFloat("Draw Panels (ms)", &it->second.drawPanelMs);
			ImGui::DragFloat("Draw Overlay World (ms)", &it->second.drawWorldOverlayMs);
			ImGui::DragFloat("Draw Overlay Minimap (ms)", &it->second.drawMinimapOverlayMs);
		}
		else {
			ImGui::SameLine(ImGui::GetWindowWidth() - 100);
			ImGui::TextColored(Colors::Cyan, "%.2f ms", timeCheat);
		}

		ImGui::EndGroup();
	}

	ImGui::End();
}