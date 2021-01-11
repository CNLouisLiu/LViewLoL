from lview import *
import math, itertools, time
from . import items
	
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
		if missile.has_tags(SpellFlag.Targeted):
			if missile.dest_id == enemy.id:
				src = game.get_obj_by_id(missile.src_id)
				if src:
					t_until_missile_hits = game.distance(missile, enemy)/(missile.speed + 1)
				
					if t_until_missile_hits < t_until_basic_hits:
						hp -= src.base_atk

	return hp - hit_dmg <= 0