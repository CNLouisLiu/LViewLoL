#pragma once
#include <string>
#include <map>
#include "Vector.h"
#include "windows.h"

/* 
	This beautiful thing is the object encoding enum. Everything about the game object type 
	is compressed in a single integer. First we have the categories that set the bits of the
	integer from 2^6 to 2^32. The bits below 2^6 are equivalent of the id of a specific object

	Example BARON = JUNGLE | OBJECTIVE | SMITABLE + 6 is part of categories JUNGLE, OBJECTIVE
	and SMITABLE and has the object index 6. The object index must be unique or we could risk
	collisions.
	
	Use IsOfTypes to check if an object has any of the categories provided
	e.g baronObj.IsOfType(SMITABLE, JUNGLE) will return true.
*/
enum GameObjectType {
	NO_OBJ              = 0,
	WARD                = (1 << 6),
	MINION              = (1 << 7),
	JUNGLE              = (1 << 8),
	OBJECTIVE           = (1 << 9),
	DRAGON              = (1 << 10),
	SMITABLE            = (1 << 11),
	PLANT               = (1 << 12),
	PLAYER              = (1 << 13),

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

	bool           LoadFromMem(DWORD base, HANDLE hProcess, bool deepLoad = true);

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

	/* In how many seconds the object expires */
	float          expiresIn;

	/* True whenever the object is visible by the players team */
	bool           isVisible;

	/* Address in memory. Used for debug purposes */
	DWORD          address;

	/* The gameTime when this object was last visible */
	float          lastVisibleAt;

	/* Unique identifier of the object in game */
	unsigned int   objectIndex;

protected:
	BYTE* buff;

private:
	static std::map<std::string, GameObjectType>  gameObjectNameTypeDict;
};