#include "MissileInfo.h"

MissileInfo* MissileInfo::UnknownMissile = new MissileInfo();

std::map<std::string, MissileInfo*> MissileInfo::missiles = {

	{std::string("Unknown"),
		UnknownMissile
	},

	// Aatrox
	{std::string("AatroxW"),
		(new MissileInfo())
			->withName("AatroxW")
			->withSpeed(1800.f)
			->withRange(825.f)
			->withRadius(80.f)
			->withFlags(COLLIDE_GENERIC)
	},

	// Ahri
	{std::string("AhriOrbMissile"),
		(new MissileInfo())
			->withName("AhriOrbMissile")
			->withSpeed(2500.f)
			->withRange(880.f)
			->withRadius(100.f)
			->withFlags(COLLIDE_GENERIC | PIERCE_ALL)
	},

	{std::string("AhriSeduceMissile"),
		(new MissileInfo())
			->withName("AhriSeduceMissile")
			->withSpeed(1500.f)
			->withRange(975.f)
			->withRadius(60.f)
			->withFlags(COLLIDE_GENERIC)
	},

	// Akali
	{std::string("AkaliEMis"),
		(new MissileInfo())
			->withName("AkaliEMis")
			->withSpeed(1800.f)
			->withRange(825.f)
			->withRadius(70.f)
			->withFlags(COLLIDE_GENERIC)
	},

	// Amumu
	{std::string("SadMummyBandageToss"),
		(new MissileInfo())
			->withName("SadMummyBandageToss")
			->withSpeed(2000.f)
			->withRange(1100.f)
			->withRadius(80.f)
			->withFlags(COLLIDE_GENERIC)
	},

	// Anivia
	{std::string("FlashFrostSpell"),
		(new MissileInfo())
			->withName("FlashFrostSpell")
			->withSpeed(950.f)
			->withRange(1100.f)
			->withRadius(110.f)
			->withFlags(COLLIDE_WINDWALL | FIXED_LOCATION)
	},

	// Aphelios
	{std::string("ApheliosCalibrumQ"),
		(new MissileInfo())
			->withName("ApheliosCalibrumQ")
			->withSpeed(1850.f)
			->withRange(1450.f)
			->withRadius(60.f)
			->withFlags(COLLIDE_GENERIC)
	},

	{std::string("ApheliosRMis"),
		(new MissileInfo())
			->withName("ApheliosRMis")
			->withSpeed(2050.f)
			->withRange(1600.f)
			->withRadius(125.f)
			->withFlags(COLLIDE_WINDWALL | FIXED_LOCATION)
	},

	// Ashe
	{std::string("VolleyAttack"),
		(new MissileInfo())
			->withName("VolleyAttack")
			->withSpeed(2000.f)
			->withRange(1200.f)
			->withRadius(20.f)
			->withFlags(COLLIDE_GENERIC)
	},

	{std::string("EnchantedCrystalArrow"),
		(new MissileInfo())
			->withName("EnchantedCrystalArrow")
			->withSpeed(1600.f)
			->withRange(20000.f)
			->withRadius(130.f)
			->withRadiusImpact(350.f)
			->withFlags(COLLIDE_WINDWALL | COLLIDE_CHAMPION | PIERCE_MOB)
	},

	// Aurelion
	{std::string("AurelionSolQMissile"),
		(new MissileInfo())
			->withName("AurelionSolQMissile")
			->withSpeed(850.f)
			->withRange(1075.f)
			->withRadius(110.f)
			->withFlags(COLLIDE_WINDWALL | PIERCE_ALL)
	},

	{std::string("BardQMissile"),
		(new MissileInfo())
			->withName("BardQMissile")
			->withSpeed(1500.f)
			->withRange(950.f)
			->withRadius(60.f)
			->withFlags(COLLIDE_GENERIC)
	},

	{std::string("BardRMissile"),
		(new MissileInfo())
			->withName("BardRMissile")
			->withSpeed(2100.f)
			->withRange(3400.f)
			->withRadiusImpact(350.f)
			->withFlags(FIXED_LOCATION)
	},

	{ std::string("RocketGrabMissile"),
		(new MissileInfo())
			->withName("RocketGrabMissile")
			->withSpeed(1800.f)
			->withRange(1150.f)
			->withRadius(70.f)
			->withFlags(COLLIDE_GENERIC)
	},

	{ std::string("BrandQMissile"),
		(new MissileInfo())
			->withName("BrandQMissile")
			->withSpeed(1600.f)
			->withRange(1050.f)
			->withRadius(60.f)
			->withFlags(COLLIDE_GENERIC)
	},

	{ std::string("BraumQMissile"),
		(new MissileInfo())
			->withName("BraumQMissile")
			->withSpeed(1700.f)
			->withRange(1000.f)
			->withRadius(70.f)
			->withFlags(COLLIDE_GENERIC)
	},

	{ std::string("BraumRMissile"),
		(new MissileInfo())
			->withName("BraumRMissile")
			->withSpeed(1400.f)
			->withRange(1250.f)
			->withRadius(115.f)
			->withFlags(COLLIDE_GENERIC | PIERCE_ALL)
	},

	{ std::string("CaitlynPiltoverPeacemaker"),
		(new MissileInfo())
			->withName("CaitlynPiltoverPeacemaker")
			->withSpeed(2200.f)
			->withRange(1250.f)
			->withRadius(90.f)
			->withFlags(COLLIDE_GENERIC | PIERCE_ALL)
	},

	{ std::string("CaitlynEntrapment"),
		(new MissileInfo())
			->withName("CaitlynEntrapment")
			->withSpeed(1600.f)
			->withRange(750.f)
			->withRadius(70.f)
			->withFlags(COLLIDE_GENERIC)
	},

	{ std::string("CamilleEMissile"),
		(new MissileInfo())
			->withName("CamilleEMissile")
			->withSpeed(1900.f)
			->withRange(800.f)
			->withRadius(60.f)
			->withFlags(COLLIDE_WALL)
	},

	{ std::string("PhosphorusBombMissile"),
		(new MissileInfo())
			->withName("PhosphorusBombMissile")
			->withSpeed(1000.f)
			->withRange(825.f)
			->withRadiusImpact(250.f)
			->withFlags(COLLIDE_WINDWALL | FIXED_LOCATION)
	},

	{ std::string("MissileBarrageMissile"),
		(new MissileInfo())
			->withName("MissileBarrageMissile")
			->withSpeed(2000.f)
			->withRange(1300.f)
			->withRadius(40.f)
			->withFlags(COLLIDE_GENERIC)
	},

	{ std::string("MissileBarrageMissile2"),
		(new MissileInfo())
			->withName("MissileBarrageMissile2")
			->withSpeed(2000.f)
			->withRange(1500.f)
			->withRadius(40.f)
			->withFlags(COLLIDE_GENERIC)
	},

	{ std::string("DravenDoubleShotMissile"),
		(new MissileInfo())
			->withName("DravenDoubleShotMissile")
			->withSpeed(1600.f)
			->withRange(1050.f)
			->withRadius(130.f)
			->withFlags(COLLIDE_GENERIC | PIERCE_ALL)
	},

	{ std::string("InfectedCleaverMissile"),
		(new MissileInfo())
			->withName("InfectedCleaverMissile")
			->withSpeed(2000.f)
			->withRange(975.f)
			->withRadius(60.f)
			->withFlags(COLLIDE_GENERIC)
	},

	{ std::string("EkkoQMis"),
		(new MissileInfo())
			->withName("EkkoQMis")
			->withSpeed(1650.f)
			->withRange(1175.f)
			->withRadius(60.f)
			->withFlags((COLLIDE_GENERIC | FIXED_LOCATION) | PIERCE_ALL)
	},

	{ std::string("EliseHumanE"),
		(new MissileInfo())
			->withName("EliseHumanE")
			->withSpeed(1600.f)
			->withRange(1075.f)
			->withRadius(55.f)
			->withFlags(COLLIDE_GENERIC)
	},

	{ std::string("EvelynnQ"),
		(new MissileInfo())
			->withName("EvelynnQ")
			->withSpeed(2400.f)
			->withRange(800.f)
			->withRadius(60.f)
			->withFlags(COLLIDE_GENERIC)
	},

	{ std::string("EzrealQ"),
		(new MissileInfo())
			->withName("EzrealQ")
			->withSpeed(2000.f)
			->withRange(1150.f)
			->withRadius(60.f)
			->withFlags(COLLIDE_GENERIC)
	},

	{ std::string("EzrealW"),
		(new MissileInfo())
			->withName("EzrealW")
			->withSpeed(2000.f)
			->withRange(1150.f)
			->withRadius(60.f)
			->withFlags(COLLIDE_CHAMPION | COLLIDE_WINDWALL | COLLIDE_STRUCTURE | PIERCE_MOB)
	},

	{ std::string("EzrealR"),
		(new MissileInfo())
			->withName("EzrealR")
			->withSpeed(2000.f)
			->withRange(20000.f)
			->withRadius(160.f)
			->withFlags(COLLIDE_GENERIC | PIERCE_ALL)
	},

	{ std::string("FizzRMissile"),
		(new MissileInfo())
			->withName("FizzRMissile")
			->withSpeed(1300.f)
			->withRange(1300.f)
			->withRadius(150.f)
			->withFlags(COLLIDE_WINDWALL | COLLIDE_CHAMPION)
	},

	{ std::string("GalioQMissile"),
		(new MissileInfo())
			->withName("GalioQMissile")
			->withSpeed(1150.f)
			->withRange(825.f)
			->withRadius(60.f)
			->withRadiusImpact(235.f)  
			->withFlags(COLLIDE_GENERIC | PIERCE_ALL)
	},

	{ std::string("GnarQMissile"),
		(new MissileInfo())
			->withName("GnarQMissile")
			->withSpeed(2500.f)
			->withRange(1125.f)
			->withRadius(55.f)
			->withFlags(COLLIDE_GENERIC | PIERCE_ALL | FIXED_LOCATION)
	},

	{ std::string("GnarBigQMissile"),
		(new MissileInfo())
			->withName("GnarBigQMissile")
			->withSpeed(2100.f)
			->withRange(1125.f)
			->withRadius(90.f)
			->withFlags(COLLIDE_GENERIC)
	},

	{ std::string("GragasQMissile"),
		(new MissileInfo())
			->withName("GragasQMissile")
			->withSpeed(1000.f)
			->withRange(850.f)
			->withRadiusImpact(275.f)
			->withFlags(COLLIDE_WINDWALL | FIXED_LOCATION)
	},

	{ std::string("GragasRBoom"),
		(new MissileInfo())
			->withName("GragasRBoom")
			->withSpeed(1800.f)
			->withRange(1000.f)
			->withRadiusImpact(400.f)
			->withFlags(COLLIDE_WINDWALL | FIXED_LOCATION)
	},

	{ std::string("GravesQLineMis"),
		(new MissileInfo())
			->withName("GravesQLineMis")
			->withSpeed(1500.f)
			->withRange(925.f)
			->withRadius(55.f)
			->withFlags(COLLIDE_GENERIC | COLLIDE_WALL | PIERCE_ALL)
	},

	{ std::string("GravesQReturn"),
		(new MissileInfo())
			->withName("GravesQReturn")
			->withSpeed(1500.f)
			->withRange(925.f)
			->withRadius(55.f)
			->withFlags(COLLIDE_GENERIC | PIERCE_ALL | FIXED_LOCATION)
	},

	{ std::string("GravesSmokeGrenadeBoom"),
		(new MissileInfo())
			->withName("GravesSmokeGrenadeBoom")
			->withSpeed(1500.f)
			->withRange(950.f)
			->withRadius(50.f)
			->withRadiusImpact(250.f)
			->withFlags(COLLIDE_WINDWALL | FIXED_LOCATION)
	},

	{ std::string("GravesChargeShotShot"),
		(new MissileInfo())
			->withName("GravesChargeShotShot")
			->withSpeed(2100.f)
			->withRange(1000.f)
			->withRadius(100.f)
			->withRadiusImpact(800.f)
			->withAngleImpact(80.f)
			->withFlags(COLLIDE_GENERIC | PIERCE_MOB)
	},

	{ std::string("HecarimUltMissile"),
		(new MissileInfo())
			->withName("HecarimUltMissile")
			->withSpeed(1100.f)
			->withRange(1650.f)
			->withRadius(280.f)
			->withFlags(COLLIDE_GENERIC | PIERCE_ALL | FIXED_LOCATION)
	},

	{ std::string("HeimerdingerESpell"),
		(new MissileInfo())
			->withName("HeimerdingerESpell")
			->withSpeed(1200.f)
			->withRange(970.f)
			->withRadiusImpact(250.f)
			->withFlags(FIXED_LOCATION)
	},

	{ std::string("HeimerdingerESpell_ult"),
		(new MissileInfo())
			->withName("HeimerdingerESpell_ult")
			->withSpeed(1200.f)
			->withRange(970.f)
			->withRadiusImpact(250.f)
			->withFlags(FIXED_LOCATION)
	},

	{ std::string("IllaoiEMis"),
		(new MissileInfo())
			->withName("IllaoiEMis")
			->withSpeed(1900.f)
			->withRange(900.f)
			->withRadius(50.f)
			->withFlags(COLLIDE_GENERIC)
	},

	{ std::string("IreliaR"),
		(new MissileInfo())
			->withName("IreliaR")
			->withSpeed(2000.f)
			->withRange(950.f)
			->withRadius(160.f)
			->withFlags(COLLIDE_GENERIC & ~COLLIDE_MOB)
	},

	{ std::string("IvernQ"),
		(new MissileInfo())
			->withName("IvernQ")
			->withSpeed(1300.f)
			->withRange(1075.f)
			->withRadius(80.f)
			->withFlags(COLLIDE_GENERIC)
	},

	{ std::string("HowlingGaleSpell"),
		(new MissileInfo())
			->withName("HowlingGaleSpell")
			->withSpeed(667.f)
			->withRange(1750.f)
			->withRadius(100.f)
			->withFlags(COLLIDE_GENERIC | PIERCE_ALL)
	},

	{ std::string("JayceShockBlastWallMis"),
		(new MissileInfo())
			->withName("JayceShockBlastWallMis")
			->withSpeed(2350.f)
			->withRange(1600.f)
			->withRadius(115.f)
			->withFlags(COLLIDE_GENERIC)
	},

	{ std::string("JayceShockBlastMis"),
		(new MissileInfo())
			->withName("JayceShockBlastMis")
			->withSpeed(1450.f)
			->withRange(1050.f)
			->withRadius(70.f)
			->withFlags(COLLIDE_GENERIC)
	},

	{ std::string("JhinETrap"),
		(new MissileInfo())
			->withName("JhinETrap")
			->withSpeed(1600.f)
			->withRange(750.f)
			->withRadiusImpact(130.f)
			->withFlags(COLLIDE_WINDWALL | FIXED_LOCATION)
	},

	{ std::string("JhinRShotMis"),
		(new MissileInfo())
			->withName("JhinRShotMis")
			->withSpeed(5000.f)
			->withRange(3500.f)
			->withRadius(80.f)
			->withFlags(COLLIDE_GENERIC | PIERCE_MOB)
	},

	{ std::string("JinxWMissile"),
		(new MissileInfo())
			->withName("JinxWMissile")
			->withSpeed(3300.f)
			->withRange(1450.f)
			->withRadius(60.f)
			->withFlags(COLLIDE_GENERIC)
	},

	{ std::string("JinxEHit"),
		(new MissileInfo())
			->withName("JinxEHit")
			->withSpeed(1100.f)
			->withRange(900.f)
			->withRadiusImpact(120.f)
			->withFlags(COLLIDE_WINDWALL | FIXED_LOCATION)
	},

	{ std::string("JinxR"),
		(new MissileInfo())
			->withName("JinxR")
			->withSpeed(1700.f)
			->withRange(20000.f)
			->withRadius(140.f)
			->withFlags(COLLIDE_GENERIC & ~COLLIDE_MOB)
	},

	{ std::string("KaisaW"),
		(new MissileInfo())
			->withName("KaisaW")
			->withSpeed(1750.f)
			->withRange(3000.f)
			->withRadius(100.f)
			->withFlags(COLLIDE_GENERIC)
	},

	{ std::string("KalistaMysticShotMisTrue"),
		(new MissileInfo())
			->withName("KalistaMysticShotMisTrue")
			->withSpeed(2400.f)
			->withRange(1150.f)
			->withRadius(40.f)
			->withFlags(COLLIDE_GENERIC)
	},

	{ std::string("KarmaQMissile"),
		(new MissileInfo())
			->withName("KarmaQMissile")
			->withSpeed(1700.f)
			->withRange(950.f)
			->withRadius(60.f)
			->withFlags(COLLIDE_GENERIC)
	},

	{ std::string("KarmaQMissileMantra"),
		(new MissileInfo())
			->withName("KarmaQMissileMantra")
			->withSpeed(1700.f)
			->withRange(950.f)
			->withRadius(80.f)
			->withFlags(COLLIDE_GENERIC)
	},

	{ std::string("KayleQMis"),
		(new MissileInfo())
			->withName("KayleQMis")
			->withSpeed(1600.f)
			->withRange(900.f)
			->withRadius(60.f)
			->withFlags(COLLIDE_GENERIC)
	},

	{ std::string("KennenShurikenHurlMissile1"),
		(new MissileInfo())
			->withName("KennenShurikenHurlMissile1")
			->withSpeed(1700.f)
			->withRange(1050.f)
			->withRadius(50.f)
			->withFlags(COLLIDE_GENERIC)
	},

	{ std::string("KhazixWMissile"),
		(new MissileInfo())
			->withName("KhazixWMissile")
			->withSpeed(1700.f)
			->withRange(1000.f)
			->withRadius(70.f)
			->withFlags(COLLIDE_GENERIC)
	},

	{ std::string("KledQMissile"),
		(new MissileInfo())
			->withName("KledQMissile")
			->withSpeed(1600.f)
			->withRange(800.f)
			->withRadius(45.f)
			->withFlags(COLLIDE_GENERIC & ~COLLIDE_MOB)
	},

	{ std::string("KledRiderQMissile"),
		(new MissileInfo())
			->withName("KledRiderQMissile")
			->withSpeed(3000.f)
			->withRange(700.f)
			->withRadius(25.f)
			->withFlags(COLLIDE_GENERIC)
	},

	{ std::string("KogMawQ"),
		(new MissileInfo())
			->withName("KogMawQ")
			->withSpeed(1650.f)
			->withRange(1200.f)
			->withRadius(70.f)
			->withFlags(COLLIDE_GENERIC)
	},

	{ std::string("KogMawVoidOozeMissile"),
		(new MissileInfo())
			->withName("KogMawVoidOozeMissile")
			->withSpeed(1400.f)
			->withRange(1360.f)
			->withRadius(120.f)
			->withFlags(COLLIDE_GENERIC | PIERCE_ALL)
	},

	{ std::string("LeblancEMissile"),
		(new MissileInfo())
			->withName("LeblancEMissile")
			->withSpeed(1750.f)
			->withRange(925.f)
			->withRadius(55.f)
			->withFlags(COLLIDE_GENERIC)
	},

	{ std::string("LeblancREMissile"),
		(new MissileInfo())
			->withName("LeblancREMissile")
			->withSpeed(1750.f)
			->withRange(925.f)
			->withRadius(55.f)
			->withFlags(COLLIDE_GENERIC)
	},

	{ std::string("BlindMonkQOne"),
		(new MissileInfo())
			->withName("BlindMonkQOne")
			->withSpeed(1800.f)
			->withRange(1100.f)
			->withRadius(60.f)
			->withFlags(COLLIDE_GENERIC)
	},

	{ std::string("LeonaZenithBladeMissile"),
		(new MissileInfo())
			->withName("LeonaZenithBladeMissile")
			->withSpeed(2000.f)
			->withRange(875.f)
			->withRadius(70.f)
			->withFlags(COLLIDE_GENERIC | PIERCE_MOB)
	},

	{ std::string("LissandraQMissile"),
		(new MissileInfo())
			->withName("LissandraQMissile")
			->withSpeed(2200.f)
			->withRange(750.f)
			->withRadius(75.f)
			->withFlags(COLLIDE_GENERIC)
	},

	{ std::string("LissandraEMissile"),
		(new MissileInfo())
			->withName("LissandraEMissile")
			->withSpeed(850.f)
			->withRange(1025.f)
			->withRadius(125.f)
			->withFlags(COLLIDE_GENERIC | PIERCE_ALL)
	},

	{ std::string("LucianW"),
		(new MissileInfo())
			->withName("LucianW")
			->withSpeed(1600.f)
			->withRange(900.f)
			->withRadius(80.f)
			->withFlags(COLLIDE_GENERIC)
	},

	{ std::string("LuluQMissile"),
		(new MissileInfo())
			->withName("LuluQMissile")
			->withSpeed(1450.f)
			->withRange(925.f)
			->withRadius(60.f)
			->withFlags(COLLIDE_GENERIC | PIERCE_ALL)
	},

	{ std::string("LuxLightBindingDummy"),
		(new MissileInfo())
			->withName("LuxLightBindingDummy")
			->withSpeed(1200.f)
			->withRange(1175.f)
			->withRadius(70.f)
			->withFlags(COLLIDE_GENERIC | PIERCE_ALL)
	},

	{ std::string("LuxLightStrikeKugel"),
		(new MissileInfo())
			->withName("LuxLightStrikeKugel")
			->withSpeed(1200.f)
			->withRange(1100.f)
			->withRadius(50.f)
			->withRadiusImpact(300.f)
			->withFlags(COLLIDE_WINDWALL | FIXED_LOCATION)
	},

	{ std::string("LuxRVfxMis"),
		(new MissileInfo())
			->withName("LuxRVfxMis")
			->withSpeed(1000000.f)
			->withRange(3340.f)
			->withRadius(120.f)
			->withFlags(COLLIDE_MOB | COLLIDE_CHAMPION | PIERCE_ALL)
	},

	{ std::string("MaokaiQMissile"),
		(new MissileInfo())
			->withName("MaokaiQMissile")
			->withSpeed(1600.f)
			->withRange(600.f)
			->withRadius(110.f)
			->withFlags(COLLIDE_GENERIC | PIERCE_ALL)
	},

	{ std::string("MorganaQ"),
		(new MissileInfo())
			->withName("MorganaQ")
			->withSpeed(1200.f)
			->withRange(1250.f)
			->withRadius(70.f)
			->withFlags(COLLIDE_GENERIC)
	},

	{ std::string("NamiQMissile"),
		(new MissileInfo())
			->withName("NamiQMissile")
			->withSpeed(1000.f)
			->withRange(875.f)
			->withRadiusImpact(180.f)
			->withFlags(FIXED_LOCATION)
	},

	{ std::string("NamiRMissile"),
		(new MissileInfo())
			->withName("NamiRMissile")
			->withSpeed(850.f)
			->withRange(2750.f)
			->withRadius(250.f)
			->withFlags(COLLIDE_GENERIC | PIERCE_ALL)
	},

	{ std::string("NautilusAnchorDragMissile"),
		(new MissileInfo())
			->withName("NautilusAnchorDragMissile")
			->withSpeed(2000.f)
			->withRange(925.f)
			->withRadius(90.f)
			->withFlags(COLLIDE_GENERIC)
	},

	{ std::string("NeekoQ"),
		(new MissileInfo())
			->withName("NeekoQ")
			->withSpeed(1500.f)
			->withRange(800.f)
			->withRadiusImpact(200.f)
			->withFlags(FIXED_LOCATION | COLLIDE_WALL)
	},

	{ std::string("NeekoE"),
		(new MissileInfo())
			->withName("NeekoE")
			->withSpeed(1300.f)
			->withRange(1000.f)
			->withRadius(70.f)
			->withFlags(COLLIDE_GENERIC | PIERCE_ALL)
	},

	{ std::string("JavelinToss"),
		(new MissileInfo())
			->withName("JavelinToss")
			->withSpeed(1300.f)
			->withRange(1500.f)
			->withRadius(40.f)
			->withFlags(COLLIDE_GENERIC)
	},

	{ std::string("NocturneDuskbringer"),
		(new MissileInfo())
			->withName("NocturneDuskbringer")
			->withSpeed(1600.f)
			->withRange(1200.f)
			->withRadius(60.f)
			->withFlags(COLLIDE_GENERIC | PIERCE_ALL)
	},

	{ std::string("OlafAxeThrow"),
		(new MissileInfo())
			->withName("OlafAxeThrow")
			->withSpeed(1600.f)
			->withRange(1000.f)
			->withRadius(90.f)
			->withFlags(COLLIDE_GENERIC | PIERCE_ALL)
	},

	{ std::string("OrianaIzuna"),
		(new MissileInfo())
			->withName("OrianaIzuna")
			->withSpeed(1400.f)
			->withRange(825.f)
			->withRadius(80.f)
			->withFlags(COLLIDE_GENERIC | PIERCE_ALL)
	},

	{ std::string("PantheonQMissile"),
		(new MissileInfo())
			->withName("PantheonQMissile")
			->withSpeed(2700.f)
			->withRange(1200.f)
			->withRadius(60.f)
			->withFlags(COLLIDE_GENERIC | PIERCE_ALL)
	},

	{ std::string("PoppyRMissile"),
		(new MissileInfo())
			->withName("PoppyRMissile")
			->withSpeed(2000.f)
			->withRange(1200.f)
			->withRadius(100.f)
			->withFlags(FIXED_LOCATION)
	},

	{ std::string("PykeQRange"),
		(new MissileInfo())
			->withName("PykeQRange")
			->withSpeed(2000.f)
			->withRange(1100.f)
			->withRadius(70.f)
			->withFlags(COLLIDE_GENERIC)
	},

	{ std::string("QuinnQ"),
		(new MissileInfo())
			->withName("QuinnQ")
			->withSpeed(1550.f)
			->withRange(1025.f)
			->withRadius(60.f)
			->withFlags(COLLIDE_GENERIC)
	},

	{ std::string("RakanQMis"),
		(new MissileInfo())
			->withName("RakanQMis")
			->withSpeed(1850.f)
			->withRange(850.f)
			->withRadius(65.f)
			->withFlags(COLLIDE_GENERIC)
	},

	{ std::string("RekSaiQBurrowedMis"),
		(new MissileInfo())
			->withName("RekSaiQBurrowedMis")
			->withSpeed(1950.f)
			->withRange(1625.f)
			->withRadius(65.f)
			->withFlags(COLLIDE_GENERIC)
	},

	{ std::string("RengarEMis"),
		(new MissileInfo())
			->withName("RengarEMis")
			->withSpeed(1500.f)
			->withRange(1000.f)
			->withRadius(70.f)
			->withFlags(COLLIDE_GENERIC)
	},

	{ std::string("RumbleGrenadeMissile"),
		(new MissileInfo())
			->withName("RumbleGrenadeMissile")
			->withSpeed(2000.f)
			->withRange(850.f)
			->withRadius(60.f)
			->withFlags(COLLIDE_GENERIC)
	},

	{ std::string("RyzeQ"),
		(new MissileInfo())
			->withName("RyzeQ")
			->withSpeed(1700.f)
			->withRange(1000.f)
			->withRadius(55.f)
			->withFlags(COLLIDE_GENERIC)
	},

	{ std::string("SamiraQGun"),
		(new MissileInfo())
			->withName("SamiraQGun")
			->withSpeed(2600.f)
			->withRange(1000.f)
			->withRadius(60.f)
			->withFlags(COLLIDE_GENERIC)
	},

	{ std::string("SejuaniRMissile"),
		(new MissileInfo())
			->withName("SejuaniRMissile")
			->withSpeed(1600.f)
			->withRange(1300.f)
			->withRadius(120.f)
			->withFlags(FIXED_LOCATION | COLLIDE_WINDWALL)
	},

	{ std::string("SennaW"),
		(new MissileInfo())
			->withName("SennaW")
			->withSpeed(1150.f)
			->withRange(1300.f)
			->withRadius(60.f)
			->withFlags(COLLIDE_GENERIC)
	},

	{ std::string("SennaRWarningMis"),
		(new MissileInfo())
			->withName("SennaRWarningMis")
			->withSpeed(20000.f)
			->withRange(20000.f)
			->withRadius(180.f)
			->withFlags(COLLIDE_GENERIC | PIERCE_ALL)
	},

	{ std::string("SeraphineQInitialMissile"),
		(new MissileInfo())
			->withName("SeraphineQInitialMissile")
			->withSpeed(1200.f)
			->withRange(900.f)
			->withRadius(50.f)
			->withRadiusImpact(350.f)
			->withFlags(FIXED_LOCATION | COLLIDE_WINDWALL)
	},

	{ std::string("SeraphineEMissile"),
		(new MissileInfo())
			->withName("SeraphineEMissile")
			->withSpeed(1200.f)
			->withRange(1300.f)
			->withRadius(70.f)
			->withFlags(COLLIDE_GENERIC | PIERCE_ALL)
	},

	{ std::string("SeraphineR"),
		(new MissileInfo())
			->withName("SeraphineR")
			->withSpeed(1600.f)
			->withRange(1200.f)
			->withRadius(160.f)
			->withFlags(COLLIDE_GENERIC | PIERCE_ALL)
	},

	{ std::string("ShyvanaFireballMissile"),
		(new MissileInfo())
			->withName("ShyvanaFireballMissile")
			->withSpeed(1575.f)
			->withRange(925.f)
			->withRadius(60.f)
			->withFlags(COLLIDE_GENERIC | PIERCE_MOB)
	},

	{ std::string("ShyvanaFireballDragonMissile"),
		(new MissileInfo())
			->withName("ShyvanaFireballDragonMissile")
			->withSpeed(1575.f)
			->withRange(975.f)
			->withRadius(60.f)
			->withFlags(COLLIDE_GENERIC)
	},

	{ std::string("SionEMissile"),
		(new MissileInfo())
			->withName("SionEMissile")
			->withSpeed(1800.f)
			->withRange(800.f)
			->withRadius(80.f)
			->withFlags(COLLIDE_GENERIC)
	},

	{ std::string("SivirQMissile"),
		(new MissileInfo())
			->withName("SivirQMissile")
			->withSpeed(1350.f)
			->withRange(1250.f)
			->withRadius(90.f)
			->withFlags(COLLIDE_GENERIC | PIERCE_ALL)
	},

	{ std::string("SkarnerFractureMissile"),
		(new MissileInfo())
			->withName("SkarnerFractureMissile")
			->withSpeed(1500.f)
			->withRange(1000.f)
			->withRadius(70.f)
			->withFlags(COLLIDE_GENERIC | PIERCE_ALL)
	},

	{ std::string("SonaRMissile"),
		(new MissileInfo())
			->withName("SonaRMissile")
			->withSpeed(2400.f)
			->withRange(1000.f)
			->withRadius(140.f)
			->withFlags(COLLIDE_GENERIC | PIERCE_ALL)
	},

	{ std::string("SorakaQMissile"),
		(new MissileInfo())
			->withName("SorakaQMissile")
			->withSpeed(1150.f)
			->withRange(810.f)
			->withRadius(35.f)
			->withRadiusImpact(235.f)
			->withFlags(FIXED_LOCATION)
	},

	{ std::string("SylasE2Mis"),
		(new MissileInfo())
			->withName("SylasE2Mis")
			->withSpeed(1600.f)
			->withRange(850.f)
			->withRadius(60.f)
			->withFlags(COLLIDE_GENERIC)
	},

	{ std::string("TahmKenchQMissile"),
		(new MissileInfo())
			->withName("TahmKenchQMissile")
			->withSpeed(2800.f)
			->withRange(900.f)
			->withRadius(70.f)
			->withFlags(COLLIDE_GENERIC)
	},

	{ std::string(""),
		(new MissileInfo())
			->withName("")
			->withSpeed(0)
			->withRange(0)
			->withRadius(0)
			->withFlags(NONE)
	},

	{ std::string("TaliyahQMis"),
		(new MissileInfo())
			->withName("TaliyahQMis")
			->withSpeed(3600.f)
			->withRange(1000.f)
			->withRadius(100.f)
			->withFlags(COLLIDE_GENERIC)
	},

	{ std::string("TaliyahRMis"),
		(new MissileInfo())
			->withName("TaliyahRMis")
			->withSpeed(1700.f)
			->withRange(3000.f)
			->withRadius(120.f)
			->withFlags(COLLIDE_GENERIC | PIERCE_ALL)
	},

	{ std::string("TalonWMissileOne"),
		(new MissileInfo())
			->withName("TalonWMissileOne")
			->withSpeed(2500.f)
			->withRange(650.f)
			->withRadius(75.f)
			->withFlags(COLLIDE_GENERIC | PIERCE_ALL)
	},

	{ std::string("ThreshQMissile"),
		(new MissileInfo())
			->withName("ThreshQMissile")
			->withSpeed(1900.f)
			->withRange(1100.f)
			->withRadius(70.f)
			->withFlags(COLLIDE_GENERIC)
	},

	{ std::string(""),
		(new MissileInfo())
			->withName("")
			->withSpeed(0)
			->withRange(0)
			->withRadius(0)
			->withFlags(NONE)
	},

	{ std::string("SealFateMissile"),
		(new MissileInfo())
			->withName("SealFateMissile")
			->withSpeed(1000.f)
			->withRange(1450.f)
			->withRadius(40.f)
			->withFlags(COLLIDE_GENERIC | PIERCE_ALL)
	},

	{ std::string("UrgotQMissile"),
		(new MissileInfo())
			->withName("UrgotQMissile")
			->withSpeed(1000.f)
			->withRange(800.f)
			->withRadiusImpact(180.f)
			->withFlags(FIXED_LOCATION)
	},

	{ std::string("UrgotR"),
		(new MissileInfo())
			->withName("UrgotR")
			->withSpeed(3200.f)
			->withRange(1600.f)
			->withRadius(80.f)
			->withFlags(COLLIDE_GENERIC | PIERCE_MOB)
	},

	{ std::string("VarusQMissile"),
		(new MissileInfo())
			->withName("VarusQMissile")
			->withSpeed(1900.f)
			->withRange(1525.f)
			->withRadius(70.f)
			->withFlags(COLLIDE_GENERIC | PIERCE_ALL)
	},

	{ std::string("VarusEMissile"),
		(new MissileInfo())
			->withName("VarusEMissile")
			->withSpeed(1500.f)
			->withRange(925.f)
			->withRadiusImpact(260.f)
			->withFlags(FIXED_LOCATION)
	},

	{ std::string("VarusRMissile"),
		(new MissileInfo())
			->withName("VarusRMissile")
			->withSpeed(1500.f)
			->withRange(1200.f)
			->withRadius(120.f)
			->withFlags(COLLIDE_GENERIC)
	},

	{ std::string("VeigarBalefulStrikeMis"),
		(new MissileInfo())
			->withName("VeigarBalefulStrikeMis")
			->withSpeed(2200.f)
			->withRange(900.f)
			->withRadius(70)
			->withFlags(COLLIDE_GENERIC)
	},

	{ std::string("VelkozQMissileSplit"),
		(new MissileInfo())
			->withName("VelkozQMissileSplit")
			->withSpeed(2100.f)
			->withRange(1100.f)
			->withRadius(45.f)
			->withFlags(COLLIDE_GENERIC)
	},

	{ std::string("VelkozQMissile"),
		(new MissileInfo())
			->withName("VelkozQMissile")
			->withSpeed(1300.f)
			->withRange(1050.f)
			->withRadius(50.f)
			->withFlags(COLLIDE_GENERIC)
	},

	{ std::string("VelkozWMissile"),
		(new MissileInfo())
			->withName("VelkozWMissile")
			->withSpeed(1700.f)
			->withRange(1050.f)
			->withRadiusImpact(87.5f)
			->withFlags(FIXED_LOCATION)
	},

	{ std::string("ViktorDeathRayMissile"),
		(new MissileInfo())
			->withName("ViktorDeathRayMissile")
			->withSpeed(1050.f)
			->withRange(700.f)
			->withRadius(80.f)
			->withFlags(COLLIDE_GENERIC | PIERCE_ALL)
	},

	{ std::string("XayahQ"),
		(new MissileInfo())
			->withName("XayahQ")
			->withSpeed(2075.f)
			->withRange(1100.f)
			->withRadius(45.f)
			->withFlags(COLLIDE_GENERIC | PIERCE_ALL)
	},

	{ std::string("XerathMageSpearMissile"),
		(new MissileInfo())
			->withName("XerathMageSpearMissile")
			->withSpeed(1400.f)
			->withRange(1050.f)
			->withRadius(60.f)
			->withFlags(COLLIDE_GENERIC)
	},

	{ std::string("XerathLocusPulse"),
		(new MissileInfo())
			->withName("XerathLocusPulse")
			->withSpeed(10000.f)
			->withRange(5000.f)
			->withRadiusImpact(200.f)
			->withFlags(FIXED_LOCATION)
	},

	{ std::string("YasuoQ3Mis"),
		(new MissileInfo())
			->withName("YasuoQ3Mis")
			->withSpeed(1200.f)
			->withRange(1000.f)
			->withRadius(90.f)
			->withFlags(COLLIDE_GENERIC | PIERCE_ALL)
	},

	{ std::string("YoneQ3Missile"),
		(new MissileInfo())
			->withName("YoneQ3Missile")
			->withSpeed(1500.f)
			->withRange(1050.f)
			->withRadius(80.f)
			->withFlags(COLLIDE_GENERIC | PIERCE_ALL)
	},

	{ std::string("ZacQMissile"),
		(new MissileInfo())
			->withName("ZacQMissile")
			->withSpeed(2800.f)
			->withRange(800.f)
			->withRadius(120.f)
			->withFlags(COLLIDE_GENERIC)
	},

	{ std::string("ZedQMissile"),
		(new MissileInfo())
			->withName("ZedQMissile")
			->withSpeed(1700.f)
			->withRange(900.f)
			->withRadius(50.f)
			->withFlags(COLLIDE_GENERIC | PIERCE_ALL)
	},

	{ std::string("ZiggsQSpell"),
		(new MissileInfo())
			->withName("ZiggsQSpell")
			->withSpeed(1750.f)
			->withRange(850.f)
			->withRadiusImpact(150.f)
			->withFlags(FIXED_LOCATION | COLLIDE_WINDWALL)
	},

	{ std::string("ZiggsW"),
		(new MissileInfo())
			->withName("ZiggsW")
			->withSpeed(1750.f)
			->withRange(1000.f)
			->withRadiusImpact(240.f)
			->withFlags(FIXED_LOCATION | COLLIDE_WINDWALL)
	},

	{ std::string("ZiggsE"),
		(new MissileInfo())
			->withName("ZiggsE")
			->withSpeed(1800.f)
			->withRange(900.f)
			->withRadiusImpact(250.f)
			->withFlags(FIXED_LOCATION | COLLIDE_WINDWALL)
	},

	{ std::string("ZiggsRBoom"),
		(new MissileInfo())
			->withName("ZiggsRBoom")
			->withSpeed(1550.f)
			->withRange(5000.f)
			->withRadiusImpact(480.f)
			->withFlags(FIXED_LOCATION)
	},

	{ std::string("ZileanQMissile"),
		(new MissileInfo())
			->withName("ZileanQMissile")
			->withSpeed(10000.f)
			->withRange(900.f)
			->withRadius(150.f)
			->withFlags(FIXED_LOCATION | COLLIDE_WINDWALL)
	},

	{ std::string("ZoeQMissile"),
		(new MissileInfo())
			->withName("ZoeQMissile")
			->withSpeed(1200.f)
			->withRange(800.f)
			->withRadius(50.f)
			->withFlags(COLLIDE_GENERIC)
	},

	{ std::string("ZoeQMis2"),
		(new MissileInfo())
			->withName("ZoeQMis2")
			->withSpeed(2500.f)
			->withRange(1600.f)
			->withRadius(70.f)
			->withFlags(COLLIDE_GENERIC)
	},

	{ std::string("ZoeEMis"),
		(new MissileInfo())
			->withName("ZoeEMis")
			->withSpeed(1700.f)
			->withRange(800.f)
			->withRadius(50.f)
			->withFlags(COLLIDE_GENERIC | FIXED_LOCATION)
	},

	{ std::string("ZyraE"),
		(new MissileInfo())
			->withName("ZyraE")
			->withSpeed(1150.f)
			->withRange(1100.f)
			->withRadius(70.f)
			->withFlags(COLLIDE_GENERIC | PIERCE_ALL)
	},

	// Minions

	{ std::string("SRU_OrderMinionRangedBasicAttack"),
		(new MissileInfo())
			->withName("SRU_OrderMinionRangedBasicAttack")
			->withSpeed(650.f)
			->withRange(0.f)
			->withRadius(5.f)
			->withFlags(COLLIDE_WINDWALL | TARGETED)
	},

	{ std::string("SRU_OrderMinionRangedBasicAttack2"),
		(new MissileInfo())
			->withName("SRU_OrderMinionRangedBasicAttack2")
			->withSpeed(650.f)
			->withRange(0.f)
			->withRadius(5.f)
			->withFlags(COLLIDE_WINDWALL | TARGETED)
	},

	{ std::string("SRU_OrderMinionSiegeBasicAttack"),
		(new MissileInfo())
			->withName("SRU_OrderMinionSiegeBasicAttack")
			->withSpeed(1200.f)
			->withRange(0.f)
			->withRadius(8.f)
			->withFlags(COLLIDE_WINDWALL | TARGETED)
	},

	{ std::string("SRU_ChaosMinionRangedBasicAttack"),
			(new MissileInfo())
				->withName("SRU_ChaosMinionRangedBasicAttack")
				->withSpeed(650.f)
				->withRange(0.f)
				->withRadius(5.f)
				->withFlags(COLLIDE_WINDWALL | TARGETED)
	},

	{ std::string("SRU_ChaosMinionRangedBasicAttack2"),
		(new MissileInfo())
			->withName("SRU_ChaosMinionRangedBasicAttack2")
			->withSpeed(650.f)
			->withRange(0.f)
			->withRadius(5.f)
			->withFlags(COLLIDE_WINDWALL | TARGETED)
	},

	{ std::string("SRU_ChaosMinionSiegeBasicAttack"),
		(new MissileInfo())
			->withName("SRU_ChaosMinionSiegeBasicAttack")
			->withSpeed(1200.f)
			->withRange(0.f)
			->withRadius(8.f)
			->withFlags(COLLIDE_WINDWALL | TARGETED)
	},
};