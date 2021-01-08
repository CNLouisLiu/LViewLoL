from lview import *
import math, itertools, time
	
def find_impact_collision_champs(game, missile):
	
	result = []
	for champ in game.champs:
		if champ.is_visible and champ.is_alive and champ.is_enemy_to(missile):
			threshold = missile.impact_radius + champ.gameplay_radius
			if game.distance(champ, missile) <  threshold:
				result.append(champ)
				
	return result
	
def is_last_hitable(game, player, enemy):
	missile_speed = player.basic_missile_speed
	if missile_speed == 0:
		missile_speed = 1
		
	hit_dmg = player.get_basic_phys(enemy) + player.get_basic_magic(enemy)
	
	hp = enemy.health
	atk_speed = player.base_atk_speed * player.atk_speed_multi
	t_current_range = game.distance(player, enemy)/(missile_speed*atk_speed/player.base_atk_speed)

	for  missile in game.missiles:
		if missile.has_tags(SpellFlag.Targeted):
			if missile.dest_id == enemy.id:
				src = game.get_obj_by_id(missile.src_id)
				if src:
					s = game.distance(missile, enemy)/missile.speed
				
					if s < t_current_range:
						hp -= src.base_atk

	return hp - hit_dmg <= 0