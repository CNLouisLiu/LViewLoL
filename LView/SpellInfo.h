#pragma once
#include <string>
#include <map>

/// Flags of a spell/missile (they are the same thing anyway)
enum SpellFlags {

	// Flags from the game data files
	AffectAllyChampion        = 1,
	AffectEnemyChampion       = 1 << 1,
	AffectAllyLaneMinion      = 1 << 2,
	AffectEnemyLaneMinion     = 1 << 3,
	AffectAllyWard            = 1 << 4,
	AffectEnemyWard           = 1 << 5,
	AffectAllyTurret          = 1 << 6,
	AffectEnemyTurret         = 1 << 7,
	AffectAllyInhibs          = 1 << 8,
	AffectEnemyInhibs         = 1 << 9,
	AffectAllyNonLaneMinion   = 1 << 10,
	AffectJungleMonster       = 1 << 11,
	AffectEnemyNonLaneMinion  = 1 << 12,
	AffectAlwaysSelf          = 1 << 13,
	AffectNeverSelf           = 1 << 14,

	// Custom flags set by us. These flags cant be unpacked from the game files (exception Targeted flag).
	CollideLaneMinion         = 1 << 16,
	CollideNonLaneMinion      = 1 << 17,
	CollideWindwall           = 1 << 18,
	CollideChampion           = 1 << 19,
	CollideJungleMonster      = 1 << 20,
						      
	ProjectedDestination      = 1 << 22,

	CollideMob                = CollideLaneMinion     | CollideNonLaneMinion     | CollideJungleMonster,
	CollideGeneric            = CollideMob            | CollideChampion          | CollideWindwall,


	AffectAllyMob             = AffectAllyLaneMinion  | AffectAllyNonLaneMinion,
	AffectEnemyMob            = AffectEnemyLaneMinion | AffectEnemyNonLaneMinion | AffectJungleMonster,
	AffectAllyGeneric         = AffectAllyMob         | AffectAllyChampion,
	AffectEnemyGeneric        = AffectEnemyMob        | AffectEnemyChampion,
};

/// Static data of a spell that we load from disk
class SpellInfo {

public:
	SpellInfo* AddFlags(SpellFlags flags);
	SpellInfo* SetImpactRadius(float radius);
	SpellInfo* SetImpactAngle(float angle);
public:
	// Values from game's data files
	std::string name;
	std::string icon;

	SpellFlags flags;
	float delay;
	float range;
	float radius;
	float height;
	float speed;

	// Custom values set by us
	float impactRadius;
	float impactAngle;
};

