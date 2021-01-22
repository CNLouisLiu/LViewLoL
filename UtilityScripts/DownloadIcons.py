'''
	Utility scripts that scraps icons from the latest communitydragon data file dump.
'''

import sys, urllib.request, re, time, os
from pprint import pprint

headers = {}
headers['User-Agent'] = "Mozilla/5.0 (X11; Linux i686) AppleWebKit/537.17 (KHTML, like Gecko) Chrome/24.0.1312.27 Safari/537.17"
result_folder = 'icons_spells'
pattern_item = '<a href="[\w\.]+/?" title="[\w\.]+">([\w\.]+)/?</a>'

def download_icons(url, f_filter = lambda x: True):
	global headers, result_folder
	
	print('Requesting: ' + url)
	req = urllib.request.Request(url, headers = headers)
	page = urllib.request.urlopen(req).read().decode('utf-8')
	icons = filter(lambda n: n.endswith('.png'), re.findall(pattern_item, page))
	icons = filter(f_filter, icons)
	
	for icon in icons:
		print('Downloading: ' + icon)
		req = urllib.request.Request(url + icon, headers = headers)
		icon_bin = urllib.request.urlopen(req).read()
		with open(os.path.join(result_folder, icon), 'wb') as file:
			file.write(icon_bin)
			
		time.sleep(0.02)

def read_character_icons(url_characters, url_character_icons, f_filter = lambda x: True):
	global headers, result_folder, pattern_item
	
	failed = []
	
	print('Requesting: ' +  url_characters)
	req = urllib.request.Request(url_characters, headers = headers)
	page = urllib.request.urlopen(req).read().decode('utf-8')
	characters = re.findall(pattern_item, page)
	for character in characters:
		try:
			url = url_character_icons.format(character)
			download_icons(url, f_filter)
			
		except Exception as e:
			print('Failed to retrieve data for {}. ({})'.format(character, str(e)))
			failed.append(character)
		time.sleep(0.05)
		
	print('Error retrieving following icons:')
	pprint(failed)

def read_other_icons():
	global headers, result_folder, pattern_item
	
	url = 'https://raw.communitydragon.org/latest/game/data/spells/icons2d/'
	download_icons(url)
	
if not os.path.isdir(result_folder):
	os.mkdir(result_folder)
		
		
# Read champion icons
#x = 'https://raw.communitydragon.org/latest/game/assets/characters/'
#y = 'https://raw.communitydragon.org/latest/game/assets/characters/{}/hud/'
#read_character_icons(x, y, lambda x: 'square' in x)

download_icons('https://raw.communitydragon.org/latest/game/assets/characters/viego/hud/icons2d/')