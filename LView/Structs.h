#pragma once

#include "windows.h"
#include "Offsets.h"
#include "Utils.h"
#include <string>
#include <sstream>
#include <ctime>
#include <map>

static const char* gSpellTypeName[7] = { "Q", "W", "E", "R", "D", "F", "?" };
static std::map<std::string, std::string> gSummonerSpellNameDict = {
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

struct Vector2 {
	float x;
	float y;
};

struct Vector3 {
	float x;
	float y;
	float z;
};

struct Vector4 {
	float x;
	float y;
	float z;
	float w;
};

enum class SpellType {
	Q = 0, W, E, R, D, F, NONE
};

class Spell {

public:
	Spell(SpellType type)
	:type(type) {	
	}


	float GetRemainingCooldown(float gameTime) {
		return (readyAt > gameTime ? readyAt - gameTime : 0.f);
	}

	const char* GetTypeStr() {
		return gSpellTypeName[(int)type];
	}

	void LoadFromMem(DWORD_PTR base, HANDLE hProcess) { 
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
			if(translatedName != gSummonerSpellNameDict.end())
				name = std::string(translatedName->second);
		}
	}

public:
	std::string name;
	SpellType type;
	int level = 0;
	float readyAt = 0.f;

private:
	std::string remainingCooldownStr;
};

class Renderer {
	
public:
	int width, height;

	float viewMatrix[16];
	float projMatrix[16];
	float viewProjMatrix[16];

	void LoadFromMem(DWORD_PTR base, HANDLE hProcess) {

		Mem::Read(hProcess, base + oRendererWidth, &width, 4);
		Mem::Read(hProcess, base + oRendererHeight, &height, 4);
		Mem::Read(hProcess, base + oRendererViewMat, viewMatrix, 16 * sizeof(float));
		Mem::Read(hProcess, base + oRendererProjMat, projMatrix, 16 * sizeof(float));
		multiply(viewProjMatrix, viewMatrix, 4, 4, projMatrix, 4, 4);
	}

	/* Multiply two matrices */
	void multiply(float *out, float *a, int row1, int col1, float *b, int row2, int col2) {
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

	Vector2 WorldToScreen(Vector3 pos) {
		Vector2 returnVec = {0.f, 0.f};

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
};

class Champion {

public:

	Champion()
	:   Q(Spell(SpellType::Q)),
		W(Spell(SpellType::W)),
		E(Spell(SpellType::E)),
		R(Spell(SpellType::R)),
		D(Spell(SpellType::D)),
		F(Spell(SpellType::F)) {
	}

	/* base must be the address at which the hero object starts */
	void LoadFromMem(DWORD_PTR base, HANDLE hProcess) {
		
		// Read static stuff
		if (name.empty()) {
			Mem::Read(hProcess, base + oObjTeam, &team, sizeof(short));
			Mem::Read(hProcess, base + oObjSpellBook, spellSlotPtrs, sizeof(DWORD) * 6);

			char buff[50];
			Mem::Read(hProcess, base + oObjChampionName, buff, 50);
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

public:
	short team;
	bool isVisible;
	std::string name;
	Vector3 position;
	Spell Q, W, E, R, D, F;

private:
	DWORD spellSlotPtrs[6];
};
