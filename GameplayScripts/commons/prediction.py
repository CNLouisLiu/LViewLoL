from lview import *
import math, itertools, time
from . import items

# Spells and missiles are both spells but dont always have the same values (like speed, range etc). 
# We need to define a mapping between skills and the missiles those skills are spawning
SpellToMissileMapping = {
	# ahri
	"ahriorbofdeception": "ahriorbmissile",
	"ahriseduce": "ahriseducemissile",
	
	# ezreal
	"ezrealq": "ezrealq",
	"ezrealw": "ezrealw",
	"ezrealr": "ezrealr",
}

SupportedChamps = {
	"ahri",
	"ezreal"
}

def is_skillshot(spell):
	global SpellToMissileMapping
	return spell.name in SpellToMissileMapping
	
def is_champ_supported(champ):
	global SupportedChamps
	return champ.name in SupportedChamps
	
def find_impact_collision_champs(game, missile):
	
	result = []
	for champ in game.champs:
		if champ.is_visible and champ.is_alive and champ.is_enemy_to(missile):
			threshold = missile.impact_radius + champ.gameplay_radius
			if game.distance(champ, missile) <  threshold:
				result.append(champ)
				
	return result
	
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
	
#   Simulates the movement of the spell missile and that of the target enemy for a few iterations 
# and returns the point where the mouse must cast the spell in order for a collision to trigger
# if no such point is found it return None.
def castpoint_for_collision(game, spell, caster, target):
	global SpellToMissileMapping
	
	if spell.name not in SpellToMissileMapping:
		return None
		
	missile = game.get_spell_info(SpellToMissileMapping[spell.name])
	iterations = int(missile.range/50.0)
	target_dir = target.pos.sub(target.prev_pos).normalize()
	if math.isnan(target_dir.x):
		target_dir.x = 0.0
	if math.isnan(target_dir.y):
		target_dir.y = 0.0
	if math.isnan(target_dir.z):
		target_dir.z = 0.0
		
	t_finish = spell.delay + (missile.range / missile.speed)
	step = t_finish/iterations
	for i in range(iterations):
		t = i*step
		target_future_pos = target.pos.add(target_dir.scale(t*target.movement_speed))
		spell_dir = target_future_pos.sub(caster.pos).normalize().scale(t*missile.speed)
		spell_future_pos = caster.pos.add(spell_dir)
		
		print(target_future_pos.distance(spell_future_pos))
		if target_future_pos.distance(spell_future_pos) < missile.radius/2.0:
			return target_future_pos
		
	return None