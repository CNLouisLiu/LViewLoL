
#include "UnitInfo.h"

// Generated automatically
std::map<std::string, UnitInfo*> UnitInfo::infos = {
{ std::string("unknown"), new UnitInfo() },

{ std::string("aatrox"), 
  new UnitInfo(
  {
       /* name                 */      "aatrox",                                           
       /* healthBarHeight      */      140.0,                   
       /* baseMoveSpeed        */      345.0,                     
       /* attackRange          */      175.0,                       
       /* attackSpeed          */      0.6510000228881836,                       
       /* attackSpeedRatio     */      0.6510000228881836,                  
                                                                            
       /* acquisitionRange     */      475.0,                  
       /* selectionRadius      */      135.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      347.79998779296875,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("ahri"), 
  new UnitInfo(
  {
       /* name                 */      "ahri",                                           
       /* healthBarHeight      */      94.0,                   
       /* baseMoveSpeed        */      330.0,                     
       /* attackRange          */      550.0,                       
       /* attackSpeed          */      0.6679999828338623,                       
       /* attackSpeedRatio     */      0.6679999828338623,                  
                                                                            
       /* acquisitionRange     */      525.0,                  
       /* selectionRadius      */      100.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      1750.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("akali"), 
  new UnitInfo(
  {
       /* name                 */      "akali",                                           
       /* healthBarHeight      */      105.0,                   
       /* baseMoveSpeed        */      345.0,                     
       /* attackRange          */      125.0,                       
       /* attackSpeed          */      0.625,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      400.0,                  
       /* selectionRadius      */      100.0,            
       /* pathRadius           */      30.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("alistar"), 
  new UnitInfo(
  {
       /* name                 */      "alistar",                                           
       /* healthBarHeight      */      120.0,                   
       /* baseMoveSpeed        */      330.0,                     
       /* attackRange          */      125.0,                       
       /* attackSpeed          */      0.625,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      145.0,            
       /* pathRadius           */      50.0,        
       /* gameplayRadius       */      80.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("amumu"), 
  new UnitInfo(
  {
       /* name                 */      "amumu",                                           
       /* healthBarHeight      */      68.0,                   
       /* baseMoveSpeed        */      335.0,                     
       /* attackRange          */      125.0,                       
       /* attackSpeed          */      0.7360000014305115,                       
       /* attackSpeedRatio     */      0.6380000114440918,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      100.0,            
       /* pathRadius           */      30.0,        
       /* gameplayRadius       */      55.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("anivia"), 
  new UnitInfo(
  {
       /* name                 */      "anivia",                                           
       /* healthBarHeight      */      120.0,                   
       /* baseMoveSpeed        */      325.0,                     
       /* attackRange          */      600.0,                       
       /* attackSpeed          */      0.625,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      140.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      1500.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("aniviaegg"), 
  new UnitInfo(
  {
       /* name                 */      "aniviaegg",                                           
       /* healthBarHeight      */      120.0,                   
       /* baseMoveSpeed        */      325.0,                     
       /* attackRange          */      600.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      80.0,            
       /* pathRadius           */      54.400001525878906,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("aniviaiceblock"), 
  new UnitInfo(
  {
       /* name                 */      "aniviaiceblock",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      130.0,            
       /* pathRadius           */      100.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("annie"), 
  new UnitInfo(
  {
       /* name                 */      "annie",                                           
       /* healthBarHeight      */      85.0,                   
       /* baseMoveSpeed        */      335.0,                     
       /* attackRange          */      625.0,                       
       /* attackSpeed          */      0.5789999961853027,                       
       /* attackSpeedRatio     */      0.5789999961853027,                  
                                                                            
       /* acquisitionRange     */      625.0,                  
       /* selectionRadius      */      100.0,            
       /* pathRadius           */      30.0,        
       /* gameplayRadius       */      55.0,
       
       /* basicAtkMissileSpeed */      1200.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("annietibbers"), 
  new UnitInfo(
  {
       /* name                 */      "annietibbers",                                           
       /* healthBarHeight      */      92.0,                   
       /* baseMoveSpeed        */      350.0,                     
       /* attackRange          */      150.0,                       
       /* attackSpeed          */      1.7359999418258667,                       
       /* attackSpeedRatio     */      1.7359999418258667,                  
                                                                            
       /* acquisitionRange     */      625.0,                  
       /* selectionRadius      */      155.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      80.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Minion).set(Unit_Minion_Summon).set(Unit_Minion_Summon_Large)
  })
},


{ std::string("aphelios"), 
  new UnitInfo(
  {
       /* name                 */      "aphelios",                                           
       /* healthBarHeight      */      130.0,                   
       /* baseMoveSpeed        */      325.0,                     
       /* attackRange          */      550.0,                       
       /* attackSpeed          */      0.6399999856948853,                       
       /* attackSpeedRatio     */      0.6399999856948853,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      110.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("apheliosturret"), 
  new UnitInfo(
  {
       /* name                 */      "apheliosturret",                                           
       /* healthBarHeight      */      215.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      600.0,                       
       /* attackSpeed          */      0.800000011920929,                       
       /* attackSpeedRatio     */      0.800000011920929,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      80.0,            
       /* pathRadius           */      8.5,        
       /* gameplayRadius       */      20.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Minion).set(Unit_Minion_Summon)
  })
},


{ std::string("ashe"), 
  new UnitInfo(
  {
       /* name                 */      "ashe",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      325.0,                     
       /* attackRange          */      600.0,                       
       /* attackSpeed          */      0.6579999923706055,                       
       /* attackSpeedRatio     */      0.6579999923706055,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      120.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      2500.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("assassinmode_mookcounticon"), 
  new UnitInfo(
  {
       /* name                 */      "assassinmode_mookcounticon",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      20.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      1.0,            
       /* pathRadius           */      1.0,        
       /* gameplayRadius       */      1.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("assassinmode_objective_boss2"), 
  new UnitInfo(
  {
       /* name                 */      "assassinmode_objective_boss2",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      325.0,                     
       /* attackRange          */      150.0,                       
       /* attackSpeed          */      0.6669999957084656,                       
       /* attackSpeedRatio     */      0.6669999957084656,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      120.0,            
       /* pathRadius           */      30.0,        
       /* gameplayRadius       */      110.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Monster_Epic).set(Unit_Monster).set(Unit_Special_Void).set(Unit_Monster_Camp)
  })
},


{ std::string("assassinmode_roamingunit"), 
  new UnitInfo(
  {
       /* name                 */      "assassinmode_roamingunit",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      250.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.6579999923706055,                       
       /* attackSpeedRatio     */      0.6579999923706055,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      100.0,            
       /* pathRadius           */      10.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Special_TurretIgnores).set(Unit_Minion).set(Unit_Special_MonsterIgnores).set(Unit_Special_EpicMonsterIgnores)
  })
},


{ std::string("aurelionsol"), 
  new UnitInfo(
  {
       /* name                 */      "aurelionsol",                                           
       /* healthBarHeight      */      120.0,                   
       /* baseMoveSpeed        */      325.0,                     
       /* attackRange          */      550.0,                       
       /* attackSpeed          */      0.625,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      400.0,                  
       /* selectionRadius      */      165.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      4000.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("azir"), 
  new UnitInfo(
  {
       /* name                 */      "azir",                                           
       /* healthBarHeight      */      95.0,                   
       /* baseMoveSpeed        */      335.0,                     
       /* attackRange          */      525.0,                       
       /* attackSpeed          */      0.625,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      700.0,                  
       /* selectionRadius      */      88.88890075683594,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      2600.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("azirsoldier"), 
  new UnitInfo(
  {
       /* name                 */      "azirsoldier",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      375.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      1.0,            
       /* pathRadius           */      0.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Special_AzirW)
  })
},


{ std::string("azirsundisc"), 
  new UnitInfo(
  {
       /* name                 */      "azirsundisc",                                           
       /* healthBarHeight      */      615.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      750.0,                       
       /* attackSpeed          */      0.8330000042915344,                       
       /* attackSpeedRatio     */      0.8330000042915344,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      280.0,            
       /* pathRadius           */      0.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      1200.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Structure).set(Unit_Structure_Turret)
  })
},


{ std::string("azirtowerclicker"), 
  new UnitInfo(
  {
       /* name                 */      "azirtowerclicker",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      50.0,                  
       /* selectionRadius      */      80.0,            
       /* pathRadius           */      0.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("azirultsoldier"), 
  new UnitInfo(
  {
       /* name                 */      "azirultsoldier",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      1.0,            
       /* pathRadius           */      125.0,        
       /* gameplayRadius       */      125.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Special_AzirR)
  })
},


{ std::string("bard"), 
  new UnitInfo(
  {
       /* name                 */      "bard",                                           
       /* healthBarHeight      */      110.0,                   
       /* baseMoveSpeed        */      330.0,                     
       /* attackRange          */      500.0,                       
       /* attackSpeed          */      0.625,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      88.88890075683594,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      80.0,
       
       /* basicAtkMissileSpeed */      2000.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("bardfollower"), 
  new UnitInfo(
  {
       /* name                 */      "bardfollower",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      345.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      1.0,            
       /* pathRadius           */      1.0,        
       /* gameplayRadius       */      50.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("bardhealthshrine"), 
  new UnitInfo(
  {
       /* name                 */      "bardhealthshrine",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      1.0,            
       /* pathRadius           */      1.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("bardpickup"), 
  new UnitInfo(
  {
       /* name                 */      "bardpickup",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      350.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      1.0,            
       /* pathRadius           */      1.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("bardpickupnoicon"), 
  new UnitInfo(
  {
       /* name                 */      "bardpickupnoicon",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      350.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      1.0,            
       /* pathRadius           */      1.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("blitzcrank"), 
  new UnitInfo(
  {
       /* name                 */      "blitzcrank",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      325.0,                     
       /* attackRange          */      125.0,                       
       /* attackSpeed          */      0.625,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      165.0,            
       /* pathRadius           */      50.0,        
       /* gameplayRadius       */      80.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("bluetrinket"), 
  new UnitInfo(
  {
       /* name                 */      "bluetrinket",                                           
       /* healthBarHeight      */      180.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      0.0,            
       /* pathRadius           */      5.0,        
       /* gameplayRadius       */      1.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Special_TurretIgnores).set(Unit_Ward).set(Unit_Special)
  })
},


{ std::string("brand"), 
  new UnitInfo(
  {
       /* name                 */      "brand",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      340.0,                     
       /* attackRange          */      550.0,                       
       /* attackSpeed          */      0.625,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      88.88890075683594,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      2000.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("braum"), 
  new UnitInfo(
  {
       /* name                 */      "braum",                                           
       /* healthBarHeight      */      110.0,                   
       /* baseMoveSpeed        */      335.0,                     
       /* attackRange          */      125.0,                       
       /* attackSpeed          */      0.6439999938011169,                       
       /* attackSpeedRatio     */      0.6439999938011169,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      100.0,            
       /* pathRadius           */      50.0,        
       /* gameplayRadius       */      80.0,
       
       /* basicAtkMissileSpeed */      347.79998779296875,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("bw_anclantern"), 
  new UnitInfo(
  {
       /* name                 */      "bw_anclantern",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      0.0,            
       /* pathRadius           */      0.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("bw_ap_bubbs"), 
  new UnitInfo(
  {
       /* name                 */      "bw_ap_bubbs",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      345.0,                     
       /* attackRange          */      175.0,                       
       /* attackSpeed          */      0.6579999923706055,                       
       /* attackSpeedRatio     */      0.6579999923706055,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      100.0,            
       /* pathRadius           */      30.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("bw_ap_chaosturret"), 
  new UnitInfo(
  {
       /* name                 */      "bw_ap_chaosturret",                                           
       /* healthBarHeight      */      525.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      750.0,                       
       /* attackSpeed          */      0.8330000042915344,                       
       /* attackSpeedRatio     */      0.8330000042915344,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      130.0,            
       /* pathRadius           */      125.0,        
       /* gameplayRadius       */      88.4000015258789,
       
       /* basicAtkMissileSpeed */      1200.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Structure).set(Unit_Structure_Turret).set(Unit_Structure_Turret_Outer)
  })
},


{ std::string("bw_ap_chaosturret2"), 
  new UnitInfo(
  {
       /* name                 */      "bw_ap_chaosturret2",                                           
       /* healthBarHeight      */      525.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      750.0,                       
       /* attackSpeed          */      0.8330000042915344,                       
       /* attackSpeedRatio     */      0.8330000042915344,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      130.0,            
       /* pathRadius           */      125.0,        
       /* gameplayRadius       */      88.4000015258789,
       
       /* basicAtkMissileSpeed */      1200.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Structure).set(Unit_Structure_Turret).set(Unit_Structure_Turret_Inhib)
  })
},


{ std::string("bw_ap_chaosturret3"), 
  new UnitInfo(
  {
       /* name                 */      "bw_ap_chaosturret3",                                           
       /* healthBarHeight      */      525.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      750.0,                       
       /* attackSpeed          */      0.8330000042915344,                       
       /* attackSpeedRatio     */      0.8330000042915344,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      130.0,            
       /* pathRadius           */      125.0,        
       /* gameplayRadius       */      88.4000015258789,
       
       /* basicAtkMissileSpeed */      1200.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Structure_Turret_Nexus).set(Unit_Structure).set(Unit_Structure_Turret)
  })
},


{ std::string("bw_ap_chaosturretrubble"), 
  new UnitInfo(
  {
       /* name                 */      "bw_ap_chaosturretrubble",                                           
       /* healthBarHeight      */      525.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      750.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      130.0,            
       /* pathRadius           */      88.4000015258789,        
       /* gameplayRadius       */      88.4000015258789,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("bw_ap_finn"), 
  new UnitInfo(
  {
       /* name                 */      "bw_ap_finn",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      345.0,                     
       /* attackRange          */      175.0,                       
       /* attackSpeed          */      0.6579999923706055,                       
       /* attackSpeedRatio     */      0.6579999923706055,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      100.0,            
       /* pathRadius           */      30.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("bw_ap_orderturret"), 
  new UnitInfo(
  {
       /* name                 */      "bw_ap_orderturret",                                           
       /* healthBarHeight      */      530.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      750.0,                       
       /* attackSpeed          */      0.8330000042915344,                       
       /* attackSpeedRatio     */      0.8330000042915344,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      130.0,            
       /* pathRadius           */      125.0,        
       /* gameplayRadius       */      88.4000015258789,
       
       /* basicAtkMissileSpeed */      1200.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Structure).set(Unit_Structure_Turret).set(Unit_Structure_Turret_Outer)
  })
},


{ std::string("bw_ap_orderturret2"), 
  new UnitInfo(
  {
       /* name                 */      "bw_ap_orderturret2",                                           
       /* healthBarHeight      */      530.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      750.0,                       
       /* attackSpeed          */      0.8330000042915344,                       
       /* attackSpeedRatio     */      0.8330000042915344,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      130.0,            
       /* pathRadius           */      125.0,        
       /* gameplayRadius       */      88.4000015258789,
       
       /* basicAtkMissileSpeed */      1200.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Structure).set(Unit_Structure_Turret).set(Unit_Structure_Turret_Inhib)
  })
},


{ std::string("bw_ap_orderturret3"), 
  new UnitInfo(
  {
       /* name                 */      "bw_ap_orderturret3",                                           
       /* healthBarHeight      */      530.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      750.0,                       
       /* attackSpeed          */      0.8330000042915344,                       
       /* attackSpeedRatio     */      0.8330000042915344,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      130.0,            
       /* pathRadius           */      125.0,        
       /* gameplayRadius       */      88.4000015258789,
       
       /* basicAtkMissileSpeed */      1200.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Structure_Turret_Nexus).set(Unit_Structure).set(Unit_Structure_Turret)
  })
},


{ std::string("bw_ap_orderturretrubble"), 
  new UnitInfo(
  {
       /* name                 */      "bw_ap_orderturretrubble",                                           
       /* healthBarHeight      */      530.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      750.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      130.0,            
       /* pathRadius           */      88.4000015258789,        
       /* gameplayRadius       */      88.4000015258789,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("bw_boat"), 
  new UnitInfo(
  {
       /* name                 */      "bw_boat",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      0.0,            
       /* pathRadius           */      0.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("bw_bottle"), 
  new UnitInfo(
  {
       /* name                 */      "bw_bottle",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      345.0,                     
       /* attackRange          */      175.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      100.0,            
       /* pathRadius           */      30.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("bw_brdgdoor"), 
  new UnitInfo(
  {
       /* name                 */      "bw_brdgdoor",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      5100.0,            
       /* pathRadius           */      0.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("bw_dblrope"), 
  new UnitInfo(
  {
       /* name                 */      "bw_dblrope",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      450.0,            
       /* pathRadius           */      0.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("bw_fishhk"), 
  new UnitInfo(
  {
       /* name                 */      "bw_fishhk",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      345.0,                     
       /* attackRange          */      175.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      500.0,            
       /* pathRadius           */      30.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("bw_hcannon"), 
  new UnitInfo(
  {
       /* name                 */      "bw_hcannon",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      345.0,                     
       /* attackRange          */      175.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      400.0,            
       /* pathRadius           */      30.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("bw_lantern"), 
  new UnitInfo(
  {
       /* name                 */      "bw_lantern",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      345.0,                     
       /* attackRange          */      175.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      600.0,            
       /* pathRadius           */      30.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("bw_seagull"), 
  new UnitInfo(
  {
       /* name                 */      "bw_seagull",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      345.0,                     
       /* attackRange          */      175.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      24000.0,            
       /* pathRadius           */      30.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("bw_shadowshark"), 
  new UnitInfo(
  {
       /* name                 */      "bw_shadowshark",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      345.0,                     
       /* attackRange          */      175.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      25000.0,            
       /* pathRadius           */      30.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("bw_shortrope"), 
  new UnitInfo(
  {
       /* name                 */      "bw_shortrope",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      345.0,                     
       /* attackRange          */      175.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      100.0,            
       /* pathRadius           */      30.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("bw_shrkhk"), 
  new UnitInfo(
  {
       /* name                 */      "bw_shrkhk",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      345.0,                     
       /* attackRange          */      175.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      1000.0,            
       /* pathRadius           */      30.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("bw_signa"), 
  new UnitInfo(
  {
       /* name                 */      "bw_signa",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      345.0,                     
       /* attackRange          */      175.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      500.0,            
       /* pathRadius           */      30.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("bw_squid"), 
  new UnitInfo(
  {
       /* name                 */      "bw_squid",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      0.0,            
       /* pathRadius           */      0.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("bw_statlant"), 
  new UnitInfo(
  {
       /* name                 */      "bw_statlant",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      345.0,                     
       /* attackRange          */      175.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      1500.0,            
       /* pathRadius           */      30.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("bw_tooth"), 
  new UnitInfo(
  {
       /* name                 */      "bw_tooth",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      345.0,                     
       /* attackRange          */      175.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      100.0,            
       /* pathRadius           */      30.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("bw_vship"), 
  new UnitInfo(
  {
       /* name                 */      "bw_vship",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      345.0,                     
       /* attackRange          */      175.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      18000.0,            
       /* pathRadius           */      30.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("caitlyn"), 
  new UnitInfo(
  {
       /* name                 */      "caitlyn",                                           
       /* healthBarHeight      */      99.0,                   
       /* baseMoveSpeed        */      325.0,                     
       /* attackRange          */      650.0,                       
       /* attackSpeed          */      0.6809999942779541,                       
       /* attackSpeedRatio     */      0.5680000185966492,                  
                                                                            
       /* acquisitionRange     */      800.0,                  
       /* selectionRadius      */      120.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      2500.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("caitlyntrap"), 
  new UnitInfo(
  {
       /* name                 */      "caitlyntrap",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      0.0,            
       /* pathRadius           */      0.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Special_Trap).set(Unit_Special)
  })
},


{ std::string("camille"), 
  new UnitInfo(
  {
       /* name                 */      "camille",                                           
       /* healthBarHeight      */      110.0,                   
       /* baseMoveSpeed        */      340.0,                     
       /* attackRange          */      125.0,                       
       /* attackSpeed          */      0.6439999938011169,                       
       /* attackSpeedRatio     */      0.6439999938011169,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      100.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      467.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("cassiopeia"), 
  new UnitInfo(
  {
       /* name                 */      "cassiopeia",                                           
       /* healthBarHeight      */      110.0,                   
       /* baseMoveSpeed        */      328.0,                     
       /* attackRange          */      550.0,                       
       /* attackSpeed          */      0.6470000147819519,                       
       /* attackSpeedRatio     */      0.6470000147819519,                  
                                                                            
       /* acquisitionRange     */      550.0,                  
       /* selectionRadius      */      120.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      1200.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("cassiopeia_death"), 
  new UnitInfo(
  {
       /* name                 */      "cassiopeia_death",                                           
       /* healthBarHeight      */      110.0,                   
       /* baseMoveSpeed        */      335.0,                     
       /* attackRange          */      550.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      550.0,                  
       /* selectionRadius      */      120.0,            
       /* pathRadius           */      40.79999923706055,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("chaosinhibitor"), 
  new UnitInfo(
  {
       /* name                 */      "chaosinhibitor",                                           
       /* healthBarHeight      */      370.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      0.0,            
       /* pathRadius           */      0.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Structure_Inhibitor).set(Unit_Structure)
  })
},


{ std::string("chaosinhibitor_d"), 
  new UnitInfo(
  {
       /* name                 */      "chaosinhibitor_d",                                           
       /* healthBarHeight      */      370.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      0.0,            
       /* pathRadius           */      0.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("chaosnexus"), 
  new UnitInfo(
  {
       /* name                 */      "chaosnexus",                                           
       /* healthBarHeight      */      500.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      0.0,            
       /* pathRadius           */      0.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Structure).set(Unit_Structure_Nexus)
  })
},


{ std::string("chogath"), 
  new UnitInfo(
  {
       /* name                 */      "chogath",                                           
       /* healthBarHeight      */      93.0,                   
       /* baseMoveSpeed        */      345.0,                     
       /* attackRange          */      125.0,                       
       /* attackSpeed          */      0.625,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      130.0,            
       /* pathRadius           */      50.0,        
       /* gameplayRadius       */      80.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion).set(Unit_Special_Void)
  })
},


{ std::string("corki"), 
  new UnitInfo(
  {
       /* name                 */      "corki",                                           
       /* healthBarHeight      */      110.0,                   
       /* baseMoveSpeed        */      325.0,                     
       /* attackRange          */      550.0,                       
       /* attackSpeed          */      0.6380000114440918,                       
       /* attackSpeedRatio     */      0.6380000114440918,                  
                                                                            
       /* acquisitionRange     */      500.0,                  
       /* selectionRadius      */      135.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      2000.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("corkibomb"), 
  new UnitInfo(
  {
       /* name                 */      "corkibomb",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      950.0,                  
       /* selectionRadius      */      60.0,            
       /* pathRadius           */      45.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Special_TeleportTarget).set(Unit_Special_CorkiBomb).set(Unit_Special)
  })
},


{ std::string("corkibombally"), 
  new UnitInfo(
  {
       /* name                 */      "corkibombally",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      950.0,                  
       /* selectionRadius      */      60.0,            
       /* pathRadius           */      45.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Special_TeleportTarget).set(Unit_Special)
  })
},


{ std::string("darius"), 
  new UnitInfo(
  {
       /* name                 */      "darius",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      340.0,                     
       /* attackRange          */      175.0,                       
       /* attackSpeed          */      0.625,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      125.0,            
       /* pathRadius           */      25.766599655151367,        
       /* gameplayRadius       */      80.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("destroyednexus"), 
  new UnitInfo(
  {
       /* name                 */      "destroyednexus",                                           
       /* healthBarHeight      */      500.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      0.0,            
       /* pathRadius           */      0.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("destroyedtower"), 
  new UnitInfo(
  {
       /* name                 */      "destroyedtower",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      0.0,            
       /* pathRadius           */      0.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("diana"), 
  new UnitInfo(
  {
       /* name                 */      "diana",                                           
       /* healthBarHeight      */      90.0,                   
       /* baseMoveSpeed        */      345.0,                     
       /* attackRange          */      150.0,                       
       /* attackSpeed          */      0.625,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      400.0,                  
       /* selectionRadius      */      75.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      347.79998779296875,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("dominationscout"), 
  new UnitInfo(
  {
       /* name                 */      "dominationscout",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      0.0,            
       /* pathRadius           */      0.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Special_Trap).set(Unit_Special)
  })
},


{ std::string("doombotsbossteemo"), 
  new UnitInfo(
  {
       /* name                 */      "doombotsbossteemo",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      300.0,                     
       /* attackRange          */      500.0,                       
       /* attackSpeed          */      0.625,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      1000.0,                  
       /* selectionRadius      */      120.0,            
       /* pathRadius           */      100.0,        
       /* gameplayRadius       */      40.0,
       
       /* basicAtkMissileSpeed */      700.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Monster).set(Unit_Monster_Epic).set(Unit_Champion)
  })
},


{ std::string("doombots_cauldron"), 
  new UnitInfo(
  {
       /* name                 */      "doombots_cauldron",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      0.0,            
       /* pathRadius           */      0.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("draven"), 
  new UnitInfo(
  {
       /* name                 */      "draven",                                           
       /* healthBarHeight      */      105.0,                   
       /* baseMoveSpeed        */      330.0,                     
       /* attackRange          */      550.0,                       
       /* attackSpeed          */      0.6790000200271606,                       
       /* attackSpeedRatio     */      0.6790000200271606,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      111.11109924316406,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      1600.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("drmundo"), 
  new UnitInfo(
  {
       /* name                 */      "drmundo",                                           
       /* healthBarHeight      */      110.0,                   
       /* baseMoveSpeed        */      345.0,                     
       /* attackRange          */      125.0,                       
       /* attackSpeed          */      0.7210000157356262,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      135.0,            
       /* pathRadius           */      50.0,        
       /* gameplayRadius       */      80.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("ekko"), 
  new UnitInfo(
  {
       /* name                 */      "ekko",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      340.0,                     
       /* attackRange          */      125.0,                       
       /* attackSpeed          */      0.6880000233650208,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      120.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("elise"), 
  new UnitInfo(
  {
       /* name                 */      "elise",                                           
       /* healthBarHeight      */      117.0,                   
       /* baseMoveSpeed        */      330.0,                     
       /* attackRange          */      550.0,                       
       /* attackSpeed          */      0.625,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      550.0,                  
       /* selectionRadius      */      120.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      1600.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("elisespider"), 
  new UnitInfo(
  {
       /* name                 */      "elisespider",                                           
       /* healthBarHeight      */      70.0,                   
       /* baseMoveSpeed        */      355.0,                     
       /* attackRange          */      125.0,                       
       /* attackSpeed          */      0.625,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      145.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("elisespiderling"), 
  new UnitInfo(
  {
       /* name                 */      "elisespiderling",                                           
       /* healthBarHeight      */      20.0,                   
       /* baseMoveSpeed        */      350.0,                     
       /* attackRange          */      175.0,                       
       /* attackSpeed          */      0.6650000214576721,                       
       /* attackSpeedRatio     */      0.6650000214576721,                  
                                                                            
       /* acquisitionRange     */      400.0,                  
       /* selectionRadius      */      35.0,            
       /* pathRadius           */      1.0,        
       /* gameplayRadius       */      1.0,
       
       /* basicAtkMissileSpeed */      2000.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Minion).set(Unit_Minion_Summon)
  })
},


{ std::string("evelynn"), 
  new UnitInfo(
  {
       /* name                 */      "evelynn",                                           
       /* healthBarHeight      */      90.0,                   
       /* baseMoveSpeed        */      335.0,                     
       /* attackRange          */      125.0,                       
       /* attackSpeed          */      0.6669999957084656,                       
       /* attackSpeedRatio     */      0.6669999957084656,                  
                                                                            
       /* acquisitionRange     */      400.0,                  
       /* selectionRadius      */      120.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      467.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("ezreal"), 
  new UnitInfo(
  {
       /* name                 */      "ezreal",                                           
       /* healthBarHeight      */      90.0,                   
       /* baseMoveSpeed        */      325.0,                     
       /* attackRange          */      550.0,                       
       /* attackSpeed          */      0.625,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      550.0,                  
       /* selectionRadius      */      115.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      2000.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("fiddlesticks"), 
  new UnitInfo(
  {
       /* name                 */      "fiddlesticks",                                           
       /* healthBarHeight      */      110.0,                   
       /* baseMoveSpeed        */      335.0,                     
       /* attackRange          */      480.0,                       
       /* attackSpeed          */      0.625,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      520.0,                  
       /* selectionRadius      */      135.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("fiora"), 
  new UnitInfo(
  {
       /* name                 */      "fiora",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      345.0,                     
       /* attackRange          */      150.0,                       
       /* attackSpeed          */      0.6899999976158142,                       
       /* attackSpeedRatio     */      0.6899999976158142,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      100.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      467.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("fizz"), 
  new UnitInfo(
  {
       /* name                 */      "fizz",                                           
       /* healthBarHeight      */      80.0,                   
       /* baseMoveSpeed        */      335.0,                     
       /* attackRange          */      175.0,                       
       /* attackSpeed          */      0.6579999923706055,                       
       /* attackSpeedRatio     */      0.6579999923706055,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      108.33329772949219,            
       /* pathRadius           */      30.0,        
       /* gameplayRadius       */      55.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("fizzbait"), 
  new UnitInfo(
  {
       /* name                 */      "fizzbait",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      320.0,                     
       /* attackRange          */      175.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      108.33329772949219,            
       /* pathRadius           */      0.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("fizzshark"), 
  new UnitInfo(
  {
       /* name                 */      "fizzshark",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      320.0,                     
       /* attackRange          */      175.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      108.33329772949219,            
       /* pathRadius           */      0.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("galio"), 
  new UnitInfo(
  {
       /* name                 */      "galio",                                           
       /* healthBarHeight      */      135.0,                   
       /* baseMoveSpeed        */      335.0,                     
       /* attackRange          */      150.0,                       
       /* attackSpeed          */      0.625,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      400.0,                  
       /* selectionRadius      */      125.0,            
       /* pathRadius           */      50.0,        
       /* gameplayRadius       */      80.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("gangplank"), 
  new UnitInfo(
  {
       /* name                 */      "gangplank",                                           
       /* healthBarHeight      */      105.0,                   
       /* baseMoveSpeed        */      345.0,                     
       /* attackRange          */      125.0,                       
       /* attackSpeed          */      0.6579999923706055,                       
       /* attackSpeedRatio     */      0.6899999976158142,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      85.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("gangplankbarrel"), 
  new UnitInfo(
  {
       /* name                 */      "gangplankbarrel",                                           
       /* healthBarHeight      */      200.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      0.0,            
       /* pathRadius           */      0.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Special_UntargetableBySpells).set(Unit_IsolationNonImpacting)
  })
},


{ std::string("garen"), 
  new UnitInfo(
  {
       /* name                 */      "garen",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      340.0,                     
       /* attackRange          */      175.0,                       
       /* attackSpeed          */      0.625,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      400.0,                  
       /* selectionRadius      */      75.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      347.79998779296875,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("gnar"), 
  new UnitInfo(
  {
       /* name                 */      "gnar",                                           
       /* healthBarHeight      */      80.0,                   
       /* baseMoveSpeed        */      335.0,                     
       /* attackRange          */      175.0,                       
       /* attackSpeed          */      0.625,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      100.0,            
       /* pathRadius           */      30.0,        
       /* gameplayRadius       */      55.0,
       
       /* basicAtkMissileSpeed */      1500.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("gnarbig"), 
  new UnitInfo(
  {
       /* name                 */      "gnarbig",                                           
       /* healthBarHeight      */      120.0,                   
       /* baseMoveSpeed        */      335.0,                     
       /* attackRange          */      175.0,                       
       /* attackSpeed          */      0.625,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      180.0,            
       /* pathRadius           */      50.0,        
       /* gameplayRadius       */      80.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("gragas"), 
  new UnitInfo(
  {
       /* name                 */      "gragas",                                           
       /* healthBarHeight      */      110.0,                   
       /* baseMoveSpeed        */      330.0,                     
       /* attackRange          */      125.0,                       
       /* attackSpeed          */      0.675000011920929,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      155.0,            
       /* pathRadius           */      50.0,        
       /* gameplayRadius       */      80.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("graves"), 
  new UnitInfo(
  {
       /* name                 */      "graves",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      340.0,                     
       /* attackRange          */      425.0,                       
       /* attackSpeed          */      0.4749999940395355,                       
       /* attackSpeedRatio     */      0.49000000953674316,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      110.0,            
       /* pathRadius           */      10.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      3000.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("habw_banner"), 
  new UnitInfo(
  {
       /* name                 */      "habw_banner",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      345.0,                     
       /* attackRange          */      175.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      1000.0,            
       /* pathRadius           */      30.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("ha_ap_bannermidbridge"), 
  new UnitInfo(
  {
       /* name                 */      "ha_ap_bannermidbridge",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      0.0,            
       /* pathRadius           */      0.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("ha_ap_bridgelanestatue"), 
  new UnitInfo(
  {
       /* name                 */      "ha_ap_bridgelanestatue",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      4000.0,            
       /* pathRadius           */      0.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("ha_ap_chains"), 
  new UnitInfo(
  {
       /* name                 */      "ha_ap_chains",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      4000.0,            
       /* pathRadius           */      0.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("ha_ap_chains_long"), 
  new UnitInfo(
  {
       /* name                 */      "ha_ap_chains_long",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      4000.0,            
       /* pathRadius           */      0.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("ha_ap_chaosturret"), 
  new UnitInfo(
  {
       /* name                 */      "ha_ap_chaosturret",                                           
       /* healthBarHeight      */      600.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      750.0,                       
       /* attackSpeed          */      0.8330000042915344,                       
       /* attackSpeedRatio     */      0.8330000042915344,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      130.0,            
       /* pathRadius           */      125.0,        
       /* gameplayRadius       */      88.4000015258789,
       
       /* basicAtkMissileSpeed */      1200.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Structure).set(Unit_Structure_Turret).set(Unit_Structure_Turret_Outer)
  })
},


{ std::string("ha_ap_chaosturret2"), 
  new UnitInfo(
  {
       /* name                 */      "ha_ap_chaosturret2",                                           
       /* healthBarHeight      */      600.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      750.0,                       
       /* attackSpeed          */      0.8330000042915344,                       
       /* attackSpeedRatio     */      0.8330000042915344,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      130.0,            
       /* pathRadius           */      125.0,        
       /* gameplayRadius       */      88.4000015258789,
       
       /* basicAtkMissileSpeed */      1200.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Structure).set(Unit_Structure_Turret).set(Unit_Structure_Turret_Inhib)
  })
},


{ std::string("ha_ap_chaosturret3"), 
  new UnitInfo(
  {
       /* name                 */      "ha_ap_chaosturret3",                                           
       /* healthBarHeight      */      600.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      750.0,                       
       /* attackSpeed          */      0.8330000042915344,                       
       /* attackSpeedRatio     */      0.8330000042915344,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      130.0,            
       /* pathRadius           */      125.0,        
       /* gameplayRadius       */      88.4000015258789,
       
       /* basicAtkMissileSpeed */      1200.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Structure_Turret_Nexus).set(Unit_Structure).set(Unit_Structure_Turret)
  })
},


{ std::string("ha_ap_chaosturretrubble"), 
  new UnitInfo(
  {
       /* name                 */      "ha_ap_chaosturretrubble",                                           
       /* healthBarHeight      */      600.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      0.0,            
       /* pathRadius           */      0.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("ha_ap_chaosturretshrine"), 
  new UnitInfo(
  {
       /* name                 */      "ha_ap_chaosturretshrine",                                           
       /* healthBarHeight      */      600.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      1100.0,                       
       /* attackSpeed          */      2.5,                       
       /* attackSpeedRatio     */      2.5,                  
                                                                            
       /* acquisitionRange     */      1200.0,                  
       /* selectionRadius      */      130.0,            
       /* pathRadius           */      0.0,        
       /* gameplayRadius       */      88.4000015258789,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Structure).set(Unit_Structure_Turret).set(Unit_Structure_Turret_Shrine)
  })
},


{ std::string("ha_ap_chaosturrettutorial"), 
  new UnitInfo(
  {
       /* name                 */      "ha_ap_chaosturrettutorial",                                           
       /* healthBarHeight      */      600.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      700.0,                       
       /* attackSpeed          */      1.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      700.0,                  
       /* selectionRadius      */      130.0,            
       /* pathRadius           */      125.0,        
       /* gameplayRadius       */      88.4000015258789,
       
       /* basicAtkMissileSpeed */      1200.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("ha_ap_cutaway"), 
  new UnitInfo(
  {
       /* name                 */      "ha_ap_cutaway",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      600.0,            
       /* pathRadius           */      0.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("ha_ap_healthrelic"), 
  new UnitInfo(
  {
       /* name                 */      "ha_ap_healthrelic",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      325.0,                     
       /* attackRange          */      170.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      120.0,            
       /* pathRadius           */      0.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("ha_ap_hermit"), 
  new UnitInfo(
  {
       /* name                 */      "ha_ap_hermit",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      0.0,            
       /* pathRadius           */      0.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("ha_ap_hermit_robot"), 
  new UnitInfo(
  {
       /* name                 */      "ha_ap_hermit_robot",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      0.0,            
       /* pathRadius           */      0.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("ha_ap_herotower"), 
  new UnitInfo(
  {
       /* name                 */      "ha_ap_herotower",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      0.0,            
       /* pathRadius           */      0.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("ha_ap_ordershrineturret"), 
  new UnitInfo(
  {
       /* name                 */      "ha_ap_ordershrineturret",                                           
       /* healthBarHeight      */      625.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      1100.0,                       
       /* attackSpeed          */      2.5,                       
       /* attackSpeedRatio     */      2.5,                  
                                                                            
       /* acquisitionRange     */      1200.0,                  
       /* selectionRadius      */      130.0,            
       /* pathRadius           */      0.0,        
       /* gameplayRadius       */      88.4000015258789,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Structure).set(Unit_Structure_Turret).set(Unit_Structure_Turret_Shrine)
  })
},


{ std::string("ha_ap_orderturret"), 
  new UnitInfo(
  {
       /* name                 */      "ha_ap_orderturret",                                           
       /* healthBarHeight      */      625.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      750.0,                       
       /* attackSpeed          */      0.8330000042915344,                       
       /* attackSpeedRatio     */      0.8330000042915344,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      130.0,            
       /* pathRadius           */      125.0,        
       /* gameplayRadius       */      88.4000015258789,
       
       /* basicAtkMissileSpeed */      1200.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Structure).set(Unit_Structure_Turret).set(Unit_Structure_Turret_Outer)
  })
},


{ std::string("ha_ap_orderturret2"), 
  new UnitInfo(
  {
       /* name                 */      "ha_ap_orderturret2",                                           
       /* healthBarHeight      */      625.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      750.0,                       
       /* attackSpeed          */      0.8330000042915344,                       
       /* attackSpeedRatio     */      0.8330000042915344,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      130.0,            
       /* pathRadius           */      125.0,        
       /* gameplayRadius       */      88.4000015258789,
       
       /* basicAtkMissileSpeed */      1200.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Structure).set(Unit_Structure_Turret).set(Unit_Structure_Turret_Inhib)
  })
},


{ std::string("ha_ap_orderturret3"), 
  new UnitInfo(
  {
       /* name                 */      "ha_ap_orderturret3",                                           
       /* healthBarHeight      */      625.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      750.0,                       
       /* attackSpeed          */      0.8330000042915344,                       
       /* attackSpeedRatio     */      0.8330000042915344,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      130.0,            
       /* pathRadius           */      125.0,        
       /* gameplayRadius       */      88.4000015258789,
       
       /* basicAtkMissileSpeed */      1200.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Structure_Turret_Nexus).set(Unit_Structure).set(Unit_Structure_Turret)
  })
},


{ std::string("ha_ap_orderturretrubble"), 
  new UnitInfo(
  {
       /* name                 */      "ha_ap_orderturretrubble",                                           
       /* healthBarHeight      */      625.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      0.0,            
       /* pathRadius           */      0.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("ha_ap_orderturrettutorial"), 
  new UnitInfo(
  {
       /* name                 */      "ha_ap_orderturrettutorial",                                           
       /* healthBarHeight      */      625.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      700.0,                       
       /* attackSpeed          */      1.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      700.0,                  
       /* selectionRadius      */      130.0,            
       /* pathRadius           */      125.0,        
       /* gameplayRadius       */      88.4000015258789,
       
       /* basicAtkMissileSpeed */      1200.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("ha_ap_periphbridge"), 
  new UnitInfo(
  {
       /* name                 */      "ha_ap_periphbridge",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      0.0,            
       /* pathRadius           */      0.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("ha_ap_poro"), 
  new UnitInfo(
  {
       /* name                 */      "ha_ap_poro",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      150.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      115.0,            
       /* pathRadius           */      31.52079963684082,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("ha_ap_porospawner"), 
  new UnitInfo(
  {
       /* name                 */      "ha_ap_porospawner",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      450.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      115.0,            
       /* pathRadius           */      31.52079963684082,        
       /* gameplayRadius       */      50.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("ha_ap_poro_snowman"), 
  new UnitInfo(
  {
       /* name                 */      "ha_ap_poro_snowman",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      0.0,            
       /* pathRadius           */      0.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("ha_ap_shpnorth"), 
  new UnitInfo(
  {
       /* name                 */      "ha_ap_shpnorth",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      0.0,            
       /* pathRadius           */      0.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("ha_ap_shpsouth"), 
  new UnitInfo(
  {
       /* name                 */      "ha_ap_shpsouth",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      0.0,            
       /* pathRadius           */      0.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("ha_ap_viking"), 
  new UnitInfo(
  {
       /* name                 */      "ha_ap_viking",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      0.0,            
       /* pathRadius           */      0.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("ha_chaosminionmelee"), 
  new UnitInfo(
  {
       /* name                 */      "ha_chaosminionmelee",                                           
       /* healthBarHeight      */      37.0,                   
       /* baseMoveSpeed        */      325.0,                     
       /* attackRange          */      110.0,                       
       /* attackSpeed          */      1.25,                       
       /* attackSpeedRatio     */      1.25,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      115.0,            
       /* pathRadius           */      35.74369812011719,        
       /* gameplayRadius       */      48.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Minion).set(Unit_Minion_Lane).set(Unit_Minion_Lane_Melee)
  })
},


{ std::string("ha_chaosminionranged"), 
  new UnitInfo(
  {
       /* name                 */      "ha_chaosminionranged",                                           
       /* healthBarHeight      */      33.0,                   
       /* baseMoveSpeed        */      325.0,                     
       /* attackRange          */      550.0,                       
       /* attackSpeed          */      0.6669999957084656,                       
       /* attackSpeedRatio     */      0.6669999957084656,                  
                                                                            
       /* acquisitionRange     */      700.0,                  
       /* selectionRadius      */      115.0,            
       /* pathRadius           */      35.74369812011719,        
       /* gameplayRadius       */      48.0,
       
       /* basicAtkMissileSpeed */      650.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Minion).set(Unit_Minion_Lane).set(Unit_Minion_Lane_Ranged)
  })
},


{ std::string("ha_chaosminionsiege"), 
  new UnitInfo(
  {
       /* name                 */      "ha_chaosminionsiege",                                           
       /* healthBarHeight      */      52.0,                   
       /* baseMoveSpeed        */      325.0,                     
       /* attackRange          */      280.0,                       
       /* attackSpeed          */      1.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      140.0,            
       /* pathRadius           */      55.74369812011719,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      1200.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Minion).set(Unit_Minion_Lane).set(Unit_Minion_Lane_Siege)
  })
},


{ std::string("ha_chaosminionsuper"), 
  new UnitInfo(
  {
       /* name                 */      "ha_chaosminionsuper",                                           
       /* healthBarHeight      */      71.0,                   
       /* baseMoveSpeed        */      325.0,                     
       /* attackRange          */      170.0,                       
       /* attackSpeed          */      0.6940000057220459,                       
       /* attackSpeedRatio     */      0.6940000057220459,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      145.0,            
       /* pathRadius           */      55.52080154418945,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Minion_Lane_Super).set(Unit_Minion).set(Unit_Minion_Lane)
  })
},


{ std::string("ha_fb_healthrelic"), 
  new UnitInfo(
  {
       /* name                 */      "ha_fb_healthrelic",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      325.0,                     
       /* attackRange          */      170.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      120.0,            
       /* pathRadius           */      0.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("ha_orderminionmelee"), 
  new UnitInfo(
  {
       /* name                 */      "ha_orderminionmelee",                                           
       /* healthBarHeight      */      42.0,                   
       /* baseMoveSpeed        */      325.0,                     
       /* attackRange          */      110.0,                       
       /* attackSpeed          */      1.25,                       
       /* attackSpeedRatio     */      1.25,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      115.0,            
       /* pathRadius           */      35.74369812011719,        
       /* gameplayRadius       */      48.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Minion).set(Unit_Minion_Lane).set(Unit_Minion_Lane_Melee)
  })
},


{ std::string("ha_orderminionranged"), 
  new UnitInfo(
  {
       /* name                 */      "ha_orderminionranged",                                           
       /* healthBarHeight      */      41.0,                   
       /* baseMoveSpeed        */      325.0,                     
       /* attackRange          */      550.0,                       
       /* attackSpeed          */      0.6669999957084656,                       
       /* attackSpeedRatio     */      0.6669999957084656,                  
                                                                            
       /* acquisitionRange     */      700.0,                  
       /* selectionRadius      */      115.0,            
       /* pathRadius           */      35.74369812011719,        
       /* gameplayRadius       */      48.0,
       
       /* basicAtkMissileSpeed */      650.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Minion).set(Unit_Minion_Lane).set(Unit_Minion_Lane_Ranged)
  })
},


{ std::string("ha_orderminionsiege"), 
  new UnitInfo(
  {
       /* name                 */      "ha_orderminionsiege",                                           
       /* healthBarHeight      */      52.0,                   
       /* baseMoveSpeed        */      325.0,                     
       /* attackRange          */      300.0,                       
       /* attackSpeed          */      1.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      140.0,            
       /* pathRadius           */      55.74369812011719,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      1200.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Minion).set(Unit_Minion_Lane).set(Unit_Minion_Lane_Siege)
  })
},


{ std::string("ha_orderminionsuper"), 
  new UnitInfo(
  {
       /* name                 */      "ha_orderminionsuper",                                           
       /* healthBarHeight      */      68.0,                   
       /* baseMoveSpeed        */      325.0,                     
       /* attackRange          */      170.0,                       
       /* attackSpeed          */      0.6940000057220459,                       
       /* attackSpeedRatio     */      0.6940000057220459,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      145.0,            
       /* pathRadius           */      55.52080154418945,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Minion_Lane_Super).set(Unit_Minion).set(Unit_Minion_Lane)
  })
},


{ std::string("hecarim"), 
  new UnitInfo(
  {
       /* name                 */      "hecarim",                                           
       /* healthBarHeight      */      120.0,                   
       /* baseMoveSpeed        */      345.0,                     
       /* attackRange          */      175.0,                       
       /* attackSpeed          */      0.6700000166893005,                       
       /* attackSpeedRatio     */      0.6700000166893005,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      140.0,            
       /* pathRadius           */      50.0,        
       /* gameplayRadius       */      80.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("heimerdinger"), 
  new UnitInfo(
  {
       /* name                 */      "heimerdinger",                                           
       /* healthBarHeight      */      87.0,                   
       /* baseMoveSpeed        */      340.0,                     
       /* attackRange          */      550.0,                       
       /* attackSpeed          */      0.625,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      550.0,                  
       /* selectionRadius      */      100.0,            
       /* pathRadius           */      30.54439926147461,        
       /* gameplayRadius       */      55.0,
       
       /* basicAtkMissileSpeed */      1500.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("heimertblue"), 
  new UnitInfo(
  {
       /* name                 */      "heimertblue",                                           
       /* healthBarHeight      */      240.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      650.0,                       
       /* attackSpeed          */      1.25,                       
       /* attackSpeedRatio     */      1.25,                  
                                                                            
       /* acquisitionRange     */      650.0,                  
       /* selectionRadius      */      60.0,            
       /* pathRadius           */      1.0,        
       /* gameplayRadius       */      35.0,
       
       /* basicAtkMissileSpeed */      1599.39990234375,
	   /* tags                 */      std::bitset<128>().set(Unit_Minion).set(Unit_Minion_Summon)
  })
},


{ std::string("heimertyellow"), 
  new UnitInfo(
  {
       /* name                 */      "heimertyellow",                                           
       /* healthBarHeight      */      110.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      530.0,                       
       /* attackSpeed          */      1.25,                       
       /* attackSpeedRatio     */      1.25,                  
                                                                            
       /* acquisitionRange     */      450.0,                  
       /* selectionRadius      */      60.0,            
       /* pathRadius           */      1.0,        
       /* gameplayRadius       */      35.0,
       
       /* basicAtkMissileSpeed */      1599.39990234375,
	   /* tags                 */      std::bitset<128>().set(Unit_Minion).set(Unit_Minion_Summon)
  })
},


{ std::string("illaoi"), 
  new UnitInfo(
  {
       /* name                 */      "illaoi",                                           
       /* healthBarHeight      */      112.0,                   
       /* baseMoveSpeed        */      340.0,                     
       /* attackRange          */      125.0,                       
       /* attackSpeed          */      0.5709999799728394,                       
       /* attackSpeedRatio     */      0.5709999799728394,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      100.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      467.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("illaoiminion"), 
  new UnitInfo(
  {
       /* name                 */      "illaoiminion",                                           
       /* healthBarHeight      */      -10.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      525.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      575.0,                  
       /* selectionRadius      */      80.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Special_UntargetableBySpells).set(Unit_Special_TurretIgnores).set(Unit_Special_TeleportTarget).set(Unit_IsolationNonImpacting).set(Unit_Special_KPMinion)
  })
},


{ std::string("irelia"), 
  new UnitInfo(
  {
       /* name                 */      "irelia",                                           
       /* healthBarHeight      */      101.0,                   
       /* baseMoveSpeed        */      335.0,                     
       /* attackRange          */      200.0,                       
       /* attackSpeed          */      0.656000018119812,                       
       /* attackSpeedRatio     */      0.656000018119812,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      100.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      467.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("ireliablades"), 
  new UnitInfo(
  {
       /* name                 */      "ireliablades",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      0.0,            
       /* pathRadius           */      0.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("item_twinshadow"), 
  new UnitInfo(
  {
       /* name                 */      "item_twinshadow",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      940.0,                     
       /* attackRange          */      300.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      125.0,            
       /* pathRadius           */      100.0,        
       /* gameplayRadius       */      100.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Monster)
  })
},


{ std::string("ivern"), 
  new UnitInfo(
  {
       /* name                 */      "ivern",                                           
       /* healthBarHeight      */      135.0,                   
       /* baseMoveSpeed        */      330.0,                     
       /* attackRange          */      475.0,                       
       /* attackSpeed          */      0.6439999938011169,                       
       /* attackSpeedRatio     */      0.6439999938011169,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      140.0,            
       /* pathRadius           */      40.0,        
       /* gameplayRadius       */      70.0,
       
       /* basicAtkMissileSpeed */      4000.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion).set(Unit_Special_MonsterIgnores)
  })
},


{ std::string("ivernminion"), 
  new UnitInfo(
  {
       /* name                 */      "ivernminion",                                           
       /* healthBarHeight      */      95.0,                   
       /* baseMoveSpeed        */      420.0,                     
       /* attackRange          */      125.0,                       
       /* attackSpeed          */      0.699999988079071,                       
       /* attackSpeedRatio     */      0.699999988079071,                  
                                                                            
       /* acquisitionRange     */      300.0,                  
       /* selectionRadius      */      80.0,            
       /* pathRadius           */      85.0,        
       /* gameplayRadius       */      100.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Minion).set(Unit_Special_MonsterIgnores).set(Unit_Minion_Summon).set(Unit_Minion_Summon_Large)
  })
},


{ std::string("iverntotem"), 
  new UnitInfo(
  {
       /* name                 */      "iverntotem",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      0.0,            
       /* pathRadius           */      0.009999999776482582,        
       /* gameplayRadius       */      0.009999999776482582,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Special_TurretIgnores).set(Unit_Special)
  })
},


{ std::string("jammerdevice"), 
  new UnitInfo(
  {
       /* name                 */      "jammerdevice",                                           
       /* healthBarHeight      */      180.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      0.0,            
       /* pathRadius           */      5.0,        
       /* gameplayRadius       */      1.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Special_TurretIgnores).set(Unit_Ward).set(Unit_Special)
  })
},


{ std::string("janna"), 
  new UnitInfo(
  {
       /* name                 */      "janna",                                           
       /* healthBarHeight      */      120.0,                   
       /* baseMoveSpeed        */      315.0,                     
       /* attackRange          */      550.0,                       
       /* attackSpeed          */      0.625,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      550.0,                  
       /* selectionRadius      */      125.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      1600.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("jarvaniv"), 
  new UnitInfo(
  {
       /* name                 */      "jarvaniv",                                           
       /* healthBarHeight      */      110.0,                   
       /* baseMoveSpeed        */      340.0,                     
       /* attackRange          */      175.0,                       
       /* attackSpeed          */      0.6579999923706055,                       
       /* attackSpeedRatio     */      0.6579999923706055,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      125.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      20.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("jarvanivstandard"), 
  new UnitInfo(
  {
       /* name                 */      "jarvanivstandard",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      1.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      1.0,                  
       /* selectionRadius      */      140.0,            
       /* pathRadius           */      13.600000381469727,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Special_TeleportTarget).set(Unit_Special)
  })
},


{ std::string("jarvanivwall"), 
  new UnitInfo(
  {
       /* name                 */      "jarvanivwall",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      1.0,            
       /* pathRadius           */      95.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("jax"), 
  new UnitInfo(
  {
       /* name                 */      "jax",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      350.0,                     
       /* attackRange          */      125.0,                       
       /* attackSpeed          */      0.6380000114440918,                       
       /* attackSpeedRatio     */      0.6380000114440918,                  
                                                                            
       /* acquisitionRange     */      400.0,                  
       /* selectionRadius      */      120.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      400.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("jayce"), 
  new UnitInfo(
  {
       /* name                 */      "jayce",                                           
       /* healthBarHeight      */      120.0,                   
       /* baseMoveSpeed        */      335.0,                     
       /* attackRange          */      125.0,                       
       /* attackSpeed          */      0.6579999923706055,                       
       /* attackSpeedRatio     */      0.6579999923706055,                  
                                                                            
       /* acquisitionRange     */      200.0,                  
       /* selectionRadius      */      75.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      347.79998779296875,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("jhin"), 
  new UnitInfo(
  {
       /* name                 */      "jhin",                                           
       /* healthBarHeight      */      105.0,                   
       /* baseMoveSpeed        */      330.0,                     
       /* attackRange          */      550.0,                       
       /* attackSpeed          */      0.625,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      800.0,                  
       /* selectionRadius      */      120.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      2600.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("jhintrap"), 
  new UnitInfo(
  {
       /* name                 */      "jhintrap",                                           
       /* healthBarHeight      */      40.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      0.0,            
       /* pathRadius           */      31.793100357055664,        
       /* gameplayRadius       */      125.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Special_UntargetableBySpells).set(Unit_Special_TurretIgnores).set(Unit_Special_TeleportTarget).set(Unit_Special_Trap).set(Unit_IsolationNonImpacting).set(Unit_Special)
  })
},


{ std::string("jinx"), 
  new UnitInfo(
  {
       /* name                 */      "jinx",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      325.0,                     
       /* attackRange          */      525.0,                       
       /* attackSpeed          */      0.625,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      550.0,                  
       /* selectionRadius      */      120.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      2750.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("jinxmine"), 
  new UnitInfo(
  {
       /* name                 */      "jinxmine",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      0.0,            
       /* pathRadius           */      0.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Special_Trap).set(Unit_Special)
  })
},


{ std::string("kaisa"), 
  new UnitInfo(
  {
       /* name                 */      "kaisa",                                           
       /* healthBarHeight      */      110.0,                   
       /* baseMoveSpeed        */      335.0,                     
       /* attackRange          */      525.0,                       
       /* attackSpeed          */      0.6439999938011169,                       
       /* attackSpeedRatio     */      0.6439999938011169,                  
                                                                            
       /* acquisitionRange     */      800.0,                  
       /* selectionRadius      */      100.0,            
       /* pathRadius           */      40.68000030517578,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      2000.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("kalista"), 
  new UnitInfo(
  {
       /* name                 */      "kalista",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      325.0,                     
       /* attackRange          */      525.0,                       
       /* attackSpeed          */      0.6940000057220459,                       
       /* attackSpeedRatio     */      0.6940000057220459,                  
                                                                            
       /* acquisitionRange     */      900.0,                  
       /* selectionRadius      */      100.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      2600.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("kalistaaltar"), 
  new UnitInfo(
  {
       /* name                 */      "kalistaaltar",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      950.0,                  
       /* selectionRadius      */      60.0,            
       /* pathRadius           */      20.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("kalistaspawn"), 
  new UnitInfo(
  {
       /* name                 */      "kalistaspawn",                                           
       /* healthBarHeight      */      65.0,                   
       /* baseMoveSpeed        */      560.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      100.0,            
       /* pathRadius           */      10.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Special_TurretIgnores).set(Unit_Special_UntargetableBySpells)
  })
},


{ std::string("karma"), 
  new UnitInfo(
  {
       /* name                 */      "karma",                                           
       /* healthBarHeight      */      110.0,                   
       /* baseMoveSpeed        */      335.0,                     
       /* attackRange          */      525.0,                       
       /* attackSpeed          */      0.625,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      525.0,                  
       /* selectionRadius      */      120.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      1500.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("karthus"), 
  new UnitInfo(
  {
       /* name                 */      "karthus",                                           
       /* healthBarHeight      */      110.0,                   
       /* baseMoveSpeed        */      335.0,                     
       /* attackRange          */      450.0,                       
       /* attackSpeed          */      0.625,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      450.0,                  
       /* selectionRadius      */      100.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      1200.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("kassadin"), 
  new UnitInfo(
  {
       /* name                 */      "kassadin",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      335.0,                     
       /* attackRange          */      150.0,                       
       /* attackSpeed          */      0.6399999856948853,                       
       /* attackSpeedRatio     */      0.6399999856948853,                  
                                                                            
       /* acquisitionRange     */      400.0,                  
       /* selectionRadius      */      120.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("katarina"), 
  new UnitInfo(
  {
       /* name                 */      "katarina",                                           
       /* healthBarHeight      */      90.0,                   
       /* baseMoveSpeed        */      340.0,                     
       /* attackRange          */      125.0,                       
       /* attackSpeed          */      0.6579999923706055,                       
       /* attackSpeedRatio     */      0.6579999923706055,                  
                                                                            
       /* acquisitionRange     */      400.0,                  
       /* selectionRadius      */      120.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      467.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("kayle"), 
  new UnitInfo(
  {
       /* name                 */      "kayle",                                           
       /* healthBarHeight      */      160.0,                   
       /* baseMoveSpeed        */      335.0,                     
       /* attackRange          */      175.0,                       
       /* attackSpeed          */      0.625,                       
       /* attackSpeedRatio     */      0.6669999957084656,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      140.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("kayn"), 
  new UnitInfo(
  {
       /* name                 */      "kayn",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      340.0,                     
       /* attackRange          */      175.0,                       
       /* attackSpeed          */      0.6690000295639038,                       
       /* attackSpeedRatio     */      0.6690000295639038,                  
                                                                            
       /* acquisitionRange     */      400.0,                  
       /* selectionRadius      */      135.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      347.79998779296875,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("kennen"), 
  new UnitInfo(
  {
       /* name                 */      "kennen",                                           
       /* healthBarHeight      */      93.0,                   
       /* baseMoveSpeed        */      335.0,                     
       /* attackRange          */      550.0,                       
       /* attackSpeed          */      0.625,                       
       /* attackSpeedRatio     */      0.6899999976158142,                  
                                                                            
       /* acquisitionRange     */      550.0,                  
       /* selectionRadius      */      100.0,            
       /* pathRadius           */      30.0,        
       /* gameplayRadius       */      55.0,
       
       /* basicAtkMissileSpeed */      1700.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("khazix"), 
  new UnitInfo(
  {
       /* name                 */      "khazix",                                           
       /* healthBarHeight      */      90.0,                   
       /* baseMoveSpeed        */      350.0,                     
       /* attackRange          */      125.0,                       
       /* attackSpeed          */      0.6679999828338623,                       
       /* attackSpeedRatio     */      0.6679999828338623,                  
                                                                            
       /* acquisitionRange     */      400.0,                  
       /* selectionRadius      */      130.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion).set(Unit_Special_Void)
  })
},


{ std::string("kindred"), 
  new UnitInfo(
  {
       /* name                 */      "kindred",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      325.0,                     
       /* attackRange          */      500.0,                       
       /* attackSpeed          */      0.625,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      525.0,                  
       /* selectionRadius      */      120.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      2000.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("kindredjunglebountyminion"), 
  new UnitInfo(
  {
       /* name                 */      "kindredjunglebountyminion",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      350.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      1.0,            
       /* pathRadius           */      1.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("kindredwolf"), 
  new UnitInfo(
  {
       /* name                 */      "kindredwolf",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      275.0,                     
       /* attackRange          */      200.0,                       
       /* attackSpeed          */      0.5580000281333923,                       
       /* attackSpeedRatio     */      0.5580000281333923,                  
                                                                            
       /* acquisitionRange     */      800.0,                  
       /* selectionRadius      */      0.0,            
       /* pathRadius           */      0.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      347.79998779296875,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("kingporo"), 
  new UnitInfo(
  {
       /* name                 */      "kingporo",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      150.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.5989999771118164,                       
       /* attackSpeedRatio     */      0.5989999771118164,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      115.0,            
       /* pathRadius           */      31.52079963684082,        
       /* gameplayRadius       */      100.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_KingPoro).set(Unit_Monster_Epic).set(Unit_Monster)
  })
},


{ std::string("kingporo_porofollower"), 
  new UnitInfo(
  {
       /* name                 */      "kingporo_porofollower",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      150.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      115.0,            
       /* pathRadius           */      50.0,        
       /* gameplayRadius       */      80.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("kled"), 
  new UnitInfo(
  {
       /* name                 */      "kled",                                           
       /* healthBarHeight      */      130.0,                   
       /* baseMoveSpeed        */      345.0,                     
       /* attackRange          */      125.0,                       
       /* attackSpeed          */      0.625,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      140.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("kledmount"), 
  new UnitInfo(
  {
       /* name                 */      "kledmount",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      335.0,                     
       /* attackRange          */      150.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      140.0,            
       /* pathRadius           */      50.0,        
       /* gameplayRadius       */      80.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Minion).set(Unit_Minion_Summon)
  })
},


{ std::string("kledrider"), 
  new UnitInfo(
  {
       /* name                 */      "kledrider",                                           
       /* healthBarHeight      */      80.0,                   
       /* baseMoveSpeed        */      300.0,                     
       /* attackRange          */      125.0,                       
       /* attackSpeed          */      0.6579999923706055,                       
       /* attackSpeedRatio     */      0.6579999923706055,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      100.0,            
       /* pathRadius           */      30.0,        
       /* gameplayRadius       */      55.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("kogmaw"), 
  new UnitInfo(
  {
       /* name                 */      "kogmaw",                                           
       /* healthBarHeight      */      93.0,                   
       /* baseMoveSpeed        */      330.0,                     
       /* attackRange          */      500.0,                       
       /* attackSpeed          */      0.6650000214576721,                       
       /* attackSpeedRatio     */      0.6650000214576721,                  
                                                                            
       /* acquisitionRange     */      900.0,                  
       /* selectionRadius      */      130.0,            
       /* pathRadius           */      30.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      1800.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion).set(Unit_Special_Void)
  })
},


{ std::string("kogmawdead"), 
  new UnitInfo(
  {
       /* name                 */      "kogmawdead",                                           
       /* healthBarHeight      */      93.0,                   
       /* baseMoveSpeed        */      325.0,                     
       /* attackRange          */      500.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      900.0,                  
       /* selectionRadius      */      130.0,            
       /* pathRadius           */      30.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion).set(Unit_Special_Void)
  })
},


{ std::string("leblanc"), 
  new UnitInfo(
  {
       /* name                 */      "leblanc",                                           
       /* healthBarHeight      */      95.0,                   
       /* baseMoveSpeed        */      340.0,                     
       /* attackRange          */      525.0,                       
       /* attackSpeed          */      0.625,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      525.0,                  
       /* selectionRadius      */      100.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      1700.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("leesin"), 
  new UnitInfo(
  {
       /* name                 */      "leesin",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      345.0,                     
       /* attackRange          */      125.0,                       
       /* attackSpeed          */      0.6510000228881836,                       
       /* attackSpeedRatio     */      0.6510000228881836,                  
                                                                            
       /* acquisitionRange     */      400.0,                  
       /* selectionRadius      */      102.77780151367188,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("leona"), 
  new UnitInfo(
  {
       /* name                 */      "leona",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      335.0,                     
       /* attackRange          */      125.0,                       
       /* attackSpeed          */      0.625,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      400.0,                  
       /* selectionRadius      */      75.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      347.79998779296875,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("lillia"), 
  new UnitInfo(
  {
       /* name                 */      "lillia",                                           
       /* healthBarHeight      */      120.0,                   
       /* baseMoveSpeed        */      330.0,                     
       /* attackRange          */      325.0,                       
       /* attackSpeed          */      0.625,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      400.0,                  
       /* selectionRadius      */      135.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("lissandra"), 
  new UnitInfo(
  {
       /* name                 */      "lissandra",                                           
       /* healthBarHeight      */      120.0,                   
       /* baseMoveSpeed        */      325.0,                     
       /* attackRange          */      550.0,                       
       /* attackSpeed          */      0.656000018119812,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      88.88890075683594,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      2000.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("lissandrapassive"), 
  new UnitInfo(
  {
       /* name                 */      "lissandrapassive",                                           
       /* healthBarHeight      */      180.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      0.0,            
       /* pathRadius           */      5.0,        
       /* gameplayRadius       */      1.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Special_TurretIgnores).set(Unit_Ward).set(Unit_Special)
  })
},


{ std::string("lucian"), 
  new UnitInfo(
  {
       /* name                 */      "lucian",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      335.0,                     
       /* attackRange          */      500.0,                       
       /* attackSpeed          */      0.6380000114440918,                       
       /* attackSpeedRatio     */      0.6380000114440918,                  
                                                                            
       /* acquisitionRange     */      800.0,                  
       /* selectionRadius      */      100.0,            
       /* pathRadius           */      40.68000030517578,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      2800.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("lulu"), 
  new UnitInfo(
  {
       /* name                 */      "lulu",                                           
       /* healthBarHeight      */      85.0,                   
       /* baseMoveSpeed        */      330.0,                     
       /* attackRange          */      550.0,                       
       /* attackSpeed          */      0.625,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      625.0,                  
       /* selectionRadius      */      100.0,            
       /* pathRadius           */      30.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      1450.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("lulufaerie"), 
  new UnitInfo(
  {
       /* name                 */      "lulufaerie",                                           
       /* healthBarHeight      */      60.0,                   
       /* baseMoveSpeed        */      275.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      800.0,                  
       /* selectionRadius      */      0.0,            
       /* pathRadius           */      0.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("lux"), 
  new UnitInfo(
  {
       /* name                 */      "lux",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      330.0,                     
       /* attackRange          */      550.0,                       
       /* attackSpeed          */      0.6690000295639038,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      625.0,                  
       /* selectionRadius      */      100.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      1600.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("luxair"), 
  new UnitInfo(
  {
       /* name                 */      "luxair",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      330.0,                     
       /* attackRange          */      550.0,                       
       /* attackSpeed          */      0.6690000295639038,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      625.0,                  
       /* selectionRadius      */      100.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("luxdark"), 
  new UnitInfo(
  {
       /* name                 */      "luxdark",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      330.0,                     
       /* attackRange          */      550.0,                       
       /* attackSpeed          */      0.6690000295639038,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      625.0,                  
       /* selectionRadius      */      100.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("luxfire"), 
  new UnitInfo(
  {
       /* name                 */      "luxfire",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      330.0,                     
       /* attackRange          */      550.0,                       
       /* attackSpeed          */      0.6690000295639038,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      625.0,                  
       /* selectionRadius      */      100.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("luxice"), 
  new UnitInfo(
  {
       /* name                 */      "luxice",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      330.0,                     
       /* attackRange          */      550.0,                       
       /* attackSpeed          */      0.6690000295639038,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      625.0,                  
       /* selectionRadius      */      100.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("luxmagma"), 
  new UnitInfo(
  {
       /* name                 */      "luxmagma",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      330.0,                     
       /* attackRange          */      550.0,                       
       /* attackSpeed          */      0.6690000295639038,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      625.0,                  
       /* selectionRadius      */      100.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("luxmystic"), 
  new UnitInfo(
  {
       /* name                 */      "luxmystic",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      330.0,                     
       /* attackRange          */      550.0,                       
       /* attackSpeed          */      0.6690000295639038,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      625.0,                  
       /* selectionRadius      */      100.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("luxnature"), 
  new UnitInfo(
  {
       /* name                 */      "luxnature",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      330.0,                     
       /* attackRange          */      550.0,                       
       /* attackSpeed          */      0.6690000295639038,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      625.0,                  
       /* selectionRadius      */      100.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("luxstorm"), 
  new UnitInfo(
  {
       /* name                 */      "luxstorm",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      330.0,                     
       /* attackRange          */      550.0,                       
       /* attackSpeed          */      0.6690000295639038,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      625.0,                  
       /* selectionRadius      */      100.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("luxwater"), 
  new UnitInfo(
  {
       /* name                 */      "luxwater",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      330.0,                     
       /* attackRange          */      550.0,                       
       /* attackSpeed          */      0.6690000295639038,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      625.0,                  
       /* selectionRadius      */      100.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("malphite"), 
  new UnitInfo(
  {
       /* name                 */      "malphite",                                           
       /* healthBarHeight      */      115.0,                   
       /* baseMoveSpeed        */      335.0,                     
       /* attackRange          */      125.0,                       
       /* attackSpeed          */      0.7360000014305115,                       
       /* attackSpeedRatio     */      0.6380000114440918,                  
                                                                            
       /* acquisitionRange     */      400.0,                  
       /* selectionRadius      */      125.0,            
       /* pathRadius           */      50.0,        
       /* gameplayRadius       */      80.0,
       
       /* basicAtkMissileSpeed */      1000.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("malzahar"), 
  new UnitInfo(
  {
       /* name                 */      "malzahar",                                           
       /* healthBarHeight      */      115.0,                   
       /* baseMoveSpeed        */      335.0,                     
       /* attackRange          */      500.0,                       
       /* attackSpeed          */      0.625,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      88.88890075683594,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      2000.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("malzaharvoidling"), 
  new UnitInfo(
  {
       /* name                 */      "malzaharvoidling",                                           
       /* healthBarHeight      */      38.0,                   
       /* baseMoveSpeed        */      400.0,                     
       /* attackRange          */      150.0,                       
       /* attackSpeed          */      0.6650000214576721,                       
       /* attackSpeedRatio     */      0.6650000214576721,                  
                                                                            
       /* acquisitionRange     */      800.0,                  
       /* selectionRadius      */      70.0,            
       /* pathRadius           */      20.0,        
       /* gameplayRadius       */      10.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Minion).set(Unit_Minion_Summon)
  })
},


{ std::string("maokai"), 
  new UnitInfo(
  {
       /* name                 */      "maokai",                                           
       /* healthBarHeight      */      120.0,                   
       /* baseMoveSpeed        */      335.0,                     
       /* attackRange          */      125.0,                       
       /* attackSpeed          */      0.800000011920929,                       
       /* attackSpeedRatio     */      0.6949999928474426,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      125.0,            
       /* pathRadius           */      50.0,        
       /* gameplayRadius       */      80.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("maokaisproutling"), 
  new UnitInfo(
  {
       /* name                 */      "maokaisproutling",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      400.0,                     
       /* attackRange          */      20.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      110.0,            
       /* pathRadius           */      40.0,        
       /* gameplayRadius       */      48.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Minion).set(Unit_Minion_Summon).set(Unit_Special_Trap).set(Unit_Special)
  })
},


{ std::string("masteryi"), 
  new UnitInfo(
  {
       /* name                 */      "masteryi",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      355.0,                     
       /* attackRange          */      125.0,                       
       /* attackSpeed          */      0.6790000200271606,                       
       /* attackSpeedRatio     */      0.6790000200271606,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      125.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("missfortune"), 
  new UnitInfo(
  {
       /* name                 */      "missfortune",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      325.0,                     
       /* attackRange          */      550.0,                       
       /* attackSpeed          */      0.656000018119812,                       
       /* attackSpeedRatio     */      0.656000018119812,                  
                                                                            
       /* acquisitionRange     */      800.0,                  
       /* selectionRadius      */      100.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      2000.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("monkeyking"), 
  new UnitInfo(
  {
       /* name                 */      "monkeyking",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      345.0,                     
       /* attackRange          */      175.0,                       
       /* attackSpeed          */      0.7110000252723694,                       
       /* attackSpeedRatio     */      0.6579999923706055,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      100.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      20.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("monkeykingclone"), 
  new UnitInfo(
  {
       /* name                 */      "monkeykingclone",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      345.0,                     
       /* attackRange          */      175.0,                       
       /* attackSpeed          */      0.7110000252723694,                       
       /* attackSpeedRatio     */      0.6579999923706055,                  
                                                                            
       /* acquisitionRange     */      800.0,                  
       /* selectionRadius      */      100.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion_Clone).set(Unit_Champion)
  })
},


{ std::string("monkeykingflying"), 
  new UnitInfo(
  {
       /* name                 */      "monkeykingflying",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      345.0,                     
       /* attackRange          */      175.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      800.0,                  
       /* selectionRadius      */      100.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion_Clone).set(Unit_Champion)
  })
},


{ std::string("mordekaiser"), 
  new UnitInfo(
  {
       /* name                 */      "mordekaiser",                                           
       /* healthBarHeight      */      120.0,                   
       /* baseMoveSpeed        */      335.0,                     
       /* attackRange          */      175.0,                       
       /* attackSpeed          */      0.625,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      400.0,                  
       /* selectionRadius      */      125.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      80.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("morgana"), 
  new UnitInfo(
  {
       /* name                 */      "morgana",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      335.0,                     
       /* attackRange          */      450.0,                       
       /* attackSpeed          */      0.625,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      120.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      1600.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("nami"), 
  new UnitInfo(
  {
       /* name                 */      "nami",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      335.0,                     
       /* attackRange          */      550.0,                       
       /* attackSpeed          */      0.6439999938011169,                       
       /* attackSpeedRatio     */      0.6439999938011169,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      125.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      1500.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("nasus"), 
  new UnitInfo(
  {
       /* name                 */      "nasus",                                           
       /* healthBarHeight      */      110.0,                   
       /* baseMoveSpeed        */      350.0,                     
       /* attackRange          */      125.0,                       
       /* attackSpeed          */      0.6380000114440918,                       
       /* attackSpeedRatio     */      0.6380000114440918,                  
                                                                            
       /* acquisitionRange     */      350.0,                  
       /* selectionRadius      */      135.0,            
       /* pathRadius           */      50.0,        
       /* gameplayRadius       */      80.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("nasusult"), 
  new UnitInfo(
  {
       /* name                 */      "nasusult",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      350.0,                     
       /* attackRange          */      125.0,                       
       /* attackSpeed          */      0.6380000114440918,                       
       /* attackSpeedRatio     */      0.6380000114440918,                  
                                                                            
       /* acquisitionRange     */      350.0,                  
       /* selectionRadius      */      135.0,            
       /* pathRadius           */      50.0,        
       /* gameplayRadius       */      80.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("nautilus"), 
  new UnitInfo(
  {
       /* name                 */      "nautilus",                                           
       /* healthBarHeight      */      135.0,                   
       /* baseMoveSpeed        */      325.0,                     
       /* attackRange          */      175.0,                       
       /* attackSpeed          */      0.7059999704360962,                       
       /* attackSpeedRatio     */      0.6119999885559082,                  
                                                                            
       /* acquisitionRange     */      400.0,                  
       /* selectionRadius      */      125.0,            
       /* pathRadius           */      50.0,        
       /* gameplayRadius       */      80.0,
       
       /* basicAtkMissileSpeed */      1000.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("neeko"), 
  new UnitInfo(
  {
       /* name                 */      "neeko",                                           
       /* healthBarHeight      */      111.0,                   
       /* baseMoveSpeed        */      340.0,                     
       /* attackRange          */      550.0,                       
       /* attackSpeed          */      0.625,                       
       /* attackSpeedRatio     */      0.6700000166893005,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      90.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      80.0,
       
       /* basicAtkMissileSpeed */      2000.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("nidalee"), 
  new UnitInfo(
  {
       /* name                 */      "nidalee",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      335.0,                     
       /* attackRange          */      525.0,                       
       /* attackSpeed          */      0.6380000114440918,                       
       /* attackSpeedRatio     */      0.6380000114440918,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      110.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      2500.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("nidaleecougar"), 
  new UnitInfo(
  {
       /* name                 */      "nidaleecougar",                                           
       /* healthBarHeight      */      75.0,                   
       /* baseMoveSpeed        */      335.0,                     
       /* attackRange          */      125.0,                       
       /* attackSpeed          */      0.6380000114440918,                       
       /* attackSpeedRatio     */      0.6380000114440918,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      140.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("nidaleespear"), 
  new UnitInfo(
  {
       /* name                 */      "nidaleespear",                                           
       /* healthBarHeight      */      25.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      0.0,            
       /* pathRadius           */      0.0,        
       /* gameplayRadius       */      50.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Special_UntargetableBySpells).set(Unit_Special_TurretIgnores).set(Unit_Special_TeleportTarget).set(Unit_Special_Trap).set(Unit_IsolationNonImpacting).set(Unit_Special)
  })
},


{ std::string("nightmarebots_malzahar_riftherald"), 
  new UnitInfo(
  {
       /* name                 */      "nightmarebots_malzahar_riftherald",                                           
       /* healthBarHeight      */      170.0,                   
       /* baseMoveSpeed        */      325.0,                     
       /* attackRange          */      250.0,                       
       /* attackSpeed          */      0.4000000059604645,                       
       /* attackSpeedRatio     */      0.5,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      120.0,            
       /* pathRadius           */      110.0,        
       /* gameplayRadius       */      110.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Monster_Epic).set(Unit_Monster).set(Unit_Special_Void).set(Unit_Monster_Camp)
  })
},


{ std::string("nocturne"), 
  new UnitInfo(
  {
       /* name                 */      "nocturne",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      345.0,                     
       /* attackRange          */      125.0,                       
       /* attackSpeed          */      0.7210000157356262,                       
       /* attackSpeedRatio     */      0.6679999828338623,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      120.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("npc_khazixstatue"), 
  new UnitInfo(
  {
       /* name                 */      "npc_khazixstatue",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      345.0,                     
       /* attackRange          */      175.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      100.0,            
       /* pathRadius           */      30.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("npc_worldscup"), 
  new UnitInfo(
  {
       /* name                 */      "npc_worldscup",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      345.0,                     
       /* attackRange          */      175.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      100.0,            
       /* pathRadius           */      30.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("nunu"), 
  new UnitInfo(
  {
       /* name                 */      "nunu",                                           
       /* healthBarHeight      */      140.0,                   
       /* baseMoveSpeed        */      345.0,                     
       /* attackRange          */      125.0,                       
       /* attackSpeed          */      0.625,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      140.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("nunusnowball"), 
  new UnitInfo(
  {
       /* name                 */      "nunusnowball",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      475.0,                     
       /* attackRange          */      20.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      110.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      48.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("olaf"), 
  new UnitInfo(
  {
       /* name                 */      "olaf",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      350.0,                     
       /* attackRange          */      125.0,                       
       /* attackSpeed          */      0.6940000057220459,                       
       /* attackSpeedRatio     */      0.6940000057220459,                  
                                                                            
       /* acquisitionRange     */      400.0,                  
       /* selectionRadius      */      111.11109924316406,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      347.79998779296875,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("olafaxe"), 
  new UnitInfo(
  {
       /* name                 */      "olafaxe",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      325.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      1.0,            
       /* pathRadius           */      1.0,        
       /* gameplayRadius       */      50.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("orderinhibitor"), 
  new UnitInfo(
  {
       /* name                 */      "orderinhibitor",                                           
       /* healthBarHeight      */      370.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      0.0,            
       /* pathRadius           */      0.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Structure_Inhibitor).set(Unit_Structure)
  })
},


{ std::string("orderinhibitor_d"), 
  new UnitInfo(
  {
       /* name                 */      "orderinhibitor_d",                                           
       /* healthBarHeight      */      120.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      0.0,            
       /* pathRadius           */      0.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("ordernexus"), 
  new UnitInfo(
  {
       /* name                 */      "ordernexus",                                           
       /* healthBarHeight      */      500.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      0.0,            
       /* pathRadius           */      0.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Structure).set(Unit_Structure_Nexus)
  })
},


{ std::string("orianna"), 
  new UnitInfo(
  {
       /* name                 */      "orianna",                                           
       /* healthBarHeight      */      110.0,                   
       /* baseMoveSpeed        */      325.0,                     
       /* attackRange          */      525.0,                       
       /* attackSpeed          */      0.6579999923706055,                       
       /* attackSpeedRatio     */      0.6579999923706055,                  
                                                                            
       /* acquisitionRange     */      525.0,                  
       /* selectionRadius      */      120.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      1450.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("oriannaball"), 
  new UnitInfo(
  {
       /* name                 */      "oriannaball",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      475.0,                     
       /* attackRange          */      20.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      110.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      48.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("oriannanoball"), 
  new UnitInfo(
  {
       /* name                 */      "oriannanoball",                                           
       /* healthBarHeight      */      110.0,                   
       /* baseMoveSpeed        */      325.0,                     
       /* attackRange          */      525.0,                       
       /* attackSpeed          */      0.6579999923706055,                       
       /* attackSpeedRatio     */      0.6579999923706055,                  
                                                                            
       /* acquisitionRange     */      525.0,                  
       /* selectionRadius      */      120.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("ornn"), 
  new UnitInfo(
  {
       /* name                 */      "ornn",                                           
       /* healthBarHeight      */      110.0,                   
       /* baseMoveSpeed        */      335.0,                     
       /* attackRange          */      175.0,                       
       /* attackSpeed          */      0.625,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      125.0,            
       /* pathRadius           */      25.766599655151367,        
       /* gameplayRadius       */      80.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("ornnram"), 
  new UnitInfo(
  {
       /* name                 */      "ornnram",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      1.0,            
       /* pathRadius           */      1.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("pantheon"), 
  new UnitInfo(
  {
       /* name                 */      "pantheon",                                           
       /* healthBarHeight      */      137.0,                   
       /* baseMoveSpeed        */      345.0,                     
       /* attackRange          */      175.0,                       
       /* attackSpeed          */      0.6439999938011169,                       
       /* attackSpeedRatio     */      0.6439999938011169,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      125.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      20.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("perksperxie"), 
  new UnitInfo(
  {
       /* name                 */      "perksperxie",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      560.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      115.0,            
       /* pathRadius           */      31.52079963684082,        
       /* gameplayRadius       */      50.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("perkszombieward"), 
  new UnitInfo(
  {
       /* name                 */      "perkszombieward",                                           
       /* healthBarHeight      */      180.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      0.0,            
       /* pathRadius           */      5.0,        
       /* gameplayRadius       */      1.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Special_TurretIgnores).set(Unit_Ward).set(Unit_Special)
  })
},


{ std::string("petakalidragon"), 
  new UnitInfo(
  {
       /* name                 */      "petakalidragon",                                           
       /* healthBarHeight      */      70.0,                   
       /* baseMoveSpeed        */      350.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      115.0,            
       /* pathRadius           */      50.0,        
       /* gameplayRadius       */      80.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("petbuglet"), 
  new UnitInfo(
  {
       /* name                 */      "petbuglet",                                           
       /* healthBarHeight      */      70.0,                   
       /* baseMoveSpeed        */      350.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      0.0,            
       /* pathRadius           */      50.0,        
       /* gameplayRadius       */      80.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("petgargoyle"), 
  new UnitInfo(
  {
       /* name                 */      "petgargoyle",                                           
       /* healthBarHeight      */      70.0,                   
       /* baseMoveSpeed        */      350.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      0.0,            
       /* pathRadius           */      50.0,        
       /* gameplayRadius       */      80.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("petgemtiger"), 
  new UnitInfo(
  {
       /* name                 */      "petgemtiger",                                           
       /* healthBarHeight      */      70.0,                   
       /* baseMoveSpeed        */      350.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      115.0,            
       /* pathRadius           */      50.0,        
       /* gameplayRadius       */      80.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("petghosty"), 
  new UnitInfo(
  {
       /* name                 */      "petghosty",                                           
       /* healthBarHeight      */      80.0,                   
       /* baseMoveSpeed        */      350.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      0.0,            
       /* pathRadius           */      0.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("petgriffin"), 
  new UnitInfo(
  {
       /* name                 */      "petgriffin",                                           
       /* healthBarHeight      */      70.0,                   
       /* baseMoveSpeed        */      350.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      115.0,            
       /* pathRadius           */      50.0,        
       /* gameplayRadius       */      80.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("petgrumpylion"), 
  new UnitInfo(
  {
       /* name                 */      "petgrumpylion",                                           
       /* healthBarHeight      */      75.0,                   
       /* baseMoveSpeed        */      350.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      0.0,            
       /* pathRadius           */      0.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("pethextechbirb"), 
  new UnitInfo(
  {
       /* name                 */      "pethextechbirb",                                           
       /* healthBarHeight      */      70.0,                   
       /* baseMoveSpeed        */      350.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      0.0,            
       /* pathRadius           */      50.0,        
       /* gameplayRadius       */      80.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("petminer"), 
  new UnitInfo(
  {
       /* name                 */      "petminer",                                           
       /* healthBarHeight      */      75.0,                   
       /* baseMoveSpeed        */      350.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      0.0,            
       /* pathRadius           */      0.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("petminigolem"), 
  new UnitInfo(
  {
       /* name                 */      "petminigolem",                                           
       /* healthBarHeight      */      85.0,                   
       /* baseMoveSpeed        */      350.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      0.0,            
       /* pathRadius           */      0.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("petpenguknight"), 
  new UnitInfo(
  {
       /* name                 */      "petpenguknight",                                           
       /* healthBarHeight      */      70.0,                   
       /* baseMoveSpeed        */      350.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      0.0,            
       /* pathRadius           */      0.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("petqiyanadog"), 
  new UnitInfo(
  {
       /* name                 */      "petqiyanadog",                                           
       /* healthBarHeight      */      70.0,                   
       /* baseMoveSpeed        */      350.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      115.0,            
       /* pathRadius           */      50.0,        
       /* gameplayRadius       */      80.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("petsennabunny"), 
  new UnitInfo(
  {
       /* name                 */      "petsennabunny",                                           
       /* healthBarHeight      */      70.0,                   
       /* baseMoveSpeed        */      350.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      115.0,            
       /* pathRadius           */      50.0,        
       /* gameplayRadius       */      80.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("petsgcat"), 
  new UnitInfo(
  {
       /* name                 */      "petsgcat",                                           
       /* healthBarHeight      */      70.0,                   
       /* baseMoveSpeed        */      350.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      115.0,            
       /* pathRadius           */      50.0,        
       /* gameplayRadius       */      80.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("petsgpig"), 
  new UnitInfo(
  {
       /* name                 */      "petsgpig",                                           
       /* healthBarHeight      */      70.0,                   
       /* baseMoveSpeed        */      350.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      115.0,            
       /* pathRadius           */      50.0,        
       /* gameplayRadius       */      80.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("petsgshisa"), 
  new UnitInfo(
  {
       /* name                 */      "petsgshisa",                                           
       /* healthBarHeight      */      70.0,                   
       /* baseMoveSpeed        */      350.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      115.0,            
       /* pathRadius           */      50.0,        
       /* gameplayRadius       */      80.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("petspiritfox"), 
  new UnitInfo(
  {
       /* name                 */      "petspiritfox",                                           
       /* healthBarHeight      */      70.0,                   
       /* baseMoveSpeed        */      350.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      115.0,            
       /* pathRadius           */      50.0,        
       /* gameplayRadius       */      80.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("pettftavatar"), 
  new UnitInfo(
  {
       /* name                 */      "pettftavatar",                                           
       /* healthBarHeight      */      80.0,                   
       /* baseMoveSpeed        */      350.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      115.0,            
       /* pathRadius           */      50.0,        
       /* gameplayRadius       */      80.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("poppy"), 
  new UnitInfo(
  {
       /* name                 */      "poppy",                                           
       /* healthBarHeight      */      80.0,                   
       /* baseMoveSpeed        */      345.0,                     
       /* attackRange          */      125.0,                       
       /* attackSpeed          */      0.625,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      400.0,                  
       /* selectionRadius      */      95.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      55.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("practicetool_targetdummy"), 
  new UnitInfo(
  {
       /* name                 */      "practicetool_targetdummy",                                           
       /* healthBarHeight      */      95.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      175.0,                       
       /* attackSpeed          */      0.6579999923706055,                       
       /* attackSpeedRatio     */      0.6579999923706055,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      100.0,            
       /* pathRadius           */      30.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("preseason_turret_shield"), 
  new UnitInfo(
  {
       /* name                 */      "preseason_turret_shield",                                           
       /* healthBarHeight      */      300.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      750.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      0.0,            
       /* pathRadius           */      0.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      1200.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Structure).set(Unit_Structure_Turret)
  })
},


{ std::string("promocontroller"), 
  new UnitInfo(
  {
       /* name                 */      "promocontroller",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      0.0,            
       /* pathRadius           */      0.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("pyke"), 
  new UnitInfo(
  {
       /* name                 */      "pyke",                                           
       /* healthBarHeight      */      99.0,                   
       /* baseMoveSpeed        */      330.0,                     
       /* attackRange          */      150.0,                       
       /* attackSpeed          */      0.6669999957084656,                       
       /* attackSpeedRatio     */      0.6669999957084656,                  
                                                                            
       /* acquisitionRange     */      400.0,                  
       /* selectionRadius      */      120.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      347.79998779296875,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("qiyana"), 
  new UnitInfo(
  {
       /* name                 */      "qiyana",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      335.0,                     
       /* attackRange          */      150.0,                       
       /* attackSpeed          */      0.625,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      120.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("quinn"), 
  new UnitInfo(
  {
       /* name                 */      "quinn",                                           
       /* healthBarHeight      */      105.0,                   
       /* baseMoveSpeed        */      335.0,                     
       /* attackRange          */      525.0,                       
       /* attackSpeed          */      0.6679999828338623,                       
       /* attackSpeedRatio     */      0.6679999828338623,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      120.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      2000.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("quinnvalor"), 
  new UnitInfo(
  {
       /* name                 */      "quinnvalor",                                           
       /* healthBarHeight      */      105.0,                   
       /* baseMoveSpeed        */      335.0,                     
       /* attackRange          */      525.0,                       
       /* attackSpeed          */      0.6679999828338623,                       
       /* attackSpeedRatio     */      0.6679999828338623,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      120.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("rakan"), 
  new UnitInfo(
  {
       /* name                 */      "rakan",                                           
       /* healthBarHeight      */      110.0,                   
       /* baseMoveSpeed        */      335.0,                     
       /* attackRange          */      300.0,                       
       /* attackSpeed          */      0.6349999904632568,                       
       /* attackSpeedRatio     */      0.6349999904632568,                  
                                                                            
       /* acquisitionRange     */      475.0,                  
       /* selectionRadius      */      125.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      1000.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("rammus"), 
  new UnitInfo(
  {
       /* name                 */      "rammus",                                           
       /* healthBarHeight      */      85.0,                   
       /* baseMoveSpeed        */      335.0,                     
       /* attackRange          */      125.0,                       
       /* attackSpeed          */      0.656000018119812,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      120.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("rammusdbc"), 
  new UnitInfo(
  {
       /* name                 */      "rammusdbc",                                           
       /* healthBarHeight      */      85.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.625,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      120.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("rammuspb"), 
  new UnitInfo(
  {
       /* name                 */      "rammuspb",                                           
       /* healthBarHeight      */      85.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.625,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      120.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("reksai"), 
  new UnitInfo(
  {
       /* name                 */      "reksai",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      335.0,                     
       /* attackRange          */      175.0,                       
       /* attackSpeed          */      0.6669999957084656,                       
       /* attackSpeedRatio     */      0.6669999957084656,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      100.0,            
       /* pathRadius           */      30.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion).set(Unit_Special_Void)
  })
},


{ std::string("reksaitunnel"), 
  new UnitInfo(
  {
       /* name                 */      "reksaitunnel",                                           
       /* healthBarHeight      */      60.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      50.0,                  
       /* selectionRadius      */      75.0,            
       /* pathRadius           */      0.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Special_TeleportTarget).set(Unit_IsolationNonImpacting).set(Unit_Special_Tunnel)
  })
},


{ std::string("renekton"), 
  new UnitInfo(
  {
       /* name                 */      "renekton",                                           
       /* healthBarHeight      */      110.0,                   
       /* baseMoveSpeed        */      345.0,                     
       /* attackRange          */      125.0,                       
       /* attackSpeed          */      0.6650000214576721,                       
       /* attackSpeedRatio     */      0.6650000214576721,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      125.0,            
       /* pathRadius           */      50.0,        
       /* gameplayRadius       */      80.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("rengar"), 
  new UnitInfo(
  {
       /* name                 */      "rengar",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      345.0,                     
       /* attackRange          */      125.0,                       
       /* attackSpeed          */      0.6669999957084656,                       
       /* attackSpeedRatio     */      0.6669999957084656,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      70.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("riven"), 
  new UnitInfo(
  {
       /* name                 */      "riven",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      340.0,                     
       /* attackRange          */      125.0,                       
       /* attackSpeed          */      0.625,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      130.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      347.79998779296875,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("rumble"), 
  new UnitInfo(
  {
       /* name                 */      "rumble",                                           
       /* healthBarHeight      */      110.0,                   
       /* baseMoveSpeed        */      345.0,                     
       /* attackRange          */      125.0,                       
       /* attackSpeed          */      0.6439999938011169,                       
       /* attackSpeedRatio     */      0.6439999938011169,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      165.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      80.0,
       
       /* basicAtkMissileSpeed */      347.79998779296875,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("ryze"), 
  new UnitInfo(
  {
       /* name                 */      "ryze",                                           
       /* healthBarHeight      */      115.0,                   
       /* baseMoveSpeed        */      340.0,                     
       /* attackRange          */      550.0,                       
       /* attackSpeed          */      0.625,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      575.0,                  
       /* selectionRadius      */      120.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      2400.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("s5test_wardcorpse"), 
  new UnitInfo(
  {
       /* name                 */      "s5test_wardcorpse",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      450.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      0.0,            
       /* pathRadius           */      0.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Special_TurretIgnores).set(Unit_Special)
  })
},


{ std::string("samira"), 
  new UnitInfo(
  {
       /* name                 */      "samira",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      335.0,                     
       /* attackRange          */      500.0,                       
       /* attackSpeed          */      0.6579999923706055,                       
       /* attackSpeedRatio     */      0.6579999923706055,                  
                                                                            
       /* acquisitionRange     */      800.0,                  
       /* selectionRadius      */      100.0,            
       /* pathRadius           */      40.68000030517578,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      2800.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("sejuani"), 
  new UnitInfo(
  {
       /* name                 */      "sejuani",                                           
       /* healthBarHeight      */      110.0,                   
       /* baseMoveSpeed        */      340.0,                     
       /* attackRange          */      150.0,                       
       /* attackSpeed          */      0.6880000233650208,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      140.0,            
       /* pathRadius           */      50.0,        
       /* gameplayRadius       */      80.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("senna"), 
  new UnitInfo(
  {
       /* name                 */      "senna",                                           
       /* healthBarHeight      */      90.0,                   
       /* baseMoveSpeed        */      330.0,                     
       /* attackRange          */      600.0,                       
       /* attackSpeed          */      0.625,                       
       /* attackSpeedRatio     */      0.20000000298023224,                  
                                                                            
       /* acquisitionRange     */      800.0,                  
       /* selectionRadius      */      115.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      8000.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("sennasoul"), 
  new UnitInfo(
  {
       /* name                 */      "sennasoul",                                           
       /* healthBarHeight      */      200.0,                   
       /* baseMoveSpeed        */      325.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      0.0,            
       /* pathRadius           */      0.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Special_UntargetableBySpells).set(Unit_IsolationNonImpacting)
  })
},


{ std::string("seraphine"), 
  new UnitInfo(
  {
       /* name                 */      "seraphine",                                           
       /* healthBarHeight      */      130.0,                   
       /* baseMoveSpeed        */      325.0,                     
       /* attackRange          */      525.0,                       
       /* attackSpeed          */      0.6690000295639038,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      525.0,                  
       /* selectionRadius      */      0.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("sett"), 
  new UnitInfo(
  {
       /* name                 */      "sett",                                           
       /* healthBarHeight      */      112.0,                   
       /* baseMoveSpeed        */      340.0,                     
       /* attackRange          */      125.0,                       
       /* attackSpeed          */      0.625,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      100.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      20.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("shaco"), 
  new UnitInfo(
  {
       /* name                 */      "shaco",                                           
       /* healthBarHeight      */      93.0,                   
       /* baseMoveSpeed        */      350.0,                     
       /* attackRange          */      125.0,                       
       /* attackSpeed          */      0.6940000057220459,                       
       /* attackSpeedRatio     */      0.6940000057220459,                  
                                                                            
       /* acquisitionRange     */      400.0,                  
       /* selectionRadius      */      135.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("shacobox"), 
  new UnitInfo(
  {
       /* name                 */      "shacobox",                                           
       /* healthBarHeight      */      57.0,                   
       /* baseMoveSpeed        */      325.0,                     
       /* attackRange          */      600.0,                       
       /* attackSpeed          */      1.3589999675750732,                       
       /* attackSpeedRatio     */      1.3589999675750732,                  
                                                                            
       /* acquisitionRange     */      700.0,                  
       /* selectionRadius      */      115.0,            
       /* pathRadius           */      1.0,        
       /* gameplayRadius       */      50.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Minion).set(Unit_Special_TeleportTarget).set(Unit_Minion_Summon).set(Unit_Special_Trap).set(Unit_Special)
  })
},


{ std::string("shen"), 
  new UnitInfo(
  {
       /* name                 */      "shen",                                           
       /* healthBarHeight      */      105.0,                   
       /* baseMoveSpeed        */      340.0,                     
       /* attackRange          */      125.0,                       
       /* attackSpeed          */      0.7509999871253967,                       
       /* attackSpeedRatio     */      0.6510000228881836,                  
                                                                            
       /* acquisitionRange     */      400.0,                  
       /* selectionRadius      */      100.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("shenspirit"), 
  new UnitInfo(
  {
       /* name                 */      "shenspirit",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      1.0,            
       /* pathRadius           */      1.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("shyvana"), 
  new UnitInfo(
  {
       /* name                 */      "shyvana",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      350.0,                     
       /* attackRange          */      125.0,                       
       /* attackSpeed          */      0.6579999923706055,                       
       /* attackSpeedRatio     */      0.6579999923706055,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      100.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      467.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("shyvanadragon"), 
  new UnitInfo(
  {
       /* name                 */      "shyvanadragon",                                           
       /* healthBarHeight      */      110.0,                   
       /* baseMoveSpeed        */      350.0,                     
       /* attackRange          */      175.0,                       
       /* attackSpeed          */      0.6579999923706055,                       
       /* attackSpeedRatio     */      0.6579999923706055,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      145.0,            
       /* pathRadius           */      50.0,        
       /* gameplayRadius       */      80.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("sightward"), 
  new UnitInfo(
  {
       /* name                 */      "sightward",                                           
       /* healthBarHeight      */      180.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      0.0,            
       /* pathRadius           */      5.0,        
       /* gameplayRadius       */      1.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Special_TurretIgnores).set(Unit_Special_UntargetableBySpells).set(Unit_Ward).set(Unit_Special)
  })
},


{ std::string("singed"), 
  new UnitInfo(
  {
       /* name                 */      "singed",                                           
       /* healthBarHeight      */      110.0,                   
       /* baseMoveSpeed        */      345.0,                     
       /* attackRange          */      125.0,                       
       /* attackSpeed          */      0.6129999756813049,                       
       /* attackSpeedRatio     */      0.6129999756813049,                  
                                                                            
       /* acquisitionRange     */      300.0,                  
       /* selectionRadius      */      135.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("sion"), 
  new UnitInfo(
  {
       /* name                 */      "sion",                                           
       /* healthBarHeight      */      125.0,                   
       /* baseMoveSpeed        */      345.0,                     
       /* attackRange          */      175.0,                       
       /* attackSpeed          */      0.6790000200271606,                       
       /* attackSpeedRatio     */      0.6790000200271606,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      125.0,            
       /* pathRadius           */      25.766599655151367,        
       /* gameplayRadius       */      80.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("sivir"), 
  new UnitInfo(
  {
       /* name                 */      "sivir",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      335.0,                     
       /* attackRange          */      500.0,                       
       /* attackSpeed          */      0.625,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      500.0,                  
       /* selectionRadius      */      115.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      1750.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("skarner"), 
  new UnitInfo(
  {
       /* name                 */      "skarner",                                           
       /* healthBarHeight      */      85.0,                   
       /* baseMoveSpeed        */      335.0,                     
       /* attackRange          */      125.0,                       
       /* attackSpeed          */      0.625,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      130.0,            
       /* pathRadius           */      50.0,        
       /* gameplayRadius       */      80.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("skarnercrystalprop"), 
  new UnitInfo(
  {
       /* name                 */      "skarnercrystalprop",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      0.0,            
       /* pathRadius           */      44.20000076293945,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("skarnerpassivecrystal"), 
  new UnitInfo(
  {
       /* name                 */      "skarnerpassivecrystal",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      325.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      1.0,            
       /* pathRadius           */      1.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("sona"), 
  new UnitInfo(
  {
       /* name                 */      "sona",                                           
       /* healthBarHeight      */      113.0,                   
       /* baseMoveSpeed        */      325.0,                     
       /* attackRange          */      550.0,                       
       /* attackSpeed          */      0.6439999938011169,                       
       /* attackSpeedRatio     */      0.6439999938011169,                  
                                                                            
       /* acquisitionRange     */      800.0,                  
       /* selectionRadius      */      110.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      1500.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("sonadjgenre01"), 
  new UnitInfo(
  {
       /* name                 */      "sonadjgenre01",                                           
       /* healthBarHeight      */      113.0,                   
       /* baseMoveSpeed        */      325.0,                     
       /* attackRange          */      550.0,                       
       /* attackSpeed          */      0.6439999938011169,                       
       /* attackSpeedRatio     */      0.6439999938011169,                  
                                                                            
       /* acquisitionRange     */      800.0,                  
       /* selectionRadius      */      110.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("sonadjgenre02"), 
  new UnitInfo(
  {
       /* name                 */      "sonadjgenre02",                                           
       /* healthBarHeight      */      113.0,                   
       /* baseMoveSpeed        */      325.0,                     
       /* attackRange          */      550.0,                       
       /* attackSpeed          */      0.6439999938011169,                       
       /* attackSpeedRatio     */      0.6439999938011169,                  
                                                                            
       /* acquisitionRange     */      800.0,                  
       /* selectionRadius      */      110.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("sonadjgenre03"), 
  new UnitInfo(
  {
       /* name                 */      "sonadjgenre03",                                           
       /* healthBarHeight      */      113.0,                   
       /* baseMoveSpeed        */      325.0,                     
       /* attackRange          */      550.0,                       
       /* attackSpeed          */      0.6439999938011169,                       
       /* attackSpeedRatio     */      0.6439999938011169,                  
                                                                            
       /* acquisitionRange     */      800.0,                  
       /* selectionRadius      */      110.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("soraka"), 
  new UnitInfo(
  {
       /* name                 */      "soraka",                                           
       /* healthBarHeight      */      105.0,                   
       /* baseMoveSpeed        */      325.0,                     
       /* attackRange          */      550.0,                       
       /* attackSpeed          */      0.625,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      110.0,            
       /* pathRadius           */      44.20000076293945,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      1000.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("spellbook1"), 
  new UnitInfo(
  {
       /* name                 */      "spellbook1",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      325.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      52.0,            
       /* pathRadius           */      35.36000061035156,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("sruap_chaosinhibitor"), 
  new UnitInfo(
  {
       /* name                 */      "sruap_chaosinhibitor",                                           
       /* healthBarHeight      */      370.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      0.0,            
       /* pathRadius           */      0.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Structure_Inhibitor).set(Unit_Structure)
  })
},


{ std::string("sruap_chaosinhibitor_rubble"), 
  new UnitInfo(
  {
       /* name                 */      "sruap_chaosinhibitor_rubble",                                           
       /* healthBarHeight      */      370.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      0.0,            
       /* pathRadius           */      0.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("sruap_chaosnexus"), 
  new UnitInfo(
  {
       /* name                 */      "sruap_chaosnexus",                                           
       /* healthBarHeight      */      500.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      0.0,            
       /* pathRadius           */      0.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Structure).set(Unit_Structure_Nexus)
  })
},


{ std::string("sruap_chaosnexus_rubble"), 
  new UnitInfo(
  {
       /* name                 */      "sruap_chaosnexus_rubble",                                           
       /* healthBarHeight      */      500.0,                   
       /* baseMoveSpeed        */      345.0,                     
       /* attackRange          */      175.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      100.0,            
       /* pathRadius           */      30.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("sruap_flag"), 
  new UnitInfo(
  {
       /* name                 */      "sruap_flag",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      345.0,                     
       /* attackRange          */      175.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      100.0,            
       /* pathRadius           */      30.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("sruap_magecrystal"), 
  new UnitInfo(
  {
       /* name                 */      "sruap_magecrystal",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      1250.0,                       
       /* attackSpeed          */      2.5,                       
       /* attackSpeedRatio     */      2.5,                  
                                                                            
       /* acquisitionRange     */      1250.0,                  
       /* selectionRadius      */      130.0,            
       /* pathRadius           */      88.4000015258789,        
       /* gameplayRadius       */      88.4000015258789,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Structure).set(Unit_Structure_Turret).set(Unit_Structure_Turret_Shrine)
  })
},


{ std::string("sruap_orderinhibitor"), 
  new UnitInfo(
  {
       /* name                 */      "sruap_orderinhibitor",                                           
       /* healthBarHeight      */      370.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      0.0,            
       /* pathRadius           */      0.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Structure_Inhibitor).set(Unit_Structure)
  })
},


{ std::string("sruap_orderinhibitor_rubble"), 
  new UnitInfo(
  {
       /* name                 */      "sruap_orderinhibitor_rubble",                                           
       /* healthBarHeight      */      370.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      0.0,            
       /* pathRadius           */      0.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("sruap_ordernexus"), 
  new UnitInfo(
  {
       /* name                 */      "sruap_ordernexus",                                           
       /* healthBarHeight      */      500.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      0.0,            
       /* pathRadius           */      0.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Structure).set(Unit_Structure_Nexus)
  })
},


{ std::string("sruap_ordernexus_rubble"), 
  new UnitInfo(
  {
       /* name                 */      "sruap_ordernexus_rubble",                                           
       /* healthBarHeight      */      500.0,                   
       /* baseMoveSpeed        */      345.0,                     
       /* attackRange          */      175.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      100.0,            
       /* pathRadius           */      30.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("sruap_turret_chaos1"), 
  new UnitInfo(
  {
       /* name                 */      "sruap_turret_chaos1",                                           
       /* healthBarHeight      */      525.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      750.0,                       
       /* attackSpeed          */      0.8330000042915344,                       
       /* attackSpeedRatio     */      0.8330000042915344,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      130.0,            
       /* pathRadius           */      125.0,        
       /* gameplayRadius       */      88.4000015258789,
       
       /* basicAtkMissileSpeed */      1200.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Structure).set(Unit_Structure_Turret).set(Unit_Structure_Turret_Outer)
  })
},


{ std::string("sruap_turret_chaos1_bot"), 
  new UnitInfo(
  {
       /* name                 */      "sruap_turret_chaos1_bot",                                           
       /* healthBarHeight      */      525.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      750.0,                       
       /* attackSpeed          */      0.8330000042915344,                       
       /* attackSpeedRatio     */      0.8330000042915344,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      130.0,            
       /* pathRadius           */      125.0,        
       /* gameplayRadius       */      88.4000015258789,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Structure).set(Unit_Structure_Turret).set(Unit_Structure_Turret_Outer)
  })
},


{ std::string("sruap_turret_chaos1_rubble"), 
  new UnitInfo(
  {
       /* name                 */      "sruap_turret_chaos1_rubble",                                           
       /* healthBarHeight      */      525.0,                   
       /* baseMoveSpeed        */      345.0,                     
       /* attackRange          */      175.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      100.0,            
       /* pathRadius           */      30.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("sruap_turret_chaos2"), 
  new UnitInfo(
  {
       /* name                 */      "sruap_turret_chaos2",                                           
       /* healthBarHeight      */      525.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      750.0,                       
       /* attackSpeed          */      0.8330000042915344,                       
       /* attackSpeedRatio     */      0.8330000042915344,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      130.0,            
       /* pathRadius           */      125.0,        
       /* gameplayRadius       */      88.4000015258789,
       
       /* basicAtkMissileSpeed */      1200.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Structure).set(Unit_Structure_Turret).set(Unit_Structure_Turret_Inner)
  })
},


{ std::string("sruap_turret_chaos3"), 
  new UnitInfo(
  {
       /* name                 */      "sruap_turret_chaos3",                                           
       /* healthBarHeight      */      525.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      750.0,                       
       /* attackSpeed          */      0.8330000042915344,                       
       /* attackSpeedRatio     */      0.8330000042915344,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      130.0,            
       /* pathRadius           */      125.0,        
       /* gameplayRadius       */      88.4000015258789,
       
       /* basicAtkMissileSpeed */      1200.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Structure).set(Unit_Structure_Turret).set(Unit_Structure_Turret_Inhib)
  })
},


{ std::string("sruap_turret_chaos3_test"), 
  new UnitInfo(
  {
       /* name                 */      "sruap_turret_chaos3_test",                                           
       /* healthBarHeight      */      525.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      750.0,                       
       /* attackSpeed          */      0.8330000042915344,                       
       /* attackSpeedRatio     */      0.8330000042915344,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      130.0,            
       /* pathRadius           */      125.0,        
       /* gameplayRadius       */      88.4000015258789,
       
       /* basicAtkMissileSpeed */      1200.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Structure).set(Unit_Structure_Turret).set(Unit_Structure_Turret_Inhib)
  })
},


{ std::string("sruap_turret_chaos4"), 
  new UnitInfo(
  {
       /* name                 */      "sruap_turret_chaos4",                                           
       /* healthBarHeight      */      525.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      750.0,                       
       /* attackSpeed          */      0.8330000042915344,                       
       /* attackSpeedRatio     */      0.8330000042915344,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      130.0,            
       /* pathRadius           */      125.0,        
       /* gameplayRadius       */      88.4000015258789,
       
       /* basicAtkMissileSpeed */      1200.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Structure_Turret_Nexus).set(Unit_Structure).set(Unit_Structure_Turret)
  })
},


{ std::string("sruap_turret_chaos5"), 
  new UnitInfo(
  {
       /* name                 */      "sruap_turret_chaos5",                                           
       /* healthBarHeight      */      525.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      1250.0,                       
       /* attackSpeed          */      0.22200000286102295,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      1250.0,                  
       /* selectionRadius      */      130.0,            
       /* pathRadius           */      125.0,        
       /* gameplayRadius       */      88.4000015258789,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Structure).set(Unit_Structure_Turret).set(Unit_Structure_Turret_Shrine)
  })
},


{ std::string("sruap_turret_order1"), 
  new UnitInfo(
  {
       /* name                 */      "sruap_turret_order1",                                           
       /* healthBarHeight      */      525.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      750.0,                       
       /* attackSpeed          */      0.8330000042915344,                       
       /* attackSpeedRatio     */      0.8330000042915344,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      130.0,            
       /* pathRadius           */      125.0,        
       /* gameplayRadius       */      88.4000015258789,
       
       /* basicAtkMissileSpeed */      1200.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Structure).set(Unit_Structure_Turret).set(Unit_Structure_Turret_Outer)
  })
},


{ std::string("sruap_turret_order1_bot"), 
  new UnitInfo(
  {
       /* name                 */      "sruap_turret_order1_bot",                                           
       /* healthBarHeight      */      525.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      750.0,                       
       /* attackSpeed          */      0.8330000042915344,                       
       /* attackSpeedRatio     */      0.8330000042915344,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      130.0,            
       /* pathRadius           */      125.0,        
       /* gameplayRadius       */      88.4000015258789,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Structure).set(Unit_Structure_Turret).set(Unit_Structure_Turret_Outer)
  })
},


{ std::string("sruap_turret_order1_rubble"), 
  new UnitInfo(
  {
       /* name                 */      "sruap_turret_order1_rubble",                                           
       /* healthBarHeight      */      485.0,                   
       /* baseMoveSpeed        */      345.0,                     
       /* attackRange          */      175.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      100.0,            
       /* pathRadius           */      30.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("sruap_turret_order2"), 
  new UnitInfo(
  {
       /* name                 */      "sruap_turret_order2",                                           
       /* healthBarHeight      */      485.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      750.0,                       
       /* attackSpeed          */      0.8330000042915344,                       
       /* attackSpeedRatio     */      0.8330000042915344,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      130.0,            
       /* pathRadius           */      125.0,        
       /* gameplayRadius       */      88.4000015258789,
       
       /* basicAtkMissileSpeed */      1200.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Structure).set(Unit_Structure_Turret).set(Unit_Structure_Turret_Inner)
  })
},


{ std::string("sruap_turret_order3"), 
  new UnitInfo(
  {
       /* name                 */      "sruap_turret_order3",                                           
       /* healthBarHeight      */      485.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      750.0,                       
       /* attackSpeed          */      0.8330000042915344,                       
       /* attackSpeedRatio     */      0.8330000042915344,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      130.0,            
       /* pathRadius           */      125.0,        
       /* gameplayRadius       */      88.4000015258789,
       
       /* basicAtkMissileSpeed */      1200.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Structure).set(Unit_Structure_Turret).set(Unit_Structure_Turret_Inhib)
  })
},


{ std::string("sruap_turret_order3_test"), 
  new UnitInfo(
  {
       /* name                 */      "sruap_turret_order3_test",                                           
       /* healthBarHeight      */      485.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      750.0,                       
       /* attackSpeed          */      0.8330000042915344,                       
       /* attackSpeedRatio     */      0.8330000042915344,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      130.0,            
       /* pathRadius           */      125.0,        
       /* gameplayRadius       */      88.4000015258789,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Structure).set(Unit_Structure_Turret).set(Unit_Structure_Turret_Inhib)
  })
},


{ std::string("sruap_turret_order4"), 
  new UnitInfo(
  {
       /* name                 */      "sruap_turret_order4",                                           
       /* healthBarHeight      */      485.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      750.0,                       
       /* attackSpeed          */      0.8330000042915344,                       
       /* attackSpeedRatio     */      0.8330000042915344,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      130.0,            
       /* pathRadius           */      125.0,        
       /* gameplayRadius       */      88.4000015258789,
       
       /* basicAtkMissileSpeed */      1200.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Structure_Turret_Nexus).set(Unit_Structure).set(Unit_Structure_Turret)
  })
},


{ std::string("sruap_turret_order5"), 
  new UnitInfo(
  {
       /* name                 */      "sruap_turret_order5",                                           
       /* healthBarHeight      */      485.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      1250.0,                       
       /* attackSpeed          */      2.5,                       
       /* attackSpeedRatio     */      2.5,                  
                                                                            
       /* acquisitionRange     */      1250.0,                  
       /* selectionRadius      */      130.0,            
       /* pathRadius           */      125.0,        
       /* gameplayRadius       */      88.4000015258789,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Structure).set(Unit_Structure_Turret).set(Unit_Structure_Turret_Shrine)
  })
},


{ std::string("sru_antlermouse"), 
  new UnitInfo(
  {
       /* name                 */      "sru_antlermouse",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      345.0,                     
       /* attackRange          */      175.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      100.0,            
       /* pathRadius           */      30.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("sru_baron"), 
  new UnitInfo(
  {
       /* name                 */      "sru_baron",                                           
       /* healthBarHeight      */      260.0,                   
       /* baseMoveSpeed        */      300.0,                     
       /* attackRange          */      900.0,                       
       /* attackSpeed          */      0.625,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      400.0,                  
       /* selectionRadius      */      180.0,            
       /* pathRadius           */      0.0,        
       /* gameplayRadius       */      105.0,
       
       /* basicAtkMissileSpeed */      1300.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Monster_Epic).set(Unit_Monster).set(Unit_Special_Void).set(Unit_Monster_Camp)
  })
},


{ std::string("sru_baronspawn"), 
  new UnitInfo(
  {
       /* name                 */      "sru_baronspawn",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      900.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      0.0,            
       /* pathRadius           */      0.0,        
       /* gameplayRadius       */      1.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("sru_bird"), 
  new UnitInfo(
  {
       /* name                 */      "sru_bird",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      900.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      0.0,            
       /* pathRadius           */      0.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("sru_blue"), 
  new UnitInfo(
  {
       /* name                 */      "sru_blue",                                           
       /* healthBarHeight      */      128.0,                   
       /* baseMoveSpeed        */      275.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.49300000071525574,                       
       /* attackSpeedRatio     */      0.49300000071525574,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      120.0,            
       /* pathRadius           */      30.0,        
       /* gameplayRadius       */      131.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Monster_Blue).set(Unit_Monster_Buff).set(Unit_Monster).set(Unit_Monster_Camp).set(Unit_Monster_Large)
  })
},


{ std::string("sru_bluemini"), 
  new UnitInfo(
  {
       /* name                 */      "sru_bluemini",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      330.0,                     
       /* attackRange          */      450.0,                       
       /* attackSpeed          */      0.625,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      100.0,            
       /* pathRadius           */      30.0,        
       /* gameplayRadius       */      50.0,
       
       /* basicAtkMissileSpeed */      750.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Monster_Blue).set(Unit_Monster).set(Unit_Monster_Camp)
  })
},


{ std::string("sru_bluemini2"), 
  new UnitInfo(
  {
       /* name                 */      "sru_bluemini2",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      330.0,                     
       /* attackRange          */      450.0,                       
       /* attackSpeed          */      0.625,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      100.0,            
       /* pathRadius           */      30.0,        
       /* gameplayRadius       */      50.0,
       
       /* basicAtkMissileSpeed */      750.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Monster_Blue).set(Unit_Monster).set(Unit_Monster_Camp)
  })
},


{ std::string("sru_camprespawnmarker"), 
  new UnitInfo(
  {
       /* name                 */      "sru_camprespawnmarker",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      0.0,            
       /* pathRadius           */      0.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Special)
  })
},


{ std::string("sru_chaosminionmelee"), 
  new UnitInfo(
  {
       /* name                 */      "sru_chaosminionmelee",                                           
       /* healthBarHeight      */      40.0,                   
       /* baseMoveSpeed        */      325.0,                     
       /* attackRange          */      110.0,                       
       /* attackSpeed          */      1.25,                       
       /* attackSpeedRatio     */      1.25,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      115.0,            
       /* pathRadius           */      35.74369812011719,        
       /* gameplayRadius       */      48.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Minion).set(Unit_Minion_Lane).set(Unit_Minion_Lane_Melee)
  })
},


{ std::string("sru_chaosminionranged"), 
  new UnitInfo(
  {
       /* name                 */      "sru_chaosminionranged",                                           
       /* healthBarHeight      */      38.0,                   
       /* baseMoveSpeed        */      325.0,                     
       /* attackRange          */      550.0,                       
       /* attackSpeed          */      0.6669999957084656,                       
       /* attackSpeedRatio     */      0.6669999957084656,                  
                                                                            
       /* acquisitionRange     */      700.0,                  
       /* selectionRadius      */      115.0,            
       /* pathRadius           */      35.74369812011719,        
       /* gameplayRadius       */      48.0,
       
       /* basicAtkMissileSpeed */      650.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Minion).set(Unit_Minion_Lane).set(Unit_Minion_Lane_Ranged)
  })
},


{ std::string("sru_chaosminionsiege"), 
  new UnitInfo(
  {
       /* name                 */      "sru_chaosminionsiege",                                           
       /* healthBarHeight      */      55.0,                   
       /* baseMoveSpeed        */      325.0,                     
       /* attackRange          */      300.0,                       
       /* attackSpeed          */      1.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      140.0,            
       /* pathRadius           */      55.74369812011719,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      1200.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Minion).set(Unit_Minion_Lane).set(Unit_Minion_Lane_Siege)
  })
},


{ std::string("sru_chaosminionsuper"), 
  new UnitInfo(
  {
       /* name                 */      "sru_chaosminionsuper",                                           
       /* healthBarHeight      */      77.0,                   
       /* baseMoveSpeed        */      325.0,                     
       /* attackRange          */      170.0,                       
       /* attackSpeed          */      0.8500000238418579,                       
       /* attackSpeedRatio     */      0.8500000238418579,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      145.0,            
       /* pathRadius           */      55.52080154418945,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Minion_Lane_Super).set(Unit_Minion).set(Unit_Minion_Lane)
  })
},


{ std::string("sru_crab"), 
  new UnitInfo(
  {
       /* name                 */      "sru_crab",                                           
       /* healthBarHeight      */      61.0,                   
       /* baseMoveSpeed        */      255.0,                     
       /* attackRange          */      300.0,                       
       /* attackSpeed          */      0.6380000114440918,                       
       /* attackSpeedRatio     */      0.6380000114440918,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      110.0,            
       /* pathRadius           */      100.0,        
       /* gameplayRadius       */      50.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Monster).set(Unit_Special_Peaceful).set(Unit_Monster_Camp).set(Unit_Monster_Large).set(Unit_Monster_Crab)
  })
},


{ std::string("sru_crabward"), 
  new UnitInfo(
  {
       /* name                 */      "sru_crabward",                                           
       /* healthBarHeight      */      56.5,                   
       /* baseMoveSpeed        */      755.0,                     
       /* attackRange          */      300.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      0.0,            
       /* pathRadius           */      0.0,        
       /* gameplayRadius       */      50.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("sru_dragon"), 
  new UnitInfo(
  {
       /* name                 */      "sru_dragon",                                           
       /* healthBarHeight      */      102.5,                   
       /* baseMoveSpeed        */      330.0,                     
       /* attackRange          */      500.0,                       
       /* attackSpeed          */      0.5,                       
       /* attackSpeedRatio     */      0.5,                  
                                                                            
       /* acquisitionRange     */      1000.0,                  
       /* selectionRadius      */      200.0,            
       /* pathRadius           */      1.0,        
       /* gameplayRadius       */      125.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Monster_Epic).set(Unit_Monster).set(Unit_Monster_Dragon).set(Unit_Monster_Camp)
  })
},


{ std::string("sru_dragon_air"), 
  new UnitInfo(
  {
       /* name                 */      "sru_dragon_air",                                           
       /* healthBarHeight      */      102.5,                   
       /* baseMoveSpeed        */      330.0,                     
       /* attackRange          */      500.0,                       
       /* attackSpeed          */      0.5,                       
       /* attackSpeedRatio     */      0.5,                  
                                                                            
       /* acquisitionRange     */      1000.0,                  
       /* selectionRadius      */      200.0,            
       /* pathRadius           */      1.0,        
       /* gameplayRadius       */      125.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Monster_Epic).set(Unit_Monster).set(Unit_Monster_Dragon).set(Unit_Monster_Camp)
  })
},


{ std::string("sru_dragon_earth"), 
  new UnitInfo(
  {
       /* name                 */      "sru_dragon_earth",                                           
       /* healthBarHeight      */      102.5,                   
       /* baseMoveSpeed        */      330.0,                     
       /* attackRange          */      500.0,                       
       /* attackSpeed          */      0.5,                       
       /* attackSpeedRatio     */      0.5,                  
                                                                            
       /* acquisitionRange     */      1000.0,                  
       /* selectionRadius      */      200.0,            
       /* pathRadius           */      1.0,        
       /* gameplayRadius       */      125.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Monster_Epic).set(Unit_Monster).set(Unit_Monster_Dragon).set(Unit_Monster_Camp)
  })
},


{ std::string("sru_dragon_elder"), 
  new UnitInfo(
  {
       /* name                 */      "sru_dragon_elder",                                           
       /* healthBarHeight      */      202.0,                   
       /* baseMoveSpeed        */      330.0,                     
       /* attackRange          */      500.0,                       
       /* attackSpeed          */      0.5,                       
       /* attackSpeedRatio     */      0.5,                  
                                                                            
       /* acquisitionRange     */      1000.0,                  
       /* selectionRadius      */      200.0,            
       /* pathRadius           */      1.0,        
       /* gameplayRadius       */      125.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Monster_Epic).set(Unit_Monster).set(Unit_Monster_Dragon).set(Unit_Monster_Camp)
  })
},


{ std::string("sru_dragon_fire"), 
  new UnitInfo(
  {
       /* name                 */      "sru_dragon_fire",                                           
       /* healthBarHeight      */      102.5,                   
       /* baseMoveSpeed        */      330.0,                     
       /* attackRange          */      500.0,                       
       /* attackSpeed          */      0.5,                       
       /* attackSpeedRatio     */      0.5,                  
                                                                            
       /* acquisitionRange     */      1000.0,                  
       /* selectionRadius      */      200.0,            
       /* pathRadius           */      1.0,        
       /* gameplayRadius       */      125.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Monster_Epic).set(Unit_Monster).set(Unit_Monster_Dragon).set(Unit_Monster_Camp)
  })
},


{ std::string("sru_dragon_prop"), 
  new UnitInfo(
  {
       /* name                 */      "sru_dragon_prop",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      4000.0,            
       /* pathRadius           */      0.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("sru_dragon_water"), 
  new UnitInfo(
  {
       /* name                 */      "sru_dragon_water",                                           
       /* healthBarHeight      */      102.5,                   
       /* baseMoveSpeed        */      330.0,                     
       /* attackRange          */      500.0,                       
       /* attackSpeed          */      0.5,                       
       /* attackSpeedRatio     */      0.5,                  
                                                                            
       /* acquisitionRange     */      1000.0,                  
       /* selectionRadius      */      200.0,            
       /* pathRadius           */      1.0,        
       /* gameplayRadius       */      125.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Monster_Epic).set(Unit_Monster).set(Unit_Monster_Dragon).set(Unit_Monster_Camp)
  })
},


{ std::string("sru_duck"), 
  new UnitInfo(
  {
       /* name                 */      "sru_duck",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      345.0,                     
       /* attackRange          */      175.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      100.0,            
       /* pathRadius           */      30.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("sru_duckie"), 
  new UnitInfo(
  {
       /* name                 */      "sru_duckie",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      115.0,            
       /* pathRadius           */      31.52079963684082,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("sru_es_bannerplatform_chaos"), 
  new UnitInfo(
  {
       /* name                 */      "sru_es_bannerplatform_chaos",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      345.0,                     
       /* attackRange          */      175.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      250.0,            
       /* pathRadius           */      30.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("sru_es_bannerplatform_order"), 
  new UnitInfo(
  {
       /* name                 */      "sru_es_bannerplatform_order",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      345.0,                     
       /* attackRange          */      175.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      250.0,            
       /* pathRadius           */      30.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("sru_es_bannerwall_chaos"), 
  new UnitInfo(
  {
       /* name                 */      "sru_es_bannerwall_chaos",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      345.0,                     
       /* attackRange          */      175.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      500.0,            
       /* pathRadius           */      30.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("sru_es_bannerwall_order"), 
  new UnitInfo(
  {
       /* name                 */      "sru_es_bannerwall_order",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      345.0,                     
       /* attackRange          */      175.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      500.0,            
       /* pathRadius           */      30.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("sru_gromp"), 
  new UnitInfo(
  {
       /* name                 */      "sru_gromp",                                           
       /* healthBarHeight      */      80.0,                   
       /* baseMoveSpeed        */      330.0,                     
       /* attackRange          */      250.0,                       
       /* attackSpeed          */      0.42500001192092896,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      155.0,            
       /* pathRadius           */      40.0,        
       /* gameplayRadius       */      120.0,
       
       /* basicAtkMissileSpeed */      1800.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Monster_Large).set(Unit_Monster).set(Unit_Monster_Camp).set(Unit_Monster_Gromp)
  })
},


{ std::string("sru_gromp_prop"), 
  new UnitInfo(
  {
       /* name                 */      "sru_gromp_prop",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      345.0,                     
       /* attackRange          */      175.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      100.0,            
       /* pathRadius           */      30.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("sru_krug"), 
  new UnitInfo(
  {
       /* name                 */      "sru_krug",                                           
       /* healthBarHeight      */      79.0,                   
       /* baseMoveSpeed        */      250.0,                     
       /* attackRange          */      150.0,                       
       /* attackSpeed          */      0.6129999756813049,                       
       /* attackSpeedRatio     */      0.6129999756813049,                  
                                                                            
       /* acquisitionRange     */      300.0,                  
       /* selectionRadius      */      100.0,            
       /* pathRadius           */      85.0,        
       /* gameplayRadius       */      100.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Monster_Krug).set(Unit_Monster_Large).set(Unit_Monster).set(Unit_Monster_Camp)
  })
},


{ std::string("sru_krugmini"), 
  new UnitInfo(
  {
       /* name                 */      "sru_krugmini",                                           
       /* healthBarHeight      */      61.0,                   
       /* baseMoveSpeed        */      350.0,                     
       /* attackRange          */      110.0,                       
       /* attackSpeed          */      0.6129999756813049,                       
       /* attackSpeedRatio     */      0.6129999756813049,                  
                                                                            
       /* acquisitionRange     */      300.0,                  
       /* selectionRadius      */      60.0,            
       /* pathRadius           */      50.0,        
       /* gameplayRadius       */      50.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Monster_Krug).set(Unit_Monster).set(Unit_Monster_Medium).set(Unit_Monster_Camp)
  })
},


{ std::string("sru_krugminimini"), 
  new UnitInfo(
  {
       /* name                 */      "sru_krugminimini",                                           
       /* healthBarHeight      */      30.0,                   
       /* baseMoveSpeed        */      400.0,                     
       /* attackRange          */      110.0,                       
       /* attackSpeed          */      0.6129999756813049,                       
       /* attackSpeedRatio     */      0.6129999756813049,                  
                                                                            
       /* acquisitionRange     */      300.0,                  
       /* selectionRadius      */      50.0,            
       /* pathRadius           */      30.0,        
       /* gameplayRadius       */      25.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Monster_Krug).set(Unit_Monster).set(Unit_Monster_Camp)
  })
},


{ std::string("sru_lizard"), 
  new UnitInfo(
  {
       /* name                 */      "sru_lizard",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      345.0,                     
       /* attackRange          */      175.0,                       
       /* attackSpeed          */      0.6579999923706055,                       
       /* attackSpeedRatio     */      0.6579999923706055,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      100.0,            
       /* pathRadius           */      30.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("sru_murkwolf"), 
  new UnitInfo(
  {
       /* name                 */      "sru_murkwolf",                                           
       /* healthBarHeight      */      65.0,                   
       /* baseMoveSpeed        */      525.0,                     
       /* attackRange          */      175.0,                       
       /* attackSpeed          */      0.625,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      100.0,            
       /* pathRadius           */      40.0,        
       /* gameplayRadius       */      80.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Monster_Wolf).set(Unit_Monster_Large).set(Unit_Monster).set(Unit_Monster_Camp)
  })
},


{ std::string("sru_murkwolfmini"), 
  new UnitInfo(
  {
       /* name                 */      "sru_murkwolfmini",                                           
       /* healthBarHeight      */      48.0,                   
       /* baseMoveSpeed        */      525.0,                     
       /* attackRange          */      175.0,                       
       /* attackSpeed          */      0.625,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      80.0,            
       /* pathRadius           */      31.52079963684082,        
       /* gameplayRadius       */      50.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Monster_Wolf).set(Unit_Monster).set(Unit_Monster_Camp)
  })
},


{ std::string("sru_orderminionmelee"), 
  new UnitInfo(
  {
       /* name                 */      "sru_orderminionmelee",                                           
       /* healthBarHeight      */      47.0,                   
       /* baseMoveSpeed        */      325.0,                     
       /* attackRange          */      110.0,                       
       /* attackSpeed          */      1.25,                       
       /* attackSpeedRatio     */      1.25,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      115.0,            
       /* pathRadius           */      35.74369812011719,        
       /* gameplayRadius       */      48.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Minion).set(Unit_Minion_Lane).set(Unit_Minion_Lane_Melee)
  })
},


{ std::string("sru_orderminionranged"), 
  new UnitInfo(
  {
       /* name                 */      "sru_orderminionranged",                                           
       /* healthBarHeight      */      48.0,                   
       /* baseMoveSpeed        */      325.0,                     
       /* attackRange          */      550.0,                       
       /* attackSpeed          */      0.6669999957084656,                       
       /* attackSpeedRatio     */      0.6669999957084656,                  
                                                                            
       /* acquisitionRange     */      700.0,                  
       /* selectionRadius      */      115.0,            
       /* pathRadius           */      35.74369812011719,        
       /* gameplayRadius       */      48.0,
       
       /* basicAtkMissileSpeed */      650.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Minion).set(Unit_Minion_Lane).set(Unit_Minion_Lane_Ranged)
  })
},


{ std::string("sru_orderminionsiege"), 
  new UnitInfo(
  {
       /* name                 */      "sru_orderminionsiege",                                           
       /* healthBarHeight      */      55.0,                   
       /* baseMoveSpeed        */      325.0,                     
       /* attackRange          */      300.0,                       
       /* attackSpeed          */      1.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      140.0,            
       /* pathRadius           */      55.74369812011719,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      1200.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Minion).set(Unit_Minion_Lane).set(Unit_Minion_Lane_Siege)
  })
},


{ std::string("sru_orderminionsuper"), 
  new UnitInfo(
  {
       /* name                 */      "sru_orderminionsuper",                                           
       /* healthBarHeight      */      74.0,                   
       /* baseMoveSpeed        */      325.0,                     
       /* attackRange          */      170.0,                       
       /* attackSpeed          */      0.8500000238418579,                       
       /* attackSpeedRatio     */      0.8500000238418579,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      145.0,            
       /* pathRadius           */      55.52080154418945,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Minion_Lane_Super).set(Unit_Minion).set(Unit_Minion_Lane)
  })
},


{ std::string("sru_plantrespawnmarker"), 
  new UnitInfo(
  {
       /* name                 */      "sru_plantrespawnmarker",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      0.0,            
       /* pathRadius           */      0.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Special)
  })
},


{ std::string("sru_plant_health"), 
  new UnitInfo(
  {
       /* name                 */      "sru_plant_health",                                           
       /* healthBarHeight      */      62.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      60.0,            
       /* pathRadius           */      20.0,        
       /* gameplayRadius       */      80.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Plant).set(Unit_Special_UntargetableBySpells).set(Unit_Ward)
  })
},


{ std::string("sru_plant_satchel"), 
  new UnitInfo(
  {
       /* name                 */      "sru_plant_satchel",                                           
       /* healthBarHeight      */      42.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      60.0,            
       /* pathRadius           */      20.0,        
       /* gameplayRadius       */      80.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Plant).set(Unit_Special_UntargetableBySpells).set(Unit_Ward)
  })
},


{ std::string("sru_plant_vision"), 
  new UnitInfo(
  {
       /* name                 */      "sru_plant_vision",                                           
       /* healthBarHeight      */      77.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      150.0,            
       /* pathRadius           */      20.0,        
       /* gameplayRadius       */      80.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Plant).set(Unit_Special_UntargetableBySpells).set(Unit_Ward)
  })
},


{ std::string("sru_porosprite"), 
  new UnitInfo(
  {
       /* name                 */      "sru_porosprite",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      345.0,                     
       /* attackRange          */      175.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      100.0,            
       /* pathRadius           */      30.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("sru_porowl"), 
  new UnitInfo(
  {
       /* name                 */      "sru_porowl",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      345.0,                     
       /* attackRange          */      175.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      100.0,            
       /* pathRadius           */      30.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("sru_razorbeak"), 
  new UnitInfo(
  {
       /* name                 */      "sru_razorbeak",                                           
       /* healthBarHeight      */      67.0,                   
       /* baseMoveSpeed        */      450.0,                     
       /* attackRange          */      300.0,                       
       /* attackSpeed          */      0.6669999957084656,                       
       /* attackSpeedRatio     */      0.6669999957084656,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      70.0,            
       /* pathRadius           */      30.0,        
       /* gameplayRadius       */      75.0,
       
       /* basicAtkMissileSpeed */      750.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Monster_Large).set(Unit_Monster).set(Unit_Monster_Camp).set(Unit_Monster_Raptor)
  })
},


{ std::string("sru_razorbeakmini"), 
  new UnitInfo(
  {
       /* name                 */      "sru_razorbeakmini",                                           
       /* healthBarHeight      */      38.0,                   
       /* baseMoveSpeed        */      525.0,                     
       /* attackRange          */      125.0,                       
       /* attackSpeed          */      1.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      80.0,            
       /* pathRadius           */      22.5,        
       /* gameplayRadius       */      50.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Monster).set(Unit_Monster_Camp).set(Unit_Monster_Raptor)
  })
},


{ std::string("sru_red"), 
  new UnitInfo(
  {
       /* name                 */      "sru_red",                                           
       /* healthBarHeight      */      90.0,                   
       /* baseMoveSpeed        */      275.0,                     
       /* attackRange          */      200.0,                       
       /* attackSpeed          */      0.49300000071525574,                       
       /* attackSpeedRatio     */      0.49300000071525574,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      145.0,            
       /* pathRadius           */      60.0,        
       /* gameplayRadius       */      120.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Monster_Buff).set(Unit_Monster).set(Unit_Monster_Red).set(Unit_Monster_Camp).set(Unit_Monster_Large)
  })
},


{ std::string("sru_redmini"), 
  new UnitInfo(
  {
       /* name                 */      "sru_redmini",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      330.0,                     
       /* attackRange          */      450.0,                       
       /* attackSpeed          */      0.625,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      80.0,            
       /* pathRadius           */      30.0,        
       /* gameplayRadius       */      40.0,
       
       /* basicAtkMissileSpeed */      750.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Monster).set(Unit_Monster_Red).set(Unit_Monster_Camp)
  })
},


{ std::string("sru_riftherald"), 
  new UnitInfo(
  {
       /* name                 */      "sru_riftherald",                                           
       /* healthBarHeight      */      170.0,                   
       /* baseMoveSpeed        */      325.0,                     
       /* attackRange          */      250.0,                       
       /* attackSpeed          */      0.4000000059604645,                       
       /* attackSpeedRatio     */      0.5,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      120.0,            
       /* pathRadius           */      110.0,        
       /* gameplayRadius       */      110.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Monster_Epic).set(Unit_Monster).set(Unit_Special_Void).set(Unit_Monster_Camp)
  })
},


{ std::string("sru_riftherald_mercenary"), 
  new UnitInfo(
  {
       /* name                 */      "sru_riftherald_mercenary",                                           
       /* healthBarHeight      */      147.0,                   
       /* baseMoveSpeed        */      325.0,                     
       /* attackRange          */      250.0,                       
       /* attackSpeed          */      0.5,                       
       /* attackSpeedRatio     */      0.5,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      120.0,            
       /* pathRadius           */      110.0,        
       /* gameplayRadius       */      110.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Monster_Epic).set(Unit_Monster).set(Unit_Special_Void).set(Unit_Monster_Large)
  })
},


{ std::string("sru_riftherald_relic"), 
  new UnitInfo(
  {
       /* name                 */      "sru_riftherald_relic",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      350.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      1.0,            
       /* pathRadius           */      1.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("sru_snail"), 
  new UnitInfo(
  {
       /* name                 */      "sru_snail",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      115.0,            
       /* pathRadius           */      31.52079963684082,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("sru_snowdown_gingerbread"), 
  new UnitInfo(
  {
       /* name                 */      "sru_snowdown_gingerbread",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      0.0,            
       /* pathRadius           */      0.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("sru_spiritwolf"), 
  new UnitInfo(
  {
       /* name                 */      "sru_spiritwolf",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      500.0,                     
       /* attackRange          */      175.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      80.0,            
       /* pathRadius           */      31.52079963684082,        
       /* gameplayRadius       */      50.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("sru_stag"), 
  new UnitInfo(
  {
       /* name                 */      "sru_stag",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      345.0,                     
       /* attackRange          */      175.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      100.0,            
       /* pathRadius           */      30.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("sru_storekeepernorth"), 
  new UnitInfo(
  {
       /* name                 */      "sru_storekeepernorth",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      0.0,            
       /* pathRadius           */      0.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("sru_storekeepersouth"), 
  new UnitInfo(
  {
       /* name                 */      "sru_storekeepersouth",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      0.0,            
       /* pathRadius           */      0.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("swain"), 
  new UnitInfo(
  {
       /* name                 */      "swain",                                           
       /* healthBarHeight      */      105.0,                   
       /* baseMoveSpeed        */      325.0,                     
       /* attackRange          */      525.0,                       
       /* attackSpeed          */      0.625,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      525.0,                  
       /* selectionRadius      */      100.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      1800.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("swaindemonform"), 
  new UnitInfo(
  {
       /* name                 */      "swaindemonform",                                           
       /* healthBarHeight      */      120.0,                   
       /* baseMoveSpeed        */      335.0,                     
       /* attackRange          */      500.0,                       
       /* attackSpeed          */      0.625,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      500.0,                  
       /* selectionRadius      */      100.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("sylas"), 
  new UnitInfo(
  {
       /* name                 */      "sylas",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      340.0,                     
       /* attackRange          */      175.0,                       
       /* attackSpeed          */      0.6449999809265137,                       
       /* attackSpeedRatio     */      0.6449999809265137,                  
                                                                            
       /* acquisitionRange     */      525.0,                  
       /* selectionRadius      */      100.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      1750.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("syndra"), 
  new UnitInfo(
  {
       /* name                 */      "syndra",                                           
       /* healthBarHeight      */      130.0,                   
       /* baseMoveSpeed        */      330.0,                     
       /* attackRange          */      550.0,                       
       /* attackSpeed          */      0.625,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      575.0,                  
       /* selectionRadius      */      125.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      1800.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("syndraorbs"), 
  new UnitInfo(
  {
       /* name                 */      "syndraorbs",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      310.0,                     
       /* attackRange          */      550.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      575.0,                  
       /* selectionRadius      */      130.0,            
       /* pathRadius           */      0.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("syndrasphere"), 
  new UnitInfo(
  {
       /* name                 */      "syndrasphere",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      475.0,                     
       /* attackRange          */      20.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      110.0,            
       /* pathRadius           */      0.0,        
       /* gameplayRadius       */      48.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Special_SyndraSphere).set(Unit_Special)
  })
},


{ std::string("tahmkench"), 
  new UnitInfo(
  {
       /* name                 */      "tahmkench",                                           
       /* healthBarHeight      */      105.0,                   
       /* baseMoveSpeed        */      335.0,                     
       /* attackRange          */      175.0,                       
       /* attackSpeed          */      0.6579999923706055,                       
       /* attackSpeedRatio     */      0.6579999923706055,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      125.0,            
       /* pathRadius           */      50.0,        
       /* gameplayRadius       */      80.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("taliyah"), 
  new UnitInfo(
  {
       /* name                 */      "taliyah",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      335.0,                     
       /* attackRange          */      525.0,                       
       /* attackSpeed          */      0.625,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      550.0,                  
       /* selectionRadius      */      120.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      2100.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("taliyahwallchunk"), 
  new UnitInfo(
  {
       /* name                 */      "taliyahwallchunk",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      1.0,            
       /* pathRadius           */      150.0,        
       /* gameplayRadius       */      150.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("talon"), 
  new UnitInfo(
  {
       /* name                 */      "talon",                                           
       /* healthBarHeight      */      95.0,                   
       /* baseMoveSpeed        */      335.0,                     
       /* attackRange          */      125.0,                       
       /* attackSpeed          */      0.625,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      400.0,                  
       /* selectionRadius      */      120.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("taric"), 
  new UnitInfo(
  {
       /* name                 */      "taric",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      340.0,                     
       /* attackRange          */      150.0,                       
       /* attackSpeed          */      0.625,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      350.0,                  
       /* selectionRadius      */      135.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("teemo"), 
  new UnitInfo(
  {
       /* name                 */      "teemo",                                           
       /* healthBarHeight      */      75.0,                   
       /* baseMoveSpeed        */      330.0,                     
       /* attackRange          */      500.0,                       
       /* attackSpeed          */      0.6899999976158142,                       
       /* attackSpeedRatio     */      0.6899999976158142,                  
                                                                            
       /* acquisitionRange     */      500.0,                  
       /* selectionRadius      */      100.0,            
       /* pathRadius           */      30.0,        
       /* gameplayRadius       */      55.0,
       
       /* basicAtkMissileSpeed */      1300.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("teemomushroom"), 
  new UnitInfo(
  {
       /* name                 */      "teemomushroom",                                           
       /* healthBarHeight      */      31.5,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      0.0,            
       /* pathRadius           */      31.793100357055664,        
       /* gameplayRadius       */      125.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Special_UntargetableBySpells).set(Unit_Special_TurretIgnores).set(Unit_Special_TeleportTarget).set(Unit_Special_Trap).set(Unit_IsolationNonImpacting).set(Unit_Special)
  })
},


{ std::string("testcube"), 
  new UnitInfo(
  {
       /* name                 */      "testcube",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      325.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      1.0,            
       /* pathRadius           */      1.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("testcuberender"), 
  new UnitInfo(
  {
       /* name                 */      "testcuberender",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      350.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      1.0,            
       /* pathRadius           */      1.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("testcuberender10vision"), 
  new UnitInfo(
  {
       /* name                 */      "testcuberender10vision",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      350.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      1.0,            
       /* pathRadius           */      1.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("testcuberenderwcollision"), 
  new UnitInfo(
  {
       /* name                 */      "testcuberenderwcollision",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      350.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      1.0,            
       /* pathRadius           */      80.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("tftchampion"), 
  new UnitInfo(
  {
       /* name                 */      "tftchampion",                                           
       /* healthBarHeight      */      65.0,                   
       /* baseMoveSpeed        */      375.0,                     
       /* attackRange          */      1.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      0.0,            
       /* pathRadius           */      0.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("thresh"), 
  new UnitInfo(
  {
       /* name                 */      "thresh",                                           
       /* healthBarHeight      */      105.0,                   
       /* baseMoveSpeed        */      335.0,                     
       /* attackRange          */      450.0,                       
       /* attackSpeed          */      0.625,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      475.0,                  
       /* selectionRadius      */      125.0,            
       /* pathRadius           */      36.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      1000.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("threshlantern"), 
  new UnitInfo(
  {
       /* name                 */      "threshlantern",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      950.0,                  
       /* selectionRadius      */      60.0,            
       /* pathRadius           */      45.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Special_TeleportTarget).set(Unit_Special)
  })
},


{ std::string("tristana"), 
  new UnitInfo(
  {
       /* name                 */      "tristana",                                           
       /* healthBarHeight      */      80.0,                   
       /* baseMoveSpeed        */      325.0,                     
       /* attackRange          */      525.0,                       
       /* attackSpeed          */      0.656000018119812,                       
       /* attackSpeedRatio     */      0.6790000200271606,                  
                                                                            
       /* acquisitionRange     */      800.0,                  
       /* selectionRadius      */      100.0,            
       /* pathRadius           */      30.0,        
       /* gameplayRadius       */      55.0,
       
       /* basicAtkMissileSpeed */      2250.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("trundle"), 
  new UnitInfo(
  {
       /* name                 */      "trundle",                                           
       /* healthBarHeight      */      110.0,                   
       /* baseMoveSpeed        */      350.0,                     
       /* attackRange          */      175.0,                       
       /* attackSpeed          */      0.6700000166893005,                       
       /* attackSpeedRatio     */      0.6700000166893005,                  
                                                                            
       /* acquisitionRange     */      400.0,                  
       /* selectionRadius      */      135.0,            
       /* pathRadius           */      25.766599655151367,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      347.79998779296875,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("trundlewall"), 
  new UnitInfo(
  {
       /* name                 */      "trundlewall",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      350.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      130.0,            
       /* pathRadius           */      150.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("tryndamere"), 
  new UnitInfo(
  {
       /* name                 */      "tryndamere",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      345.0,                     
       /* attackRange          */      125.0,                       
       /* attackSpeed          */      0.6700000166893005,                       
       /* attackSpeedRatio     */      0.6700000166893005,                  
                                                                            
       /* acquisitionRange     */      400.0,                  
       /* selectionRadius      */      135.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      347.79998779296875,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("tt_dummypusher"), 
  new UnitInfo(
  {
       /* name                 */      "tt_dummypusher",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      325.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      1.0,            
       /* pathRadius           */      1.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("tutorial_portal"), 
  new UnitInfo(
  {
       /* name                 */      "tutorial_portal",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      90.0,            
       /* pathRadius           */      5.0,        
       /* gameplayRadius       */      1.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("tutorial_statue_darius"), 
  new UnitInfo(
  {
       /* name                 */      "tutorial_statue_darius",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      100.0,            
       /* pathRadius           */      5.0,        
       /* gameplayRadius       */      1.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("tutorial_statue_lux"), 
  new UnitInfo(
  {
       /* name                 */      "tutorial_statue_lux",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      100.0,            
       /* pathRadius           */      5.0,        
       /* gameplayRadius       */      1.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("tutorial_statue_masteryi"), 
  new UnitInfo(
  {
       /* name                 */      "tutorial_statue_masteryi",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      100.0,            
       /* pathRadius           */      5.0,        
       /* gameplayRadius       */      1.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("tutorial_statue_missfortune"), 
  new UnitInfo(
  {
       /* name                 */      "tutorial_statue_missfortune",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      100.0,            
       /* pathRadius           */      5.0,        
       /* gameplayRadius       */      1.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("tutorial_statue_zed"), 
  new UnitInfo(
  {
       /* name                 */      "tutorial_statue_zed",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      100.0,            
       /* pathRadius           */      5.0,        
       /* gameplayRadius       */      1.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("twistedfate"), 
  new UnitInfo(
  {
       /* name                 */      "twistedfate",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      330.0,                     
       /* attackRange          */      525.0,                       
       /* attackSpeed          */      0.6510000228881836,                       
       /* attackSpeedRatio     */      0.6510000228881836,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      110.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      1500.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("twitch"), 
  new UnitInfo(
  {
       /* name                 */      "twitch",                                           
       /* healthBarHeight      */      85.0,                   
       /* baseMoveSpeed        */      330.0,                     
       /* attackRange          */      550.0,                       
       /* attackSpeed          */      0.6790000200271606,                       
       /* attackSpeedRatio     */      0.6790000200271606,                  
                                                                            
       /* acquisitionRange     */      575.0,                  
       /* selectionRadius      */      135.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      2500.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("udyr"), 
  new UnitInfo(
  {
       /* name                 */      "udyr",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      350.0,                     
       /* attackRange          */      125.0,                       
       /* attackSpeed          */      0.6579999923706055,                       
       /* attackSpeedRatio     */      0.6579999923706055,                  
                                                                            
       /* acquisitionRange     */      400.0,                  
       /* selectionRadius      */      125.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      467.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("udyrphoenix"), 
  new UnitInfo(
  {
       /* name                 */      "udyrphoenix",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      350.0,                     
       /* attackRange          */      125.0,                       
       /* attackSpeed          */      0.6579999923706055,                       
       /* attackSpeedRatio     */      0.6579999923706055,                  
                                                                            
       /* acquisitionRange     */      400.0,                  
       /* selectionRadius      */      125.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("udyrphoenixult"), 
  new UnitInfo(
  {
       /* name                 */      "udyrphoenixult",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      350.0,                     
       /* attackRange          */      125.0,                       
       /* attackSpeed          */      0.6579999923706055,                       
       /* attackSpeedRatio     */      0.6579999923706055,                  
                                                                            
       /* acquisitionRange     */      400.0,                  
       /* selectionRadius      */      125.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("udyrtiger"), 
  new UnitInfo(
  {
       /* name                 */      "udyrtiger",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      350.0,                     
       /* attackRange          */      125.0,                       
       /* attackSpeed          */      0.6579999923706055,                       
       /* attackSpeedRatio     */      0.6579999923706055,                  
                                                                            
       /* acquisitionRange     */      400.0,                  
       /* selectionRadius      */      125.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("udyrtigerult"), 
  new UnitInfo(
  {
       /* name                 */      "udyrtigerult",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      350.0,                     
       /* attackRange          */      125.0,                       
       /* attackSpeed          */      0.6579999923706055,                       
       /* attackSpeedRatio     */      0.6579999923706055,                  
                                                                            
       /* acquisitionRange     */      400.0,                  
       /* selectionRadius      */      125.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("udyrturtle"), 
  new UnitInfo(
  {
       /* name                 */      "udyrturtle",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      350.0,                     
       /* attackRange          */      125.0,                       
       /* attackSpeed          */      0.6579999923706055,                       
       /* attackSpeedRatio     */      0.6579999923706055,                  
                                                                            
       /* acquisitionRange     */      400.0,                  
       /* selectionRadius      */      125.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("udyrturtleult"), 
  new UnitInfo(
  {
       /* name                 */      "udyrturtleult",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      350.0,                     
       /* attackRange          */      125.0,                       
       /* attackSpeed          */      0.6579999923706055,                       
       /* attackSpeedRatio     */      0.6579999923706055,                  
                                                                            
       /* acquisitionRange     */      400.0,                  
       /* selectionRadius      */      125.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("udyrult"), 
  new UnitInfo(
  {
       /* name                 */      "udyrult",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      350.0,                     
       /* attackRange          */      125.0,                       
       /* attackSpeed          */      0.6579999923706055,                       
       /* attackSpeedRatio     */      0.6579999923706055,                  
                                                                            
       /* acquisitionRange     */      400.0,                  
       /* selectionRadius      */      125.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("urf_feeneypult"), 
  new UnitInfo(
  {
       /* name                 */      "urf_feeneypult",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      750.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      130.0,            
       /* pathRadius           */      125.0,        
       /* gameplayRadius       */      88.4000015258789,
       
       /* basicAtkMissileSpeed */      1200.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Structure).set(Unit_Structure_Turret).set(Unit_Structure_Turret_Outer)
  })
},


{ std::string("urgot"), 
  new UnitInfo(
  {
       /* name                 */      "urgot",                                           
       /* healthBarHeight      */      110.0,                   
       /* baseMoveSpeed        */      330.0,                     
       /* attackRange          */      350.0,                       
       /* attackSpeed          */      0.625,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      550.0,                  
       /* selectionRadius      */      136.11109924316406,            
       /* pathRadius           */      50.0,        
       /* gameplayRadius       */      80.0,
       
       /* basicAtkMissileSpeed */      2500.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("varus"), 
  new UnitInfo(
  {
       /* name                 */      "varus",                                           
       /* healthBarHeight      */      95.0,                   
       /* baseMoveSpeed        */      330.0,                     
       /* attackRange          */      575.0,                       
       /* attackSpeed          */      0.6579999923706055,                       
       /* attackSpeedRatio     */      0.6579999923706055,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      120.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      2000.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("vayne"), 
  new UnitInfo(
  {
       /* name                 */      "vayne",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      330.0,                     
       /* attackRange          */      550.0,                       
       /* attackSpeed          */      0.6579999923706055,                       
       /* attackSpeedRatio     */      0.6579999923706055,                  
                                                                            
       /* acquisitionRange     */      575.0,                  
       /* selectionRadius      */      120.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      2000.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("veigar"), 
  new UnitInfo(
  {
       /* name                 */      "veigar",                                           
       /* healthBarHeight      */      90.0,                   
       /* baseMoveSpeed        */      340.0,                     
       /* attackRange          */      550.0,                       
       /* attackSpeed          */      0.625,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      525.0,                  
       /* selectionRadius      */      93.0,            
       /* pathRadius           */      30.0,        
       /* gameplayRadius       */      55.0,
       
       /* basicAtkMissileSpeed */      1100.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("velkoz"), 
  new UnitInfo(
  {
       /* name                 */      "velkoz",                                           
       /* healthBarHeight      */      125.0,                   
       /* baseMoveSpeed        */      340.0,                     
       /* attackRange          */      525.0,                       
       /* attackSpeed          */      0.625,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      575.0,                  
       /* selectionRadius      */      88.88890075683594,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      8000.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion).set(Unit_Special_Void)
  })
},


{ std::string("vi"), 
  new UnitInfo(
  {
       /* name                 */      "vi",                                           
       /* healthBarHeight      */      110.0,                   
       /* baseMoveSpeed        */      340.0,                     
       /* attackRange          */      125.0,                       
       /* attackSpeed          */      0.6439999938011169,                       
       /* attackSpeedRatio     */      0.6439999938011169,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      100.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      1000.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("viktor"), 
  new UnitInfo(
  {
       /* name                 */      "viktor",                                           
       /* healthBarHeight      */      115.0,                   
       /* baseMoveSpeed        */      335.0,                     
       /* attackRange          */      525.0,                       
       /* attackSpeed          */      0.6579999923706055,                       
       /* attackSpeedRatio     */      0.6579999923706055,                  
                                                                            
       /* acquisitionRange     */      525.0,                  
       /* selectionRadius      */      160.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      2300.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("viktorsingularity"), 
  new UnitInfo(
  {
       /* name                 */      "viktorsingularity",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      150.0,                     
       /* attackRange          */      20.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      110.0,            
       /* pathRadius           */      38.08000183105469,        
       /* gameplayRadius       */      48.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("visionward"), 
  new UnitInfo(
  {
       /* name                 */      "visionward",                                           
       /* healthBarHeight      */      180.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      0.0,            
       /* pathRadius           */      5.0,        
       /* gameplayRadius       */      1.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Special_TurretIgnores).set(Unit_Special_UntargetableBySpells).set(Unit_Ward).set(Unit_Special)
  })
},


{ std::string("vladimir"), 
  new UnitInfo(
  {
       /* name                 */      "vladimir",                                           
       /* healthBarHeight      */      95.0,                   
       /* baseMoveSpeed        */      330.0,                     
       /* attackRange          */      450.0,                       
       /* attackSpeed          */      0.6579999923706055,                       
       /* attackSpeedRatio     */      0.6579999923706055,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      120.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      1600.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("voidgate"), 
  new UnitInfo(
  {
       /* name                 */      "voidgate",                                           
       /* healthBarHeight      */      70.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      105.0,            
       /* pathRadius           */      80.0,        
       /* gameplayRadius       */      90.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_IsolationNonImpacting).set(Unit_Structure).set(Unit_Special_Void)
  })
},


{ std::string("voidspawn"), 
  new UnitInfo(
  {
       /* name                 */      "voidspawn",                                           
       /* healthBarHeight      */      45.0,                   
       /* baseMoveSpeed        */      400.0,                     
       /* attackRange          */      225.0,                       
       /* attackSpeed          */      0.6940000057220459,                       
       /* attackSpeedRatio     */      0.6940000057220459,                  
                                                                            
       /* acquisitionRange     */      800.0,                  
       /* selectionRadius      */      70.0,            
       /* pathRadius           */      20.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Special_MonsterIgnores).set(Unit_Minion).set(Unit_Minion_Summon).set(Unit_Special_EpicMonsterIgnores).set(Unit_Special_Void)
  })
},


{ std::string("voidspawntracer"), 
  new UnitInfo(
  {
       /* name                 */      "voidspawntracer",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      2200.0,                     
       /* attackRange          */      125.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      800.0,                  
       /* selectionRadius      */      70.0,            
       /* pathRadius           */      20.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("volibear"), 
  new UnitInfo(
  {
       /* name                 */      "volibear",                                           
       /* healthBarHeight      */      124.0,                   
       /* baseMoveSpeed        */      340.0,                     
       /* attackRange          */      150.0,                       
       /* attackSpeed          */      0.625,                       
       /* attackSpeedRatio     */      0.699999988079071,                  
                                                                            
       /* acquisitionRange     */      400.0,                  
       /* selectionRadius      */      125.0,            
       /* pathRadius           */      50.0,        
       /* gameplayRadius       */      80.0,
       
       /* basicAtkMissileSpeed */      467.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("warwick"), 
  new UnitInfo(
  {
       /* name                 */      "warwick",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      335.0,                     
       /* attackRange          */      125.0,                       
       /* attackSpeed          */      0.6380000114440918,                       
       /* attackSpeedRatio     */      0.6380000114440918,                  
                                                                            
       /* acquisitionRange     */      400.0,                  
       /* selectionRadius      */      111.11109924316406,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      55.0,
       
       /* basicAtkMissileSpeed */      347.79998779296875,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("xayah"), 
  new UnitInfo(
  {
       /* name                 */      "xayah",                                           
       /* healthBarHeight      */      105.0,                   
       /* baseMoveSpeed        */      325.0,                     
       /* attackRange          */      525.0,                       
       /* attackSpeed          */      0.625,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      800.0,                  
       /* selectionRadius      */      120.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      2500.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("xerath"), 
  new UnitInfo(
  {
       /* name                 */      "xerath",                                           
       /* healthBarHeight      */      120.0,                   
       /* baseMoveSpeed        */      340.0,                     
       /* attackRange          */      525.0,                       
       /* attackSpeed          */      0.625,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      88.88890075683594,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      2000.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("xinzhao"), 
  new UnitInfo(
  {
       /* name                 */      "xinzhao",                                           
       /* healthBarHeight      */      92.0,                   
       /* baseMoveSpeed        */      345.0,                     
       /* attackRange          */      175.0,                       
       /* attackSpeed          */      0.6449999809265137,                       
       /* attackSpeedRatio     */      0.6449999809265137,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      108.33329772949219,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      20.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("yasuo"), 
  new UnitInfo(
  {
       /* name                 */      "yasuo",                                           
       /* healthBarHeight      */      103.0,                   
       /* baseMoveSpeed        */      345.0,                     
       /* attackRange          */      175.0,                       
       /* attackSpeed          */      0.6970000267028809,                       
       /* attackSpeedRatio     */      0.6700000166893005,                  
                                                                            
       /* acquisitionRange     */      400.0,                  
       /* selectionRadius      */      75.0,            
       /* pathRadius           */      32.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      347.79998779296875,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("yellowtrinket"), 
  new UnitInfo(
  {
       /* name                 */      "yellowtrinket",                                           
       /* healthBarHeight      */      180.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      0.0,            
       /* pathRadius           */      5.0,        
       /* gameplayRadius       */      1.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Special_TurretIgnores).set(Unit_Ward).set(Unit_Special)
  })
},


{ std::string("yellowtrinketupgrade"), 
  new UnitInfo(
  {
       /* name                 */      "yellowtrinketupgrade",                                           
       /* healthBarHeight      */      180.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      0.0,            
       /* pathRadius           */      5.0,        
       /* gameplayRadius       */      1.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Special_TurretIgnores).set(Unit_Ward).set(Unit_Special)
  })
},


{ std::string("yone"), 
  new UnitInfo(
  {
       /* name                 */      "yone",                                           
       /* healthBarHeight      */      103.0,                   
       /* baseMoveSpeed        */      345.0,                     
       /* attackRange          */      175.0,                       
       /* attackSpeed          */      0.625,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      400.0,                  
       /* selectionRadius      */      75.0,            
       /* pathRadius           */      32.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      347.79998779296875,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("yorick"), 
  new UnitInfo(
  {
       /* name                 */      "yorick",                                           
       /* healthBarHeight      */      110.0,                   
       /* baseMoveSpeed        */      340.0,                     
       /* attackRange          */      175.0,                       
       /* attackSpeed          */      0.625,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      400.0,                  
       /* selectionRadius      */      125.0,            
       /* pathRadius           */      50.0,        
       /* gameplayRadius       */      80.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("yorickbigghoul"), 
  new UnitInfo(
  {
       /* name                 */      "yorickbigghoul",                                           
       /* healthBarHeight      */      80.0,                   
       /* baseMoveSpeed        */      300.0,                     
       /* attackRange          */      600.0,                       
       /* attackSpeed          */      1.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      700.0,                  
       /* selectionRadius      */      90.0,            
       /* pathRadius           */      40.0,        
       /* gameplayRadius       */      20.0,
       
       /* basicAtkMissileSpeed */      1200.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Minion).set(Unit_Minion_Summon).set(Unit_Minion_Summon_Large)
  })
},


{ std::string("yorickghoulmelee"), 
  new UnitInfo(
  {
       /* name                 */      "yorickghoulmelee",                                           
       /* healthBarHeight      */      30.0,                   
       /* baseMoveSpeed        */      300.0,                     
       /* attackRange          */      125.0,                       
       /* attackSpeed          */      0.5,                       
       /* attackSpeedRatio     */      0.5,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      70.0,            
       /* pathRadius           */      20.0,        
       /* gameplayRadius       */      1.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Minion).set(Unit_Minion_Summon)
  })
},


{ std::string("yorickwghoul"), 
  new UnitInfo(
  {
       /* name                 */      "yorickwghoul",                                           
       /* healthBarHeight      */      30.0,                   
       /* baseMoveSpeed        */      325.0,                     
       /* attackRange          */      250.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      90.0,            
       /* pathRadius           */      80.0,        
       /* gameplayRadius       */      20.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("yorickwinvisible"), 
  new UnitInfo(
  {
       /* name                 */      "yorickwinvisible",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      350.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      90.0,            
       /* pathRadius           */      80.0,        
       /* gameplayRadius       */      20.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Special_UntargetableBySpells).set(Unit_Special_YorickW).set(Unit_IsolationNonImpacting)
  })
},


{ std::string("yuumi"), 
  new UnitInfo(
  {
       /* name                 */      "yuumi",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      330.0,                     
       /* attackRange          */      500.0,                       
       /* attackSpeed          */      0.625,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      550.0,                  
       /* selectionRadius      */      120.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      1500.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("zac"), 
  new UnitInfo(
  {
       /* name                 */      "zac",                                           
       /* healthBarHeight      */      113.0,                   
       /* baseMoveSpeed        */      340.0,                     
       /* attackRange          */      175.0,                       
       /* attackSpeed          */      0.7360000014305115,                       
       /* attackSpeedRatio     */      0.6380000114440918,                  
                                                                            
       /* acquisitionRange     */      400.0,                  
       /* selectionRadius      */      90.0,            
       /* pathRadius           */      43.07490158081055,        
       /* gameplayRadius       */      80.0,
       
       /* basicAtkMissileSpeed */      1000.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("zacrebirthbloblet"), 
  new UnitInfo(
  {
       /* name                 */      "zacrebirthbloblet",                                           
       /* healthBarHeight      */      30.0,                   
       /* baseMoveSpeed        */      290.0,                     
       /* attackRange          */      600.0,                       
       /* attackSpeed          */      0.625,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      130.0,            
       /* pathRadius           */      54.400001525878906,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Minion).set(Unit_Minion_Summon)
  })
},


{ std::string("zed"), 
  new UnitInfo(
  {
       /* name                 */      "zed",                                           
       /* healthBarHeight      */      95.0,                   
       /* baseMoveSpeed        */      345.0,                     
       /* attackRange          */      125.0,                       
       /* attackSpeed          */      0.6510000228881836,                       
       /* attackSpeedRatio     */      0.6510000228881836,                  
                                                                            
       /* acquisitionRange     */      400.0,                  
       /* selectionRadius      */      100.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      467.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("zedshadow"), 
  new UnitInfo(
  {
       /* name                 */      "zedshadow",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      325.0,                     
       /* attackRange          */      125.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      400.0,                  
       /* selectionRadius      */      100.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("ziggs"), 
  new UnitInfo(
  {
       /* name                 */      "ziggs",                                           
       /* healthBarHeight      */      78.0,                   
       /* baseMoveSpeed        */      325.0,                     
       /* attackRange          */      550.0,                       
       /* attackSpeed          */      0.656000018119812,                       
       /* attackSpeedRatio     */      0.656000018119812,                  
                                                                            
       /* acquisitionRange     */      800.0,                  
       /* selectionRadius      */      100.0,            
       /* pathRadius           */      30.0,        
       /* gameplayRadius       */      55.0,
       
       /* basicAtkMissileSpeed */      1500.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("zilean"), 
  new UnitInfo(
  {
       /* name                 */      "zilean",                                           
       /* healthBarHeight      */      108.0,                   
       /* baseMoveSpeed        */      335.0,                     
       /* attackRange          */      550.0,                       
       /* attackSpeed          */      0.625,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      550.0,                  
       /* selectionRadius      */      135.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      1200.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("zoe"), 
  new UnitInfo(
  {
       /* name                 */      "zoe",                                           
       /* healthBarHeight      */      110.0,                   
       /* baseMoveSpeed        */      340.0,                     
       /* attackRange          */      550.0,                       
       /* attackSpeed          */      0.625,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      550.0,                  
       /* selectionRadius      */      120.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      1600.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("zoeorbs"), 
  new UnitInfo(
  {
       /* name                 */      "zoeorbs",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      310.0,                     
       /* attackRange          */      0.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      0.0,                  
       /* selectionRadius      */      130.0,            
       /* pathRadius           */      0.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_)
  })
},


{ std::string("zyra"), 
  new UnitInfo(
  {
       /* name                 */      "zyra",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      340.0,                     
       /* attackRange          */      575.0,                       
       /* attackSpeed          */      0.625,                       
       /* attackSpeedRatio     */      0.625,                  
                                                                            
       /* acquisitionRange     */      575.0,                  
       /* selectionRadius      */      120.0,            
       /* pathRadius           */      35.0,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      1700.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("zyragraspingplant"), 
  new UnitInfo(
  {
       /* name                 */      "zyragraspingplant",                                           
       /* healthBarHeight      */      240.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      175.0,                       
       /* attackSpeed          */      0.800000011920929,                       
       /* attackSpeedRatio     */      0.800000011920929,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      80.0,            
       /* pathRadius           */      8.5,        
       /* gameplayRadius       */      20.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Minion).set(Unit_Minion_Summon)
  })
},


{ std::string("zyrapassive"), 
  new UnitInfo(
  {
       /* name                 */      "zyrapassive",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      600.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      80.0,            
       /* pathRadius           */      8.5,        
       /* gameplayRadius       */      20.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Champion)
  })
},


{ std::string("zyraseed"), 
  new UnitInfo(
  {
       /* name                 */      "zyraseed",                                           
       /* healthBarHeight      */      0.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      600.0,                       
       /* attackSpeed          */      0.0,                       
       /* attackSpeedRatio     */      0.0,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      40.0,            
       /* pathRadius           */      54.400001525878906,        
       /* gameplayRadius       */      65.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Minion).set(Unit_Minion_SummonName_game_character_displayname_ZyraSeed)
  })
},


{ std::string("zyrathornplant"), 
  new UnitInfo(
  {
       /* name                 */      "zyrathornplant",                                           
       /* healthBarHeight      */      215.0,                   
       /* baseMoveSpeed        */      0.0,                     
       /* attackRange          */      600.0,                       
       /* attackSpeed          */      0.800000011920929,                       
       /* attackSpeedRatio     */      0.800000011920929,                  
                                                                            
       /* acquisitionRange     */      600.0,                  
       /* selectionRadius      */      80.0,            
       /* pathRadius           */      8.5,        
       /* gameplayRadius       */      20.0,
       
       /* basicAtkMissileSpeed */      0.0,
	   /* tags                 */      std::bitset<128>().set(Unit_Minion).set(Unit_Minion_Summon)
  })
},


};

