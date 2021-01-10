#include "GameObject.h"
#include "Utils.h"
#include "Offsets.h"
#include "Spell.h"
#include "GameData.h"

BYTE  GameObject::buff[GameObject::sizeBuff]         = {};
BYTE  GameObject::buffDeep[GameObject::sizeBuffDeep] = {};

bool GameObject::HasUnitTags(const UnitTag& type1) const {
	return unitInfo->tags.test(type1);
}

bool GameObject::IsEqualTo(const GameObject& other) const {
	return this->objectIndex == other.objectIndex;
}

bool GameObject::IsNotEqualTo(const GameObject& other) const {
	return this->objectIndex != other.objectIndex;
}

float GameObject::GetAcquisitionRadius() const
{
	return unitInfo->acquisitionRange;
}

float GameObject::GetSelectionRadius() const
{
	return unitInfo->selectionRadius;
}

float GameObject::GetPathingRadius() const
{
	return unitInfo->pathRadius;
}

float GameObject::GetGameplayRadius() const
{
	return unitInfo->gameplayRadius;
}

float GameObject::GetBasicAttackMissileSpeed() const
{
	return unitInfo->basicAttackMissileSpeed;
}

float GameObject::GetBasicAttackWindup() const
{
	return unitInfo->basicAttackWindup;
}

float GameObject::GetAttackSpeedRatio() const
{
	return unitInfo->attackSpeedRatio;
}

float GameObject::GetBaseMovementSpeed() const
{
	return unitInfo->baseMovementSpeed;
}

float GameObject::GetBaseAttackSpeed() const
{
	return unitInfo->baseAttackSpeed;
}

float GameObject::GetBaseAttackRange() const
{
	return unitInfo->baseAttackRange;
}

float GameObject::GetAttackRange()  const {
	return GetBaseAttackRange() + GetGameplayRadius();
}

float GameObject::GetHpBarHeight() const
{
	return unitInfo->healthBarHeight;
}

bool GameObject::IsEnemyTo(const GameObject& other) const {
	return this->team != other.team;
}

bool GameObject::IsAllyTo(const GameObject& other) const {
	return this->team == other.team;
}

void GameObject::LoadFromMem(DWORD base, HANDLE hProcess, bool deepLoad) {

	address = base;
	Mem::Read(hProcess, base, buff, sizeBuff);

	previousPosition = position.clone();
	memcpy(&team, &buff[Offsets::ObjTeam], sizeof(short));
	memcpy(&position, &buff[Offsets::ObjPos], sizeof(Vector3));
	memcpy(&health, &buff[Offsets::ObjHealth], sizeof(float));
	memcpy(&baseAttack, &buff[Offsets::ObjBaseAtk], sizeof(float));
	memcpy(&bonusAttack, &buff[Offsets::ObjBonusAtk], sizeof(float));
	memcpy(&armour, &buff[Offsets::ObjArmor], sizeof(float));
	memcpy(&magicResist, &buff[Offsets::ObjMagicRes], sizeof(float));
	memcpy(&duration, &buff[Offsets::ObjExpiry], sizeof(float));
	memcpy(&isVisible, &buff[Offsets::ObjVisibility], sizeof(bool));
	memcpy(&objectIndex, &buff[Offsets::ObjIndex], sizeof(short));
	memcpy(&crit, &buff[Offsets::ObjCrit], sizeof(float));
	memcpy(&critMulti, &buff[Offsets::ObjCritMulti], sizeof(float));
	memcpy(&abilityPower, &buff[Offsets::ObjAbilityPower], sizeof(float));
	memcpy(&atkSpeedMulti, &buff[Offsets::ObjAtkSpeedMulti], sizeof(float));
	memcpy(&movementSpeed, &buff[Offsets::ObjMoveSpeed], sizeof(float));
	memcpy(&networkId, &buff[Offsets::ObjNetworkID], sizeof(DWORD));

	// Check if alive
	DWORD spawnCount;
	memcpy(&spawnCount, &buff[Offsets::ObjSpawnCount], sizeof(int));
	isAlive = (spawnCount % 2 == 0);

	if (deepLoad) {

		char nameBuff[50];
		Mem::Read(hProcess, Mem::ReadDWORDFromBuffer(buff, Offsets::ObjName), nameBuff, 50);

		if (Character::ContainsOnlyASCII(nameBuff, 50))
			name = Character::ToLower(std::string(nameBuff));
		else
			name = std::string("");
		unitInfo = GameData::GetUnitInfoByName(name);
	}

	// Read extension of object
	if (HasUnitTags(Unit_Champion)) {
		LoadChampionFromMem(base, hProcess, deepLoad);
	}
	else if(unitInfo == GameData::UnknownUnit) {
		// Try reading missile extension
		LoadMissileFromMem(base, hProcess, deepLoad);
	}
}

// Champion stuff

DWORD GameObject::spellSlotPointerBuffer[6] = {};
BYTE  GameObject::itemListBuffer[0x100] = {};

