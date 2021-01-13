from lview import *
import math, itertools, time
from . import items

Version = "0.1"
MissileToSpell = {}
Spells         = {}
ChampionSpells = {}

class SFlag:
	Targeted        = 1
	Line            = 2
	Cone            = 4
	Area            = 8
	
	CollideWindwall = 16
	CollideChampion = 32
	CollideMob      = 64
	
	
	CollideGeneric   = CollideMob      | CollideChampion | CollideWindwall
	SkillshotLine    = CollideGeneric  | Line
	
class Spell:
	def __init__(self, name, missile_names, flags, delay = 0.0):
		global MissileToSpell, Spells
		
		self.flags = flags
		self.name = name
		self.missiles = missile_names
		self.delay = delay
		Spells[name] = self
		for missile in missile_names:
			MissileToSpell[missile] = self
			
	delay    = 0.0
	flags    = 0
	name     = "?"
	missiles = []
	
ChampionSpells = {
	"aatrox": [
		Spell("aatroxw",                ["aatroxw"],                               SFlag.CollideGeneric)
	],
	"aurelionsol": [
		Spell("aurelionsolq",           ["aurelionsolqmissile"],                   SFlag.SkillshotLine),
		Spell("aurelionsolr",           ["aurelionsolrbeammissile"],               SFlag.Line | SFlag.CollideWindwall)
	],
	"ahri": [                                                                      
		Spell("ahriorbofdeception",     ["ahriorbmissile"],                        SFlag.Line | SFlag.CollideWindwall),
		Spell("ahriseduce",             ["ahriseducemissile"],                     SFlag.CollideGeneric)
	],
	"ashe": [                           
		Spell("volleyattack",           ["volleyattack", "volleyattackwithsound"], SFlag.SkillshotLine),
		Spell("enchantedcrystalarrow",  ["enchantedcrystalarrow"],                 SFlag.Line | SFlag.CollideWindwall | SFlag.CollideChampion)
	],
	"chogath": [                        
		Spell("rupture",                [],                                        SFlag.Area, delay = 0.627),
		Spell("feralscream",            [],                                        SFlag.Cone | SFlag.CollideWindwall)
	],
	"ezreal": [                         
		Spell("ezrealq",                ["ezrealq"],                               SFlag.SkillshotLine),
		Spell("ezrealw",                ["ezrealw"],                               SFlag.SkillshotLine),
		Spell("ezrealr",                ["ezrealr"],                               SFlag.SkillshotLine)
	],
	"graves": [                         
		Spell("gravesqlinespell",       ["gravesqlinemis", "gravesqreturn"],       SFlag.Line | SFlag.CollideChampion | SFlag.CollideWindwall),
		Spell("gravessmokegrenade",     ["gravessmokegrenadeboom"],                SFlag.Area | SFlag.CollideWindwall),
		Spell("graveschargeshot",       ["graveschargeshotshot"],                  SFlag.Line | SFlag.CollideWindwall)
	],
	"twistedfate": [                    
		Spell("wildcards",              ["sealfatemissile"],                       SFlag.CollideWindwall | SFlag.Line)
	],
	"leesin": [                         
		Spell("blindmonkqone",          ["blindmonkqone"],                         SFlag.SkillshotLine)
	],
	"veigar": [                         
		Spell("veigarbalefulstrike",    ["veigarbalefulstrikemis"],                SFlag.SkillshotLine),
		Spell("veigardarkmatter",       [],                                        SFlag.Area, delay=1.0),
		Spell("veigareventhorizon",     [],                                        SFlag.Area, delay=0.5)
	], 
	"lux": [                            
		Spell("luxlightbinding",        ["luxlightbindingmis"],                    SFlag.SkillshotLine),
		Spell("luxlightstrikekugel",    ["luxlightstrikekugel"],                   SFlag.Area | SFlag.CollideWindwall),
		Spell("luxmalicecannon",        ["luxmalicecannon"],                       SFlag.Line)
	],
	"ziggs": [                          
		Spell("ziggsq",                 ["ziggsqspell", "ziggsqspell2", "ziggsqspell3"],                              SFlag.Area | SFlag.CollideWindwall),
		Spell("ziggsw",                 ["ziggsw"],                                                                   SFlag.Area | SFlag.CollideWindwall),
		Spell("ziggse",                 ["ziggse2"],                                                                  SFlag.Area | SFlag.CollideWindwall),
		Spell("ziggsr",                 ["ziggsrboom", "ziggsrboommedium", "ziggsrboomlong", "ziggsrboomextralong"],  SFlag.Area),
	],
	"jhin": [                           
		Spell("jhinw",                  ["jhinw"],                                 SFlag.Line | SFlag.CollideChampion | SFlag.CollideWindwall, delay=0.5),
		Spell("jhine",                  ["jhinetrap"],                             SFlag.Area | SFlag.CollideWindwall),
		Spell("jhinrshot",              ["jhinrshotmis", "jhinrshotmis4"],         SFlag.Line | SFlag.CollideWindwall | SFlag.CollideChampion)
	],
	"morgana": [                        
		Spell("morganaq",               ["morganaq"],                              SFlag.SkillshotLine),
		Spell("morganaw",               [],                                        SFlag.Area, delay=0.25)
	],
	"missfortune": [
		Spell("missfortunescattershot", [],                                        SFlag.Area, delay=0.25),
		Spell("missfortunebullettime",  ["missfortunebullets"],                    SFlag.Line | SFlag.CollideWindwall)
	],                                                                             
	"annie": [                                                                     
		Spell("anniew",                 [],                                        SFlag.Cone | SFlag.CollideWindwall),
		Spell("annier",                 [],                                        SFlag.Area)
	],
	"olaf": [
		Spell("olafaxethrowcast",       ["olafaxethrow"],                          SFlag.Line | SFlag.CollideWindwall)
	],
	"anivia": [
		Spell("flashfrost",             ["flashfrostspell"],                       SFlag.Line | SFlag.CollideWindwall),
		Spell("crystallize",            [],                                        SFlag.Area, delay=0.25),
		Spell("glacialstorm",           [],                                        SFlag.Area)
	],
	"urgot": [
		Spell("urgotq",                 ["urgotqmissile"],                         SFlag.Area | SFlag.CollideWindwall, delay = 0.2),
		Spell("urgotr",                 ["urgotr"],                                SFlag.Line | SFlag.CollideWindwall | SFlag.CollideChampion)
	],
	"shyvana": [
		Spell("shyvanafireball",        ["shyvanafireballmissile"],                SFlag.Line | SFlag.CollideChampion | SFlag.CollideWindwall),
		Spell("shyvanafireballdragon2", ["shyvanafireballdragonmissile"],          SFlag.Line | SFlag.Area | SFlag.CollideChampion | SFlag.CollideWindwall)
	],
	"zyra": [
		Spell("zyraq",                  [],                                        SFlag.Area),
		Spell("zyraw",                  [],                                        SFlag.Area),
		Spell("zyrae",                  ["zyrae"],                                 SFlag.Line | SFlag.CollideWindwall),
		Spell("zyrar",                  [],                                        SFlag.Area)
	],
	"zilean": [
		Spell("zileanq",                ["zileanqmissile"],                        SFlag.Area | SFlag.CollideWindwall)
	],
	"orianna": [
		Spell("orianaizunacommand",     ["orianaizuna"],                           SFlag.Line | SFlag.Area | SFlag.CollideWindwall)
	]
}

