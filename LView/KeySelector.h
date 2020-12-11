#pragma once
#include "Input.h"
#include <map>

class KeySelector {

public:
	KeySelector(const char* comboName, HKey key);

	void Draw();
	HKey  GetKey();

private:
	const char*                 comboName;
	int                         selectedKey = 0;

	static const int            numKeys = 3;
	static const char*          keyNames[numKeys];
	static const HKey           keyValues[numKeys];
	static std::map<HKey, int>  keyToIndex;
};