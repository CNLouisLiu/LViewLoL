#pragma once
#include "BaseView.h"
#include "UI.h"
#include <deque>

class TrackPoint {

public:
	TrackPoint(Vector3 point, time_t registeredAt) {
		pt = point;
		time = registeredAt;
	}

	Vector3 pt;
	time_t time;
};

class HeroTrackerView : public BaseView {

public:
	const char*    GetName();
	void           DrawSettings(LeagueMemoryReader& reader, UI& ui);

	void           DrawMinimapOverlay(LeagueMemoryReader& reader, ImDrawList* overlayCanvas, UI& ui);
	void           DrawWorldSpaceOverlay(LeagueMemoryReader& reader, ImDrawList* overlayCanvas, UI& ui);

private:

	std::deque<TrackPoint*> track;
	int                     trackedHeroIndex = -1;
	time_t                  timeOfLastStoredPosition = 0;
	float                   timeBetweenTwoSteps = 10;

	// Settings
	time_t                  secondsToTrack = 15;
	bool                    drawTrackInWorld;
};