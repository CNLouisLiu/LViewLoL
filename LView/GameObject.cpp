#include "GameObject.h"
#include "Utils.h"
#include "Offsets.h"
#include "Spell.h"

BYTE  GameObject::buff[GameObject::sizeBuff]         = {};
BYTE  GameObject::buffDeep[GameObject::sizeBuffDeep] = {};

bool GameObject::HasTags(const UnitTag& type1) const {
	return unitInfo->tags.test(type1);
}

bool GameObject::HasTags2(const UnitTag& type1, const UnitTag& type2)  const {
	return unitInfo->tags.test(type1) && unitInfo->tags.test(type2);
}

bool GameObject::HasTags3(const UnitTag& type1, const UnitTag& type2, const UnitTag& type3) const {
	return unitInfo->tags.test(type1) && unitInfo->tags.test(type2) && unitInfo->tags.test(type3);
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

object GameObject::GetPythonUnitInfo()
{
	return object(ptr(unitInfo));
}

void GameObject::LoadFromMem(DWORD base, HANDLE hProcess, bool deepLoad) {

	address = base;
	Mem::Read(hProcess, base, buff, sizeBuff);

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
			name = std::string(nameBuff);
		else {
			name = std::string("");
		}

		// Get static UnitInfo
		std::string nameLower;
		nameLower.resize(name.size());

		std::transform(name.begin(),
			name.end(),
			nameLower.begin(),
			::tolower);

		auto it = UnitInfo::infos.find(nameLower);
		if (it != UnitInfo::infos.end())
			unitInfo = it->second;
		else {
			unitInfo = UnitInfo::infos.find("unknown")->second;
		}
	}

	// Read extension of object
	if (HasTags(Unit_Champion)) {
		LoadChampionFromMem(base, hProcess, deepLoad);
	}
	else {
		// Try reading missile extension
		int addrMissileSpellInfo = 0;
		LoadMissileFromMem(base, hProcess, deepLoad);
	}
}

// Champion stuff


DWORD GameObject::spellSlotPtrs[6] = {};
BYTE  GameObject::itemListStruct[0x100] = {};

void GameObject::LoadChampionFromMem(DWORD base, HANDLE hProcess, bool deepLoad) {
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
			if (target.HasTags(Unit_Champion))
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

	missileInfo = MissileInfo::UnknownMissile;
	
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
		name = std::string(nameBuff);

	// Find static data
	auto it = MissileInfo::missiles.find(name);
	if (it != MissileInfo::missiles.end())
		missileInfo = it->second;

	// Calculate end position using range since for some skills (e.g GLOBAL skills) the end position is incorrect
	if (missileInfo != MissileInfo::UnknownMissile && !HasMissileTags(FIXED_LOCATION)) {

		// Calculate direction vector and normalize
		endPos = Vector3(endPos.x - startPos.x, 0, endPos.z - startPos.z);
		endPos = endPos.normalize();

		// Update endposition using the height of the current position
		endPos.x = endPos.x*missileInfo->range + startPos.x;
		endPos.y = position.y;
		endPos.z = endPos.z*missileInfo->range + startPos.z;
	}
}

float GameObject::GetSpeed() const
{
	return missileInfo->speed;
}

float GameObject::GetRange() const
{
	return missileInfo->range;
}

float GameObject::GetRadius() const
{
	return missileInfo->radius;
}

float GameObject::GetRadiusImpact() const
{
	return missileInfo->radiusImpact;
}

float GameObject::GetAngleImpact() const
{
	return missileInfo->angleImpact;
}

bool GameObject::HasMissileTags(const MissileTag & tag)
{
	return (missileInfo->tags & tag) == tag;
}

bool GameObject::HasMissileTags2(const MissileTag & tag, const MissileTag & tag2)
{
	int compound = tag | tag2;
	return (missileInfo->tags & compound) == compound;
}

bool GameObject::HasMissileTags3(const MissileTag & tag, const MissileTag & tag2, const MissileTag & tag3)
{
	int compound = tag | tag2 | tag3;
	return (missileInfo->tags & compound) == compound;
}

bool GameObject::EqualTags(const MissileTag & tag)
{
	return missileInfo->tags == tag;
}

bool GameObject::EqualTags2(const MissileTag & tag, const MissileTag & tag2)
{
	return missileInfo->tags == (tag | tag2);
}

bool GameObject::EqualTags3(const MissileTag & tag, const MissileTag & tag2, const MissileTag & tag3)
{
	return missileInfo->tags == (tag | tag2 | tag3);
}
