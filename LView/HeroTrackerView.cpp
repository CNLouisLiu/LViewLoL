#include "HeroTrackerView.h"
#include <ctime>

const char* HeroTrackerView::GetName() {
	return "Champion Hunter";
}

void HeroTrackerView::OnSaveSettings(ConfigSet& configs) {
	BaseView::OnSaveSettings(configs);

	configs.Set<int>("secondsToTrack", secondsToTrack);
	configs.Set<bool>("drawTrackInWorld", drawTrackInWorld);
}

void HeroTrackerView::OnLoadSettings(ConfigSet& configs) {
	BaseView::OnLoadSettings(configs);

	secondsToTrack = configs.Get<int>("secondsToTrack", 15);
	drawTrackInWorld = configs.Get<bool>("drawTrackInWorld", false);
}

void HeroTrackerView::DrawSettings(LeagueMemoryReader& reader, UI& ui) {
	
	ImGui::Checkbox("Draw Track in World##drawTrackInWorld", &drawTrackInWorld);
	ImGui::SliderInt("Seconds to Track##secondsToTrack", (int*)&secondsToTrack, 5, 30);
	ImGui::Text("CHAMPION TO TRACK:");

	static int selected = 0;
	if (ImGui::RadioButton("None", &selected, -1)) {
		trackedHero = nullptr;
	}
	int i = 0;
	for (auto it = reader.champions.begin(); it != reader.champions.end(); ++it, ++i) {
		
		Champion* champ = *it;
		if (champ->team == reader.localChampion->team)
			continue;
		if (ImGui::RadioButton(champ->name.c_str(), &selected, i)) {
			trackedHero = champ;
			timeOfLastStoredPosition = 0;
			track.clear();
		}
	}


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
	if (trackedHero != nullptr) {
		time_t currentTime = time(0) * 1000;
		if (currentTime - timeOfLastStoredPosition > timeBetweenTwoSteps) {
			timeOfLastStoredPosition = currentTime;
			track.push_back(new TrackPoint(trackedHero->position, currentTime));
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