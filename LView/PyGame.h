#pragma once
#include <boost/python.hpp>
#include "MemSnapshot.h"
#include "Utils.h"

using namespace boost::python;

/// Interface used by python scripts for game related stuff
class PyGame {

public:
	std::map<int, float>  distanceCache;
	GameRenderer*         renderer;
					      
	ImDrawList*           overlay;
	ImVec2                minimapPos, minimapSize;

public:
	PyGame() {}

	// Exposed Fields
	dict                  allObjects;
	list                  champs, minions, turrets, jungle, missiles, others;
	float                 gameTime;
					      
	MapObject*            map;
	GameObject*           hoveredObject;
	Champion*             localChampion;

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

	object GetMap() {
		return object(boost::ref(*map));
	}

	//Exposed methods
	Vector2 WorldToScreen(const Vector3& pos) {
		return renderer->WorldToScreen(pos);
	}

	Vector2 WorldToMinimap(const Vector3& pos) {
		return renderer->WorldToMinimap(pos, minimapPos, minimapSize);
	}

	float DistanceToMinimap(float dist) {
		return renderer->DistanceToMinimap(dist, minimapSize);
	}

	BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(IsScreenPointOnScreenOverloads, IsScreenPointOnScreen, 1, 3);
	bool IsScreenPointOnScreen(const Vector2& point, float offsetX = 0.f, float offsetY = 0.f) {
		return renderer->IsScreenPointOnScreen(point, offsetX, offsetY);
	}

	BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(IsWorldPointOnScreenOverloads, IsWorldPointOnScreen, 1, 3);
	bool IsWorldPointOnScreen(const Vector3& point, float offsetX = 0.f, float offsetY = 0.f) {
		return renderer->IsWorldPointOnScreen(point, offsetX, offsetY);
	}

	void DrawCircle(const Vector2& center, float radius, int numPoints, float thickness, const ImVec4& color) {
		overlay->AddCircle(ImVec2(center.x, center.y), radius, ImColor(color), numPoints, thickness);
	}

	void DrawCircleFilled(const Vector2& center, float radius, int numPoints, const ImVec4& color) {
		overlay->AddCircleFilled(ImVec2(center.x, center.y), radius, ImColor(color), numPoints);
	}

	void DrawTxt(const Vector2& pos, const char* text, const ImVec4& color) {
		overlay->AddText(ImVec2(pos.x, pos.y), ImColor(color), text);
	}

	BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(DrawRectOverloads, DrawRect, 2, 3);
	void DrawRect(const Vector4& box, const ImVec4& color, float rounding = 0) {
		overlay->AddRect(ImVec2(box.x, box.y), ImVec2(box.z, box.w), ImColor(color), rounding);
	}

	BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(DrawRectFilledOverloads, DrawRectFilled, 2, 3);
	void DrawRectFilled(const Vector4& box, const ImVec4& color, float rounding = 0) {
		overlay->AddRectFilled(ImVec2(box.x, box.y), ImVec2(box.z, box.w), ImColor(color), rounding);
	}

	void DrawRectWorld(const Vector3& p1, const Vector3& p2, const Vector3& p3, const Vector3& p4, float thickness, const ImVec4& color) {
		static Vector2 points[4];
		points[0] = renderer->WorldToScreen(p1);
		points[1] = renderer->WorldToScreen(p2);
		points[2] = renderer->WorldToScreen(p3);
		points[3] = renderer->WorldToScreen(p4);

		overlay->AddPolyline((ImVec2*)points, 4, ImColor(color), true, thickness);
	}

	void DrawTriangleWorld(const Vector3& p1, const Vector3& p2, const Vector3& p3, float thickness, const ImVec4& color) {
		overlay->AddTriangle((ImVec2&)renderer->WorldToScreen(p1), (ImVec2&)renderer->WorldToScreen(p2), (ImVec2&)renderer->WorldToScreen(p3), ImColor(color), thickness);
	}

	void DrawTriangleWorldFilled(const Vector3& p1, const Vector3& p2, const Vector3& p3, const ImVec4& color) {
		overlay->AddTriangleFilled((ImVec2&)renderer->WorldToScreen(p1), (ImVec2&)renderer->WorldToScreen(p2), (ImVec2&)renderer->WorldToScreen(p3), ImColor(color));
	}

	void DrawCircleWorld (const Vector3& center, float radius, int numPoints, float thickness, const ImVec4& color) {
		renderer->DrawCircleAt(overlay, center, radius, false, numPoints, ImColor(color), thickness);
	}

	void DrawCircleWorldFilled(const Vector3& center, float radius, int numPoints, const ImVec4& color) {
		renderer->DrawCircleAt(overlay, center, radius, true, numPoints, ImColor(color));
	}

	void DrawLine(const Vector2& start, const Vector2& end, float thickness, const ImVec4& color) {
		overlay->AddLine((const ImVec2&)start, (const ImVec2&)end, ImColor(color), thickness);
	}

	BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(DrawButtonOverloads, DrawButton, 4, 5);
	void DrawButton(const Vector2& p, const char* text, ImVec4& colorButton, ImVec4& colorText, float rounding = 0) {
		int txtSize = strlen(text);
		overlay->AddRectFilled(ImVec2(p.x, p.y), ImVec2(p.x + txtSize * 7.2f + 5, p.y + 17), ImColor(colorButton), rounding);
		overlay->AddText(ImVec2(p.x + 5, p.y + 2), ImColor(colorText), text);
	}

	void PressKey(int key) {
		Input::PressKey((HKey)key);
	}

	bool WasKeyPressed(int key) {
		return Input::WasKeyPressed((HKey)key);
	}

	void PressLeftClick() {
		Input::PressLeftClick();
	}

	void PressRightClick() {
		Input::PressRightClick();
	}

	void ClickAt(bool leftClick, const Vector2& pos) {
		Input::ClickAt(leftClick, pos.x, pos.y);
	}

	bool IsKeyDown(int key) {
		return Input::IsKeyDown((HKey)key);
	}

	Vector2 GetCursor() {
		return Input::GetCursorPosition();
	}

	void MoveCursor(const Vector2& pos) {
		Input::MoveCursorTo(pos.x, pos.y);
	}

	float Distance(GameObject* first, GameObject* second) {
		
		int key = (first->objectIndex > second->objectIndex) ?
			(first->objectIndex << 16) | second->objectIndex : 
			(second->objectIndex << 16) | first->objectIndex;

		auto it = distanceCache.find(key);
		if (it != distanceCache.end())
			return it->second;

		float dist = League::Distance(first->position, second->position);
		distanceCache[key] = dist;

		return dist;
	}

	static PyGame ConstructFromMemSnapshot(MemSnapshot& snapshot) {
		PyGame gs;

		gs.gameTime = snapshot.gameTime;
		gs.renderer = snapshot.renderer.get();
		gs.hoveredObject = snapshot.hoveredObject.get();
		gs.localChampion = snapshot.localChampion.get();
		gs.map = snapshot.map.get();

		for (auto it = snapshot.idxToObjectMap.begin(); it != snapshot.idxToObjectMap.end(); ++it) {
			gs.allObjects[it->first] = boost::ref(*it->second);
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
		for (auto it = snapshot.missiles.begin(); it != snapshot.missiles.end(); ++it) {
			gs.missiles.append(boost::ref(**it));
		}
		for (auto it = snapshot.others.begin(); it != snapshot.others.end(); ++it) {
			gs.others.append(boost::ref(**it));
		}
		return gs;
	}
};