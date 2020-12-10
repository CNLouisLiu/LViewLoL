#include "HeroTrackerView.h"
#include <ctime>

const char* HeroTrackerView::GetName() {
	return "Champion Hunter";
}

void HeroTrackerView::DrawSettings(LeagueMemoryReader& reader, UI& ui) {
	
	ImGui::Checkbox("Draw Track in World", &drawTrackInWorld);

	const char* comboFirstText = (trackedHeroIndex == -1 ? "None" : reader.champions[trackedHeroIndex]->name.c_str());
	if (ImGui::BeginCombo("Champion to Track###heroTrackerHero", comboFirstText)) {
	
		bool selected = false;
		if (ImGui::Selectable("None", &selected))
			trackedHeroIndex = -1;
		
		for (size_t i = 0; i < reader.numChampions; ++i) {
			selected = false;
			if (ImGui::Selectable(reader.champions[i]->name.c_str(), &selected)) {
				trackedHeroIndex = i;
				timeOfLastStoredPosition = 0;
				track.clear();
			}
		}

		ImGui::EndCombo();
	}

	ImGui::SliderInt("Seconds to Track###heroTrackerTrackSecs", (int*)&secondsToTrack, 5, 30);
}

void HeroTrackerView::DrawWorldSpaceOverlay(LeagueMemoryReader& reader, ImDrawList* overlayCanvas, UI& ui) {

	if (drawTrackInWorld) {
		int nrStep = 0;
		for (auto it = track.begin(); it != track.end(); ++it) {

			//Vector2 screenPos = reader.renderer.WorldToScreen((*it)->pt);
			//overlayCanvas->AddCircleFilled(ImVec2(screenPos.x, screenPos.y), 8.f, ImColor::HSV(0.6f - 0.2f*nrStep / track.size(), 1.f, 1.f), 10);
			reader.renderer.DrawCircleAt(overlayCanvas, (*it)->pt, 40.f, false, 10, ImColor::HSV(0.6f - 0.2f*nrStep / track.size(), 1.f, 1.f));
			nrStep++;
		}
	}
}

void HeroTrackerView::DrawMinimapOverlay(LeagueMemoryReader& reader, ImDrawList* overlayCanvas, UI& ui) {
	if (trackedHeroIndex != -1) {
		time_t currentTime = time(0) * 1000;
		if (currentTime - timeOfLastStoredPosition > timeBetweenTwoSteps) {
			timeOfLastStoredPosition = currentTime;
			track.push_back(new TrackPoint(reader.champions[trackedHeroIndex]->position, currentTime));
		}

		while (track.size() > 0 && (currentTime - track.front()->time) > secondsToTrack * 1000) {
			delete track.front();
			track.pop_front();
		}

		float nrStep = 0.f;
		for (auto it = track.begin(); it != track.end(); ++it) {

			Vector2 pos = reader.renderer.WorldToMinimap((*it)->pt);
			overlayCanvas->AddCircleFilled(ImVec2(pos.x, pos.y), 4.f, ImColor::HSV(0.6f - 0.2f*nrStep / track.size(), 1.f, 1.f), 4);

			nrStep++;
		}
	}
}