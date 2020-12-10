#pragma once
#include <string>
#include "Vector.h"
#include "windows.h"

class GameObject {

public:
	GameObject() { buff = new BYTE[0x3000]; }
	~GameObject() { delete[] buff; }

	void         LoadFromMem(DWORD_PTR base, HANDLE hProcess);

	float        health;
	float        baseAttack;
	float        bonusAttack;
	float        armour;
	float        magicResist;

	/* Team of the object 100 = Blue, 200 = Red, 300 = Jungle */
	short        team;

	/* When the object expires (GameTime). Used for wards/shaco boxes etc */
	float        expiryAt;

	/* True whenever the object is visible by the players team */
	bool         isVisible;

	std::string  name;
	Vector3      position;
	
	/* Address in memory. Used for debug purposes */
	DWORD        address;

protected:
	BYTE* buff;
};