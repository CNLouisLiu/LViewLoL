from lview import *

lview_script_info = {
	"script": "Skillshots",
	"author": "<author-name>",
	"description": "<script-description>"
}

def lview_load_cfg(cfg):
	pass
	
def lview_save_cfg(cfg):
	pass
	
def lview_draw_settings(game, ui):
	pass
	
def lview_update(game, ui):
	
	for missile in game.missiles:
		if missile.is_enemy_to(game.local_champ) and missile.dest_idx == 0:
			pt_start = game.world_to_screen(missile.pos)
			pt_end = game.world_to_screen(missile.end_pos)
			game.draw_line(pt_start, pt_end, 3, Color.RED)