#include "HeroTrackerView.h"
#include <ctime>

const char* HeroTrackerView::GetName() {
	return "Champion Hunter";
}

void HeroTrackerView::DrawSettings(LeagueProcessHook reader) {
	
	const char* comboFirstText = (trackedHeroIndex == -1 ? "None" : reader.champions[trackedHeroIndex].name.c_str());
	if (ImGui::BeginCombo("Champion to Track###heroTrackerHero", comboFirstText)) {
	
		bool selected = false;
		if (ImGui::Selectable("None", &selected))
			trackedHeroIndex = -1;
		
		for (int i = 0; i < reader.numChampions; ++i) {
			selected = false;
			if (ImGui::Selectable(reader.champions[i].name.c_str(), &selected)) {
				trackedHeroIndex = i;
				timeOfLastStoredPosition = 0;
				track.clear();
			}
		}

		ImGui::EndCombo();
	}

	ImGui::SliderInt("Seconds to Track###heroTrackerTrackSecs", (int*)&secondsToTrack, 5, 30);

	if (ImGui::TreeNode("Help")) {
		ImGui::Text("Please position and resize the \"Hero Tracker Overlay\"\n"
			"window to cover the minimap. This setting will be saved\n"
		    "This is necessarry for cheat detection prevention");
		ImGui::TreePop();
	}
	
}

void HeroTrackerView::DrawPanel(LeagueProcessHook reader) {

	ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 2.0f);
	ImGui::SetNextWindowBgAlpha(0.0f);
	ImGui::Begin("Hero Tracker Overlay##heroTrackerOverlay", nullptr,
		ImGuiWindowFlags_NoScrollbar
	);

	if (trackedHeroIndex != -1) {
		time_t currentTime = time(0)*1000;
		if (currentTime - timeOfLastStoredPosition > timeBetweenTwoSteps) {
			timeOfLastStoredPosition = currentTime;
			track.push_back(new TrackPoint(reader.champions[trackedHeroIndex].position, currentTime));
		}

		while (track.size() > 0 && (currentTime - track.front()->time) > secondsToTrack * 1000) {
			delete track.front();
			track.pop_front();
		}

		// Now draw positions
		ImDrawList* list = ImGui::GetWindowDrawList();


		ImVec2 windowSize = ImGui::GetWindowSize();
		ImVec2 windowPos = ImGui::GetWindowPos();

		float nrStep = 0.f;
		for (auto it = track.begin(); it != track.end(); ++it) {
			

			ImVec2 pos = ImVec2((*it)->pt.x / LEAGUE_MAP_BOUNDS, (*it)->pt.z / LEAGUE_MAP_BOUNDS);
			pos.x = windowPos.x + pos.x * windowSize.x;
			pos.y = windowPos.y + windowSize.y - (pos.y * windowSize.y);
			list->AddCircleFilled(pos, 4.f, ImColor::HSV(0.6f - 0.2f*nrStep/track.size(), 1.f, 1.f), 4);

			nrStep++;
		}
	}
	

	ImGui::End();
	ImGui::PopStyleVar();
}

void HeroTrackerView::DrawOverlay(LeagueProcessHook reader, ImDrawList* overlayCanvas) {

}