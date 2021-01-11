from lview import *
from commons.targeting import TargetingConfig
import json, time

lview_script_info = {
	"script": "Targeted Skill",
	"author": "leryss",
	"description": "Automatically targets and uses skill against enemies. It binds the 1,2,3,4 keys to Q,W,E,R. That means when pressing 1 it will target the champion and simulate a Q key press",
}

targeting = TargetingConfig()

def get_skill_by_position(champ, i):
	if 2 == i:
		return champ.Q
	if 3 == i:
		return champ.W
	if 4 == i:
		return champ.E
	if 5 == i:
		return champ.R

def lview_load_cfg(cfg):
	global targeting
	targeting.load_from_cfg(cfg)
	
def lview_save_cfg(cfg):
	global targeting
	targeting.save_to_cfg(cfg)

def lview_draw_settings(game, ui):
	global targeting
	targeting.draw(ui)
	
def lview_update(game, ui):
	global targeting

	for i in range(2, 6):
		if game.was_key_pressed(i): # Check if keys 1,2,3,4 was pressed
			skill = get_skill_by_position(game.player, i)
			target = targeting.get_target(game, skill.range)
			if target:
				old_cpos = game.get_cursor()
				game.move_cursor(game.world_to_screen(target.pos))
				
				skill.trigger()
				
				time.sleep(0.01)
				game.move_cursor(old_cpos)