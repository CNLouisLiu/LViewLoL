from lview import *

lview_script_info = {
	"script": "Last Hit Assist",
	"author": "leryss",
	"description": "Shows when to attack minion in order to last hit them. Takes into account item that modify on hit damage like botrk and guinsoo."
}

def lview_load_cfg(cfg):
	pass
	
def lview_save_cfg(cfg):
	pass
	
def lview_draw_settings(game, ui):
	pass
	
def lview_update(game, ui):
	
	for minion in game.minions:
		if minion.is_alive and minion.is_enemy_to(game.local_champ) and game.is_point_on_screen(minion.pos):
			
			#p = game.world_to_screen(minion.pos)
			#game.draw_text(p, str(game.local_champ.get_basic_phys(minion)), Color.RED)
			#p.y += 15
			#game.draw_text(p, str(game.local_champ.get_basic_magic(minion)), Color.CYAN)
			
			hit_dmg = game.local_champ.get_basic_phys(minion) + game.local_champ.get_basic_magic(minion)
			if minion.health - hit_dmg <= 0:
				game.draw_circle_world(minion.pos, minion.gameplay_radius, 20, 3, Color.CYAN)