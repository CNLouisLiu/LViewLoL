#include "Utils.h"

ImColor Colors::White = ImColor::HSV(0.f, 0.f, 1.f);
ImColor Colors::Orange = ImColor::HSV(0.1f, 0.85f, 0.6f);
ImColor Colors::Red = ImColor::HSV(0.f, 1.f, 0.5f);

float Mem::ReadFloat(HANDLE hProcess, DWORD_PTR addr) {
	float val = 0.f;
	SIZE_T bytesRead = 0;

	ReadProcessMemory(hProcess, (DWORD_PTR*)addr, &val, sizeof(float), &bytesRead);

	return val;
}

DWORD_PTR Mem::ReadPointer(HANDLE hProcess, DWORD_PTR addr) {
	DWORD_PTR ptr = NULL;
	SIZE_T bytesRead = 0;

	ReadProcessMemory(hProcess, (DWORD_PTR*)addr, &ptr, 4, &bytesRead);

	return ptr;
}


void Mem::Read(HANDLE hProcess, DWORD_PTR addr, void* structure, int size) {
	SIZE_T bytesRead = 0;

	ReadProcessMemory(hProcess, (DWORD_PTR*)addr, structure, size, &bytesRead);
}

DWORD Mem::ReadPointerFromBuffer(void* buff, int position) {
	DWORD result;
	memcpy(&result, (char*)buff + position, 4);
	return result;
}

BOOL Process::IsProcessRunning(DWORD pid)
{
	HANDLE process = OpenProcess(SYNCHRONIZE, FALSE, pid);
	DWORD ret = WaitForSingleObject(process, 0);
	CloseHandle(process);
	return ret == WAIT_TIMEOUT;
}