#include "Champion.h"
#include "Offsets.h"
#include "Utils.h"

void Champion::LoadFromMem(DWORD base, HANDLE hProcess, bool deepLoad) {

	GameObject::LoadFromMem(base, hProcess);

	// Read spells
	memcpy(&spellSlotPtrs, &buff[Offsets::ObjSpellBook], sizeof(DWORD) * 6);

	Q.LoadFromMem(spellSlotPtrs[0], hProcess);
	W.LoadFromMem(spellSlotPtrs[1], hProcess);
	E.LoadFromMem(spellSlotPtrs[2], hProcess);
	R.LoadFromMem(spellSlotPtrs[3], hProcess);

	D.LoadFromMem(spellSlotPtrs[4], hProcess);
	F.LoadFromMem(spellSlotPtrs[5], hProcess);
	
	// Read items
	DWORD ptrList = Mem::ReadDWORD(hProcess, address + Offsets::ObjItemList);
	Mem::Read(hProcess, ptrList, itemListStruct, 0x100);

	for (int i = 0; i < 6; ++i) {
		items[i] = nullptr;
		DWORD itemPtr = 0, itemInfoPtr = 0;
		memcpy(&itemPtr, itemListStruct + i * 0x10 + Offsets::ItemListItem, sizeof(DWORD));
		if (itemPtr == 0)
			continue;

		itemInfoPtr = Mem::ReadDWORD(hProcess, itemPtr + Offsets::ItemInfo);
		if (itemInfoPtr == 0)
			continue;
		items[i] = Item::items[Mem::ReadDWORD(hProcess, itemInfoPtr + Offsets::ItemInfoId)];
	}

	// Read level
	level = Mem::ReadDWORD(hProcess, base + Offsets::ObjLvl);
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

bool Champion::IsRanged() {
	return GetBaseAttackRange() >= 300.f;
}

float CritFromItems(Item* items[]) {
	float crit = 0.f;
	for (int i = 0; i < 6; ++i) {
		if (items[i] != nullptr)
			crit += items[i]->crit;
	}

	return crit;
}

float Champion::GetOnHitPhysDamage(const GameObject& target)
{
	float physDmg = GetBasicAttackDamage();
	float botrkDmg = 0.f;

	for (int i = 0; i < 6; ++i) {
		if (items[i] == nullptr)
			continue;

		switch (items[i]->id) {
		case 3124: // Guinsoo
			physDmg += CritFromItems(items) * 100.f * 2.f;
			break;
		case 6677: // Rageknife
			physDmg += CritFromItems(items) * 100.f * 1.75f;
			break;
		case 6670: // Noonquiver
			physDmg += 20.f;
			break;
		case 1043: // Recurve bow
			physDmg += 15.f;
			break;
		case 3153: // Blade of the ruined king
			botrkDmg = (IsRanged() ? 0.06f : 0.1f) * target.health;
			if (target.HasTags(Unit_Champion))
				physDmg += botrkDmg;
			else
				physDmg += League::Clamp(botrkDmg, 0.f, 60.f);
			break;
		case 1056:
			physDmg += 5.f;
			break;
		default:
			break;
		}
	}

	return League::EffectiveDamage(physDmg, target.armour);
}

float Champion::GetOnHitMagicDamage(const GameObject& target)
{
	float magicDmg = 0.f;

	for (int i = 0; i < 6; ++i) {
		if (items[i] == nullptr)
			continue;

		switch (items[i]->id) {
		case 3115: // Nashors tooth
			magicDmg += 15.f + 0.2f * abilityPower;
			break;
		case 3091: // Wits End
			magicDmg += 11.17f + 3.82f * level;
			break;
		default:
			break;
		}
	}

	return League::EffectiveDamage(magicDmg, target.magicResist);
}

tuple Champion::ItemsToPyTuple() {
	list l;
	for (int i = 0; i < 6; ++i)
		l.append(ptr(items[i]));

	return tuple(l);
}