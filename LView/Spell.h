#pragma once
#include <string>
#include "windows.h"
#include <map>

enum class SpellSlot {
	Q = 0, W, E, R, D, F, NONE
};

enum class SummonerSpellType {
	HASTE, HEAL, BARRIER, EXHAUST, CLARITY, SNOWBALL, FLASH, TELEPORT, CLEANSE, IGNITE, SMITE, NONE
};

class Spell {

public:
	Spell(SpellSlot slot) :slot(slot) {}


	float       GetRemainingCooldown(float gameTime);
	const char* GetTypeStr();
	void        LoadFromMem(DWORD_PTR base, HANDLE hProcess);

public:
	std::string   name;
	SpellSlot     slot;
	SummonerSpellType summonerSpellType;
	int           level = 0;
	float         readyAt = 0.f;
	float         damage = 0.f;

	DWORD         addressSlot;

private:
	static const char*                            spellTypeName[7];
	static std::map<std::string, std::string>     summonerSpellNameDict;
	static std::map<std::string, SummonerSpellType>   summonerSpellTypeDict;
};