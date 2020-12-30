#pragma once
#include "Vector.h"
#include "GameObject.h"

class Missile: public GameObject {

public:
	short srcIndex;
	short destIndex;
	Vector3 startPos;
	Vector3 endPos;

	float spellWidth;
	float spellRange;
	float missileSpeed;

	void LoadFromMem(DWORD base, HANDLE hProcess, bool deepLoad = true);
};