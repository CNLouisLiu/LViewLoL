#include "Structs.h"

const char* gSpellTypeName[7] = { "Q", "W", "E", "R", "D", "F", "?" };
std::map<std::string, std::string> gSummonerSpellNameDict = {
	{std::string("SummonerHaste"), std::string("Ghost")},
	{std::string("SummonerHeal"), std::string("Heal")},
	{std::string("SummonerBarrier"), std::string("Barrier")},
	{std::string("SummonerExhaust"), std::string("Exhaust")},
	{std::string("SummonerClarity"), std::string("Clarity")},
	{std::string("SummonerMark"), std::string("Snowball")},
	{std::string("SummonerFlash"), std::string("Flash")},
	{std::string("SummonerTeleport"), std::string("Teleport")},
	{std::string("SummonerBoost"), std::string("Cleanse")},
	{std::string("SummonerDot"), std::string("Ignite")},
	{std::string("SummonerSmite"), std::string("Smite")},
};

float Spell::GetRemainingCooldown(float gameTime) {
	return (readyAt > gameTime ? readyAt - gameTime : 0.f);
}

const char* Spell::GetTypeStr() {
	return gSpellTypeName[(int)type];
}

void Spell::LoadFromMem(DWORD_PTR base, HANDLE hProcess) {
	readyAt = Mem::ReadFloat(hProcess, base + oSpellSlotTime);
	Mem::Read(hProcess, base + oSpellSlotLevel, &level, 4);

	// Read static stuff
	if (name.empty()) {
		DWORD spellInfoPtr = Mem::ReadPointer(hProcess, base + oSpellSlotSpellInfo);
		DWORD spellDataPtr = Mem::ReadPointer(hProcess, spellInfoPtr + oSpellInfoSpellData);
		DWORD spellNamePtr = Mem::ReadPointer(hProcess, spellDataPtr + oSpellDataSpellName);


		char buff[50];
		Mem::Read(hProcess, spellNamePtr, buff, 50);
		name = std::string(buff);

		auto translatedName = gSummonerSpellNameDict.find(name.c_str());
		if (translatedName != gSummonerSpellNameDict.end())
			name = std::string(translatedName->second);
	}
}




void Renderer::LoadFromMem(DWORD_PTR renderBase, DWORD_PTR moduleBase, HANDLE hProcess) {

	char buff[128];
	Mem::Read(hProcess, renderBase, buff, 128);
	memcpy(&width, &buff[oRendererWidth], sizeof(int));
	memcpy(&height, &buff[oRendererHeight], sizeof(int));

	Mem::Read(hProcess, moduleBase + oViewProjMatrices, buff, 128);
	memcpy(viewMatrix, buff, 16 * sizeof(float));
	memcpy(projMatrix, &buff[16*sizeof(float)], 16 * sizeof(float));
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

Vector2 Renderer::WorldToScreen(Vector3 pos) {
	Vector2 returnVec = { 0.f, 0.f };

	Vector2 screen = { (float)width, (float)height };

	Vector4 clipCoords;
	clipCoords.x = pos.x * viewProjMatrix[0] + pos.y * viewProjMatrix[4] + pos.z * viewProjMatrix[8] + viewProjMatrix[12];
	clipCoords.y = pos.x * viewProjMatrix[1] + pos.y * viewProjMatrix[5] + pos.z * viewProjMatrix[9] + viewProjMatrix[13];
	clipCoords.z = pos.x * viewProjMatrix[2] + pos.y * viewProjMatrix[6] + pos.z * viewProjMatrix[10] + viewProjMatrix[14];
	clipCoords.w = pos.x * viewProjMatrix[3] + pos.y * viewProjMatrix[7] + pos.z * viewProjMatrix[11] + viewProjMatrix[15];

	if (clipCoords.w < 0.05f) return returnVec;

	Vector3 M;
	M.x = clipCoords.x / clipCoords.w;
	M.y = clipCoords.y / clipCoords.w;
	M.z = clipCoords.z / clipCoords.w;

	returnVec.x = (screen.x / 2.f * M.x) + (M.x + screen.x / 2.f);
	returnVec.y = -(screen.y / 2.f * M.y) + (M.y + screen.y / 2.f);

	return returnVec;
}


void Renderer::DrawCircleAt(ImDrawList* canvas, Vector3 worldPos, float radius, bool filled, int numPoints, ImColor color) {
	
	ImVec2* points = new ImVec2[numPoints];
	float step = 2*3.14 / numPoints;

	int i = 0;
	for (float theta = 0; theta < 2 * 3.14; theta+=step, i++) {
		Vector3 worldSpace = { worldPos.x + radius * cos(theta), worldPos.y, worldPos.z - radius * sin(theta) };
		Vector2 screenSpace = WorldToScreen(worldSpace);
		points[i].x = screenSpace.x;
		points[i].y = screenSpace.y;
	}

	if (filled)
		canvas->AddConvexPolyFilled(points, numPoints, color);
	else
		canvas->AddPolyline(points, numPoints, color, true, 3.f);
	
	delete[] points;
}




void Champion::LoadFromMem(DWORD_PTR base, HANDLE hProcess) {

	// Read static stuff
	if (name.empty()) {
		Mem::Read(hProcess, base + oObjTeam, &team, sizeof(short));
		Mem::Read(hProcess, base + oObjSpellBook, spellSlotPtrs, sizeof(DWORD) * 6);

		char buff[50];
		Mem::Read(hProcess, Mem::ReadPointer(hProcess, base + oObjChampionName), buff, 50);
		name = std::string(buff);
	}

	// Read dynamic stuff
	Mem::Read(hProcess, base + oObjVisibility, &isVisible, sizeof(bool));
	Mem::Read(hProcess, base + oObjPos, &position, sizeof(Vector3));

	Q.LoadFromMem(spellSlotPtrs[0], hProcess);
	W.LoadFromMem(spellSlotPtrs[1], hProcess);
	E.LoadFromMem(spellSlotPtrs[2], hProcess);
	R.LoadFromMem(spellSlotPtrs[3], hProcess);

	D.LoadFromMem(spellSlotPtrs[4], hProcess);
	F.LoadFromMem(spellSlotPtrs[5], hProcess);
}