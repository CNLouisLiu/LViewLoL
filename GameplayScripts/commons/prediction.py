from lview import *
import math, itertools, time

def linear_collision(p1, d1, p2, d2, radius):
	
	t = time.time()
	Ax = (d1.x - d2.x)**2.0
	Bx = p1.x*d1.x - p1.x*d2.x - p2.x*d1.x + p2.x*d2.x
	Cx = (p1.x - p2.x)**2.0
	
	Ay = (d1.y - d2.y)**2.0
	By = p1.y*d1.y - p1.y*d2.y - p2.y*d1.y + p2.y*d2.y
	Cy = (p1.y - p2.y)**2.0
	
	a = Ax + Ay
	b = 2.0*(Bx + By)
	c = Cx + Cy - radius**2.0
	delta = b*b - 4.0*a*c
	
	if a == 0.0 or delta < 0.0:
		return False

	sqrt_d = math.sqrt(delta)
	t1 = (-b + sqrt_d)/(2.0*a)
	t2 = (-b - sqrt_d)/(2.0*a)
	t2 = time.time() - t
	
	return (t1 >= 0.0 and t2 >= 0.0)

def find_missile_collision(game, missile):
	
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
		if mob.is_visible and mob.is_alive and mob.is_enemy_to(missile) and dist < missile.range:
			if game.linear_collision(missile_start, missile_speed, Vec2(mob.pos.x, mob.pos.z), Vec2(0, 0), missile.radius + mob.gameplay_radius):
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
			if missile.dest_idx == enemy.id:
				if missile.src_idx in game.all_objs:
					s = game.distance(missile, enemy)/missile.speed
				
					if s < t_current_range:
						hp -= game.all_objs[missile.src_idx].base_atk

	return hp - hit_dmg <= 0