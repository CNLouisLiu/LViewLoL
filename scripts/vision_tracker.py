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

show_circle_map = {
	"WARD": False,
	"WARD_PINK": False,
	"SHACO_BOX": False,
	"TEEMO_MUSHROOM": False
}

def lview_load_cfg(cfg):
	show_circle_map["WARD"]           = cfg.get_bool("circleWards", True)
	show_circle_map["WARD_PINK"]      = cfg.get_bool("circlePinks", True)
	show_circle_map["SHACO_BOX"]      = cfg.get_bool("circleBoxes", True)
	show_circle_map["TEEMO_MUSHROOM"] = cfg.get_bool("circleMushrooms", True)
	
def lview_save_cfg(cfg):
	cfg.set_bool("circleWards",     show_circle_map["WARD"])
	cfg.set_bool("circlePinks",     show_circle_map["WARD_PINK"])
	cfg.set_bool("circleBoxes",     show_circle_map["SHACO_BOX"])
	cfg.set_bool("circleMushrooms", show_circle_map["TEEMO_MUSHROOM"])
	
def lview_draw_settings(game, ui):
	
	ui.text("Show circles for:")
	show_circle_map["WARD"]           = ui.checkbox("Normal wards",    show_circle_map["WARD"])
	show_circle_map["WARD_PINK"]      = ui.checkbox("Pink wards",      show_circle_map["WARD_PINK"])
	show_circle_map["SHACO_BOX"]      = ui.checkbox("Shaco boxes",     show_circle_map["SHACO_BOX"])
	show_circle_map["TEEMO_MUSHROOM"] = ui.checkbox("Teemo mushrooms", show_circle_map["TEEMO_MUSHROOM"])
	
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
				if show_circle_map[obj_str]:
					radius = radius_map[obj_str]
					game.draw_circle_world(obj.pos, radius, 40, 3, Color.RED)