def draw_prediction_info(game, ui):
	global ChampionSpells, Version
	
	ui.separator()
	ui.text("Using LPrediction v" + Version, Color.PURPLE)
	if is_champ_supported(game.player):
		ui.text(game.player.name.upper() + " has skillshot prediction support", Color.GREEN)
	else:
		ui.text(game.player.name.upper() + " doesnt have skillshot prediction support", Color.RED)
	
	if ui.treenode('Supported Champions'):
		for champ, spells in ChampionSpells.items():
			ui.text(f"{champ.upper()} {' '*(20 - len(champ))}: {str([spell.name for spell in spells])}")
			
		ui.treepop()

def is_skillshot(spell):
	global Spells, MissileToSpell
	return spell.name in Spells or spell.name in MissileToSpell
	
def get_parent_spell(missile):
	global MissileToSpell
	return MissileToSpell.get(missile.name, None)
	
def is_champ_supported(champ):
	global ChampionSpells
	return champ.name in ChampionSpells
	
def is_skill_cone(skill):
	if skill.name not in Spells:
		return False
	return Spells[skill.name].flags & SFlag.Cone
	
def is_last_hitable(game, player, enemy):
	missile_speed = player.basic_missile_speed + 1
		
	hit_dmg = items.get_onhit_physical(player, enemy) + items.get_onhit_magical(player, enemy)
	
	hp = enemy.health
	atk_speed = player.base_atk_speed * player.atk_speed_multi
	t_until_basic_hits = game.distance(player, enemy)/missile_speed#(missile_speed*atk_speed/player.base_atk_speed)

	for missile in game.missiles:
		if missile.dest_id == enemy.id:
			src = game.get_obj_by_id(missile.src_id)
			if src:
				t_until_missile_hits = game.distance(missile, enemy)/(missile.speed + 1)
			
				if t_until_missile_hits < t_until_basic_hits:
					hp -= src.base_atk

	return hp - hit_dmg <= 0
	
