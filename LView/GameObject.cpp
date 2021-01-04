#include "GameObject.h"
#include "Utils.h"
#include "Offsets.h"

BYTE GameObject::buff[GameObject::sizeBuff] = {};
BYTE GameObject::buffDeep[GameObject::sizeBuffDeep] = {};

bool GameObject::HasTags(const UnitTag& type1) const {
	return info->tags.test(type1);
}

bool GameObject::HasTags2(const UnitTag& type1, const UnitTag& type2)  const {
	return info->tags.test(type1) && info->tags.test(type2);
}

bool GameObject::HasTags3(const UnitTag& type1, const UnitTag& type2, const UnitTag& type3) const {
	return info->tags.test(type1) && info->tags.test(type2) && info->tags.test(type3);
}

bool GameObject::IsEqualTo(const GameObject& other) const {
	return this->objectIndex == other.objectIndex;
}

bool GameObject::IsNotEqualTo(const GameObject& other) const {
	return this->objectIndex != other.objectIndex;
}

bool ContainsOnlyASCII(const char* buff, int maxSize) {
	for (int i = 0; i < maxSize; ++i) {
		if (buff[i] == 0)
			return true;
		if ((unsigned char)buff[i] > 127)
			return false;
	}
	return true;
}

void GameObject::LoadFromMem(DWORD base, HANDLE hProcess, bool deepLoad) {

	address = base;
	Mem::Read(hProcess, base, buff, sizeBuff);

	memcpy(&team,                       &buff[Offsets::ObjTeam],                   sizeof(short));
	memcpy(&position,                   &buff[Offsets::ObjPos],                    sizeof(Vector3));
	memcpy(&health,                     &buff[Offsets::ObjHealth],                 sizeof(float));
	memcpy(&baseAttack,                 &buff[Offsets::ObjBaseAtk],                sizeof(float));
	memcpy(&bonusAttack,                &buff[Offsets::ObjBonusAtk],               sizeof(float));
	memcpy(&armour,                     &buff[Offsets::ObjArmor],                  sizeof(float));
	memcpy(&magicResist,                &buff[Offsets::ObjMagicRes],               sizeof(float));
	memcpy(&duration,                   &buff[Offsets::ObjExpiry],                 sizeof(float));
	memcpy(&isVisible,                  &buff[Offsets::ObjVisibility],             sizeof(bool));
	memcpy(&objectIndex,                &buff[Offsets::ObjIndex],                  sizeof(short));
	memcpy(&crit,                       &buff[Offsets::ObjCrit],                   sizeof(float));
	memcpy(&critMulti,                  &buff[Offsets::ObjCritMulti],              sizeof(float));
	memcpy(&abilityPower,               &buff[Offsets::ObjAbilityPower],           sizeof(float));
	memcpy(&bonusAbilityPower,          &buff[Offsets::ObjBonusAbilityPower],      sizeof(float));
	memcpy(&atkSpeedMulti,              &buff[Offsets::ObjAtkSpeedMulti],          sizeof(float));
	memcpy(&networkId,                  &buff[Offsets::ObjNetworkID],              sizeof(DWORD));
	
	// Check if alive
	DWORD spawnCount;
	memcpy(&spawnCount, &buff[Offsets::ObjSpawnCount], sizeof(int));
	isAlive = (spawnCount % 2 == 0);

	// Get name
	if (deepLoad) {
		char nameBuff[50];
		Mem::Read(hProcess, Mem::ReadDWORDFromBuffer(buff, Offsets::ObjName), nameBuff, 50);

		if (ContainsOnlyASCII(nameBuff, 50))
			name = std::string(nameBuff);
		else
			name = std::string("");
	}

	if (deepLoad) {
		// Get static UnitInfo
		std::string nameLower;
		nameLower.resize(name.size());

		std::transform(name.begin(),
			name.end(),
			nameLower.begin(),
			::tolower);

		auto it = UnitInfo::infos.find(nameLower);
		if (it != UnitInfo::infos.end())
			info = it->second;
		else {
			info = UnitInfo::infos["unknown"];
		}
	}
}

float GameObject::GetAcquisitionRadius() const
{
	return info->acquisitionRange;
}

float GameObject::GetSelectionRadius() const
{
	return info->selectionRadius;
}

float GameObject::GetPathingRadius() const
{
	return info->pathRadius;
}

float GameObject::GetGameplayRadius() const
{
	return info->gameplayRadius;
}

float GameObject::GetBasicAttackMissileSpeed() const
{
	return info->basicAttackMissileSpeed;
}

float GameObject::GetAttackSpeedRatio() const
{
	return info->attackSpeedRatio;
}

float GameObject::GetBaseMovementSpeed() const
{
	return info->baseMovementSpeed;
}

float GameObject::GetBaseAttackSpeed() const
{
	return info->baseAttackSpeed;
}

float GameObject::GetBaseAttackRange() const
{
	return info->baseAttackRange;
}

float GameObject::GetAttackRange()  const {
	return GetBaseAttackRange() + GetGameplayRadius();
}

float GameObject::GetHpBarHeight() const
{
	return info->healthBarHeight;
}

bool GameObject::IsEnemyTo(const GameObject& other) const {
	return this->team != other.team;
}

bool GameObject::IsAllyTo(const GameObject& other) const {
	return this->team == other.team;
}

object GameObject::GetPythonUnitInfo()
{
	return object(ptr(info));
}
