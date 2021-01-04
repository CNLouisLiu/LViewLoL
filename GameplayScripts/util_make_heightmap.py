from lview import *
import json, time, os
from pprint import pformat

lview_script_info = {
	"script": "Util Make Height Map",
	"author": "<author-name>",
	"description": "<script-description>"
}

def lview_load_cfg(cfg):
	pass
	
def lview_save_cfg(cfg):
	pass
	
def lview_draw_settings(game, ui):
	global enable_draw
	if ui.button("Extrapolate"):
		extrapolate()
		
	#if ui.button('Load'):
	#	load()
		
	#if ui.button('Save'):
	#	save()
		
	enable_draw = ui.checkbox("Draw map", enable_draw)

enable_draw    = False
size           = 512
m              = [[0 for i in range(size)] for i in range(size)]

file_name      = ""
time_last_save = 0
first_iter     = True

def extrapolate():
	global m, size
	
	for i in range(1, size - 1):
		for j in range(1, size - 1):
			if m[i][j] != 0:
				continue
				
			neighbours = []
			if m[i - 1][j - 1] != 0:
				neighbours.append(m[i - 1][j - 1])
			if m[i - 1][j] != 0:
				neighbours.append(m[i - 1][j])
			if m[i - 1][j + 1] != 0:
				neighbours.append(m[i - 1][j + 1])
				
			if m[i][j - 1] != 0:
				neighbours.append(m[i][j - 1])
			if m[i][j + 1] != 0:
				neighbours.append(m[i][j + 1])
				
			if m[i + 1][j - 1] != 0:
				neighbours.append(m[i + 1][j - 1])
			if m[i + 1][j] != 0:
				neighbours.append(m[i + 1][j])
			if m[i + 1][j + 1] != 0:
				neighbours.append(m[i + 1][j + 1])
			
			if len(neighbours) > 0:
				m[i][j] = sum(neighbours)/len(neighbours)
				
def save(s):
	global m
	
	with open(s, 'w') as f:
		f.write(json.dumps(m))
		
def load(s):
	global m
	
	if os.path.exists(s):
		with open(s, 'r') as f:
			m = json.loads(f.read())
	
def draw(game):
	global m, size
	
	c = game.local_champ.pos.clone()
	c.scale(size/15000)
	
	window = 50
	cx = int(c.x)
	cz = int(c.z)
	startx = 0 if cx - window < 0 else cx - window
	endx = size if cx + window > size else cx + window
	startz = 0 if cz - window < 0 else cz - window
	endz = size if cz + window > size else cz + window
	
	for i in range(startx, endx):
		for j in range(startz, endz):
			color = Color(0, 0, 0, 0)
			if m[i][j] != 0:
				color = Color(0, (m[i][j] + 300)/400, 0, 0.8)
			p = Vec3(i/size*15000, 0, j/size*15000)
			p2 = Vec3(i/size*15000, 100 + m[i][j], j/size*15000)
			#game.draw_line(game.world_to_screen(p), game.world_to_screen(p2), 2, color)
			#game.draw_circle_world_filled(p2, 10, 5, color)
			
			game.draw_text(game.world_to_screen(p), f'{m[i][j]:.0f}', Color.GREEN)
def lview_update(game, ui):
	global m, size, enable_draw, time_last_save, first_iter
	global file_name
	
	if first_iter:
		first_iter = False
		file_name = "HeightMap_" + str(game.map.type) + ".json"
		load(file_name)
	
	#game.draw_button(game.world_to_screen(game.local_champ.pos), f'{game.height_at(game.local_champ.pos.x, game.local_champ.pos.z):.2f}', Color.WHITE, Color.BLACK)
	
	for champ in game.champs:
		p = champ.pos.clone()
		p.scale(size/15000)
		
		if m[int(p.x)][int(p.z)] == 0:
			m[int(p.x)][int(p.z)] = champ.pos.y
		else:
			m[int(p.x)][int(p.z)] = (champ.pos.y + m[int(p.x)][int(p.z)])/2
	
	if time.time() - time_last_save > 10:
		save(file_name)
		time_last_save = time.time()
	
	if enable_draw:
		draw(game)
	
	