#pragma once
#include "ItemInfo.h"

class ItemSlot {

public:
	int GetId();
	float GetCost();
	float GetMovementSpeed();
	float GetHealth();
	float GetCrit();
	float GetAbilityPower();
	float GetMana();
	float GetArmour();
	float GetMagicResist();
	float GetPhysicalDamage();
	float GetAttackSpeed();
	float GetLifeSteal();
	float GetHpRegen();
	float GetMovementSpeedPercent();

public:
	bool      isEmpty = true;
	int       slot    = 0;
	ItemInfo* stats   = nullptr;
};