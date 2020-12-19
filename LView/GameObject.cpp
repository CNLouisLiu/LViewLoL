#include "GameObject.h"
#include "Utils.h"
#include "Offsets.h"

std::map<std::string, GameObjectType>  GameObject::gameObjectNameTypeDict = {

	// Minions
	{"SRU_OrderMinionMelee",     GameObjectType::MINION_MELEE},
	{"SRU_OrderMinionRanged",    GameObjectType::MINION_RANGED},
	{"SRU_OrderMinionSiege",     GameObjectType::MINION_CANNON},
	{"SRU_ChaosMinionMelee",     GameObjectType::MINION_MELEE},
	{"SRU_ChaosMinionRanged",    GameObjectType::MINION_RANGED},
	{"SRU_ChaosMinionSiege",     GameObjectType::MINION_CANNON},

	// Jungle objectives
	{"SRU_Baron",                GameObjectType::BARON},
	{"SRU_RiftHerald",           GameObjectType::HERALD},
	{"SRU_Dragon_Fire",          GameObjectType::DRAGON_FIRE},
	{"SRU_Dragon_Earth",         GameObjectType::DRAGON_MOUNTAIN},
	{"SRU_Dragon_Water",         GameObjectType::DRAGON_OCEAN},
	{"SRU_Dragon_Air",           GameObjectType::DRAGON_AIR},
	{"SRU_Dragon_Elder",         GameObjectType::DRAGON_ELDER},

	// Jungle mobs
	{"SRU_Krug",                 GameObjectType::KRUG},
	{"SRU_KrugMini",             GameObjectType::KRUG_MEDIUM},
	{"SRU_KrugMiniMini",         GameObjectType::KRUG_SMALL},
	{"SRU_Murkwolf",             GameObjectType::WOLF},
	{"SRU_Razorbeak",            GameObjectType::RAZORBEAK},
	{"SRU_Gromp",                GameObjectType::GROMP},
	{"SRU_Blue",                 GameObjectType::BLUE},
	{"SRU_Red",                  GameObjectType::RED},
	{"Sru_Crab",                 GameObjectType::CRAB},

	{"SRU_MurkwolfMini",         GameObjectType::WOLF_SMALL},
	{"SRU_RazorbeakMini",        GameObjectType::RAZORBEAK_SMALL},

	// Plants
	{"SRU_Plant_Satchel",        GameObjectType::PLANT_EXPLOSION },
	{"SRU_Plant_Vision",         GameObjectType::PLANT_VISION},
	{"SRU_Plant_Health",         GameObjectType::PLANT_HEALING},

	// Wards
	{"YellowTrinket",            GameObjectType::WARD},
	{"SightWard",                GameObjectType::WARD},
	{"JammerDevice",             GameObjectType::WARD_PINK},

	// Shits
	{"ShacoBox",                 GameObjectType::SHACO_BOX},
	{"TeemoMushroom",            GameObjectType::TEEMO_MUSHROOM},
	{"Shaco",                    GameObjectType::SHACO_CLONE},
	{"Leblanc",                  GameObjectType::LEBLANC_CLONE},
	
};

bool GameObject::IsOfOneType(const GameObjectType& type1) const {
	return (type & type1) == type1;
}

bool GameObject::IsOfTwoTypes(const GameObjectType& type1, const GameObjectType& type2)  const {
	GameObjectType compoundType = (GameObjectType)(type1 | type2);
	return (type & compoundType) == compoundType;
}

bool GameObject::IsOfThreeTypes(const GameObjectType& type1, const GameObjectType& type2, const GameObjectType& type3) const {
	GameObjectType compoundType = (GameObjectType)(type1 | type2 | type3);
	return (type & compoundType) == compoundType;
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
	memcpy(&targetRadius,               &buff[Offsets::ObjTargetRadius],           sizeof(float));
	memcpy(&isVisible,                  &buff[Offsets::ObjVisibility],             sizeof(bool));
	memcpy(&objectIndex,                &buff[Offsets::ObjIndex],                  sizeof(int));
	memcpy(&crit,                       &buff[Offsets::ObjCrit],                   sizeof(float));
	memcpy(&critMulti,                  &buff[Offsets::ObjCritMulti],              sizeof(float));
	memcpy(&abilityPower,               &buff[Offsets::ObjAbilityPower],           sizeof(float));
	memcpy(&bonusAbilityPower,          &buff[Offsets::ObjBonusAbilityPower],      sizeof(float));
	memcpy(&atkSpeedMulti,              &buff[Offsets::ObjAtkSpeedMulti],          sizeof(float));

	// Check if alive
	DWORD spawnCount;
	memcpy(&spawnCount, &buff[Offsets::ObjSpawnCount], sizeof(int));
	isAlive = (spawnCount % 2 == 0);

	// Get name
	if (deepLoad) {
		char nameBuff[50];
		Mem::Read(hProcess, Mem::ReadPointerFromBuffer(buff, Offsets::ObjName), nameBuff, 50);

		if (ContainsOnlyASCII(nameBuff, 50))
			name = std::string(nameBuff);
		else
			name = std::string("");

		auto it = gameObjectNameTypeDict.find(name);
		if (it == gameObjectNameTypeDict.end())
			type = GameObjectType::NO_OBJ;
		else
			type = it->second;
	}

	if (deepLoad) {
		DWORD unitComponentInfoPtr;
		memcpy(&unitComponentInfoPtr, &buff[Offsets::UnitComponentInfo], sizeof(DWORD));
		
		DWORD unitProperties = Mem::ReadPointer(hProcess, unitComponentInfoPtr + Offsets::UnitProperties);
		Mem::Read(hProcess, unitProperties, buffDeep, sizeBuffDeep);
		memcpy(&gameplayRadius,  &buffDeep[Offsets::UnitBoundingRadius], sizeof(float));
		memcpy(&baseAttackRange, &buffDeep[Offsets::UnitAttackRange],    sizeof(float));
		memcpy(&baseAttackSpeed, &buffDeep[Offsets::UnitBaseAtkSpeed],   sizeof(float));
		memcpy(&maxAttackSpeed,  &buffDeep[Offsets::UnitMaxAtkSpeed],    sizeof(float));

		if (gameplayRadius > 200.f) // When its greater than 200.f its the default value which is 65.f
			gameplayRadius = 65.f;
	}
}

float GameObject::GetAttackRange()  const {
	return baseAttackRange + gameplayRadius;
}

bool GameObject::IsEnemyTo(const GameObject& other) const {
	return this->team != other.team;
}

bool GameObject::IsAllyTo(const GameObject& other) const {
	return this->team == other.team;
}