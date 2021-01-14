from lview import *
from commons.targeting import TargetingConfig
from commons.prediction import *
import json, time

lview_script_info = {
	"script": "Auto Spell",
	"author": "leryss",
	"description": "Automatically casts spells on targets. Skillshots are cast using movement speed prediction.",
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
	draw_prediction_info(game, ui)
	
def lview_update(game, ui):
	global targeting

	for i in range(2, 6):
		if game.was_key_pressed(i): # Check if keys 1,2,3,4 was pressed
			skill = get_skill_by_position(game.player, i)
			b_is_skillshot = is_skillshot(skill.name)
			skill_range = get_skillshot_range(game, skill.name) if b_is_skillshot else 1500.0
			target = targeting.get_target(game, skill_range)
			
			if target:
				if b_is_skillshot:
					cast_point = castpoint_for_collision(game, skill, game.player, target)
				else:
					cast_point = target.pos
					
				if cast_point:
					cast_point = game.world_to_screen(cast_point)
					
					old_cpos = game.get_cursor()
					game.move_cursor(cast_point)
					
					skill.trigger()
					
					time.sleep(0.01)
					game.move_cursor(old_cpos)