#pragma once
#include <string>
#include "windows.h"
#include <map>
#include "Input.h"
#include "MemoryLoadable.h"
#include "SpellInfo.h"
#include "SpellInterface.h"

/// The slot that the champion spell is on
enum class SpellSlot {
	Q = 0, W, E, R, D, F, NONE
};

/// Type of summoner spell
enum class SummonerSpellType {
	NONE, GHOST, HEAL, BARRIER, EXHAUST, CLARITY, SNOWBALL, FLASH, TELEPORT, CLEANSE, IGNITE, SMITE
};

/// Class that represents a spell some of this data is loaded from disk and the rest is read from memory
class Spell: MemoryLoadable, SpellInterface {

public:
	Spell(SpellSlot slot) :slot(slot) {}


	float               GetRemainingCooldown(float gameTime);
	const char*         GetTypeStr();
	void                LoadFromMem(DWORD base, HANDLE hProcess, bool deepLoad = true);
	void                Trigger();
			            
	bool                HasSpellFlags(SpellFlags flags)   const override;
	bool                EqualSpellFlags(SpellFlags flags) const override;
	float               GetSpeed()                        const override;
	float               GetCastRange()                    const override;
	float               GetWidth()                        const override;
	float               GetCastRadius()                   const override;
	float               GetDelay()                        const override;
	float               GetHeight()                       const override;
	float               GetTravelTime()                   const override;
	std::string         GetIcon()                         const override;

public:
	std::string       name;
	SpellSlot         slot;
	SummonerSpellType summonerSpellType;
	int               level = 0;
	float             readyAt = 0.f;
	float             value = 0.f;

	DWORD             addressSlot;
	SpellInfo*        info;

private:
	static BYTE                                        buffer[0x150];
	static const char*                                 spellTypeName[6];
	static const HKey                                  spellSlotKey[6];
	static std::map<std::string, SummonerSpellType>    summonerSpellTypeDict;
};