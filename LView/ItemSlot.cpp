#include "ItemSlot.h"

int ItemSlot::GetId()
{
	return stats->id;
}

float ItemSlot::GetCost()
{
	return stats->cost;
}

float ItemSlot::GetMovementSpeed()
{
	return stats->movementSpeed;
}

float ItemSlot::GetHealth()
{
	return stats->health;
}

float ItemSlot::GetCrit()
{
	return stats->crit;
}

float ItemSlot::GetAbilityPower()
{
	return stats->abilityPower;
}

float ItemSlot::GetMana()
{
	return stats->mana;
}

float ItemSlot::GetArmour()
{
	return stats->armour;
}

float ItemSlot::GetMagicResist()
{
	return stats->magicResist;
}

float ItemSlot::GetPhysicalDamage()
{
	return stats->physicalDamage;
}

float ItemSlot::GetAttackSpeed()
{
	return stats->attackSpeed;
}

float ItemSlot::GetLifeSteal()
{
	return stats->lifeSteal;
}

float ItemSlot::GetHpRegen()
{
	return stats->hpRegen;
}

float ItemSlot::GetMovementSpeedPercent()
{
	return stats->movementSpeed;
}
