#include "GameRenderer.h"
#include "Offsets.h"
#include "Utils.h"
#include "MapObject.h"
#include <algorithm>


void GameRenderer::LoadFromMem(DWORD_PTR renderBase, DWORD_PTR moduleBase, HANDLE hProcess) {

	char buff[128];
	Mem::Read(hProcess, renderBase, buff, 128);
	memcpy(&width, &buff[Offsets::RendererWidth], sizeof(int));
	memcpy(&height, &buff[Offsets::RendererHeight], sizeof(int));

	Mem::Read(hProcess, moduleBase + Offsets::ViewProjMatrices, buff, 128);
	memcpy(viewMatrix, buff, 16 * sizeof(float));
	memcpy(projMatrix, &buff[16 * sizeof(float)], 16 * sizeof(float));
	MultiplyMatrices(viewProjMatrix, viewMatrix, 4, 4, projMatrix, 4, 4);
}

/* Multiply two matrices */
void GameRenderer::MultiplyMatrices(float *out, float *a, int row1, int col1, float *b, int row2, int col2) {
	int size = row1 * col2;
	for (int i = 0; i < row1; i++) {
		for (int j = 0; j < col2; j++) {
			float sum = 0.f;
			for (int k = 0; k < col1; k++)
				sum = sum + a[i * col1 + k] * b[k * col2 + j];
			out[i * col2 + j] = sum;
		}
	}
}

Vector2 GameRenderer::WorldToScreen(const Vector3& pos) const {
	
	Vector2 out = { 0.f, 0.f };
	Vector2 screen = { (float)width, (float)height };
	static Vector4 clipCoords;
	clipCoords.x = pos.x * viewProjMatrix[0] + pos.y * viewProjMatrix[4] + pos.z * viewProjMatrix[8] + viewProjMatrix[12];
	clipCoords.y = pos.x * viewProjMatrix[1] + pos.y * viewProjMatrix[5] + pos.z * viewProjMatrix[9] + viewProjMatrix[13];
	clipCoords.z = pos.x * viewProjMatrix[2] + pos.y * viewProjMatrix[6] + pos.z * viewProjMatrix[10] + viewProjMatrix[14];
	clipCoords.w = pos.x * viewProjMatrix[3] + pos.y * viewProjMatrix[7] + pos.z * viewProjMatrix[11] + viewProjMatrix[15];

	if (clipCoords.w < 1.0f)
		clipCoords.w = 1.f;

	Vector3 M;
	M.x = clipCoords.x / clipCoords.w;
	M.y = clipCoords.y / clipCoords.w;
	M.z = clipCoords.z / clipCoords.w;

	out.x = (screen.x / 2.f * M.x) + (M.x + screen.x / 2.f);
	out.y = -(screen.y / 2.f * M.y) + (M.y + screen.y / 2.f);
	

	return out;
}

Vector2 GameRenderer::WorldToMinimap(const Vector3& pos, const Vector2& wPos, const Vector2& wSize) const {

	Vector2 result = { pos.x / 15000.f, pos.z / 15000.f };
	result.x = wPos.x + result.x * wSize.x;
	result.y = wPos.y + wSize.y - (result.y * wSize.y);

	return result;
}

float GameRenderer::DistanceToMinimap(float dist, const Vector2& wSize) const {

	// This assumes that the minimap is a square !
	return (dist / 15000.f) * wSize.x;
}

bool GameRenderer::IsScreenPointOnScreen(const Vector2& point, float offsetX, float offsetY) const {
	return point.x > -offsetX && point.x < (width + offsetX) && point.y > -offsetY && point.y < (height + offsetY);
}

bool GameRenderer::IsWorldPointOnScreen(const Vector3& point, float offsetX, float offsetY) const {
	return IsScreenPointOnScreen(WorldToScreen(point), offsetX, offsetY);
}

void GameRenderer::DrawCircleAt(ImDrawList* canvas, const Vector3& worldPos, float radius, bool filled, int numPoints, ImColor color, float thickness) const {

	if (numPoints >= 200)
		return;
	static ImVec2 points[200];

	float step = 6.2831f / numPoints;
	float theta = 0.f;
	for (int i = 0; i < numPoints; i++, theta += step) {
		Vector3 worldSpace = { worldPos.x + radius * cos(theta), worldPos.y, worldPos.z - radius * sin(theta) };
		Vector2 screenSpace = WorldToScreen(worldSpace);

		points[i].x = screenSpace.x;
		points[i].y = screenSpace.y;
	}

	if (filled)
		canvas->AddConvexPolyFilled(points, numPoints, color);
	else
		canvas->AddPolyline(points, numPoints, color, true, thickness);
}