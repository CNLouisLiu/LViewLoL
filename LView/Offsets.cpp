#include "Offsets.h"

Offsets::Offsets() {};

int Offsets::GameTime = 0;

int Offsets::ObjIndex = 0;
int Offsets::ObjTeam = 0;
int Offsets::ObjTargetRadius = 0;
int Offsets::ObjNetworkID = 0;
int Offsets::ObjPos = 0;
int Offsets::ObjVisibility = 0;
int Offsets::ObjSpawnCount = 0;
int Offsets::ObjHealth = 0;
int Offsets::ObjMana = 0;
int Offsets::ObjMaxMana = 0;
int Offsets::ObjArmor = 0;
int Offsets::ObjMagicRes = 0;
int Offsets::ObjBonusMagicRes = 0;
int Offsets::ObjBaseAtk = 0;
int Offsets::ObjBonusAtk = 0;
int Offsets::ObjMoveSpeed = 0;
int Offsets::ObjSpellBook = 0;
int Offsets::ObjName = 0;
int Offsets::ObjLvl = 0;
int Offsets::ObjExpiry = 0;
int Offsets::ObjCrit = 0;
int Offsets::ObjCritMulti = 0;
int Offsets::ObjAbilityPower = 0;
int Offsets::ObjBonusAbilityPower = 0;
int Offsets::ObjAtkSpeedMulti = 0;
int Offsets::ObjItemList = 0;

int Offsets::ItemListItem     = 0;
int Offsets::ItemInfo         = 0;
int Offsets::ItemInfoId       = 0;

int Offsets::ViewProjMatrices = 0;
int Offsets::Renderer         = 0;
int Offsets::RendererWidth    = 0;
int Offsets::RendererHeight   = 0;

int Offsets::SpellSlotRemainingCharge     = 0;
int Offsets::SpellSlotLevel               = 0;
int Offsets::SpellSlotRemainingRechargeCD = 0;
int Offsets::SpellSlotTime                = 0;
int Offsets::SpellSlotCD                  = 0;
int Offsets::SpellSlotDamage              = 0;
int Offsets::SpellSlotSpellInfo           = 0;
int Offsets::SpellSlotRemainingCD         = 0;
int Offsets::SpellInfoSpellData           = 0;
int Offsets::SpellDataSpellName           = 0;

int Offsets::HeroList   = 0;
int Offsets::MinionList = 0;
int Offsets::TurretList = 0;

int Offsets::UnitComponentInfo  = 0;
int Offsets::UnitProperties     = 0;
int Offsets::UnitAttackRange    = 0;
int Offsets::UnitBoundingRadius = 0;
int Offsets::UnitBaseAtkSpeed   = 0;
int Offsets::UnitMaxAtkSpeed    = 0;

