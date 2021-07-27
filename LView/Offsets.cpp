#include "Offsets.h"
 
Offsets::Offsets() {};
 
int Offsets::GameTime						 = 0x2FB425C;
 
int Offsets::ObjIndex                        = 0x20;
int Offsets::ObjTeam                         = 0x4C;
int Offsets::ObjMissileName                  = 0x6C;
int Offsets::ObjNetworkID                    = 0xCC;
int Offsets::ObjPos                          = 0x1d8;
int Offsets::ObjMissileSpellCast             = 0x250;
int Offsets::ObjVisibility                   = 0x270;
int Offsets::ObjSpawnCount                   = 0x218;
int Offsets::ObjSrcIndex                     = 0x290;
int Offsets::ObjMana                         = 0x298;
int Offsets::ObjMaxMana						 = 0x2A8;
int Offsets::ObjRecallState                  = 0xD8C;
int Offsets::ObjHealth                       = 0xD98;
int Offsets::ObjMaxHealth                    = 0xDA8;
int Offsets::ObjAbilityHaste				 = 0x10F4;
int Offsets::ObjLethality					 = 0x11DC;
int Offsets::ObjArmor                        = 0x12CC;
int Offsets::ObjBonusArmor					 = 0x12C8;
int Offsets::ObjMagicRes                     = 0x12D4;
int Offsets::ObjBonusMagicRes				 = 0x12D4;
int Offsets::ObjBaseAtk                      = 0x12A4;
int Offsets::ObjBonusAtk                     = 0x121C;
int Offsets::ObjMoveSpeed                    = 0x12E4;
int Offsets::ObjSpellBook                    = 0x27D0;
int Offsets::ObjTransformation               = 0x3040;
int Offsets::ObjName                         = 0x2BBC;
int Offsets::ObjLvl                          = 0x3344;
int Offsets::ObjExpiry                       = 0x298; 
int Offsets::ObjCrit                         = 0x12C8;
int Offsets::ObjCritMulti                    = 0x12B4;
int Offsets::ObjAbilityPower                 = 0x122C;
int Offsets::ObjAtkSpeedMulti                = 0x12A0;
int Offsets::ObjAtkRange                     = 0x12EC;
int Offsets::ObjTargetable					 = 0xD00;
int Offsets::ObjInvulnerable				 = 0x3D0;
int Offsets::ObjIsMoving					 = 0x3638;
int Offsets::ObjDirection					 = 0x1B88;
int Offsets::ObjItemList					 = 0x3430;
 
int Offsets::ObjExpierience					 = 0x33CC;
int Offsets::ObjMagicPen					 = 0x11C0;
int Offsets::ObjMagicPenMulti				 = 0x11C8;
int Offsets::ObjAdditionalApMulti			 = 0x122C; 
int Offsets::ObjManaRegen					 = 0x1134;
int Offsets::ObjHealthRegen					 = 0x12D8;
 
int Offsets::ZoomClass = 0x02fadb28;
int Offsets::MaxZoom = 0x20;
 
int Offsets::Chat							 = 0x02fbc6ec;
int Offsets::ChatIsOpen						 = 0x678;
 
int Offsets::SpellBookActiveSpellCast = 0x20;
int Offsets::SpellBookSpellSlots = 0x478;
 
int Offsets::ObjBuffManager = 0x21A4;
int Offsets::BuffManagerEntriesArray = 0x10;
int Offsets::BuffEntryBuff = 0x8;
int Offsets::BuffType = 0x4;
int Offsets::BuffEntryBuffStartTime = 0xC;
int Offsets::BuffEntryBuffEndTime = 0x10;
int Offsets::BuffEntryBuffCount = 0x74;
int Offsets::BuffEntryBuffCountAlt = 0x24;
int Offsets::BuffEntryBuffCountAlt2 = 0x20;
int Offsets::BuffName = 0x8;
int Offsets::BuffEntryBuffNodeStart = 0x20;
int Offsets::BuffEntryBuffNodeCurrent = 0x24;
 
int Offsets::ItemListItem                 = 0xC;
int Offsets::ItemInfo                     = 0x20;
int Offsets::ItemInfoId                   = 0x68;
 
int Offsets::CurrentDashSpeed = 0x1D0;
int Offsets::IsDashing = 0x398;
int Offsets::DashPos = 0x1FC;
int Offsets::IsMoving = 0x198;
int Offsets::NavBegin = 0x1BC;
int Offsets::NavEnd = 0x1C0;
 
int Offsets::ViewProjMatrices = 0x2FDF6A0;
int Offsets::Renderer = 0x2FE250C;
int Offsets::RendererWidth = 0xC;
int Offsets::RendererHeight = 0x10;
 
int Offsets::SpellSlotLevel = 0x20;
int Offsets::SpellSlotTime = 0x28;
int Offsets::SpellSlotCharges = 0x58;
int Offsets::SpellSlotTimeCharge = 0x78;
int Offsets::SpellSlotDamage = 0x94;
int Offsets::SpellSlotSpellInfo = 0x13C;
int Offsets::SpellInfoSpellData = 0x44;
int Offsets::SpellDataSpellName = 0x6C;
int Offsets::SpellDataMissileName = 0x6C;
int Offsets::SpellSlotSmiteTimer = 0x64;
int Offsets::SpellSlotSmiteCharges = 0x58;
 
int Offsets::ObjectManager = 0x171FB98;
int Offsets::LocalPlayer = 0x2FBC614;
int Offsets::UnderMouseObject = 0x2FB08F8;
 
int Offsets::ObjectMapCount               = 0x2C;
int Offsets::ObjectMapRoot                = 0x28;
int Offsets::ObjectMapNodeNetId           = 0x10;
int Offsets::ObjectMapNodeObject          = 0x14;
 
// int Offsets::MissileSpellInfo             = 0x230;
// int Offsets::MissileSrcIdx                = 0x290;
// int Offsets::MissileDestIdx               = 0x2E8;
// int Offsets::MissileStartPos              = 0x2A8;
// int Offsets::MissileEndPos                = 0x2B4;
 
int Offsets::SpellCastSpellInfo = 0x8;
int Offsets::SpellCastStartTime = 0x544;
int Offsets::SpellCastStartTimeAlt = 0x534;
int Offsets::SpellCastCastTime = 0x4C0;
int Offsets::SpellCastStart = 0x80;
int Offsets::SpellCastEnd = 0x8C;
int Offsets::SpellCastSrcIdx = 0x68;
int Offsets::SpellCastDestIdx = 0xC0;
 
int Offsets::MissileSpellInfo = 0x258;
int Offsets::MissileSrcIdx = 0x2B8;
int Offsets::MissileDestIdx = 0x310;
int Offsets::MissileStartPos = 0x2D0;
int Offsets::MissileEndPos = 0x2DC;
 
int Offsets::MinimapObject                = 0x2FA7FDC;
int Offsets::MinimapObjectHud             = 0x88;
int Offsets::MinimapHudPos                = 0x60;
int Offsets::MinimapHudSize               = 0x68;
 
int Offsets::AiManagerStartPath = 0x1bc;
int Offsets::AiManagerEndPath = 0x1c0;
int Offsets::AiManagerTargetPosition = 0x10;
int Offsets::AiManagerIsMoving = 0x198;
int Offsets::AiManagerIsDashing = 0x398;
int Offsets::AiManagerCurrentSegment = 0x19C;
int Offsets::AiManagerDashSpeed = 0x1D0;
