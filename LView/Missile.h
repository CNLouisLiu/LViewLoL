#pragma once
#include "Vector.h"
#include "GameObject.h"
#include "MissileInfo.h"
#include <boost/python.hpp>

using namespace boost::python;

class Missile: public GameObject {

public:
	short srcIndex;
	short destIndex;
	Vector3 startPos;
	Vector3 endPos;

	MissileInfo* info;

	void LoadFromMem(DWORD base, HANDLE hProcess, bool deepLoad = true);
	
	float GetSpeed() const;
	float GetRange() const;
	float GetRadius() const;
	float GetRadiusImpact() const;
	float GetAngleImpact() const;

	bool HasMissileTags(const MissileTag& tag);
	bool HasMissileTags2(const MissileTag& tag, const MissileTag& tag2);
	bool HasMissileTags3(const MissileTag& tag, const MissileTag& tag2, const MissileTag& tag3);

	bool EqualTags(const MissileTag& tag);
	bool EqualTags2(const MissileTag& tag, const MissileTag& tag2);
	bool EqualTags3(const MissileTag& tag, const MissileTag& tag2, const MissileTag& tag3);
};