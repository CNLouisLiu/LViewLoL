#include "Spell.h"
#include "Utils.h"
#include "Offsets.h"

const char* Spell::spellTypeName[7] = { "Q", "W", "E", "R", "D", "F", "?" };
std::map<std::string, std::string> Spell::summonerSpellNameDict = {
	{std::string("SummonerHaste"),                 std::string("Ghost")},
	{std::string("SummonerHeal"),                  std::string("Heal")},
	{std::string("SummonerBarrier"),               std::string("Barrier")},
	{std::string("SummonerExhaust"),               std::string("Exhaust")},
	{std::string("SummonerClarity"),               std::string("Clarity")},
	{std::string("SummonerMark"),                  std::string("Snowball")},
	{std::string("SummonerFlash"),                 std::string("Flash")},
	{std::string("SummonerTeleport"),              std::string("Teleport")},
	{std::string("SummonerBoost"),                 std::string("Cleanse")},
	{std::string("SummonerDot"),                   std::string("Ignite")},
	{std::string("SummonerSmite"),                 std::string("Smite")},
	{std::string("S5_SummonerSmitePlayerGanker"),  std::string("Smite")},
	{std::string("S5_SummonerSmitePlayerGanker"),  std::string("Smite")},
	{std::string("S5_SummonerSmitePlayerGanker"),  std::string("Smite")},
}; 

std::map<std::string, SummonerSpellType> Spell::summonerSpellTypeDict = {
	{std::string("SummonerHaste"),                   SummonerSpellType::HASTE},
	{std::string("SummonerHeal"),                    SummonerSpellType::HEAL},
	{std::string("SummonerBarrier"),                 SummonerSpellType::BARRIER},
	{std::string("SummonerExhaust"),                 SummonerSpellType::EXHAUST},
	{std::string("SummonerClarity"),                 SummonerSpellType::CLARITY},
	{std::string("SummonerMark"),                    SummonerSpellType::SNOWBALL},
	{std::string("SummonerFlash"),                   SummonerSpellType::FLASH},
	{std::string("SummonerTeleport"),                SummonerSpellType::TELEPORT},
	{std::string("SummonerBoost"),                   SummonerSpellType::CLEANSE},
	{std::string("SummonerDot"),                     SummonerSpellType::IGNITE},
	{std::string("SummonerSmite"),                   SummonerSpellType::SMITE},
	{std::string("S5_SummonerSmitePlayerGanker"),    SummonerSpellType::SMITE},
	{std::string("S5_SummonerSmitePlayerGanker"),    SummonerSpellType::SMITE},

};

float Spell::GetRemainingCooldown(float gameTime) {
	return (readyAt > gameTime ? readyAt - gameTime : 0.f);
}

const char* Spell::GetTypeStr() {
	return spellTypeName[(int)slot];
}

void Spell::LoadFromMem(DWORD_PTR base, HANDLE hProcess) {
	// Must optimize
	addressSlot = base;
	Mem::Read(hProcess, base + oSpellSlotTime, &readyAt, sizeof(float));
	Mem::Read(hProcess, base + oSpellSlotLevel, &level, 4);
	Mem::Read(hProcess, base + oSpellSlotDamage, &damage, sizeof(float));

	DWORD spellInfoPtr = Mem::ReadPointer(hProcess, base + oSpellSlotSpellInfo);
	DWORD spellDataPtr = Mem::ReadPointer(hProcess, spellInfoPtr + oSpellInfoSpellData);
	DWORD spellNamePtr = Mem::ReadPointer(hProcess, spellDataPtr + oSpellDataSpellName);


	char buff[50];
	Mem::Read(hProcess, spellNamePtr, buff, 50);
	name = std::string(buff);

	auto translatedName = summonerSpellNameDict.find(name.c_str());
	if (translatedName != summonerSpellNameDict.end()) {
		summonerSpellType = summonerSpellTypeDict.find(name.c_str())->second;
		name = std::string(translatedName->second);
	}
}