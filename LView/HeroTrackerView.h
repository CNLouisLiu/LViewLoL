#pragma once
#include "BaseView.h"
#include "UI.h"
#include <deque>
#include <chrono>

using namespace std::chrono;

class TrackPoint {

public:
	TrackPoint(Vector3 point, high_resolution_clock::time_point registeredAt) {
		pt = point;
		time = registeredAt;
	}

	Vector3                           pt;
	high_resolution_clock::time_point time;
};

class HeroTrackerView : public BaseView {

public:
	const char*    GetName();
	void           OnSaveSettings(ConfigSet& configs);
	void           OnLoadSettings(ConfigSet& configs);
	void           DrawSettings(const MemSnapshot& snapshot, const MiscToolbox& toolbox);

	void           DrawMinimapOverlay(const MemSnapshot& snapshot, const MiscToolbox& toolbox);
	void           DrawWorldSpaceOverlay(const MemSnapshot& snapshot, const MiscToolbox& toolbox);

private:

	std::deque<TrackPoint>               track;
	unsigned int                         trackedHeroIndex = 0;
	high_resolution_clock::time_point	 timeOfLastStoredPosition;
	duration<float, std::milli>          timeDiff;
	float                                timeBetweenTwoSteps = 400.f;

	bool                                 firstFrame = true;
	int                                  selectedIdx = 0;
	// Settings
	float                                secondsToTrack;
	bool                                 drawTrackInWorld;
};