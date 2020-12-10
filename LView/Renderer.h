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
	void     MultiplyMatrices(float *out, float *a, int row1, int col1, float *b, int row2, int col2);
	Vector2  WorldToScreen(Vector3 pos);
	Vector2  WorldToMinimap(Vector3 pos);
	void     DrawCircleAt(ImDrawList* canvas, Vector3 worldPos, float radius, bool filled, int numPoints, ImColor color, float thickness = 3.f);
};