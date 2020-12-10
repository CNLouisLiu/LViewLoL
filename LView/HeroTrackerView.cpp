#include "HeroTrackerView.h"
#include <ctime>

const char* HeroTrackerView::GetName() {
	return "Champion Hunter";
}

void HeroTrackerView::OnSaveSettings(ConfigSet& configs) {
	BaseView::OnSaveSettings(configs);

	configs.Set<float>("secondsToTrack", secondsToTrack);
	configs.Set<bool>("drawTrackInWorld", drawTrackInWorld);
}

void HeroTrackerView::OnLoadSettings(ConfigSet& configs) {
	BaseView::OnLoadSettings(configs);

	secondsToTrack = configs.Get<float>("secondsToTrack", 15);
	drawTrackInWorld = configs.Get<bool>("drawTrackInWorld", false);
}

void HeroTrackerView::DrawSettings(LeagueMemoryReader& reader, UI& ui) {
	
	ImGui::Checkbox("Draw Track in World##drawTrackInWorld", &drawTrackInWorld);
	ImGui::SliderFloat("Seconds to Track##secondsToTrack", &secondsToTrack, 5, 30);
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
			track.clear();
			timeOfLastStoredPosition = high_resolution_clock::now();
		}
	}


}

void HeroTrackerView::DrawWorldSpaceOverlay(LeagueMemoryReader& reader, ImDrawList* overlayCanvas, UI& ui) {

	if (drawTrackInWorld) {
		int nrStep = 0;
		for (auto it = track.begin(); it != track.end(); ++it) {

			reader.renderer.DrawCircleAt(overlayCanvas, (*it)->pt, 30.f, false, 10, ImColor::HSV(0.6f - 0.2f*nrStep / track.size(), 1.f, 1.f));
			nrStep++;
		}
	}
}

void HeroTrackerView::DrawMinimapOverlay(LeagueMemoryReader& reader, ImDrawList* overlayCanvas, UI& ui) {
	if (trackedHero != nullptr) {
		high_resolution_clock::time_point timeNow = high_resolution_clock::now();
		timeDiff = timeNow - timeOfLastStoredPosition;
		if (timeDiff.count() > timeBetweenTwoSteps) {
			timeOfLastStoredPosition = timeNow;
			track.push_back(new TrackPoint(trackedHero->position, timeNow));
		}

		// Remove expired tracks 
		auto it = track.begin();
		while (it != track.end()) {
			timeDiff = timeNow - (*it)->time;
			if (timeDiff.count() > 1000.f * secondsToTrack) {
				it = track.erase(it);
			}
			else
				it++;
			
		}

		// Draw the tracks on the minimap
		float nrStep = 0.f;
		for (auto it = track.begin(); it != track.end(); ++it) {

			Vector2 pos = reader.renderer.WorldToMinimap((*it)->pt);
			overlayCanvas->AddCircleFilled(ImVec2(pos.x, pos.y), 4.f, ImColor::HSV(0.6f - 0.2f*nrStep / track.size(), 1.f, 1.f), 4);

			nrStep++;
		}
	}
}