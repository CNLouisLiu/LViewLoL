#pragma once
#include <string>
#include <map>
#include "Vector.h"
#include "windows.h"

enum GameObjectType {
	NO_OBJ              = 0,
	WARD                = (1 << 6),
	MINION              = (1 << 7),
	JUNGLE              = (1 << 8),
	OBJECTIVE           = (1 << 9),
	DRAGON              = (1 << 10),
	SMITABLE            = (1 << 11),
	PLANT               = (1 << 12),

	WARD_PINK           = WARD + 1,

	MINION_CANNON       = MINION + 3,
	MINION_MELEE        = MINION + 4,
	MINION_RANGED       = MINION + 5,

	BARON               = JUNGLE | OBJECTIVE | SMITABLE + 6,
	HERALD              = JUNGLE | OBJECTIVE | SMITABLE + 7,
	
	DRAGON_FIRE         = JUNGLE | OBJECTIVE | DRAGON | SMITABLE + 8,
	DRAGON_MOUNTAIN     = JUNGLE | OBJECTIVE | DRAGON | SMITABLE + 9,
	DRAGON_OCEAN        = JUNGLE | OBJECTIVE | DRAGON | SMITABLE + 10,
	DRAGON_AIR          = JUNGLE | OBJECTIVE | DRAGON | SMITABLE + 11,
	DRAGON_ELDER        = JUNGLE | OBJECTIVE | DRAGON | SMITABLE + 12,

	KRUG                = JUNGLE | SMITABLE + 13,
	KRUG_MEDIUM         = JUNGLE + 14,
	KRUG_SMALL          = JUNGLE + 15,

	WOLF                = JUNGLE | SMITABLE + 16,
	WOLF_SMALL          = JUNGLE + 17,

	RAZORBEAK           = JUNGLE | SMITABLE + 18,
	RAZORBEAK_SMALL     = JUNGLE + 19,

	GROMP               = JUNGLE | SMITABLE + 20,
	BLUE                = JUNGLE | SMITABLE + 21,
	RED                 = JUNGLE | SMITABLE + 22,
	CRAB                = JUNGLE | SMITABLE + 23,
	PLANT_EXPLOSION     = JUNGLE | PLANT + 24, 
	PLANT_HEALING       = JUNGLE | PLANT + 25,
	PLANT_VISION        = JUNGLE | PLANT + 26,
};

class GameObject {

public:
	GameObject() { buff = new BYTE[0x3000]; }
	~GameObject() { delete[] buff; }

	void           LoadFromMem(DWORD_PTR base, HANDLE hProcess);

	bool           IsOfTypes(GameObjectType type1);
	bool           IsOfTypes(GameObjectType type1, GameObjectType type2);
	bool           IsOfTypes(GameObjectType type1, GameObjectType type2, GameObjectType type3);

	float          health;
	float          baseAttack;
	float          bonusAttack;
	float          armour;
	float          magicResist;

	std::string    name;
	Vector3        position;
	GameObjectType type;

	/* How close does the mouse cursor have to be to select the object */
	float          targetRadius;

	/* Team of the object 100 = Blue, 200 = Red, 300 = Jungle */
	short          team;

	/* When the object expires (GameTime). Used for wards/shaco boxes etc */
	float          expiryAt;

	/* True whenever the object is visible by the players team */
	bool           isVisible;

	/* Address in memory. Used for debug purposes */
	DWORD          address;

protected:
	BYTE* buff;

private:
	static std::map<std::string, GameObjectType>  gameObjectNameTypeDict;
};