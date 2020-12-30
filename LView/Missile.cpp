#include "Missile.h"
#include "Offsets.h"
#include "Utils.h"

void Missile::LoadFromMem(DWORD base, HANDLE hProcess, bool deepLoad) {
	GameObject::LoadFromMem(base, hProcess, false);

	memcpy(&srcIndex, buff + Offsets::MissileSrcIdx, sizeof(short));
	memcpy(&destIndex, buff + Offsets::MissileDestIdx, sizeof(short));
	memcpy(&startPos, buff + Offsets::MissileStartPos, sizeof(Vector3));
	memcpy(&endPos, buff + Offsets::MissileEndPos, sizeof(Vector3));

	startPos.y += 100.f;
	endPos.y += 100.f;	

	DWORD spellInfoPtr = Mem::ReadDWORDFromBuffer(buff, 0x230);
	if (spellInfoPtr == 0)
		return;

	DWORD spellDataPtr = Mem::ReadDWORD(hProcess, spellInfoPtr + Offsets::SpellInfoSpellData);
	if (spellDataPtr == 0)
		return;

	Mem::Read(hProcess, spellDataPtr, buff, 0x500);
	memcpy(&missileSpeed, buff + 0x450, sizeof(float));
	memcpy(&spellWidth, buff + 0x458, sizeof(float));
	memcpy(&spellRange, buff + 0x3D0, sizeof(float));

	char nameBuff[50];
	Mem::Read(hProcess, Mem::ReadDWORDFromBuffer(buff, 0x0058), nameBuff, 50);
	name = std::string(nameBuff);
}