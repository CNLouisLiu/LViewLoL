#pragma once
#include "Spell.h"
#include "GameObject.h"
#include "Item.h"

#include <set>
#include <boost/python.hpp>

using namespace boost::python;

class Champion : public GameObject {

public:

	Champion()
		: Q(Spell(SpellSlot::Q)),
		W(Spell(SpellSlot::W)),
		E(Spell(SpellSlot::E)),
		R(Spell(SpellSlot::R)),
		D(Spell(SpellSlot::D)),
		F(Spell(SpellSlot::F)) {
	}

	void    LoadFromMem(DWORD base, HANDLE hProcess, bool deepLoad = true) override;
	float   GetBasicAttackDamage();
	Spell*  GetSummonerSpell(SummonerSpellType type);

	bool    IsRanged();
	float   GetOnHitPhysDamage(const GameObject& target);
	float   GetOnHitMagicDamage(const GameObject& target);

	tuple   ItemsToPyTuple();

public:
	Spell         Q, W, E, R, D, F;
	Item*         items[6];

private:
	// Prealocated buffers
	DWORD   spellSlotPtrs[6];
	BYTE    itemListStruct[0x100];
};