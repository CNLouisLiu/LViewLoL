#pragma once
#include "windows.h"
#include "Structs.h"
#include "LeagueMemoryReader.h"
#include <list>
#include "BaseView.h"

class UI {

public:

	UI(std::list<BaseView*> views);
	void Start();
	void Update(LeagueMemoryReader& reader);

private:
	HWND hWindow;

	Renderer renderer;
	std::list<BaseView*> views;

public:
	ImFontConfig fontConfigSmall;
	ImFontConfig fontConfigNormal;
	ImFont* fontSmall;
	ImFont* fontNormal;

};