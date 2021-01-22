#include "Offsets.h"

Offsets::Offsets() {};

int Offsets::GameTime                     = 0x34E4CD4;

int Offsets::ObjIndex                     = 0x20;
int Offsets::ObjTeam                      = 0x4C;
int Offsets::ObjNetworkID                 = 0xCC;
int Offsets::ObjPos                       = 0x1d8;
int Offsets::ObjVisibility                = 0x270;
int Offsets::ObjSpawnCount                = 0x284;
int Offsets::ObjSrcIndex                  = 0x290;
int Offsets::ObjMana                      = 0x298;
int Offsets::ObjHealth                    = 0xD98;
int Offsets::ObjMaxHealth                 = 0xDA8;
int Offsets::ObjArmor                     = 0x1298;
int Offsets::ObjMagicRes                  = 0x12A0;
int Offsets::ObjBaseAtk                   = 0x1270;
int Offsets::ObjBonusAtk                  = 0x11F0;
int Offsets::ObjMoveSpeed                 = 0x12B0;
int Offsets::ObjSpellBook                 = 0x2b80;
int Offsets::ObjName                      = 0x2F64;
int Offsets::ObjLvl                       = 0x36BC;
int Offsets::ObjExpiry                    = 0x298; 
int Offsets::ObjCrit                      = 0x1294;
int Offsets::ObjCritMulti                 = 0x1284;
int Offsets::ObjAbilityPower              = 0x1200;
int Offsets::ObjAtkSpeedMulti             = 0x126C;
int Offsets::ObjItemList                  = 0x3700;

int Offsets::ItemListItem                 = 0xC;
int Offsets::ItemInfo                     = 0x20;
int Offsets::ItemInfoId                   = 0x68;

int Offsets::ViewProjMatrices             = 0x350E8F0;
int Offsets::Renderer                     = 0x35116EC;
int Offsets::RendererWidth                = 0x10;
int Offsets::RendererHeight               = 0x14;

int Offsets::SpellSlotLevel               = 0x20;
int Offsets::SpellSlotTime                = 0x28;
int Offsets::SpellSlotDamage              = 0x94;
int Offsets::SpellSlotSpellInfo           = 0x13C;
int Offsets::SpellInfoSpellData           = 0x44;
int Offsets::SpellDataSpellName           = 0x64;
int Offsets::SpellDataMissileName         = 0x64;

int Offsets::ObjectManager                = 0x1C50190;
int Offsets::LocalPlayer                  = 0x34EC5E0;
int Offsets::UnderMouseObject             = 0x289E358;

int Offsets::ObjectMapCount               = 0x2C;
int Offsets::ObjectMapRoot                = 0x28;
int Offsets::ObjectMapNodeNetId           = 0x10;
int Offsets::ObjectMapNodeObject          = 0x14;

int Offsets::MissileSpellInfo             = 0x230;
int Offsets::MissileSrcIdx                = 0x290;
int Offsets::MissileDestIdx               = 0x2E8;
int Offsets::MissileStartPos              = 0x2A8;
int Offsets::MissileEndPos                = 0x2B4;

int Offsets::MinimapObject                = 0x34EC5F0;     //FF 52 04 8B 0D ? ? ? ? E8 ? ? ? ?, or search mem for max_size = vec2(385.0, 384.0)
int Offsets::MinimapObjectHud             = 0x88;
int Offsets::MinimapHudPos                = 0x5C;
int Offsets::MinimapHudSize               = 0x64;