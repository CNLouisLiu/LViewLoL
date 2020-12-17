#pragma once
#undef NDEBUG
#include "ConfigSet.h"
#include <assert.h>   

class Offsets {
	
public:
	Offsets();

	static int GameTime;

	static int ObjIndex;
	static int ObjTeam;
	static int ObjTargetRadius;
	static int ObjNetworkID;
	static int ObjPos;
	static int ObjVisibility;
	static int ObjSpawnCount;
	static int ObjHealth;
	static int ObjMana;
	static int ObjMaxMana;
	static int ObjArmor;
	static int ObjMagicRes;
	static int ObjBonusMagicRes;
	static int ObjBaseAtk;
	static int ObjBonusAtk;
	static int ObjMoveSpeed;
	static int ObjSpellBook;
	static int ObjName;
	static int ObjLvl;
	static int ObjExpiry;

	static int ViewProjMatrices;
	static int Renderer;
	static int RendererWidth;
	static int RendererHeight;

	static int SpellSlotRemainingCharge;
	static int SpellSlotLevel;
	static int SpellSlotRemainingRechargeCD;
	static int SpellSlotTime;
	static int SpellSlotCD;
	static int SpellSlotDamage;
	static int SpellSlotSpellInfo;
	static int SpellSlotRemainingCD;
	static int SpellInfoSpellData;
	static int SpellDataSpellName;

	static int HeroList;
	static int MinionList;
	static int TurretList;

	static int UnitComponentInfo;
	static int UnitProperties;
	static int UnitAttackRange;
	static int UnitBoundingRadius;

	static void LoadFromConfigs();
};