from lview import *
import math, itertools

def find_missile_collision(game, missile):
	
	if missile.info.has_flags(MissileFlag.PIERCE_ALL):
		return (None, 0)
	
	s = missile.start_pos
	e = missile.end_pos
	
	a = s.z - e.z
	b = e.x - s.x
	c = (s.x - e.x)*s.z + s.x*(e.z - s.z)
	d = math.sqrt(a*a + b*b)
	
	minions, jungle, champs = [], [], []
	if not missile.info.has_flags(MissileFlag.PIERCE_MOB):
		minions, jungle = game.minions, game.jungle
	if not missile.info.has_flags(MissileFlag.PIERCE_CHAMPION):
		champs = game.champs
		
	min_d, target = 999999, None
	for mob in itertools.chain(minions, jungle, champs):
		if mob.is_visible and mob.is_alive and mob.is_enemy_to(missile) and game.is_point_on_screen(mob.pos):
			dist = s.distance(mob.pos)
			if dist < min_d and abs(a*mob.pos.x + b*mob.pos.z + c)/d < (missile.info.radius + mob.gameplay_radius):
				min_d = dist
				target = mob
					
	return target, min_d
	
def is_last_hitable(game, player, enemy):
	hit_dmg = player.get_basic_phys(enemy) + player.get_basic_magic(enemy)
	
	hp = enemy.health
	atk_speed = player.base_atk_speed * player.atk_speed_multi
	t_current_range = game.distance(player, enemy)/(2500*atk_speed/player.base_atk_speed)

	for  missile in game.missiles:
		if missile.info and missile.info.flags & MissileFlag.TARGETED:
			if missile.dest_idx == enemy.id:
				src = game.all_objs[missile.src_idx]
				s = game.distance(missile, enemy)/missile.info.speed
				
				if s < t_current_range:
					hp -= src.base_atk
	
	return hp - hit_dmg <= 0