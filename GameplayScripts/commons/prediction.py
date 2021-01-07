from lview import *
import math, itertools, time

def find_missile_collision(game, missile, use_prediction):
	
	if missile.has_tags(MissileTag.Pierce_All):
		return None
	
	missile_start = Vec2(missile.pos.x, missile.pos.z)
	missile_speed = Vec2(missile.end_pos.x - missile.pos.x, missile.end_pos.z - missile.pos.z).normalize().scale(missile.speed)
	
	minions, jungle, champs = [], [], []
	if not missile.has_tags(MissileTag.Pierce_Mob):
		minions, jungle = game.minions, game.jungle
	if not missile.has_tags(MissileTag.Pierce_Champion):
		champs = game.champs
		
	min_d, target = 999999, None
	for mob in itertools.chain(champs, minions, jungle):
		dist = missile.pos.distance(mob.pos)
		if dist < missile.range and dist < min_d and mob.is_visible and mob.is_alive and mob.is_enemy_to(missile):
			if use_prediction:
				mob_speed = mob.pos.sub(mob.prev_pos).normalize().scale(mob.movement_speed)
				mob_speed = Vec2(mob_speed.x, mob_speed.z)
			else:
				mob_speed = Vec2(0.0, 0.0)
				
			if game.linear_collision(missile_start, missile_speed, Vec2(mob.pos.x, mob.pos.z), mob_speed, missile.radius + mob.gameplay_radius):
				min_d = dist
				target = mob
	
	return target
	
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
		if missile.has_tags(MissileTag.Targeted):
			if missile.dest_id == enemy.id:
				src = game.get_obj_by_id(missile.src_id)
				if src:
					s = game.distance(missile, enemy)/missile.speed
				
					if s < t_current_range:
						hp -= src.base_atk

	return hp - hit_dmg <= 0