void Offsets::LoadFromConfigs() {
	ConfigSet& cfg = *(ConfigSet::Get());
	cfg.SetPrefixKey("Offsets");

	GameTime = cfg.GetInt("GameTime", 0);

	ObjIndex                   = cfg.GetInt("ObjIndex", 0);
	ObjTeam                    = cfg.GetInt("ObjTeam", 0);
	ObjTargetRadius            = cfg.GetInt("ObjTargetRadius", 0);
	ObjNetworkID               = cfg.GetInt("ObjNetworkID", 0);
	ObjPos                     = cfg.GetInt("ObjPos", 0);
	ObjVisibility              = cfg.GetInt("ObjVisibility", 0);
	ObjSpawnCount              = cfg.GetInt("ObjSpawnCount", 0);
	ObjHealth                  = cfg.GetInt("ObjHealth", 0);
	ObjMana                    = cfg.GetInt("ObjMana", 0);
	ObjMaxMana                 = cfg.GetInt("ObjMaxMana", 0);
	ObjArmor                   = cfg.GetInt("ObjArmor", 0);
	ObjMagicRes                = cfg.GetInt("ObjMagicRes", 0);
	ObjBonusMagicRes           = cfg.GetInt("ObjBonusMagicRes", 0);
	ObjBaseAtk                 = cfg.GetInt("ObjBaseAtk", 0);
	ObjBonusAtk                = cfg.GetInt("ObjBonusAtk", 0);
	ObjMoveSpeed               = cfg.GetInt("ObjMoveSpeed", 0);
	ObjSpellBook               = cfg.GetInt("ObjSpellBook", 0);
	ObjName                    = cfg.GetInt("ObjName", 0);
	ObjLvl                     = cfg.GetInt("ObjLvl", 0);
	ObjExpiry                  = cfg.GetInt("ObjExpiry", 0);
	ObjCrit                    = cfg.GetInt("ObjCrit", 0);
	ObjCritMulti               = cfg.GetInt("ObjCritMulti", 0);
	ObjAbilityPower            = cfg.GetInt("ObjAbilityPower", 0);
	ObjBonusAbilityPower       = cfg.GetInt("ObjBonusAbilityPower", 0);
	ObjAtkSpeedMulti           = cfg.GetInt("ObjAtkSpeedMulti", 0);
	ObjItemList                = cfg.GetInt("ObjItemList", 0);

	ItemListItem               = cfg.GetInt("ItemListItem", 0);
	ItemInfo                   = cfg.GetInt("ItemInfo", 0);
	ItemInfoId                 = cfg.GetInt("ItemInfoId", 0);

	ViewProjMatrices  = cfg.GetInt("ViewProjMatrices", 0);
	Renderer          = cfg.GetInt("Renderer", 0);
	RendererWidth     = cfg.GetInt("RendererWidth", 0);
	RendererHeight    = cfg.GetInt("RendererHeight", 0);

	SpellSlotRemainingCharge     = cfg.GetInt("SpellSlotRemainingCharge", 0);
	SpellSlotLevel               = cfg.GetInt("SpellSlotLevel", 0);
	SpellSlotRemainingRechargeCD = cfg.GetInt("SpellSlotRemainingRechargeCD", 0);
	SpellSlotTime                = cfg.GetInt("SpellSlotTime", 0);
	SpellSlotCD                  = cfg.GetInt("SpellSlotCD", 0);
	SpellSlotDamage              = cfg.GetInt("SpellSlotDamage", 0);
	SpellSlotSpellInfo           = cfg.GetInt("SpellSlotSpellInfo", 0);
	SpellSlotRemainingCD         = cfg.GetInt("SpellSlotRemainingCD", 0);
	SpellInfoSpellData           = cfg.GetInt("SpellInfoSpellData", 0);
	SpellDataSpellName           = cfg.GetInt("SpellDataSpellName", 0);

	HeroList   = cfg.GetInt("HeroList", 0);
	MinionList = cfg.GetInt("MinionList", 0);
	TurretList = cfg.GetInt("TurretList", 0);

	UnitComponentInfo   = cfg.GetInt("UnitComponentInfo", 0);
	UnitProperties      = cfg.GetInt("UnitProperties", 0);
	UnitAttackRange     = cfg.GetInt("UnitAttackRange", 0);
	UnitBoundingRadius  = cfg.GetInt("UnitBoundingRadius", 0);
	UnitBaseAtkSpeed    = cfg.GetInt("UnitBaseAtkSpeed", 0);
	UnitMaxAtkSpeed     = cfg.GetInt("UnitMaxAtkSpeed", 0);
	cfg.SetPrefixKey("");

	// Verify that we don't have missing offsets
	assert(GameTime != 0);
	assert(ObjIndex != 0);
	assert(ObjTeam != 0);
	assert(ObjTargetRadius != 0);
	assert(ObjNetworkID != 0);
	assert(ObjPos != 0);
	assert(ObjVisibility != 0);
	assert(ObjSpawnCount != 0);
	assert(ObjHealth != 0);
	assert(ObjMana != 0);
	assert(ObjMaxMana != 0);
	assert(ObjArmor != 0);
	assert(ObjMagicRes != 0);
	assert(ObjBonusMagicRes != 0);
	assert(ObjBaseAtk != 0);
	assert(ObjBonusAtk != 0);
	assert(ObjMoveSpeed != 0);
	assert(ObjSpellBook != 0);
	assert(ObjName != 0);
	assert(ObjLvl != 0);
	assert(ObjExpiry != 0);
	assert(ObjCrit != 0);
	assert(ObjCritMulti != 0);
	assert(ObjAbilityPower != 0);
	assert(ObjBonusAbilityPower != 0);
	assert(ObjAtkSpeedMulti != 0);
	assert(ObjItemList != 0);

	assert(ItemListItem != 0);
	assert(ItemInfo != 0);
	assert(ItemInfoId != 0);

	assert(ViewProjMatrices != 0);
	assert(Renderer != 0);
	assert(RendererWidth != 0);
	assert(RendererHeight != 0);

	assert(SpellSlotRemainingCharge != 0);
	assert(SpellSlotLevel != 0);
	assert(SpellSlotRemainingRechargeCD != 0);
	assert(SpellSlotTime != 0);
	assert(SpellSlotCD != 0);
	assert(SpellSlotDamage != 0);
	assert(SpellSlotSpellInfo != 0);
	assert(SpellSlotRemainingCD != 0);
	assert(SpellInfoSpellData != 0);
	assert(SpellDataSpellName != 0);

	assert(HeroList != 0);
	assert(MinionList != 0);
	assert(TurretList != 0);

	assert(UnitComponentInfo != 0);
	assert(UnitProperties != 0);
	assert(UnitAttackRange != 0);
	assert(UnitBoundingRadius != 0);
	assert(UnitBaseAtkSpeed != 0);
	assert(UnitMaxAtkSpeed != 0);
}