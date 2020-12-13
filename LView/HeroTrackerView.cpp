#include "HeroTrackerView.h"
#include <ctime>
#include "Spell.h"

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

void HeroTrackerView::DrawSettings(const MemSnapshot& snapshot, const MiscToolbox& toolbox) {
	
	ImGui::Checkbox("Draw Track in World##drawTrackInWorld", &drawTrackInWorld);
	ImGui::SliderFloat("Seconds to Track##secondsToTrack", &secondsToTrack, 5, 30);
	ImGui::Text("CHAMPION TO TRACK:");

	if (ImGui::RadioButton("None", &selectedIdx, -1)) {
		trackedHeroIndex = 0;
		track.clear();
	}

	int i = 0;
	for (auto it = snapshot.champions.begin(); it != snapshot.champions.end(); ++it, ++i) {
		
		Champion* champ = *it;
		if (champ->IsAllyTo(snapshot.localChampion))
			continue;

		if (ImGui::RadioButton(champ->name.c_str(), &selectedIdx, i)) {
			trackedHeroIndex = champ->objectIndex;
			track.clear();
			timeOfLastStoredPosition = high_resolution_clock::now();
		}
	}
}

void HeroTrackerView::DrawWorldSpaceOverlay(const MemSnapshot& snapshot, const MiscToolbox& toolbox) {

	if (drawTrackInWorld) {
		int nrStep = 0;
		for (auto it = track.begin(); it != track.end(); ++it) {

			if (!snapshot.renderer->IsWorldPointOnScreen(it->pt))
				continue;
			snapshot.renderer->DrawCircleAt(toolbox.canvas, it->pt, 30.f, false, 10, ImColor::HSV(0.6f - 0.2f*nrStep / track.size(), 1.f, 1.f));
			nrStep++;
		}
	}
}

void HeroTrackerView::DrawMinimapOverlay(const MemSnapshot& snapshot, const MiscToolbox& toolbox) {
	
	// First frame, we are defaulting the tracking to the enemy jungler :)
	if (firstFrame) {
		firstFrame = false;
		int i = 0;
		for (auto it = snapshot.champions.begin(); it != snapshot.champions.end(); ++it, ++i) {
			Champion* champ = *it;
			if (champ->team != snapshot.localChampion->team && champ->GetSummonerSpell(SummonerSpellType::SMITE) != nullptr) {
				trackedHeroIndex = champ->objectIndex;
				selectedIdx = i;
				break;
			}
		}
	}

	if (trackedHeroIndex != 0) {

		Champion* trackedHero = (Champion*)snapshot.idxToObjectMap.find(trackedHeroIndex)->second;
		high_resolution_clock::time_point timeNow = high_resolution_clock::now();
		timeDiff = timeNow - timeOfLastStoredPosition;
		if (timeDiff.count() > timeBetweenTwoSteps) {
			timeOfLastStoredPosition = timeNow;
			track.push_back(TrackPoint(trackedHero->position, timeNow));
		}

		// Remove expired tracks 
		auto it = track.begin();
		while (it != track.end()) {
			timeDiff = timeNow - it->time;
			if (timeDiff.count() > 1000.f * secondsToTrack) {
				it = track.erase(it);
			}
			else
				it++;
			
		}

		// Draw the tracks on the minimap
		float nrStep = 0.f;
		for (auto it = track.begin(); it != track.end(); ++it) {

			Vector2 pos = snapshot.renderer->WorldToMinimap(it->pt);
			float step = 0.2f*nrStep / track.size();
			toolbox.canvas->AddCircleFilled(ImVec2(pos.x, pos.y), 2.5f + step, ImColor::HSV(0.6f - step, 1.f, 1.f), 4);

			nrStep++;
		}
	}
}