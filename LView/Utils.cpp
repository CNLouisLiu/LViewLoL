#include "Utils.h"
#include <algorithm>
#include <cmath>
#include <ctime>

DWORD Mem::ReadDWORD(HANDLE hProcess, DWORD addr) {
	DWORD_PTR ptr = NULL;
	SIZE_T bytesRead = 0;

	ReadProcessMemory(hProcess, (DWORD*)addr, &ptr, 4, &bytesRead);

	return ptr;
}


void Mem::Read(HANDLE hProcess, DWORD addr, void* structure, int size) {
	SIZE_T bytesRead = 0;

	ReadProcessMemory(hProcess, (DWORD*)addr, structure, size, &bytesRead);
}

DWORD Mem::ReadDWORDFromBuffer(void* buff, int position) {
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

bool Character::ContainsOnlyASCII(const char* buff, int maxSize) {
	for (int i = 0; i < maxSize; ++i) {
		if (buff[i] == 0)
			return true;
		if ((unsigned char)buff[i] > 127)
			return false;
	}
	return true;
}

std::string Character::ToLower(std::string str)
{
	std::string strLower;
	strLower.resize(str.size());

	std::transform(str.begin(),
		str.end(),
		strLower.begin(),
		::tolower);

	return strLower;
}

std::string Character::Format(const char* c, const char* args...) {
	char buff[200];
	sprintf_s(buff, c, args);

	return std::string(buff);
}

std::string Character::RandomString(const int len) {

	std::string tmp_s;
	static const char alphanum[] =
		"0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";

	srand((unsigned int)time(0));
	tmp_s.reserve(len);

	for (int i = 0; i < len; ++i)
		tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];


	return tmp_s;
}


float League::EffectiveHP(float health, float armour) {
	return (1.f + armour / 100.f) * health;
}

float League::EffectiveDamage(float damage, float armour)
{
	if (armour >= 0)
		return damage * 100.f / (100.f + armour);
	return damage * (2.f - (100.f/(100.f - armour)));
}

