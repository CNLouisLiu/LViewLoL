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
};