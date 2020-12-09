#pragma once

#define GAME_OBJECT_ARRAY_SIZE 3000

#define oGameTime 0x34F22F0 // 				F3 0F 11 05 ? ? ? ? 8B 49 // dword_[offset]

//CObject
#define oObjIndex 0x20
#define oObjTeam 0x4C
#define oObjNetworkID 0xCC 
#define oObjPos 0x1D8 
#define oObjVisibility 0x270
#define oObjHealth 0xD98 
#define oObjMana 0x298
#define oObjMaxMana 0x2A8
#define oObjArmor 0x1278 
#define oObjMagicRes 0x1280 
#define oObjBonusMagicRes 0x1284 
#define oObjBaseAtk 0x1250
#define oObjBonusAtk 0x11D0 
#define oObjMoveSpeed 0x1290 
#define oObjAtkRange 0x1298 
#define oObjBuffMgr 0x213C
#define oObjSpellBook 0x2B60  
#define oObjChampionName 0x2F44
#define oObjLevel 0x369C // 10.24 me
#define oObjSourceIndex 0x290
#define oObjPerk1 0x3888 // 8D 8E ? ? ? ? E8 ? ? ? ? 8B CE E8 ? ? ? ? A1 // esi+[offset]h // 81 EC ? ? ? ? A1 ? ? ? ? 33 C4 89 84 24 ? ? ? ? 53 8B 9C 24 ? ? ? ? 56 8B F1 88 5C 24 0C // fn + 19F
#define oObjPerk2 0x2C8 // 8D 8B ? ? ? ? E8 ? ? ? ? 5F 5E 8D // ebx+[offset]h // E8 ? ? ? ? 8D B3 ? ? ? ? C7 83 ? ? ? ? ? ? ? ? C7 83 ? ? ? ? ? ? ? ? 8B CE // sub_XXX + 44
#define oObjExpiry 0x298
#define oInhiRemainingRespawnTime 0xFF4

//ObjectManager
#define oObjManager 0x1C5D610 // //			8B 0D ? ? ? ? 89 74 24 14 // dword_[offset]
#define oObjManagerObjArray 0x14

//MissileInfo
#define oMissileSpellInfo 0x230
#define oMissileTargetIndex 0x2E8
#define oMissileStartPos 0x2A8
#define oMissileEndPos 0x2B4

// Renderer
#define oViewProjMatrices 0x3520038
#define oRenderer 0x3522E34 // 				8B 15 ? ? ? ? 83 EC 08 F3 // dword_[offset]
#define oRendererWidth 0x10
#define oRendererHeight 0x14
#define oRendererViewMat 0x60
#define oRendererProjMat 0xA0


//oSpellSlot
#define oSpellSlotRemainingCharge 0x58
#define oSpellSlotLevel 0x20
#define oSpellSlotRemainingRechargeCD 0x64
#define oSpellSlotTime 0x28
#define oSpellSlotCD 0x18
#define oSpellSlotDamage 0x90
#define oSpellSlotSpellInfo 0x134
#define oSpellSlotRemainingCD 0x28

//oSpellInfoSpellData
#define oSpellInfoSpellData 0x44

//SpellData
#define oSpellDataMissileName 0x0058
#define oSpellDataSpellName 0x007C
#define oSpellDataSpellName2 0x007C
#define oSpellDataDescription 0x0088
#define oSpellDataEffectAmount 0xD0
#define oSpellDataIncreaseDamage 0xEC
#define oSpellDataSpellDuration 0x108
#define oSpellDataRootDuration 0x15C
#define oSpellDataIncreaseDamageBonus 0x178
#define oSpellDataCoefficient 0x200
#define oSpellDataCoefficient2 0x204
#define oSpellDataMaxHighlightTargets 0x208
#define oSpellDataCooldownTime 0x280
#define oSpellDataDelayCastOffsetPercent 0x29C
#define oSpellDataDelayTotalTimePercent 0x2A0
#define oSpellDataMaxAmmo 0x31C
#define oSpellDataAmmoUsed 0x338
#define oSpellDataAmmoRechargetime 0x354
#define oSpellDataMissileSpeed 0x450
#define oSpellDataSpellWidth 0x458
#define oSpellDataSpellRange 0x3D0
#define oSpellDataEffectSpellRange 0x10C // starts from F4
#define oSpellDataEffectSpellRangeAfterEffect 0xB8 // starts from A0

//Hero list
#define oHeroList 0x1C5B580
#define oHeroListHeroArray 0x4 
#define oHeroListNumChampions 0x8 
