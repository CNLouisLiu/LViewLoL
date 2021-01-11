#include "SpellInfo.h"


SpellInfo * SpellInfo::AddFlags(SpellFlags flags)
{
	this->flags = (SpellFlags)(this->flags | flags);
	return this;
}

SpellInfo * SpellInfo::SetImpactRadius(float radius)
{
	impactRadius = radius;
	return this;
}

SpellInfo * SpellInfo::SetImpactAngle(float angle)
{
	impactAngle = angle;
	return this;
}