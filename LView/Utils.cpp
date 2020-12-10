#include "Utils.h"
#include <cmath>

ImColor Colors::White  = ImColor::HSV(0.f, 0.f, 1.f);
ImColor Colors::Orange = ImColor::HSV(0.1f, 0.85f, 0.6f);
ImColor Colors::Red    = ImColor::HSV(0.f, 1.f, 0.5f);
ImColor Colors::Blue   = ImColor::HSV(0.65f, 1.f, 1.f);
ImColor Colors::Cyan   = ImColor::HSV(0.51f, 1.f, 1.f);

DWORD Mem::ReadPointer(HANDLE hProcess, DWORD addr) {
	DWORD_PTR ptr = NULL;
	SIZE_T bytesRead = 0;

	ReadProcessMemory(hProcess, (DWORD*)addr, &ptr, 4, &bytesRead);

	return ptr;
}


void Mem::Read(HANDLE hProcess, DWORD addr, void* structure, int size) {
	SIZE_T bytesRead = 0;

	ReadProcessMemory(hProcess, (DWORD*)addr, structure, size, &bytesRead);
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

float League::Distance(Vector3 first, Vector3 second) {
	return sqrt(pow(first.x - second.x, 2) + pow(first.y - second.y, 2) + pow(first.z - second.z, 2));
}

float League::EffectiveHP(float health, float armour) {
	return (1.f + armour / 100.f) * health;
}