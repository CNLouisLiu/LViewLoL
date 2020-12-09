#pragma once

#define TARGET_GAMEVERSION "Version 10.24.345.8390 [PUBLIC]"  // 

#define oRetAddr 0x6E502 // 				// find addr : ret // opcode : C3
#define oDrawCircleRetAddr 0x6E4FF // 		// find addr : add esp, 28 ret // opcode : 83 C4 1C C3
#define oNetClient 0x350E414 // 			8B 0D ? ? ? ? 85 C9 74 07 8B 01 6A 01 FF 50 08 8B // dword_[offset] // this addy us for IsTargetable as per chinese tool but nah~
#define oPingInstance 0x350E414 //			8B 0D ? ? ? ? 85 C9 74 07 8B 01 6A 01 FF 50 08 8B // dword_[offset]
#define oChatClientPtr 0x1C67F30 //			8B 0D ? ? ? ? 6A 00 50 E8 ? ? ? ? 33 // dword_[offset] // 8B ?? ?? ?? ?? ?? 6A ?? 50 E8 ?? ?? ?? ?? 33 C0 5F C2 // dword_[offset]
#define oObjManager 0x1C6848C // //			8B 0D ? ? ? ? 89 74 24 14 // dword_[offset]
#define oZoomClass 0x34FF1CC //				A3 ? ? ? ? 83 FA 10 72 32 // dword_[offset]
#define oGameInfo 0x350034C // 				A1 ? ? ? ? 83 78 08 02 0F 94 C0 // dword_[offset]
#define oHudInstance 0x1C6A568 //			8B 0D ? ? ? ? 6A 00 8B 49 34 E8 ? ? ? ? B0 // dword_[offset]
#define oRenderer 0x352FD44 // 				8B 15 ? ? ? ? 83 EC 08 F3 // dword_[offset]
#define oUnderMouseObject 0x1C0A160 // 		8B 0D ? ? ? ? 89 0D // dword_[offset]
#define oD3DRenderer 0x350034C // 			A1 ? ? ? ? 89 54 24 18 // dword_[offset]
#define oLocalPlayer 0x3507098 //			A1 ?? ?? ?? ?? 85 C0 74 07 05 ?? ?? ?? ?? EB 02 33 C0 56 // dword_[offset]
#define oGameTime 0x34FF228 // 				F3 0F 11 05 ? ? ? ? 8B 49 // dword_[offset]
#define oMenuGUI 0x3506B80 // 				8B 0D ? ? ? ? 6A 00 E8 ? ? ? ? C7 // dword_[offset]

//CObject
#define oObjIndex 0x20
#define oObjTeam 0x4C
#define oObjName 0x6C
#define oObjNetworkID 0xCC //
#define oObjPos 0x1D8 // 10.24 loveto5014
#define oObjVisibility 0x270
#define oObjHealth 0xD98 // 10.24 loveto5014
#define oObjMana 0x298
#define oObjMaxMana 0x2A8
#define oObjArmor 0x1278 // 10.24 loveto5014
#define oObjMagicRes 0x1280 // 10.24 loveto5014
#define oObjBonusMagicRes 0x1284 // 10.24 loveto5014
#define oObjBaseAtk 0x1250 //10.24 loveto5014
#define oObjBonusAtk 0x11D0 // 10.24 loveto5014
#define oObjMoveSpeed 0x1290 // 10.24 loveto5014
#define oObjAtkRange 0x1298 // 10.24 loveto5014
#define oObjBuffMgr 0x213C // 10.24 serge
#define oObjSpellBook 0x2B60  // 10.24 serge
#define oObjChampionName 0x3114 // 10.24 me
#define oObjLevel 0x369C // 10.24 me
#define oObjSourceIndex 0x290
#define oObjPerk1 0x3888 // 8D 8E ? ? ? ? E8 ? ? ? ? 8B CE E8 ? ? ? ? A1 // esi+[offset]h // 81 EC ? ? ? ? A1 ? ? ? ? 33 C4 89 84 24 ? ? ? ? 53 8B 9C 24 ? ? ? ? 56 8B F1 88 5C 24 0C // fn + 19F
#define oObjPerk2 0x2C8 // 8D 8B ? ? ? ? E8 ? ? ? ? 5F 5E 8D // ebx+[offset]h // E8 ? ? ? ? 8D B3 ? ? ? ? C7 83 ? ? ? ? ? ? ? ? C7 83 ? ? ? ? ? ? ? ? 8B CE // sub_XXX + 44
#define oInhiRemainingRespawnTime 0xFF4

//ObjectManager
#define objectArray 0x14

//MissileInfo
#define oMissileSpellInfo 0x230
#define oMissileTargetIndex 0x2E8
#define oMissileStartPos 0x2A8
#define oMissileEndPos 0x2B4

// Renderer
#define oRendererWidth 0x10
#define oRendererHeight 0x14
#define oRendererViewMat 0x68
#define oRendererProjMat 0xA8

//Buff
#define O_BUFFMGR_BUFFNAME 0x08
#define O_BUFFMGR_STARTTIME 0xC
#define O_BUFFMGR_ENDTIME 0x10
#define O_BUFFMGR_flBUFFCOUNT 0x130 
#define O_BUFFMGR_iBUFFCOUNT 0x74 
#define oBuffType 0x4
#define oBuffCountAlt 0x24
#define oBuffCountAlt2 0x20

//Zoom
#define oMaxZoom 0x28

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

//champion_manager
#define oChampionManagerChampionList 0x4 //24
#define oChampionCount 0x8 //152
#define oGetChampionSkins 0x58
#define oGetChampionName 0x4
