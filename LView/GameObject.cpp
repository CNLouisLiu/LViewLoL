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

bool GameObject::IsOfTypes(GameObjectType type1) {
	return (type & type1) == type1;
}

bool GameObject::IsOfTypes(GameObjectType type1, GameObjectType type2) {
	GameObjectType compoundType = (GameObjectType)(type1 | type2);
	return (type & compoundType) == compoundType;
}

bool GameObject::IsOfTypes(GameObjectType type1, GameObjectType type2, GameObjectType type3) {
	GameObjectType compoundType = (GameObjectType)(type1 | type2 | type3);
	return (type & compoundType) == compoundType;
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
	Mem::Read(hProcess, base, buff, 0x3000);

	memcpy(&team, &buff[oObjTeam], sizeof(short));
	memcpy(&position, &buff[oObjPos], sizeof(Vector3));
	memcpy(&health, &buff[oObjHealth], sizeof(float));
	memcpy(&baseAttack, &buff[oObjBaseAtk], sizeof(float));
	memcpy(&bonusAttack, &buff[oObjBonusAtk], sizeof(float));
	memcpy(&armour, &buff[oObjArmor], sizeof(float));
	memcpy(&magicResist, &buff[oObjMagicRes], sizeof(float));
	memcpy(&expiresIn, &buff[oObjExpiry], sizeof(float));
	memcpy(&targetRadius, &buff[oObjTargetRadius], sizeof(float));
	memcpy(&isVisible, &buff[oObjVisibility], sizeof(bool));
	memcpy(&objectIndex, &buff[oObjIndex], sizeof(int));
	
	// Check if alive
	DWORD spawnCount;
	memcpy(&spawnCount, &buff[oObjSpawnCount], sizeof(int));
	isAlive = (spawnCount % 2 == 0);

	// Get name
	if (deepLoad) {
		char nameBuff[50];
		Mem::Read(hProcess, Mem::ReadPointerFromBuffer(buff, oObjChampionName), nameBuff, 50);

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
		memcpy(&unitComponentInfoPtr, &buff[oUnitComponentInfo], sizeof(DWORD));
		
		DWORD unitProperties = Mem::ReadPointer(hProcess, unitComponentInfoPtr + oUnitProperties);
		Mem::Read(hProcess, unitProperties, buffDeep, 0x500);
		memcpy(&gameplayRadius, &buffDeep[oUnitBoundingRadius], sizeof(float));
		memcpy(&baseAttackRange, &buffDeep[oUnitAttackRange], sizeof(float));

		if (gameplayRadius > 200.f) // When its greater than 200.f its the default value which is 65.f
			gameplayRadius = 65.f;
	}
}

float GameObject::GetAttackRange() {
	return baseAttackRange + gameplayRadius;
}

bool GameObject::IsEnemyTo(GameObject* other) {
	return this->team != other->team;
}

bool GameObject::IsAllyTo(GameObject* other) {
	return this->team == other->team;
}