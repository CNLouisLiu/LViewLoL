#pragma once
#include "SpellInfo.h"

/// Used to expose spell information to python
class SpellInterface {

	virtual bool        HasSpellFlags(SpellFlags flags) const = 0;
	virtual bool        EqualSpellFlags(SpellFlags flags) const = 0;
	virtual float       GetSpeed() const = 0;
	virtual float       GetCastRange() const = 0;
	virtual float       GetWidth() const = 0;
	virtual float       GetCastRadius() const = 0;
	virtual float       GetDelay() const = 0;
	virtual float       GetHeight() const = 0;
	virtual float       GetTravelTime() const = 0;
	virtual std::string GetIcon() const = 0;
};