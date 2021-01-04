#pragma once
#include "Spell.h"
#include <map>

enum MissileTag {
	NONE              = 0,
	COLLIDE_WINDWALL  = 1,
	COLLIDE_MOB       = 2,
	COLLIDE_CHAMPION  = 4,
	COLLIDE_WALL      = 8,
	COLLIDE_STRUCTURE = 16,

	FIXED_LOCATION    = 32,
	TARGETED          = 64,

	PIERCE_MOB        = 128,
	PIERCE_CHAMPION   = 256,

	PIERCE_ALL        = PIERCE_MOB | PIERCE_CHAMPION,
	COLLIDE_GENERIC   = COLLIDE_MOB | COLLIDE_CHAMPION | COLLIDE_WINDWALL
};

class MissileInfo{

public:
	MissileInfo* withName(const char* x) {
		name = x;
		return this;
	}

	MissileInfo* withSpeed(float x) {
		speed = x;
		return this;
	}

	MissileInfo* withRange(float x) {
		range = x;
		return this;
	}

	MissileInfo* withRadius(float x) {
		radius = x;
		return this;
	}

	MissileInfo* withRadiusImpact(float x) {
		radiusImpact = x;
		return this;
	}

	MissileInfo* withFlags(int x) {
		tags = (MissileTag)x;
		return this;
	}

	MissileInfo* withAngleImpact(float x) {
		angleImpact = x;
		return this;
	}

public:
	const char* name           = "";

	float speed                = 0.f;
	float range                = 0.f;
	float radius               = 0.f;
	float radiusImpact         = 0.f;
	float angleImpact          = 0.f;
				               
	MissileTag tags = MissileTag::NONE;

	static std::map<std::string, MissileInfo*> missiles;
};