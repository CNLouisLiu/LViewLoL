from lview import *
import time, json

lview_script_info = {
	"script": "Orbwalker",
	"author": "leryss",
	"description": "Automatically kites enemies"
}

default_windups = {"Aatrox": 19.74, "Ahri": 20.05, "Akali": 13.9, "Alistar": 30.0, "Amumu": 23.38, "Anivia": 20.0, "Annie": 19.58, "Aphelios": 15.33, "Ashe": 21.93, "Aurelion Sol": 20.0, "Azir": 15.63, "Bard": 18.75, "Blitzcrank": 27.0, "Brand": 18.75, "Braum": 23.0, "Caitlyn": 17.71, "Camille": 19.33, "Cassiopeia": 19.2, "Cho'Gath": 21.9, "Corki": 10.0, "Darius": 20.0, "Diana": 20.83, "Dr. Mundo": 16.03, "Draven": 15.61, "Ekko": 16.25, "Elise": 18.75, "Evelynn": 15.33, "Ezreal": 18.84, "Fiddlesticks": 30.0, "Fiora": 13.79, "Fizz": 20.3, "Galio": 20.63, "Gangplank": 16.45, "Garen": 18.0, "Gnar": 14.6, "Gragas": 25.0, "Graves": 0.5, "Hecarim": 25.0, "Heimerdinger": 20.08, "Illaoi": 21.43, "Irelia": 19.67, "Ivern": 23.0, "Janna": 22.0, "Jarvan IV": 17.54, "Jax": 20.81, "Jayce": 9.5, "Jhin": 15.63, "Jinx": 16.88, "Kai'Sa": 16.11, "Kalista": 36.0, "Karma": 16.15, "Karthus": 34.38, "Kassadin": 15.0, "Katarina": 15.0, "Kayle": 19.36, "Kayn": 18.73, "Kennen": 20.0, "Khazix": 20.05, "Kindred": 17.54, "Kled": 17.5, "Kled & Skaarl": 17.5, "Kog'Maw": 16.62, "LeBlanc": 16.67, "Lee Sin": 19.53, "Leona": 22.92, "Lillia": 14.71, "Lissandra": 18.75, "Lucian": 15.0, "Lulu": 18.75, "Lux": 15.63, "Malphite": 24.97, "Malzahar": 19.0, "Maokai": 30.0, "Master Yi": 24.38, "Mega Gnar": 14.6, "MissFortune": 14.8, "Mordekaiser": 21.13, "Morgana": 14.0, "Nami": 18.0, "Nasus": 20.14, "Nautilus": 30.64, "Neeko": 21.48, "Nidalee": 15.0, "Nocturne": 20.05, "Nunu & Willump": 19.36, "Olaf": 23.44, "Orianna": 17.54, "Ornn": 21.88, "Pantheon": 19.03, "Poppy": 23.44, "Pyke": 20.0, "Qiyana": 15.33, "Quinn": 17.54, "Rakan": 17.14, "Rammus": 22.92, "Rek'Sai": 26.67, "Rell": 42.0, "Renekton": 17.73, "Rengar": 20.0, "Riven": 16.67, "Rumble": 22.92, "Ryze": 20.0, "Samira": 15.0, "Sejuani": 18.75, "Senna": 31.25, "Seraphine": 18.7, "Sett": 21.43, "Shaco": 22.15, "Shen": 17.36, "Shyvana": 19.74, "Singed": 23.62, "Sion": 24.91, "Sivir": 12.0, "Skarner": 18.0, "Sona": 17.18, "Soraka": 18.7, "Swain": 14.0, "Sylas": 16.77, "Syndra": 18.75, "Tahm Kench": 25.02, "Taliyah": 16.15, "Talon": 12.38, "Taric": 18.0, "Teemo": 21.57, "Thresh": 23.96, "Tristana": 14.8, "Trundle": 20.83, "Tryndamere": 19.0, "Twisted Fate": 24.4, "Twitch": 20.19, "Udyr": 19.84, "Urgot": 15.0, "Varus": 17.54, "Vayne": 17.54, "Veigar": 19.09, "Vel'Koz": 20.0, "Vi": 22.5, "Viktor": 18.0, "Vladimir": 19.74, "Volibear": 30.0, "Warwick": 17.5, "Monkeyking": 20.83, "Xayah": 17.69, "Xerath": 25.07, "Xin Zhao": 18.71, "Yasuo": 22.0, "Yone": 22.0, "Yorick": 20.63, "Yuumi": 15.63, "Zac": 23.15, "Zed": 19.76, "Ziggs": 20.83, "Zilean": 18.0, "Zoe": 16.15, "Zyra": 14.58}
windups = {}
last_attacked = 0
last_moved = 0
last_action_attacked = False

