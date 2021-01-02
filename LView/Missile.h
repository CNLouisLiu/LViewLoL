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
	object GetPythonObjectInfo();
};