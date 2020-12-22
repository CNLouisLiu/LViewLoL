from lview import *

lview_script_info = {
	"script": "Vision Tracker",
	"author": "leryss",
	"description": "Tracks enemy invisible objects and clones"
}

paint_circles = True

radius_map = {
	"WARD": 900,
	"WARD_PINK": 900,
	"SHACO_BOX": 300,
	"TEEMO_MUSHROOM": 100
}

show_circles = {
	"WARD": False,
	"WARD_PINK": False,
	"SHACO_BOX": False,
	"TEEMO_MUSHROOM": False
}

show_circles_minimap = {
	"WARD": False,
	"WARD_PINK": False,
	"SHACO_BOX": False,
	"TEEMO_MUSHROOM": False
}


def lview_load_cfg(cfg):
	show_circles["WARD"]           = cfg.get_bool("circleWards", True)
	show_circles["WARD_PINK"]      = cfg.get_bool("circlePinks", True)
	show_circles["SHACO_BOX"]      = cfg.get_bool("circleBoxes", True)
	show_circles["TEEMO_MUSHROOM"] = cfg.get_bool("circleMushrooms", True)
	
	show_circles_minimap["WARD"]           = cfg.get_bool("circleWardsMinimap", True)
	show_circles_minimap["WARD_PINK"]      = cfg.get_bool("circlePinksMinimap", True)
	show_circles_minimap["SHACO_BOX"]      = cfg.get_bool("circleBoxesMinimap", True)
	show_circles_minimap["TEEMO_MUSHROOM"] = cfg.get_bool("circleMushroomsMinimap", True)
	
def lview_save_cfg(cfg):
	cfg.set_bool("circleWards",     show_circles["WARD"])
	cfg.set_bool("circlePinks",     show_circles["WARD_PINK"])
	cfg.set_bool("circleBoxes",     show_circles["SHACO_BOX"])
	cfg.set_bool("circleMushrooms", show_circles["TEEMO_MUSHROOM"])
	
	cfg.set_bool("circleWardsMinimap",     show_circles_minimap["WARD"])
	cfg.set_bool("circlePinksMinimap",     show_circles_minimap["WARD_PINK"])
	cfg.set_bool("circleBoxesMinimap",     show_circles_minimap["SHACO_BOX"])
	cfg.set_bool("circleMushroomsMinimap", show_circles_minimap["TEEMO_MUSHROOM"])
	
def lview_draw_settings(game, ui):
	
	ui.text("Settings per entity")
	for x in show_circles.keys():
		if ui.treenode(x):
			show_circles[x] = ui.checkbox("Show range circles", show_circles[x])
			show_circles_minimap[x] = ui.checkbox("Show on minimap", show_circles_minimap[x])
			
			ui.treepop()
	
def lview_update(game, ui):
	
	global paint_circles
	
	for obj in game.others:
		if obj.is_ally_to(game.local_champ):
			continue
			
		is_invisible = obj.is_type(ObjType.INVISIBLE)
		is_clone = obj.is_type(ObjType.CLONE)
		
		if is_invisible or is_clone:
			obj_str = str(obj.type)
			txt = obj_str
			
			# Add expiry of the object if its also expirable
			if obj.is_type(ObjType.EXPIRABLE):
				expires_in = (obj.last_visible_at + obj.duration) - game.time
				if expires_in <= 0.0:
					continue
				txt += f":{expires_in:.0f}"
			
			p = game.world_to_screen(obj.pos)
			if game.is_point_on_screen(p):	
				game.draw_button(p, txt, Color.WHITE, Color.BLACK, 10)
			
				# Draw range circles
				draw_circle = show_circles.get(obj_str, False)
				if draw_circle:
					radius = radius_map[obj_str]
					game.draw_circle_world(obj.pos, radius, 40, 3, Color.RED)
			
			# Draw on minimap
			if show_circles_minimap.get(obj_str, False):
				mp = game.world_to_minimap(obj.pos)
				game.draw_circle(mp, game.distance_to_minimap(radius_map[obj_str]), 15, 0.5, Color.RED)
		