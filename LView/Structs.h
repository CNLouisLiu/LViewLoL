#ifndef LEAGUE_STRUCTS_H
#define LEAGUE_STRUCTS_H

#include "windows.h"
#include "Offsets.h"
#include "Utils.h"
#include <string>
#include <sstream>
#include <ctime>


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

static const char* gSpellTypeName[7] = { "Q", "W", "E", "R", "D", "F", "?" };

class Spell {

public:

	Spell(SpellType type)
	:type(type) {
	}

	float GetRemainingCooldown(float gameTime) {
		return (readyAt > gameTime ? readyAt - gameTime : 0.f);
	}

	std::string name;
	SpellType type;
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
				float sum = 0;
				for (int k = 0; k < col1; k++)
					sum = sum + a[i * col1 + k] * b[k * col2 + j];
				out[i * col2 + j] = sum;
			}
		}
	}

	Vector2 WorldToScreen(Vector3 pos) {
		Vector2 returnVec = {0.f, 0.f};

		Vector2 screen = {width, height};
		
		Vector4 clipCoords;
		clipCoords.x = pos.x * viewProjMatrix[0] + pos.y * viewProjMatrix[4] + pos.z * viewProjMatrix[8] + viewProjMatrix[12];
		clipCoords.y = pos.x * viewProjMatrix[1] + pos.y * viewProjMatrix[5] + pos.z * viewProjMatrix[9] + viewProjMatrix[13];
		clipCoords.z = pos.x * viewProjMatrix[2] + pos.y * viewProjMatrix[6] + pos.z * viewProjMatrix[10] + viewProjMatrix[14];
		clipCoords.w = pos.x * viewProjMatrix[3] + pos.y * viewProjMatrix[7] + pos.z * viewProjMatrix[11] + viewProjMatrix[15];

		if (clipCoords.w < 0.1f) return returnVec;

		Vector3 M;
		M.x = clipCoords.x / clipCoords.w;
		M.y = clipCoords.y / clipCoords.w;
		M.z = clipCoords.z / clipCoords.w;

		returnVec.x = (screen.x / 2 * M.x) + (M.x + screen.x / 2);
		returnVec.y = -(screen.y / 2 * M.y) + (M.y + screen.y / 2);

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

		name = std::string("None");
	}

	short team;
	bool isVisible;
	std::string name;
	Vector3 position;
	Spell Q, W, E, R, D, F;

	/* base must be the address at which the hero object starts */
	void LoadFromMem(DWORD_PTR base, HANDLE hProcess) {
		Mem::Read(hProcess, base + oObjTeam, &team, sizeof(short));
		Mem::Read(hProcess, base + oObjVisibility, &isVisible, sizeof(bool));

		// Read champ name
		char buff[50];
		Mem::Read(hProcess, base + oObjChampionName, buff, 50);
		name = std::string(buff);

		// Read position
		Mem::Read(hProcess, base + oObjPos, &position, sizeof(Vector3));

		// Read spells
		DWORD spellSlots[6];
		Mem::Read(hProcess, base + oObjSpellBook, spellSlots, sizeof(DWORD)*6);

		Q.readyAt = Mem::ReadFloat(hProcess, spellSlots[0] + oSpellSlotTime);
		W.readyAt = Mem::ReadFloat(hProcess, spellSlots[1] + oSpellSlotTime);
		E.readyAt = Mem::ReadFloat(hProcess, spellSlots[2] + oSpellSlotTime);
		R.readyAt = Mem::ReadFloat(hProcess, spellSlots[3] + oSpellSlotTime);

		D.readyAt = Mem::ReadFloat(hProcess, spellSlots[4] + oSpellSlotTime);
		F.readyAt = Mem::ReadFloat(hProcess, spellSlots[5] + oSpellSlotTime);
	}
};


#endif