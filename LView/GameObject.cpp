#include "GameObject.h"
#include "Utils.h"
#include "Offsets.h"

void GameObject::LoadFromMem(DWORD_PTR base, HANDLE hProcess) {

	address = base;
	Mem::Read(hProcess, base, buff, 0x3000);

	memcpy(&team, &buff[oObjTeam], sizeof(short));
	memcpy(&isVisible, &buff[oObjVisibility], sizeof(bool));
	memcpy(&position, &buff[oObjPos], sizeof(Vector3));
	memcpy(&health, &buff[oObjHealth], sizeof(float));
	memcpy(&expiryAt, &buff[oObjExpiry], sizeof(float));
	memcpy(&baseAttack, &buff[oObjBaseAtk], sizeof(float));
	memcpy(&bonusAttack, &buff[oObjBonusAtk], sizeof(float));
	memcpy(&armour, &buff[oObjArmor], sizeof(float));
	memcpy(&magicResist, &buff[oObjMagicRes], sizeof(float));

	char nameBuff[50];
	Mem::Read(hProcess, Mem::ReadPointerFromBuffer(buff, oObjChampionName), nameBuff, 50);

	if (nameBuff[0] < 65 || nameBuff[0] > 122)
		name = std::string("");
	else
		name = std::string(nameBuff);
}