# Returns a point where the mouse should click to cast a spells taking into account the targets movement speed
def castpoint_for_collision(game, spell, caster, target):
	global Spells

	print('predicted')
	if spell.name not in Spells:
		return None
	
	# Get extra data for spell that isnt provided by lview
	spell_extra = Spells[spell.name]
	if len(spell_extra.missiles) > 0:
		missile = game.get_spell_info(spell_extra.missiles[0])
	else:
		missile = spell
		
	t_delay = spell.delay + spell_extra.delay
	if missile.travel_time > 0.0:
		t_missile = missile.travel_time
	else:
		t_missile = (missile.cast_range / missile.speed) if len(spell_extra.missiles) > 0 and missile.speed > 0.0 else 0.0
			
	# Get direction of target
	target_dir = target.pos.sub(target.prev_pos).normalize()
	if math.isnan(target_dir.x):
		target_dir.x = 0.0
	if math.isnan(target_dir.y):
		target_dir.y = 0.0
	if math.isnan(target_dir.z):
		target_dir.z = 0.0
		

	# If the spell is a line we simulate the spell missile to get the collision point
	if spell_extra.flags & SFlag.Line:
		
		if len(spell_extra.missiles) > 0:
			missile = game.get_spell_info(spell_extra.missiles[0])
		else:
			missile = spell
		
		iterations = int(missile.cast_range/30.0)
		step = t_missile/iterations
		
		last_dist = 9999999
		last_target_pos = None
		for i in range(iterations):
			t = i*step
			target_future_pos = target.pos.add(target_dir.scale((t_delay + t)*target.movement_speed))
			spell_dir = target_future_pos.sub(caster.pos).normalize().scale(t*missile.speed)
			spell_future_pos = caster.pos.add(spell_dir)
			
			dist = target_future_pos.distance(spell_future_pos)
			if dist < missile.width/2.0 or dist > last_dist:
				return last_target_pos
			else:
				last_dist = dist
				last_target_pos = target_future_pos
				
		return None
		
	# If the spell is an area spell we return the position of the player when the spell procs
	elif spell_extra.flags & SFlag.Area:
		return target.pos.add(target_dir.scale((t_delay + t_missile)*target.movement_speed))
	else:
		return target.pos
		