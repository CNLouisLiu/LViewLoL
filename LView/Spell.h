#pragma once
#include <string>
#include "windows.h"
#include <map>

extern const char* gSpellTypeName[7];
extern std::map<std::string, std::string> gSummonerSpellNameDict;

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