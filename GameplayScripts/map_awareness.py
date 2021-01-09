from lview import *

lview_script_info = {
	"script": "Map Awareness",
	"author": "leryss",
	"description": "Tells you when champions get close improving your map awareness"
}

bound_min = 0
bound_max = 0

def lview_load_cfg(cfg):
	global bound_min, bound_max
	bound_min = cfg.get_float("bound_min", 2000)
	bound_max = cfg.get_float("bound_max", 4000)
	
def lview_save_cfg(cfg):
	global bound_min, bound_max
	cfg.set_float("bound_min", bound_min)
	cfg.set_float("bound_max", bound_max)
	
def lview_draw_settings(game, ui):
	global bound_min, bound_max
	bound_min = ui.dragfloat("Alert when distance greater than", bound_min, 100.0, 500.0, 10000.0)
	bound_max = ui.dragfloat("Alert when distance less than",    bound_max, 100.0, 500.0, 10000.0)
	
def lview_update(game, ui):
	global bound_min, bound_max
	for champ in game.champs:
		if champ.is_visible and champ.is_ally_to(game.player):
			continue
		
		dist = champ.pos.distance(game.player.pos)
		if dist < 2000 or dist > 4000:
			continue
		
		pos = game.world_to_screen(champ.pos.sub(game.player.pos).normalize().scale(500).add(game.player.pos))
		game.draw_image(champ.name.lower() + "_square", pos, pos.add(Vec2(32, 32)), Color.WHITE, 100.0)
		
		pos.y += 40
		game.draw_text(pos, '{:.0f}m'.format(dist), Color.WHITE)
		