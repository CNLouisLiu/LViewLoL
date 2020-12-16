#include "Utils.h"
#include <cmath>

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

float League::Distance(const Vector2& first,const Vector2& second) {
	return sqrt(pow(first.x - second.x, 2) + pow(first.y - second.y, 2));
}

float League::Distance(const Vector3& first, const Vector3& second) {
	return sqrt(pow(first.x - second.x, 2) + pow(first.y - second.y, 2) + pow(first.z - second.z, 2));
}

float League::EffectiveHP(float health, float armour) {
	return (1.f + armour / 100.f) * health;
}

float League::Clamp(float val, float lo, float hi) {
	return (val < lo) ? lo : (hi < val) ? hi : val;
}