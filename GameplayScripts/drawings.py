from lview import *

lview_script_info = {
	"script": "Drawings",
	"author": "leryss",
	"description": "Draws indicators for different things"
}

turret_ranges   = False
minion_last_hit = False
attack_range    = False

def is_last_hitable(player, enemy):
	hit_dmg = player.get_basic_phys(enemy) + player.get_basic_magic(enemy)
	return enemy.health - hit_dmg <= 0

def lview_load_cfg(cfg):
	global turret_ranges, minion_last_hit, attack_range
	turret_ranges   = cfg.get_bool("turret_ranges", True)
	minion_last_hit = cfg.get_bool("minion_last_hit", True)
	attack_range    = cfg.get_bool("attack_range", True)
	
def lview_save_cfg(cfg):
	global turret_ranges, minion_last_hit, attack_range
	cfg.set_bool("turret_ranges",   turret_ranges)
	cfg.set_bool("minion_last_hit", minion_last_hit)
	cfg.set_bool("attack_range",    attack_range)
	
def lview_draw_settings(game, ui):
	global turret_ranges, minion_last_hit, attack_range
	turret_ranges   = ui.checkbox("Turret ranges", turret_ranges)
	minion_last_hit = ui.checkbox("Minion last hit", minion_last_hit)
	attack_range    = ui.checkbox("Champion attack range", attack_range)
	
def lview_update(game, ui):
	global turret_ranges, minion_last_hit, attack_range
	
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
		color.a = 0.5
		for minion in game.minions:
		
			#p = game.world_to_screen(minion.pos)
			#game.draw_text(p, str(game.local_champ.get_basic_phys(minion)), Color.RED)
			#p.y += 15
			#game.draw_text(p, str(game.local_champ.get_basic_magic(minion)), Color.CYAN)
			
			if minion.is_alive and minion.is_enemy_to(game.local_champ) and is_last_hitable(game.local_champ, minion) and game.is_point_on_screen(minion.pos):
				game.draw_circle_world(minion.pos, minion.gameplay_radius, 4, 3, color)