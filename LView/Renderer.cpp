#include "Renderer.h"
#include "Offsets.h"
#include "Utils.h"


void Renderer::LoadFromMem(DWORD_PTR renderBase, DWORD_PTR moduleBase, HANDLE hProcess) {

	char buff[128];
	Mem::Read(hProcess, renderBase, buff, 128);
	memcpy(&width, &buff[oRendererWidth], sizeof(int));
	memcpy(&height, &buff[oRendererHeight], sizeof(int));

	Mem::Read(hProcess, moduleBase + oViewProjMatrices, buff, 128);
	memcpy(viewMatrix, buff, 16 * sizeof(float));
	memcpy(projMatrix, &buff[16 * sizeof(float)], 16 * sizeof(float));
	MultiplyMatrices(viewProjMatrix, viewMatrix, 4, 4, projMatrix, 4, 4);
}

/* Multiply two matrices */
void Renderer::MultiplyMatrices(float *out, float *a, int row1, int col1, float *b, int row2, int col2) {
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

Vector2 Renderer::WorldToScreen(const Vector3& pos) {
	
	Vector2 out = { 0.f, 0.f };
	Vector2 screen = { (float)width, (float)height };
	static Vector4 clipCoords;
	clipCoords.x = pos.x * viewProjMatrix[0] + pos.y * viewProjMatrix[4] + pos.z * viewProjMatrix[8] + viewProjMatrix[12];
	clipCoords.y = pos.x * viewProjMatrix[1] + pos.y * viewProjMatrix[5] + pos.z * viewProjMatrix[9] + viewProjMatrix[13];
	clipCoords.z = pos.x * viewProjMatrix[2] + pos.y * viewProjMatrix[6] + pos.z * viewProjMatrix[10] + viewProjMatrix[14];
	clipCoords.w = pos.x * viewProjMatrix[3] + pos.y * viewProjMatrix[7] + pos.z * viewProjMatrix[11] + viewProjMatrix[15];

	if (clipCoords.w > 0.05f) {
		Vector3 M;
		M.x = clipCoords.x / clipCoords.w;
		M.y = clipCoords.y / clipCoords.w;
		M.z = clipCoords.z / clipCoords.w;

		out.x = (screen.x / 2.f * M.x) + (M.x + screen.x / 2.f);
		out.y = -(screen.y / 2.f * M.y) + (M.y + screen.y / 2.f);
	}

	return out;
}

Vector2 Renderer::GetCursorPosition() {
	POINT pos;
	GetCursorPos(&pos);
	return { (float)pos.x, (float)pos.y };
}

Vector2 Renderer::WorldToMinimap(const Vector3& pos) {

	ImVec2 wPos = ImGui::GetWindowPos();
	ImVec2 wSize = ImGui::GetWindowSize();

	Vector2 result = { pos.x / 15000.f, pos.z / 15000.f };
	result.x = wPos.x + result.x * wSize.x;
	result.y = wPos.y + wSize.y - (result.y * wSize.y);

	return result;
}

bool Renderer::IsScreenPointOnScreen(const Vector2& point) {
	return point.x >= 0.f && point.x <= width && point.y >= 0 && point.y <= height;
}

bool Renderer::IsWorldPointOnScreen(const Vector3& point) {
	return IsScreenPointOnScreen(WorldToScreen(point));
}

void Renderer::DrawCircleAt(ImDrawList* canvas, const Vector3& worldPos, float radius, bool filled, int numPoints, ImColor color, float thickness) {

	ImVec2* points = new ImVec2[numPoints];
	float step = 6.2831 / numPoints;

	int i = 0;
	for (float theta = 0; theta < 6.2831; theta += step, i++) {
		Vector3 worldSpace = { worldPos.x + radius * cos(theta), worldPos.y, worldPos.z - radius * sin(theta) };
		Vector2 screenSpace = WorldToScreen(worldSpace);

		points[i].x = screenSpace.x;
		points[i].y = screenSpace.y;
	}

	if (filled)
		canvas->AddConvexPolyFilled(points, numPoints, color);
	else
		canvas->AddPolyline(points, numPoints, color, true, thickness);

	delete[] points;
}