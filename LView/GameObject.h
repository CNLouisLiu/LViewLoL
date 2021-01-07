#pragma once
#include <string>
#include <map>
#include "Vector.h"
#include "windows.h"
#include "MemoryLoadable.h"
#include "UnitInfo.h"
#include "MissileInfo.h"
#include "Item.h"

#include <boost/python/suite/indexing/map_indexing_suite.hpp>
#include <boost/python.hpp>

using namespace boost::python;

class GameObject: MemoryLoadable{

public:
	// Base
	void           LoadFromMem(DWORD base, HANDLE hProcess, bool deepLoad = true);

	bool           HasTags(const UnitTag& type1) const;
	bool           HasTags2(const UnitTag& type1, const UnitTag& type2) const;
	bool           HasTags3(const UnitTag& type1, const UnitTag& type2, const UnitTag& type3) const;

	float          GetAcquisitionRadius() const;
	float          GetSelectionRadius() const;
	float          GetPathingRadius() const;
	float          GetGameplayRadius() const;

	float          GetBasicAttackMissileSpeed()  const;
	float          GetBasicAttackWindup() const;

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

public:

	float          health;
	float          baseAttack;
	float          bonusAttack;
	float          armour;
	float          magicResist;
	float          crit;
	float          critMulti;
	float          abilityPower;
	float          atkSpeedMulti;
	float          movementSpeed;
	float          duration;

	short          objectIndex;
	short          team;
	
	bool           isVisible;
	bool           isAlive;
	float          lastVisibleAt;

	
	std::string    name;
	Vector3        position;
	Vector3        previousPosition;

	DWORD          networkId;
	DWORD          address;

	object         GetPythonUnitInfo();
	UnitInfo*      unitInfo;

protected:
	static const SIZE_T sizeBuff = 0x4000;
	static const SIZE_T sizeBuffDeep = 0x1000;

	static BYTE   buff[sizeBuff];
	static BYTE   buffDeep[sizeBuffDeep];

	// Champion stuff
public:
	void    LoadChampionFromMem(DWORD base, HANDLE hProcess, bool deepLoad = true);
	float   GetBasicAttackDamage();
	Spell*  GetSummonerSpell(SummonerSpellType type);

	bool    IsRanged();
	float   GetOnHitPhysDamage(const GameObject& target);
	float   GetOnHitMagicDamage(const GameObject& target);

	tuple   ItemsToPyTuple();

	Spell         Q = Spell(SpellSlot::Q);
	Spell         W = Spell(SpellSlot::W);
	Spell         E = Spell(SpellSlot::E);
	Spell         R = Spell(SpellSlot::R);
	Spell         D = Spell(SpellSlot::D);
	Spell         F = Spell(SpellSlot::F);

	DWORD         level;
	Item*         items[6];
private:
	static DWORD  spellSlotPtrs[6];
	static BYTE   itemListStruct[0x100];

	// Missile stuff
public:
	void LoadMissileFromMem(DWORD base, HANDLE hProcess, bool deepLoad = true);

	float GetSpeed() const;
	float GetRange() const;
	float GetRadius() const;
	float GetRadiusImpact() const;
	float GetAngleImpact() const;

	bool HasMissileTags(const MissileTag& tag);
	bool HasMissileTags2(const MissileTag& tag, const MissileTag& tag2);
	bool HasMissileTags3(const MissileTag& tag, const MissileTag& tag2, const MissileTag& tag3);

	bool EqualTags(const MissileTag& tag);
	bool EqualTags2(const MissileTag& tag, const MissileTag& tag2);
	bool EqualTags3(const MissileTag& tag, const MissileTag& tag2, const MissileTag& tag3);

	short srcIndex;
	short destIndex;
	Vector3 startPos;
	Vector3 endPos;

	MissileInfo* missileInfo;
};