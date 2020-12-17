#include "Champion.h"
#include "Offsets.h"

void Champion::LoadFromMem(DWORD base, HANDLE hProcess, bool deepLoad) {

	GameObject::LoadFromMem(base, hProcess);

	memcpy(&spellSlotPtrs, &buff[Offsets::ObjSpellBook], sizeof(DWORD) * 6);

	Q.LoadFromMem(spellSlotPtrs[0], hProcess);
	W.LoadFromMem(spellSlotPtrs[1], hProcess);
	E.LoadFromMem(spellSlotPtrs[2], hProcess);
	R.LoadFromMem(spellSlotPtrs[3], hProcess);

	D.LoadFromMem(spellSlotPtrs[4], hProcess);
	F.LoadFromMem(spellSlotPtrs[5], hProcess);
	
	type = (GameObjectType) (type | PLAYER);
}

float Champion::GetBasicAttackDamage() {
	return baseAttack + bonusAttack;
}

Spell* Champion::GetSummonerSpell(SummonerSpellType type) {
	if (D.summonerSpellType == type)
		return &D;
	if (F.summonerSpellType == type)
		return &F;
	return nullptr;
}