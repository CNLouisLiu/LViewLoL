
#pragma once
#include <map>

// Generated automatically
struct Item {

public:
	int id;
	float cost;
	float movementSpeed;
	float health;
	float crit;
	float abilityPower;
	float mana;
	float armour;
	float magicResist;
	float physicalDamage;
	float attackSpeed;
	float lifeSteal;
	float hpRegen;
	float movementSpeedPercent;

public:	
	static std::map<int, Item*> items;
};
