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

	// Read name
	char nameBuff[50];
	Mem::Read(hProcess, Mem::ReadDWORD(hProcess, spellDataPtr + 0x0058), nameBuff, 50);
	name = std::string(nameBuff);

	// Find static data
	auto it = MissileInfo::missiles.find(name);
	if (it != MissileInfo::missiles.end())
		info = it->second;
	else
		info = MissileInfo::missiles["Unknown"];

	// Calculate end position using range since for some skills (e.g GLOBAL skills) the end position is incorrect
	if (info != nullptr && !HasMissileTags(FIXED_LOCATION)) {

		// Calculate direction vector and normalize
		endPos = Vector3(endPos.x - startPos.x, 0, endPos.z - startPos.z);
		endPos.normalize();

		// Update endposition using the height of the current position
		endPos.x = endPos.x*info->range + startPos.x;
		endPos.y = position.y;
		endPos.z = endPos.z*info->range + startPos.z;
	}
}

float Missile::GetSpeed() const
{
	return info->speed;
}

float Missile::GetRange() const
{
	return info->range;
}

float Missile::GetRadius() const
{
	return info->radius;
}

float Missile::GetRadiusImpact() const
{
	return info->radiusImpact;
}

float Missile::GetAngleImpact() const
{
	return info->angleImpact;
}

bool Missile::HasMissileTags(const MissileTag & tag)
{
	return (info->tags & tag) == tag;
}

bool Missile::HasMissileTags2(const MissileTag & tag, const MissileTag & tag2)
{
	int compound = tag | tag2;
	return (info->tags & compound) == compound;
}

bool Missile::HasMissileTags3(const MissileTag & tag, const MissileTag & tag2, const MissileTag & tag3)
{
	int compound = tag | tag2 | tag3;
	return (info->tags & compound) == compound;
}

bool Missile::EqualTags(const MissileTag & tag)
{
	return info->tags == tag;
}

bool Missile::EqualTags2(const MissileTag & tag, const MissileTag & tag2)
{
	return info->tags == (tag | tag2);
}

bool Missile::EqualTags3(const MissileTag & tag, const MissileTag & tag2, const MissileTag & tag3)
{
	return info->tags == (tag | tag2 | tag3);
}
