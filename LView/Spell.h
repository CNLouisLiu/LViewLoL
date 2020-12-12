#pragma once
#include <string>
#include "windows.h"
#include <map>
#include "Input.h"
#include "MemoryLoadable.h"

enum class SpellSlot {
	Q = 0, W, E, R, D, F, NONE
};

enum class SummonerSpellType {
	HASTE, HEAL, BARRIER, EXHAUST, CLARITY, SNOWBALL, FLASH, TELEPORT, CLEANSE, IGNITE, SMITE, NONE
};

class Spell: MemoryLoadable {

public:
	Spell(SpellSlot slot) :slot(slot) {}


	float       GetRemainingCooldown(float gameTime);
	const char* GetTypeStr();
	void        LoadFromMem(DWORD base, HANDLE hProcess, bool deepLoad = true);
	void        Trigger();

public:
	std::string   name;
	SpellSlot     slot;
	SummonerSpellType summonerSpellType;
	int           level = 0;
	float         readyAt = 0.f;
	float         damage = 0.f;

	DWORD         addressSlot;

private:
	static BYTE                                       buffer[0x150];
	static const char*                                spellTypeName[6];
	static const HKey                                  spellSlotKey[6];
	static std::map<std::string, std::string>         summonerSpellNameDict;
	static std::map<std::string, SummonerSpellType>   summonerSpellTypeDict;
};