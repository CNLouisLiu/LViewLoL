#include "SpellInfo.h"

std::map<std::string, SpellFlags> SpellInfo::FlagMapping = {
	{std::string("CollideLaneMinion"), CollideLaneMinion},
	{std::string("CollideNonLaneMinion"), CollideNonLaneMinion},
	{std::string("CollideWindwall"), CollideWindwall},
	{std::string("CollideChampion"), CollideChampion},
	{std::string("CollideJungleMonster"), CollideJungleMonster},

	{std::string("Targeted"), Targeted},
	{std::string("FixedDestination"), FixedDestination},

	{std::string("CollideMob"), CollideMob},
	{std::string("CollideGeneric"), CollideGeneric},
};

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

void SpellInfo::SetFlag(std::string& flag)
{
	auto it = FlagMapping.find(flag);
	if (it != FlagMapping.end())
		flags = (SpellFlags)(flags | it->second);
}
