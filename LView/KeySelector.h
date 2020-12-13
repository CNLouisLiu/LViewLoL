#pragma once
#include "Input.h"
#include <map>

/*
	This class is used to render a imgui widget for selecting keyboard keys
*/
class KeySelector {

public:
	KeySelector(const char* comboName);
	KeySelector(const char* comboName, HKey key);

	void  DrawImGuiWidget();
	HKey  GetSelectedKey();
	void  SelectKey(HKey key);

private:
	const char*                 comboName;
	int                         selectedKey = 0;

	static const int            numKeys = 18;
	static const char*          keyNames[numKeys];
	static const HKey           keyValues[numKeys];
	static std::map<HKey, int>  keyToIndex;
};