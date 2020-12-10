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

	short        team;
	float        expiryAt;
	bool         isVisible;
	std::string  name;
	Vector3      position;
	DWORD        address;

protected:
	BYTE* buff;
};