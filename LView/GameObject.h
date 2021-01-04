#pragma once
#include <string>
#include <map>
#include "Vector.h"
#include "windows.h"
#include "MemoryLoadable.h"
#include "UnitInfo.h"

#include <boost/python/suite/indexing/map_indexing_suite.hpp>
#include <boost/python.hpp>

using namespace boost::python;

class GameObject: MemoryLoadable {

public:
	void           LoadFromMem(DWORD base, HANDLE hProcess, bool deepLoad = true);

	bool           HasTags(const UnitTag& type1) const;
	bool           HasTags2(const UnitTag& type1, const UnitTag& type2) const;
	bool           HasTags3(const UnitTag& type1, const UnitTag& type2, const UnitTag& type3) const;

	float          GetAcquisitionRadius() const;
	float          GetSelectionRadius() const;
	float          GetPathingRadius() const;
	float          GetGameplayRadius() const;
	float          GetBasicAttackMissileSpeed()  const;

	float          GetAttackSpeedRatio() const;
	float          GetBaseMovementSpeed() const;
	float          GetBaseAttackSpeed() const;
	float          GetBaseAttackRange() const;
	float          GetAttackRange() const;
	float          GetHpBarHeight() const;

	bool           IsEnemyTo(const GameObject& other) const;
	bool           IsAllyTo(const GameObject& other) const;
	bool           IsEqualTo(const GameObject& other) const;
	bool           IsNotEqualTo(const GameObject& other) const;

	object         GetPythonUnitInfo();

	float          health;
	float          baseAttack;
	float          bonusAttack;
	float          armour;
	float          magicResist;
	float          crit;
	float          critMulti;
	float          abilityPower;
	float          bonusAbilityPower;
	float          atkSpeedMulti;

	bool           isAlive;

	std::string    name;

	Vector3        position;

	/* Team of the object 100 = Blue, 200 = Red, 300 = Jungle */
	short          team;

	/* In how many seconds the object expires */
	float          duration;

	/* True whenever the object is visible by the players team */
	bool           isVisible;

	/* Address in memory. Used for debug purposes */
	DWORD          address;

	/* The gameTime when this object was last visible */
	float          lastVisibleAt;

	/* Unique identifier of the object in game */
	short            objectIndex;

	DWORD            networkId;

	UnitInfo*        info;

protected:
	static const SIZE_T sizeBuff = 0x3000;
	static const SIZE_T sizeBuffDeep = 0x1000;

	static BYTE buff[sizeBuff];
	static BYTE buffDeep[sizeBuffDeep];
};