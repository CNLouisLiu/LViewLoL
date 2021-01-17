from lview import *
from commons import skills
from commons.targeting import TargetingConfig
import time, json

lview_script_info = {
	"script": "Orbwalker",
	"author": "leryss",
	"description": "Automatically kites enemies. Also has last hit built in"
}

last_attacked = 0
last_moved = 0

key_attack_move = 0
key_orbwalk = 0
auto_last_hit = False
max_atk_speed = 0

toggle_mode = False
toggled = False

targeting = TargetingConfig() 

def lview_load_cfg(cfg):
	global key_attack_move, key_orbwalk, max_atk_speed, auto_last_hit, toggle_mode
	global targeting
	
	key_attack_move = cfg.get_int("key_attack_move", 0)	
	key_orbwalk     = cfg.get_int("key_orbwalk", 0)	
	max_atk_speed   = cfg.get_float("max_atk_speed", 2.0)
	auto_last_hit   = cfg.get_bool("auto_last_hit", True)
	toggle_mode     = cfg.get_bool("toggle_mode", False)
	targeting.load_from_cfg(cfg)
	
def lview_save_cfg(cfg):
	global key_attack_move, key_orbwalk, max_atk_speed, auto_last_hit, toggle_mode
	global targeting
		
	cfg.set_int("key_attack_move", key_attack_move)
	cfg.set_int("key_orbwalk", key_orbwalk)
	cfg.set_float("max_atk_speed", max_atk_speed)
	cfg.set_bool("auto_last_hit", auto_last_hit)
	cfg.set_bool("toggle_mode", toggle_mode)
	targeting.save_to_cfg(cfg)
	
def lview_draw_settings(game, ui):
	global key_attack_move, key_orbwalk, max_atk_speed, auto_last_hit, toggle_mode
	global targeting
	
	champ_name = game.player.name
	max_atk_speed   = ui.sliderfloat("Max attack speed", max_atk_speed, 1.5, 3.0)
	key_attack_move = ui.keyselect("Attack move key", key_attack_move)
	key_orbwalk     = ui.keyselect("Orbwalk activate key", key_orbwalk)
	auto_last_hit   = ui.checkbox("Last hit minions when no targets", auto_last_hit)
	toggle_mode     = ui.checkbox("Toggle mode", toggle_mode)
	targeting.draw(ui)

def find_minion_target(game):
	atk_range = game.player.base_atk_range + game.player.gameplay_radius
	min_health = 9999999999
	target = None
	for minion in game.minions:
		if minion.is_enemy_to(game.player) and minion.is_alive and minion.health < min_health and game.distance(game.player, minion) < atk_range and skills.is_last_hitable(game, game.player, minion):
			target = minion
			min_health = minion.health
		
	return target
	
def get_target(game):
	global auto_last_hit
	
	target = targeting.get_target(game, game.player.base_atk_range + game.player.gameplay_radius)
	if not target and auto_last_hit:
		return find_minion_target(game)
	
	return target

def lview_update(game, ui):
	global last_attacked, alternate, last_moved
	global key_attack_move, key_orbwalk, max_atk_speed
	global toggle_mode, toggled
	
	if toggle_mode:
		if game.was_key_pressed(key_orbwalk):
			toggled = not toggled
		if not toggled:
			return
			
	elif not game.is_key_down(key_orbwalk):
		return
	
	game.draw_button(game.world_to_screen(game.player.pos), "OrbWalking", Color.BLACK, Color.WHITE)

	# Handle basic attacks
	self = game.player
	
	atk_speed = self.base_atk_speed * self.atk_speed_multi
	b_windup_time = (1.0/self.base_atk_speed)*game.player.basic_atk_windup
	c_atk_time = 1.0/atk_speed
	max_atk_time = 1.0/max_atk_speed

	target = get_target(game)
	t = time.time()
	if t - last_attacked > max(c_atk_time, max_atk_time) and target:
		last_attacked = t
		
		game.press_key(key_attack_move)
		game.click_at(True, game.world_to_screen(target.pos))
	else:
		dt = t - last_attacked
		if dt > b_windup_time and t - last_moved > 0.15:
			last_moved = t
			game.press_right_click()
		
		
	
	