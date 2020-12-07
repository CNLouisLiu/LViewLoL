#ifndef UI_H
#define UI_H

#include "windows.h"
#include "Structs.h"
#include "LeagueProcessHook.h"
#include <list>

class UI {

public:

	void Start();
	void Update(LeagueProcessHook reader);

private:
	HWND hWindow;

	Renderer renderer;
};

#endif