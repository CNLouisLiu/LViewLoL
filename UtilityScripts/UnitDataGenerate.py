import os, json
from pprint import pprint

unit_data_folder = 'unit_data'
pattern_header = '''
#pragma once
#include <map>
#include <string>
#include <bitset>
#include <array>

// Generated automatically
struct UnitInfo {{

public:
	const char* name;
	float healthBarHeight;
	float baseMovementSpeed;
	float baseAttackRange;
	float baseAttackSpeed;
	float attackSpeedRatio;
	
	float acquisitionRange;
	float selectionRadius;
	float pathRadius;
	float gameplayRadius;
	
	float basicAttackMissileSpeed;
	
	std::bitset<128> tags;
public:	
	static std::map<std::string, UnitInfo*> infos;
}};

enum UnitTag {{
{}
}};
'''

pattern_cpp = '''
#include "UnitInfo.h"

// Generated automatically
std::map<std::string, UnitInfo*> UnitInfo::infos = {{
{{ std::string("unknown"), new UnitInfo() }},
{}
}};

'''

pattern_item = '''
{{ std::string("{}"), 
  new UnitInfo(
  {{{}
  }})
}},\n
'''

def find_key_ending_with(dictionary, partial_key):
	for key, val in dictionary.items():
		if key.endswith(partial_key):
			return val
	return None
	
objs = []
	
infos = ''
unit_tags = set()
for fname in os.listdir(unit_data_folder):
	print("Processing: "+ fname)
	if fname.startswith(('brush_', 'nexusblitz_', 'slime_', 'tft4_', 'tft_')):
		print('Object blacklisted. Skipping...')
		continue
		
	props = {}
	with open(os.path.join(unit_data_folder, fname)) as file:
		props = json.loads(file.read())
	
	root = find_key_ending_with(props, '/Root')	
	if not root:
		print('[Fail] No root found for: ' + fname)
		continue
	
	name = root.get('mCharacterName', '')
	if len(name) == 0:
		print('[Fail] No character name found for: ' + fname)
		continue
		
	missile_speed = 0.0
	basic_attack = find_key_ending_with(props, name + "BasicAttack")
	if basic_attack != None:
		spell = basic_attack.get('mSpell', None)
		if spell:
			missile_speed = spell.get("missileSpeed", 0.0)

	tags = set(['Unit_' + x.strip().replace('=', '_') for x in root.get("unitTagsString", "").split('|')])
	if '' in tags:
		tags.remove('')
	
	if 'Unit_Champion_Clone' in tags:
		objs.append(name)
	
	unit = f'''
       /* name                 */      "{name.lower()}",                                           
       /* healthBarHeight      */      {root.get("healthBarHeight", 0.0)},                   
       /* baseMoveSpeed        */      {root.get("baseMoveSpeed", 0.0)},                     
       /* attackRange          */      {root.get("attackRange", 0.0)},                       
       /* attackSpeed          */      {root.get("attackSpeed", 0.0)},                       
       /* attackSpeedRatio     */      {root.get("attackSpeedRatio", 0.0)},                  
                                                                            
       /* acquisitionRange     */      {root.get("acquisitionRange", 0.0)},                  
       /* selectionRadius      */      {root.get("selectionRadius", 0.0)},            
       /* pathRadius           */      {root.get("pathfindingCollisionRadius", 0.0)},        
       /* gameplayRadius       */      {root.get("overrideGameplayCollisionRadius", 65.0)},
       
       /* basicAtkMissileSpeed */      {missile_speed},
	   /* tags                 */      std::bitset<128>(){''.join(['.set(' + tag + ')' for tag in tags])}'''
	
	infos += pattern_item.format(name.lower(), unit)
	unit_tags = unit_tags.union(tags)

tag_str = ''
for i, tag in enumerate(sorted(unit_tags)):
	tag_str += f'   {tag} = {i + 1},\n'
	

with open("UnitInfo.h", 'w') as f:
	f.write(pattern_header.format(tag_str))
	
with open("UnitInfo.cpp", 'w') as f:
	f.write(pattern_cpp.format(infos))
	
pprint(objs)
