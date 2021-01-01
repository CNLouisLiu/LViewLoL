from lview import *
from time import time

lview_script_info = {
	"script": "Champion Tracker",
	"author": "leryss",
	"description": "Tracks a enemy throughout the jungle leaving a trail on the minimap. It will track the enemy jungler by default"
}

first_iter = True

trackable_champ_indices = {}
tracked_champ = 0

seconds_to_track = 3.0
tracks = { 0:[],1:[],2:[],3:[],4:[],5:[],6:[],7:[],8:[],9:[],}
t_last_save_tracks = 0

def lview_load_cfg(cfg):
	global seconds_to_track
	seconds_to_track = cfg.get_float("seconds_to_track", 10)
	
def lview_save_cfg(cfg):
	global seconds_to_track
	cfg.set_float("seconds_to_track", seconds_to_track)
	
def lview_draw_settings(game, ui):
	global tracked_champ, trackable_champ_indices, seconds_to_track
	
	seconds_to_track = ui.dragfloat("Seconds to track", seconds_to_track, 0.1, 3, 20)
	tracked_champ = ui.listbox("Champion to track", [game.champs[i].name for i in trackable_champ_indices], tracked_champ)
	
def lview_update(game, ui):
	
	global trackable_champ_indices, first_iter
	global tracks, tracked_champ, seconds_to_track, t_last_save_tracks
	
	if first_iter:
		first_iter = False
		trackable_champ_indices = []
		for i, champ in enumerate(game.champs):
			
			if champ.is_ally_to(game.local_champ):
				continue
				
			trackable_champ_indices.append(i)
			if champ.get_summoner_spell(SummonerSpellType.SMITE) != None:
				tracked_champ = len(trackable_champ_indices) - 1
	
	now = time()
	if now - t_last_save_tracks > 0.2:
		t_last_save_tracks = now
		for i, j in enumerate(trackable_champ_indices):
			champ = game.champs[j]
			if champ.is_alive:
				tracks[i].append((Vec3(champ.pos.x, champ.pos.y, champ.pos.z), now))
				tracks[i] = list(filter(lambda t: now - t[1] < seconds_to_track, tracks[i]))
		
	for i, (pos, t) in enumerate(tracks[tracked_champ]):
		x = i/len(tracks[tracked_champ]) 
		green = (1-2*(x-0.5)/1.0 if x > 0.5 else 1.0);
		red = (1.0 if x > 0.5 else 2*x/1.0);

		p = game.world_to_minimap(pos)
		game.draw_circle_filled(p, 4, 4, Color(red, green, 0.0, 1.0))
		