from lview import *
from time import time
import itertools, math
from commons import prediction

lview_script_info = {
	"script": "Drawings",
	"author": "leryss",
	"description": "Draws indicators for different things"
}

turret_ranges   = False
minion_last_hit = False
attack_range    = False
skillshots      = False


def lview_load_cfg(cfg):
	global turret_ranges, minion_last_hit, attack_range, skillshots
	turret_ranges   = cfg.get_bool("turret_ranges", True)
	minion_last_hit = cfg.get_bool("minion_last_hit", True)
	attack_range    = cfg.get_bool("attack_range", True)
	skillshots      = cfg.get_bool("skillshots", True)
	
def lview_save_cfg(cfg):
	global turret_ranges, minion_last_hit, attack_range, skillshots
	cfg.set_bool("turret_ranges",   turret_ranges)
	cfg.set_bool("minion_last_hit", minion_last_hit)
	cfg.set_bool("attack_range",    attack_range)
	cfg.set_bool("skillshots",      skillshots)
	
def lview_draw_settings(game, ui):
	global turret_ranges, minion_last_hit, attack_range, skillshots
	turret_ranges   = ui.checkbox("Turret ranges", turret_ranges)
	minion_last_hit = ui.checkbox("Minion last hit", minion_last_hit)
	attack_range    = ui.checkbox("Champion attack range", attack_range)
	skillshots      = ui.checkbox("Champion skillshots", skillshots)
	
def lview_update(game, ui):
	global turret_ranges, minion_last_hit, attack_range, skillshots
	
	if attack_range and game.is_point_on_screen(game.local_champ.pos):
		color = Color.GREEN
		color.a = 0.5
		game.draw_circle_world(game.local_champ.pos, game.local_champ.base_atk_range + game.local_champ.gameplay_radius, 100, 2, color)
	
	if turret_ranges:
		color = Color.RED
		color.a = 0.5
		for turret in game.turrets:
			if turret.is_alive and turret.is_enemy_to(game.local_champ) and game.is_point_on_screen(turret.pos):
				game.draw_circle_world(turret.pos, turret.base_atk_range, 100, 2, color)
	
	if minion_last_hit:
		color = Color.CYAN
		for minion in game.minions:
		
			#p = game.world_to_screen(minion.pos)
			#game.draw_text(p, str(game.local_champ.get_basic_phys(minion)), Color.RED)
			#p.y += 15
			#game.draw_text(p, str(game.local_champ.get_basic_magic(minion)), Color.CYAN)
			
			if minion.is_alive and minion.is_enemy_to(game.local_champ) and game.is_point_on_screen(minion.pos):
				if prediction.is_last_hitable(game, game.local_champ, minion):
					game.draw_circle_world(minion.pos, minion.gameplay_radius, 20, 3, color)
				
	if skillshots:
		
		for missile in game.missiles:
			if not missile.info:# or missile.is_ally_to(game.local_champ):
				continue
				
			flags = missile.info.flags
			if flags & MissileFlag.TARGETED == 0:
				end_pos = missile.end_pos
				start_pos = missile.start_pos
				curr_pos = missile.pos
				
				if missile.info.radius > 0:
					dir = Vec3(end_pos.x - start_pos.x, 0, end_pos.z - start_pos.z)
					dir.normalize()
					
					if flags & MissileFlag.FIXED_LOCATION == 0:
						obj, dist = prediction.find_missile_collision(game, missile)
						if obj:
							end_pos = Vec3(start_pos.x + dist*dir.x, curr_pos.y, start_pos.z + dist*dir.z)
							
					start_pos = curr_pos
					start_pos.y = end_pos.y
					
					left_dir = Vec3(dir.x, dir.y, dir.z)
					right_dir = Vec3(dir.x, dir.y, dir.z)
					left_dir.rotate_y(90)
					left_dir.scale(missile.info.radius)
					
					right_dir.rotate_y(-90)
					right_dir.scale(missile.info.radius)
					
					p1 = Vec3(start_pos.x + left_dir.x,  start_pos.y + left_dir.y,  start_pos.z + left_dir.z)
					p2 = Vec3(end_pos.x + left_dir.x,    end_pos.y + left_dir.y,    end_pos.z + left_dir.z)
					p3 = Vec3(end_pos.x + right_dir.x,   end_pos.y + right_dir.y,   end_pos.z + right_dir.z)
					p4 = Vec3(start_pos.x + right_dir.x, start_pos.y + right_dir.y, start_pos.z + right_dir.z)
					
					game.draw_rect_world(p1, p2, p3, p4, 3, Color.WHITE)
					game.draw_circle_world(missile.pos, missile.info.radius, 20, 5, Color.RED)
					
				if missile.info.impact_radius > 0:
					r = missile.info.impact_radius
					percent_done = missile.start_pos.distance(curr_pos)/missile.start_pos.distance(end_pos)
					color = Color(1, 1.0 - percent_done, 0, 0.5)
					
					if missile.info.impact_angle > 0:
						angle = missile.info.impact_angle/2
						
						left_dir = Vec3(-dir.x, -dir.y, -dir.z)
						right_dir = Vec3(-dir.x, -dir.y, -dir.z)
						
						left_dir.rotate_y(angle)
						left_dir.scale(r)
						left_dir.add(end_pos)
						right_dir.rotate_y(-angle)
						right_dir.scale(r)
						right_dir.add(end_pos)
						game.draw_triangle_world(end_pos, left_dir, right_dir, 3, Color.WHITE)
						
						left_dir = Vec3(-dir.x, -dir.y, -dir.z)
						right_dir = Vec3(-dir.x, -dir.y, -dir.z)
						
						left_dir.rotate_y(angle)
						left_dir.scale(r*percent_done)
						left_dir.add(end_pos)
						right_dir.rotate_y(-angle)
						right_dir.scale(r*percent_done)
						right_dir.add(end_pos)
						game.draw_triangle_world_filled(end_pos, left_dir, right_dir, color)
					else:
						game.draw_circle_world(end_pos, r, 30, 3, Color.WHITE)
						game.draw_circle_world_filled(end_pos, r*percent_done, 30, color)
					
				
				