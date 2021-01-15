from lview import *
from time import time

lview_script_info = {
	"script": "Champion Tracker",
	"author": "leryss",
	"description": "Tracks a enemy throughout the map leaving a trail on the minimap. It will track the enemy jungler by default"
}

first_iter = True

champ_ids = []
tracks = {}
tracked_champ_id = 0

seconds_to_track = 3.0
t_last_save_tracks = 0

def lview_load_cfg(cfg):
	global seconds_to_track
	seconds_to_track = cfg.get_float("seconds_to_track", 10)
	
def lview_save_cfg(cfg):
	global seconds_to_track
	cfg.set_float("seconds_to_track", seconds_to_track)
	
def lview_draw_settings(game, ui):
	global tracked_champ_id, seconds_to_track, tracks, champ_ids
	
	seconds_to_track = ui.dragfloat("Seconds to track", seconds_to_track, 0.1, 3, 20)
	tracked_champ_id = ui.listbox("Champion to track", [game.get_obj_by_netid(net_id).name for net_id in champ_ids], tracked_champ_id)
	
def lview_update(game, ui):
	
	global first_iter, champ_ids
	global tracks, tracked_champ_id, seconds_to_track, t_last_save_tracks

	if first_iter:
		first_iter = False
		
		# Populate tracks dict and find jungler to track
		for champ in game.champs:
			if champ.is_ally_to(game.player):
				continue
				
			champ_ids.append(champ.net_id)
			last_idx = len(champ_ids) - 1
			tracks[last_idx] = []
			if champ.get_summoner_spell(SummonerSpellType.Smite) != None:
				tracked_champ_id = last_idx
		
		# If we didnt find a jungler we just track the first champ by default
		if tracked_champ_id == 0:
			tracked_champ_id = 0
	
	if len(tracks) == 0:
		return
	
	now = time()
	if now - t_last_save_tracks > 0.4:
		t_last_save_tracks = now
		for idx, track in tracks.items():
			champ = game.get_obj_by_netid(champ_ids[idx])
			if champ and champ.is_alive:
				tracks[idx].append((Vec3(champ.pos.x, champ.pos.y, champ.pos.z), now))
				tracks[idx] = list(filter(lambda t: now - t[1] < seconds_to_track, tracks[idx]))
		
	for i, (pos, t) in enumerate(tracks[tracked_champ_id]):
		x = i/len(tracks[tracked_champ_id]) 
		green = (1-2*(x-0.5)/1.0 if x > 0.5 else 1.0);
		red = (1.0 if x > 0.5 else 2*x/1.0);

		p = game.world_to_minimap(pos)
		game.draw_circle_filled(p, 4, 4, Color(red, green, 0.0, 1.0))
		