key_attack_move = 0
key_orbwalk = 0
max_atk_speed = 0
auto_last_hit = False

def lview_load_cfg(cfg):
	global windups, key_attack_move, key_orbwalk, max_atk_speed, auto_last_hit
	
	windups = json.loads(cfg.get_str("windups", json.dumps(default_windups)))
	key_attack_move = cfg.get_int("key_attack_move", 0)	
	key_orbwalk = cfg.get_int("key_orbwalk", 0)	
	max_atk_speed = cfg.get_float("max_atk_speed", 2.0)
	auto_last_hit = cfg.get_bool("auto_last_hit", False)
	
def lview_save_cfg(cfg):
	global windups, key_attack_move, key_orbwalk, max_atk_speed, auto_last_hit
	
	cfg.set_str("windups", json.dumps(windups))
	cfg.set_int("key_attack_move", key_attack_move)
	cfg.set_int("key_orbwalk", key_orbwalk)
	cfg.set_float("max_atk_speed", max_atk_speed)
	cfg.set_bool("auto_last_hit", auto_last_hit)
	
def lview_draw_settings(game, ui):
	global windups, key_attack_move, key_orbwalk, max_atk_speed, auto_last_hit
	
	champ_name = game.local_champ.name
	
	if ui.button("Set defaut windup"):
		windups[champ_name] = default_windups[champ_name]
	windups[champ_name] = ui.sliderfloat(f"Windup percent ({champ_name})", windups[champ_name], 10, 60)
	
	max_atk_speed = ui.sliderfloat("Max attack speed", max_atk_speed, 1.5, 3.0)
	key_attack_move = ui.keyselect("Attack move key", key_attack_move)
	key_orbwalk = ui.keyselect("Orbwalk activate key", key_orbwalk)
	auto_last_hit = ui.checkbox("Auto last hit minions (No Prediction)", auto_last_hit)
	
def is_last_hitable(player, enemy):
	hit_dmg = player.get_basic_phys(enemy) + player.get_basic_magic(enemy)
	return enemy.health - hit_dmg <= 0
	
def find_champ_target(game, array, value_extractor):
	atk_range = game.local_champ.base_atk_range + game.local_champ.gameplay_radius
	target = None
	min = 99999999
	for obj in array:
		
		if obj.is_ally_to(game.local_champ) or game.distance(game.local_champ, obj) > atk_range:
			continue
			
		val = value_extractor(game.local_champ, obj)
		if val < min:
			min = val
			target = obj
	
	return target
	
def find_minion_target(game):
	atk_range = game.local_champ.base_atk_range + game.local_champ.gameplay_radius
	for minion in game.minions:
		if minion.is_enemy_to(game.local_champ) and minion.is_alive and game.distance(game.local_champ, minion) < atk_range and is_last_hitable(game.local_champ, minion):
			return minion
	return None
	
def get_target(game):
	global auto_last_hit
	
	target = find_champ_target(game, game.champs, lambda l, e: e.health)
	if not target and auto_last_hit:
		return find_minion_target(game)
	
	return target

def lview_update(game, ui):
	global windups, last_attacked, alternate, last_moved, last_action_attacked
	global key_attack_move, key_orbwalk, max_atk_speed
	
	if not game.is_key_down(key_orbwalk):
		return
	
	windups_norm = windups[game.local_champ.name]/100
	self = game.local_champ
	
	atk_speed = self.base_atk_speed * self.atk_speed_multi
	b_windup_time = (1.0/self.base_atk_speed)*windups_norm
	c_atk_time = 1.0/atk_speed
	max_atk_time = 1.0/max_atk_speed

	t = time.time()
	if t - last_attacked > max(c_atk_time, max_atk_time):
		last_attacked = t
		last_action_attacked = True
		target = get_target(game)
		if target:
			game.press_key(key_attack_move)
			game.click_at(True, game.world_to_screen(target.pos))
	else:
		dt = t - last_attacked
		if dt > b_windup_time and t - last_moved > 0.15:
			last_moved = t
			last_action_attacked = False
			game.press_right_click()
		
		
	
	