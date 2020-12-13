#pragma once
#include "Vector.h"
#include "windows.h"
#include "imgui.h"

class Renderer {

public:
	int      width, height;

	float    viewMatrix[16];
	float    projMatrix[16];
	float    viewProjMatrix[16];

	void     LoadFromMem(DWORD_PTR renderBase, DWORD_PTR moduleBase, HANDLE hProcess);

	/* Converts world coordinates to screen coordinates.
	*/
	Vector2  WorldToScreen(const Vector3& pos);

	/* Converts world coordinates to mminimap coordinates. Used to draw on minimap */
	Vector2  WorldToMinimap(const Vector3& pos);

	/* Draws a circle at the given coordinate. Coordinates and radius must be in world space. */
	void     DrawCircleAt(ImDrawList* canvas, const Vector3& worldPos, float radius, bool filled, int numPoints, ImColor color, float thickness = 3.f);

	/* Used to determine if a converted point from world space to screen space is on screen to avoid unnecessary draw calls */
	bool     IsScreenPointOnScreen(const Vector2& point, float offsetX = 0.f, float offsetY = 0.f);

	/* Same as IsScreenPointOnScreen but for world space */
	bool     IsWorldPointOnScreen(const Vector3& point, float offsetX = 0.f, float offsetY = 0.f);

	Vector2  GetCursorPosition();

private:
	void     MultiplyMatrices(float *out, float *a, int row1, int col1, float *b, int row2, int col2);
};