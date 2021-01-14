from lview import *
import json

lview_script_info = {
	"script": "Vision Tracker",
	"author": "leryss",
	"description": "Tracks enemy invisible objects and clones"
}

show_clones, show_wards, show_traps = None, None, None

traps = {
	#Name -> (radius, show_radius_circle, show_radius_circle_minimap, icon)                      
	'caitlyntrap'          : [50,  True,  False, "caitlyn_yordlesnaptrap"],
	'jhintrap'             : [140, True,  False, "jhin_e"],
	'jinxmine'             : [50,  True,  False, "jinx_e"],
	'maokaisproutling'     : [50,  False, False, "maokai_e"],
	'nidaleespear'         : [50,  True,  False, "nidalee_w1"],
	'shacobox'             : [300, True,  False, "jester_deathward"],
	'teemomushroom'        : [75,  True,  True,  "teemo_r"]
}

wards = {
	'bluetrinket'          : [900, True, True, "bluetrinket"],
	'jammerdevice'         : [900, True, True, "pinkward"],
	'perkszombieward'      : [900, True, True, "bluetrinket"],
	'sightward'            : [900, True, True, "sightward"],
	'visionward'           : [900, True, True, "sightward"],
	'yellowtrinket'        : [900, True, True, "yellowtrinket"],
	'yellowtrinketupgrade' : [900, True, True, "yellowtrinket"],
	'ward'                 : [900, True, True, "sightward"],
}

clones = {
	'shaco'           : [0, False, False, "shaco_square"],
	'leblanc'         : [0, False, False, "leblanc_square"],
	'monkeyking'      : [0, False, False, "monkeyking_square"],
	'neeko'           : [0, False, False, "neeko_square"],
	'fiddlesticks'    : [0, False, False, "fiddlesticks_square"],
}


def lview_load_cfg(cfg):
	global show_clones, show_wards, show_traps, traps, wards

	show_clones = cfg.get_bool("show_clones", True)
	show_wards = cfg.get_bool("show_wards", True)
	show_traps = cfg.get_bool("show_traps", True)
	
	traps = json.loads(cfg.get_str("traps", json.dumps(traps)))
	wards = json.loads(cfg.get_str("wards", json.dumps(wards)))
	
def lview_save_cfg(cfg):
	global show_clones, show_wards, show_traps, traps, wards
	
	cfg.set_bool("show_clones", show_clones)
	cfg.set_bool("show_wards", show_wards)
	cfg.set_bool("show_traps", show_traps)
	
	cfg.set_str("traps", json.dumps(traps))
	cfg.set_str("wards", json.dumps(wards))
	
def lview_draw_settings(game, ui):
	global traps, wards
	global show_clones, show_wards, show_traps
	
	show_clones = ui.checkbox("Show clones", show_clones)
	show_wards = ui.checkbox("Show wards", show_wards)
	show_traps = ui.checkbox("Show clones", show_traps)
	
	ui.text("Traps")
	for x in traps.keys():
		if ui.treenode(x):
			traps[x][1] = ui.checkbox("Show range circles", traps[x][1])
			traps[x][2] = ui.checkbox("Show on minimap", traps[x][2])
			
			ui.treepop()
			
	ui.text("Wards")
	for x in wards.keys():
		if ui.treenode(x):
			wards[x][1] = ui.checkbox("Show range circles", wards[x][1])
			wards[x][2] = ui.checkbox("Show on minimap", wards[x][2])
			
			ui.treepop()

def draw(game, obj, radius, show_circle_world, show_circle_map, icon):
			
	sp = game.world_to_screen(obj.pos)
	
	if game.is_point_on_screen(sp):
		duration = obj.duration + obj.last_visible_at - game.time
		if duration > 0:
			game.draw_text(sp.add(Vec2(5, 30)), f'{duration:.0f}', Color.WHITE)	
		game.draw_image(icon, sp, sp.add(Vec2(30, 30)), Color.WHITE, 10)
		
		if show_circle_world:
			game.draw_circle_world(obj.pos, radius, 30, 3, Color.RED)
	
	if show_circle_map:
		p = game.world_to_minimap(obj.pos)
		game.draw_circle(game.world_to_minimap(obj.pos), game.distance_to_minimap(radius), 15, 2, Color.RED)

def lview_update(game, ui):
	
	global show_clones, show_wards, show_traps
	global traps, wards, clones
	
	for obj in game.others:
		if obj.is_ally_to(game.player) or not obj.is_alive:
			continue
		
		if show_wards and obj.has_tags(UnitTag.Unit_Ward) and obj.name in wards:
			draw(game, obj, *(wards[obj.name]))
		elif show_traps and obj.has_tags(UnitTag.Unit_Special_Trap) and obj.name in traps:
			draw(game, obj, *(traps[obj.name]))
	
	if show_clones:
		for champ in game.champs:
			if champ.is_ally_to(game.player) or not champ.is_alive:
				continue
			if champ.name in clones and champ.R.name == champ.D.name:
				draw(game, champ, *(clones[champ.name]))
		