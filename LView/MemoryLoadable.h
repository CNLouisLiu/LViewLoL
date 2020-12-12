#pragma once
#include "windows.h"

class MemoryLoadable {

	virtual void LoadFromMem(DWORD base, HANDLE hProcess, bool deepLoad = true) = 0;
};