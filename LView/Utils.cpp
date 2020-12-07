#include "Utils.h"

float Mem::ReadFloat(HANDLE hProcess, DWORD_PTR addr) {
	float val = 0.f;
	SIZE_T bytesRead = 0;

	ReadProcessMemory(hProcess, (DWORD_PTR*)addr, &val, sizeof(float), &bytesRead);

	return val;
}

DWORD_PTR Mem::ReadPointer(HANDLE hProcess, DWORD_PTR addr, bool is64Bit) {
	DWORD_PTR ptr = NULL;
	SIZE_T bytesRead = 0;

	ReadProcessMemory(hProcess, (DWORD_PTR*)addr, &ptr, (is64Bit ? 4 : 4), &bytesRead);

	return ptr;
}


void Mem::Read(HANDLE hProcess, DWORD_PTR addr, void* structure, int size) {
	SIZE_T bytesRead = 0;

	ReadProcessMemory(hProcess, (DWORD_PTR*)addr, structure, size, &bytesRead);
}

BOOL Process::IsProcessRunning(DWORD pid)
{
	HANDLE process = OpenProcess(SYNCHRONIZE, FALSE, pid);
	DWORD ret = WaitForSingleObject(process, 0);
	CloseHandle(process);
	return ret == WAIT_TIMEOUT;
}