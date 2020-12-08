#pragma once
#include "BaseView.h"
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
	const char* GetName();
	void DrawSettings(LeagueProcessHook reader);
	void DrawPanel(LeagueProcessHook reader);
	void DrawOverlay(LeagueProcessHook reader, ImDrawList* overlayCanvas);

private:
	int trackedHeroIndex = -1;

	time_t timeOfLastStoredPosition = 0;
	float timeBetweenTwoSteps = 20;
	time_t secondsToTrack = 15;


	std::deque<TrackPoint*> track;

	const float LEAGUE_MAP_BOUNDS = 15000.f;
};