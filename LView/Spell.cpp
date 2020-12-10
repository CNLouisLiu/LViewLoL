#include "Spell.h"
#include "Utils.h"
#include "Offsets.h"

const char* gSpellTypeName[7] = { "Q", "W", "E", "R", "D", "F", "?" };
std::map<std::string, std::string> gSummonerSpellNameDict = {
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

float Spell::GetRemainingCooldown(float gameTime) {
	return (readyAt > gameTime ? readyAt - gameTime : 0.f);
}

const char* Spell::GetTypeStr() {
	return gSpellTypeName[(int)type];
}

void Spell::LoadFromMem(DWORD_PTR base, HANDLE hProcess) {
	Mem::Read(hProcess, base + oSpellSlotTime, &readyAt, sizeof(float));
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
		if (translatedName != gSummonerSpellNameDict.end())
			name = std::string(translatedName->second);
	}
}