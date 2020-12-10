#pragma once
#include "Spell.h"
#include "GameObject.h"

class Champion : public GameObject {

public:

	Champion()
		: Q(Spell(SpellType::Q)),
		W(Spell(SpellType::W)),
		E(Spell(SpellType::E)),
		R(Spell(SpellType::R)),
		D(Spell(SpellType::D)),
		F(Spell(SpellType::F)) {
	}

	void    LoadFromMem(DWORD_PTR base, HANDLE hProcess);
	float   GetBasicAttackDamage();

public:
	float   currentHealth;

	Spell   Q, W, E, R, D, F;

private:
	DWORD   spellSlotPtrs[6];
};