#pragma once

#include "windows.h"
#include "Offsets.h"
#include "Utils.h"
#include "imgui.h"
#include <string>
#include <sstream>
#include <ctime>
#include <map>

extern const char* gSpellTypeName[7];
extern std::map<std::string, std::string> gSummonerSpellNameDict;

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
	            Spell(SpellType type) :type(type) {}


	float       GetRemainingCooldown(float gameTime);
	const char* GetTypeStr();
	void        LoadFromMem(DWORD_PTR base, HANDLE hProcess);

public:
	std::string name;
	SpellType   type;
	int         level = 0;
	float       readyAt = 0.f;

private:
	std::string remainingCooldownStr;
};

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
	void     DrawCircleAt(ImDrawList* canvas, Vector3 worldPos, float radius, bool filled, int numPoints, ImColor color);
};

class GameObject {

public:
	             GameObject() { buff = new BYTE[0x3000];  }
	             ~GameObject() { delete[] buff; }

	void         LoadFromMem(DWORD_PTR base, HANDLE hProcess);

	short        team;
	float        health;
	float        expiryAt;
	bool         isVisible;
	std::string  name;
	Vector3      position;
	DWORD        address;

protected:
	BYTE* buff;
};

class Champion: public GameObject {

public:

	Champion()
	:   Q(Spell(SpellType::Q)),
		W(Spell(SpellType::W)),
		E(Spell(SpellType::E)),
		R(Spell(SpellType::R)),
		D(Spell(SpellType::D)),
		F(Spell(SpellType::F)) {
	}

	void    LoadFromMem(DWORD_PTR base, HANDLE hProcess);

public:
	float   currentHealth;

	Spell   Q, W, E, R, D, F;

private:
	DWORD   spellSlotPtrs[6];
};
