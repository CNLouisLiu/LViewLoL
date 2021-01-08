#pragma once
#include <map>
#include "UnitInfo.h"
#include "SpellInfo.h"

/// Data that cant be read from memory or it is too inefficient to do so can be accessed with this class.
class GameData {

public:
	static void       LoadFromFiles(const char* unitDataPath, const char* spellDataPath);
	static UnitInfo*  GetUnitInfoByName(std::string& name);
	static SpellInfo* GetSpellInfoByName(std::string& name);
private:
	static void LoadUnitData(const char* path);
	static void LoadSpellData(const char* path);
	static void SetSpellExceptions();

public:
	static UnitInfo*                         UnknownUnit;
	static SpellInfo*                        UnknownSpell;
	static std::map<std::string, UnitInfo*>  Units;
	static std::map<std::string, SpellInfo*> Spells;
};