from lview import *

show_local_champ = False
show_allies = False
show_enemies = False

lview_script_info = {
	"script": "Spell Tracker",
	"author": "leryss",
	"description": "Tracks spell cooldowns and levels"
}

def get_color_for_cooldown(cooldown):
	if cooldown >= 10.0:
		return Color.DARK_RED
	elif cooldown > 0.0:
		return Color.DARK_YELLOW
	else:
		return Color.DARK_GREEN

def draw_spell_btn(game, spell, x, y, w, h, show_spell_name = False, show_lvl = True):
	
	cooldown = spell.get_current_cooldown(game.time)
	color = get_color_for_cooldown(cooldown) if spell.level > 0 else Color.GRAY
	txt = spell.name if show_spell_name else str(spell.slot)
	
	game.draw_rect_filled(Vec4(x, y, x + w, y + h), color, 5.0)
	game.draw_text(Vec2(x + 5, y), str(int(cooldown)) if cooldown > 0.0 else txt, Color.WHITE)
	
	if show_lvl:
		for i in range(spell.level):
			offset = i*4
			game.draw_rect_filled(Vec4(x + offset + 4, y + h, x + offset + 7, y + h + 2), Color.YELLOW)

def draw_overlay_on_champ(game, champ):
	p = game.world_to_screen(champ.pos)
	p.x -= 60
	if not game.is_point_on_screen(p):
		return
		
	draw_spell_btn(game, champ.Q, p.x,       p.y,      30, 15)
	draw_spell_btn(game, champ.W, p.x + 33,  p.y,      30, 15)
	draw_spell_btn(game, champ.E, p.x + 66,  p.y,      30, 15)
	draw_spell_btn(game, champ.R, p.x + 99,  p.y,      30, 15)
	draw_spell_btn(game, champ.D, p.x,       p.y - 18, 63, 15, True, False)
	draw_spell_btn(game, champ.F, p.x + 66,  p.y - 18, 63, 15, True, False)

def lview_update(game, ui):
	global show_allies, show_enemies, show_local_champ
	
	for champ in game.champs:
		if not champ.is_visible or not champ.is_alive:
			continue
		if champ == game.local_champ and show_local_champ:
			draw_overlay_on_champ(game, champ)
		elif champ != game.local_champ:
			if champ.is_ally_to(game.local_champ) and show_allies:
				draw_overlay_on_champ(game, champ)
			elif champ.is_enemy_to(game.local_champ) and show_enemies:
				draw_overlay_on_champ(game, champ)

def lview_load_cfg(cfg):
	global show_allies, show_enemies, show_local_champ
	
	show_allies = cfg.get_bool("show_allies", False)
	show_enemies = cfg.get_bool("show_enemies", True)
	show_local_champ = cfg.get_bool("show_local_champ", False)
	
def lview_save_cfg(cfg):
	global show_allies, show_enemies, show_local_champ
	
	cfg.set_bool("show_allies", show_allies)
	cfg.set_bool("show_enemies", show_enemies)
	cfg.set_bool("show_local_champ", show_local_champ)
	
def lview_draw_settings(game, ui):
	global show_allies, show_enemies, show_local_champ
	
	show_allies = ui.checkbox("Show overlay on allies", show_allies)
	show_enemies = ui.checkbox("Show overlay on enemies", show_enemies)
	show_local_champ = ui.checkbox("Show overlay on self", show_local_champ)
	
