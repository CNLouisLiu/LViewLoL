from lview import *
import math, itertools

def find_missile_collision(game, missile):
	
	if missile.has_tags(MissileTag.Pierce_All):
		return (None, 0)
	
	s = missile.start_pos
	e = missile.end_pos
	
	a = s.z - e.z
	b = e.x - s.x
	c = (s.x - e.x)*s.z + s.x*(e.z - s.z)
	d = math.sqrt(a*a + b*b)
	
	minions, jungle, champs = [], [], []
	if not missile.has_tags(MissileTag.Pierce_Mob):
		minions, jungle = game.minions, game.jungle
	if not missile.has_tags(MissileTag.Pierce_Champion):
		champs = game.champs
		
	min_d, target = 999999, None
	for mob in itertools.chain(minions, jungle, champs):
		dist = s.distance(mob.pos)
		if mob.is_visible and mob.is_alive and mob.is_enemy_to(missile) and dist < missile.range:
			if dist < min_d and abs(a*mob.pos.x + b*mob.pos.z + c)/d < (missile.radius + mob.gameplay_radius):
				min_d = dist
				target = mob
	
	return target, min_d
	
def is_last_hitable(game, player, enemy):
	hit_dmg = player.get_basic_phys(enemy) + player.get_basic_magic(enemy)
	
	hp = enemy.health
	atk_speed = player.base_atk_speed * player.atk_speed_multi
	t_current_range = game.distance(player, enemy)/(player.basic_missile_speed*atk_speed/player.base_atk_speed)

	for  missile in game.missiles:
		if missile.has_tags(MissileTag.Targeted):
			if missile.dest_idx == enemy.id:
				src = game.all_objs[missile.src_idx]
				s = game.distance(missile, enemy)/missile.speed
				
				if s < t_current_range:
					hp -= src.base_atk
	
	return hp - hit_dmg <= 0