void GameObject::LoadChampionFromMem(DWORD base, HANDLE hProcess, bool deepLoad) {

	// Read spells
	memcpy(&spellSlotPointerBuffer, &buff[Offsets::ObjSpellBook], sizeof(DWORD) * 6);

	Q.LoadFromMem(spellSlotPointerBuffer[0], hProcess);
	W.LoadFromMem(spellSlotPointerBuffer[1], hProcess);
	E.LoadFromMem(spellSlotPointerBuffer[2], hProcess);
	R.LoadFromMem(spellSlotPointerBuffer[3], hProcess);

	D.LoadFromMem(spellSlotPointerBuffer[4], hProcess);
	F.LoadFromMem(spellSlotPointerBuffer[5], hProcess);

	// Read items
	DWORD ptrList = Mem::ReadDWORD(hProcess, address + Offsets::ObjItemList);
	Mem::Read(hProcess, ptrList, itemListBuffer, 0x100);

	for (int i = 0; i < 6; ++i) {
		items[i] = nullptr;
		DWORD itemPtr = 0, itemInfoPtr = 0;
		memcpy(&itemPtr, itemListBuffer + i * 0x10 + Offsets::ItemListItem, sizeof(DWORD));
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

float GameObject::GetBasicAttackDamage() {
	return baseAttack + bonusAttack;
}

Spell* GameObject::GetSummonerSpell(SummonerSpellType type) {
	if (D.summonerSpellType == type)
		return &D;
	if (F.summonerSpellType == type)
		return &F;
	return nullptr;
}

bool GameObject::IsRanged() {
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

float GameObject::GetOnHitPhysDamage(const GameObject& target)
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
			if (target.HasUnitTags(Unit_Champion))
				physDmg += botrkDmg;
			else
				physDmg += Clamp(botrkDmg, 0.f, 60.f);
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

float GameObject::GetOnHitMagicDamage(const GameObject& target)
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

tuple GameObject::ItemsToPyTuple() {
	list l;
	for (int i = 0; i < 6; ++i)
		l.append(ptr(items[i]));

	return tuple(l);
}

// Missile stuff
void GameObject::LoadMissileFromMem(DWORD base, HANDLE hProcess, bool deepLoad) {

	if (!deepLoad)
		return;

	DWORD spellInfoPtr = Mem::ReadDWORDFromBuffer(buff, Offsets::MissileSpellInfo);
	if (spellInfoPtr == 0)
		return;

	DWORD spellDataPtr = Mem::ReadDWORD(hProcess, spellInfoPtr + Offsets::SpellInfoSpellData);
	if (spellDataPtr == 0)
		return;

	memcpy(&srcIndex, buff + Offsets::MissileSrcIdx, sizeof(short));
	memcpy(&destIndex, buff + Offsets::MissileDestIdx, sizeof(short));
	memcpy(&startPos, buff + Offsets::MissileStartPos, sizeof(Vector3));
	memcpy(&endPos, buff + Offsets::MissileEndPos, sizeof(Vector3));

	startPos.y += 100.f;
	endPos.y += 100.f;

	Mem::Read(hProcess, spellDataPtr, buff, 0x500);

	// Read name
	char nameBuff[50];
	Mem::Read(hProcess, Mem::ReadDWORD(hProcess, spellDataPtr + Offsets::SpellDataMissileName), nameBuff, 50);
	if (Character::ContainsOnlyASCII(nameBuff, 50))
		name = Character::ToLower(std::string(nameBuff));
	else
		name = std::string("");

	// Find static data
	spellInfo = GameData::GetSpellInfoByName(name);

	// Calculate end position using range since for some skills (e.g GLOBAL skills) the end position is incorrect
	if (spellInfo != GameData::UnknownSpell && !HasSpellFlags(FixedDestination)) {

		// Calculate direction vector and normalize
		endPos = Vector3(endPos.x - startPos.x, 0, endPos.z - startPos.z);
		endPos = endPos.normalize();

		// Update endposition using the height of the current position
		endPos.x = endPos.x*spellInfo->range + startPos.x;
		endPos.y = position.y;
		endPos.z = endPos.z*spellInfo->range + startPos.z;
	}
}

bool GameObject::EqualSpellFlags(SpellFlags flags) const
{
	return spellInfo->flags == flags;
}

bool GameObject::HasSpellFlags(SpellFlags flags) const
{
	return (spellInfo->flags & flags) == flags;
}

float GameObject::GetSpeed() const
{
	return spellInfo->speed;
}

float GameObject::GetRange() const
{
	return spellInfo->range;
}

float GameObject::GetRadius() const
{
	return spellInfo->radius;
}

float GameObject::GetRadiusImpact() const
{
	return spellInfo->impactRadius;
}

float GameObject::GetDelay() const
{
	return spellInfo->delay;
}

float GameObject::GetHeight() const
{
	return spellInfo->height;
}

std::string GameObject::GetIcon() const
{
	return spellInfo->icon;
}
