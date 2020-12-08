#ifndef UI_H
#define UI_H

#include "windows.h"
#include "Structs.h"
#include "LeagueMemoryReader.h"
#include <list>
#include "BaseView.h"

class UI {

public:

	UI(std::list<BaseView*> views) {
		this->views = views;
	}

	void Start();
	void Update(LeagueMemoryReader& reader);

private:
	HWND hWindow;

	Renderer renderer;
	std::list<BaseView*> views;
};

#endif