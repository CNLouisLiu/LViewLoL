#pragma once
#include <boost/python.hpp>
#include "MemSnapshot.h"

using namespace boost::python;

class PyGame {

public:
	Renderer*   renderer;

	ImDrawList* overlay;
	ImVec2      minimapPos, minimapSize;

public:
	PyGame() {}

	// Exposed Fields
	dict allObjects;
	list champs, minions, turrets, jungle, others;
	float gameTime;

	GameObject* hoveredObject;
	Champion* localChampion;

	object GetHoveredObject() { 
		if (hoveredObject == nullptr)
			return object();
		return object(boost::ref(*hoveredObject)); 
	}

	object GetLocalChampion() { 
		if (localChampion == nullptr)
			return object();
		return object(boost::ref(*localChampion)); 
	};

	//Exposed methods
	Vector2 WorldToScreen(Vector3 pos) {
		return renderer->WorldToScreen(pos);
	}

	Vector2 WorldToMinimap(Vector3 pos) {
		return renderer->WorldToMinimap(pos);
	}

	BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(IsScreenPointOnScreenOverloads, IsScreenPointOnScreen, 1, 3);
	bool IsScreenPointOnScreen(Vector2 point, float offsetX = 0.f, float offsetY = 0.f) {
		return renderer->IsScreenPointOnScreen(point, offsetX, offsetY);
	}

	BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(IsWorldPointOnScreenOverloads, IsWorldPointOnScreen, 1, 3);
	bool IsWorldPointOnScreen(Vector3 point, float offsetX = 0.f, float offsetY = 0.f) {
		return renderer->IsWorldPointOnScreen(point, offsetX, offsetY);
	}

	void DrawCircle(Vector2 center, float radius, int numPoints, float thickness, ImVec4 color) {
		overlay->AddCircle(ImVec2(center.x, center.y), radius, ImColor(color), 30, thickness);
	}

	void DrawCircleFilled(Vector2 center, float radius, int numPoints, ImVec4 color) {
		overlay->AddCircleFilled(ImVec2(center.x, center.y), radius, ImColor(color), 30);
	}

	void DrawTxt(Vector2 pos, const char* text, ImVec4 color) {
		overlay->AddText(ImVec2(pos.x, pos.y), ImColor(color), text);
	}

	BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(DrawRectOverloads, DrawRect, 2, 3);
	void DrawRect(Vector4 box, ImVec4 color, float rounding = 0) {
		overlay->AddRect(ImVec2(box.x, box.y), ImVec2(box.z, box.w), ImColor(color), rounding);
	}

	BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(DrawRectFilledOverloads, DrawRectFilled, 2, 3);
	void DrawRectFilled(Vector4 box, ImVec4 color, float rounding = 0) {
		overlay->AddRectFilled(ImVec2(box.x, box.y), ImVec2(box.z, box.w), ImColor(color), rounding);
	}

	void DrawCircleWorld (Vector3 center, float radius, int numPoints, float thickness, ImVec4 color) {
		renderer->DrawCircleAt(overlay, center, radius, false, numPoints, ImColor(color), thickness);
	}

	void DrawCircleWorldFilled(Vector3 center, float radius, int numPoints, ImVec4 color) {
		renderer->DrawCircleAt(overlay, center, radius, true, numPoints, ImColor(color));
	}

	static PyGame ConstructFromMemSnapshot(MemSnapshot& snapshot) {
		PyGame gs;

		gs.gameTime = snapshot.gameTime;
		gs.renderer = snapshot.renderer;
		gs.hoveredObject = snapshot.hoveredObject;
		gs.localChampion = snapshot.localChampion;
		for (auto it = snapshot.idxToObjectMap.begin(); it != snapshot.idxToObjectMap.end(); ++it) {
			gs.allObjects[it->first] = boost::ref(it->second);
		}

		for (auto it = snapshot.champions.begin(); it != snapshot.champions.end(); ++it) {
			gs.champs.append(boost::ref(**it));
		}
		for (auto it = snapshot.minions.begin(); it != snapshot.minions.end(); ++it) {
			gs.minions.append(boost::ref(**it));
		}
		for (auto it = snapshot.turrets.begin(); it != snapshot.turrets.end(); ++it) {
			gs.turrets.append(boost::ref(**it));
		}
		for (auto it = snapshot.jungle.begin(); it != snapshot.jungle.end(); ++it) {
			gs.jungle.append(boost::ref(**it));
		}
		for (auto it = snapshot.others.begin(); it != snapshot.others.end(); ++it) {
			gs.others.append(boost::ref(**it));
		}
		return gs;
	}
};