#include "Missile.h"
#include "Offsets.h"

void Missile::LoadFromMem(DWORD base, HANDLE hProcess, bool deepLoad) {
	GameObject::LoadFromMem(base, hProcess, false);

	memcpy(&srcIndex, buff + Offsets::MissileSrcIdx, sizeof(short));
	memcpy(&destIndex, buff + Offsets::MissileDestIdx, sizeof(short));
	memcpy(&startPos, buff + Offsets::MissileStartPos, sizeof(Vector3));
	memcpy(&endPos, buff + Offsets::MissileEndPos, sizeof(Vector3));

	startPos.y += 100.f;
	endPos.y += 100.f;	
}