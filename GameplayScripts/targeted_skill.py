from lview import *
from commons.targeting import TargetingConfig
import json, time

lview_script_info = {
	"script": "Targeted Skill",
	"author": "leryss",
	"description": "Automatically targets and uses skill against enemies. It binds the 1,2,3,4 keys to Q,W,E,R. That means when pressing 1 it will target the champion and simulate a Q key press",
}

auto_targeting = {}
targeting = TargetingConfig()

def get_skill_by_name(champ, skill_str):
	if 'Q' == skill_str:
		return champ.Q
	if 'W' == skill_str:
		return champ.W
	if 'E' == skill_str:
		return champ.E
	if 'R' == skill_str:
		return champ.R
		
def find_champ_target(game, array, range, value_extractor):
	atk_range = game.player.base_atk_range + game.player.gameplay_radius
	target = None
	min = 99999999
	for obj in array:
		
		if not obj.is_alive or obj.is_ally_to(game.player) or game.distance(game.player, obj) > range:
			continue
			
		val = value_extractor(game.player, obj)
		if val < min:
			min = val
			target = obj
	
	return target
	

def lview_load_cfg(cfg):
	global auto_targeting, targeting
	auto_targeting  = json.loads(cfg.get_str("auto_targeting", "{}"))
	targeting.load_from_cfg(cfg)
	
def lview_save_cfg(cfg):
	global auto_targeting, targeting
	cfg.set_str("auto_targeting", json.dumps(auto_targeting))
	targeting.save_to_cfg(cfg)

def lview_draw_settings(game, ui):
	global auto_targeting, targeting
		
	if game.player.name not in auto_targeting:
		auto_targeting[game.player.name] = {'Q': False, 'W': False, 'E': False, 'R': False}
	targeting_settings = auto_targeting[game.player.name]
	for skill, enabled in targeting_settings.items():
		targeting_settings[skill] = ui.checkbox("Autotarget " + skill, enabled)
	
	targeting.draw(ui)
	
def lview_update(game, ui):
	global targeting
	
	if game.player.name not in auto_targeting:
		auto_targeting[game.player.name] = {'Q': False, 'W': False, 'E': False, 'R': False}
	
	for i, (skill_str, enabled) in enumerate(auto_targeting[game.player.name].items()):
		if game.was_key_pressed(i + 2): # Check if 1,2,3,4 was pressed
			skill = get_skill_by_name(game.player, skill_str)
			target = targeting.get_target(game, skill.range)
			if target:
				if enabled:
					old_cpos = game.get_cursor()
					game.move_cursor(game.world_to_screen(target.pos))
				skill.trigger()
				if enabled:
					time.sleep(0.01)
					game.move_cursor(old_cpos)