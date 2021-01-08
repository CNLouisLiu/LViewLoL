#include "Spell.h"
#include "Utils.h"
#include "Offsets.h"
#include "GameData.h"

BYTE Spell::buffer[0x150];
const char* Spell::spellTypeName[6] = { "Q", "W", "E", "R", "D", "F"};
const HKey   Spell::spellSlotKey[6]  = { HKey::Q, HKey::W, HKey::E, HKey::R, HKey::D, HKey::F };

std::map<std::string, std::string> Spell::summonerSpellNameDict = {
	{std::string("SummonerHaste"),                 std::string("Ghost")},
	{std::string("SummonerHeal"),                  std::string("Heal")},
	{std::string("SummonerBarrier"),               std::string("Barrier")},
	{std::string("SummonerExhaust"),               std::string("Exhaust")},
	{std::string("SummonerMana"),                  std::string("Clarity")},
	{std::string("SummonerSnowball"),              std::string("Snowball")},
	{std::string("SummonerFlash"),                 std::string("Flash")},
	{std::string("SummonerTeleport"),              std::string("Teleport")},
	{std::string("SummonerBoost"),                 std::string("Cleanse")},
	{std::string("SummonerDot"),                   std::string("Ignite")},
	{std::string("SummonerSmite"),                 std::string("Smite")},
	{std::string("S5_SummonerSmitePlayerGanker"),  std::string("Smite")},
	{std::string("S5_SummonerSmiteDuel"),          std::string("Smite")},
}; 

std::map<std::string, SummonerSpellType> Spell::summonerSpellTypeDict = {
	{std::string("SummonerHaste"),                   SummonerSpellType::GHOST},
	{std::string("SummonerHeal"),                    SummonerSpellType::HEAL},
	{std::string("SummonerBarrier"),                 SummonerSpellType::BARRIER},
	{std::string("SummonerExhaust"),                 SummonerSpellType::EXHAUST},
	{std::string("SummonerMana"),                    SummonerSpellType::CLARITY},
	{std::string("SummonerSnowball"),                SummonerSpellType::SNOWBALL},
	{std::string("SummonerFlash"),                   SummonerSpellType::FLASH},
	{std::string("SummonerTeleport"),                SummonerSpellType::TELEPORT},
	{std::string("SummonerBoost"),                   SummonerSpellType::CLEANSE},
	{std::string("SummonerDot"),                     SummonerSpellType::IGNITE},
	{std::string("SummonerSmite"),                   SummonerSpellType::SMITE},
	{std::string("S5_SummonerSmitePlayerGanker"),    SummonerSpellType::SMITE},
	{std::string("S5_SummonerSmiteDuel"),            SummonerSpellType::SMITE},

};

float Spell::GetRemainingCooldown(float gameTime) {
	return (readyAt > gameTime ? readyAt - gameTime : 0.f);
}

const char* Spell::GetTypeStr() {
	return spellTypeName[(int)slot];
}

void Spell::Trigger() {
	Input::PressKey(spellSlotKey[(int)slot]);
}

void Spell::LoadFromMem(DWORD base, HANDLE hProcess, bool deepLoad) {

	addressSlot = base;
	Mem::Read(hProcess, base, buffer, 0x150);

	memcpy(&readyAt, buffer + Offsets::SpellSlotTime, sizeof(float));
	memcpy(&level, buffer + Offsets::SpellSlotLevel, sizeof(int));
	memcpy(&value, buffer + Offsets::SpellSlotDamage, sizeof(float));

	DWORD spellInfoPtr;
	memcpy(&spellInfoPtr, buffer + Offsets::SpellSlotSpellInfo, sizeof(DWORD));
	
	DWORD spellDataPtr = Mem::ReadDWORD(hProcess, spellInfoPtr + Offsets::SpellInfoSpellData);
	DWORD spellNamePtr = Mem::ReadDWORD(hProcess, spellDataPtr + Offsets::SpellDataSpellName);

	char buff[50];
	Mem::Read(hProcess, spellNamePtr, buff, 50);
	name = std::string(buff);

	auto translatedName = summonerSpellNameDict.find(name.c_str());
	if (translatedName != summonerSpellNameDict.end()) {
		summonerSpellType = summonerSpellTypeDict.find(name.c_str())->second;
		name = std::string(translatedName->second);
	}

	info = GameData::GetSpellInfoByName(name);
}

bool Spell::EqualSpellFlags(SpellFlags flags) const
{
	return info->flags == flags;
}

bool Spell::HasSpellFlags(SpellFlags flags) const
{
	return (info->flags & flags) == flags;
}

float Spell::GetSpeed() const
{
	return info->speed;
}

float Spell::GetRange() const
{
	return info->range;
}

float Spell::GetRadius() const
{
	return info->radius;
}

float Spell::GetRadiusImpact() const
{
	return info->impactRadius;
}

float Spell::GetDelay() const
{
	return info->delay;
}

float Spell::GetHeight() const
{
	return info->height;
}

std::string Spell::GetIcon() const
{
	return info->icon;
}
