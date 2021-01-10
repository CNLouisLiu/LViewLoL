import os, json
from pprint import pprint

def find_key_ending_with(dictionary, partial_key):
	for key, val in dictionary.items():
		if key.endswith(partial_key):
			return val
	return None
	
objs, spells = [], []
infos = ''
unit_tags = set()
unit_data_folder = 'unit_data'

for fname in os.listdir(unit_data_folder):
	print("Processing: "+ fname)
	if fname.startswith(('brush_', 'nexusblitz_', 'slime_', 'tft4_', 'tft_')):
		print('Object blacklisted. Skipping...')
		continue
		
	props = {}
	with open(os.path.join(unit_data_folder, fname)) as file:
		props = json.loads(file.read())
	
	# Find character property node
	root = find_key_ending_with(props, '/Root')	
	if not root:
		print('[Fail] No root found for: ' + fname)
		continue
	
	# Get character name
	name = root.get('mCharacterName', '')
	if len(name) == 0:
		print('[Fail] No character name found for: ' + fname)
		continue
		
	# Get basic attack info
	missile_speed = 0.0
	windup = 0.0
	basic_attack = find_key_ending_with(props, name + "BasicAttack")
	if basic_attack != None:
		spell = basic_attack.get('mSpell', None)
		if spell:
			missile_speed = spell.get("missileSpeed", 0.0)
	if 'basicAttack' in root:
		basic_attack = root['basicAttack']
		if 'mAttackTotalTime' in basic_attack and 'mAttackCastTime' in basic_attack:
			windup = basic_attack['mAttackCastTime']/basic_attack['mAttackTotalTime']
		else:
			windup = 0.3 + basic_attack.get('mAttackDelayCastOffsetPercent', 0.0)

	tags = set(['Unit_' + x.strip().replace('=', '_') for x in root.get("unitTagsString", "").split('|')])
	objs.append({
		"name":             name.lower(),
		"healthBarHeight":  root.get("healthBarHeight", 100.0),
		"baseMoveSpeed":    root.get("baseMoveSpeed", 0.0),
		"attackRange":      root.get("attackRange", 0.0),
		"attackSpeed":      root.get("attackSpeed", 0.0), 
		"attackSpeedRatio": root.get("attackSpeedRatio", 0.0), 
		"acquisitionRange": root.get("acquisitionRange", 0.0),
		"selectionRadius":  root.get("selectionRadius", 0.0),
		"pathingRadius":    root.get("pathfindingCollisionRadius", 0.0),
		"gameplayRadius":   root.get("overrideGameplayCollisionRadius", 65.0),
		"basicAtkMissileSpeed": missile_speed,
		"basicAtkWindup": windup,
		"tags": list(tags)
		
	})
	
	for key, val in props.items():
		if "mSpell" not in val:
			continue
		
		s = val["mSpell"]
		if s:
			icon_name = os.path.basename(s.get("mImgIconName", [""])[0]).replace(".dds", "")
			spell = {
				"name": os.path.basename(key),
				"icon": icon_name,
				"affectsTypesFlags": s.get("mAffectsTypeFlags", 0),
				"delay": 0.5 + 0.5*s.get("delayCastOffsetPercent", 0.0),
				"range": s.get("castRangeDisplayOverride", s.get("castRange", [0.0]))[0],
				"radius": 0.0,
				"height": 0.0,
				"speed": 0.0,
				"targeted": s.get("mCastType", 0) == 1
			}
			
			missile = s.get("mMissileSpec", None)
			if missile:
				spell["radius"] = missile.get("mMissileWidth", 0.0)
				movcomp = missile.get("movementComponent", None)
				if movcomp:
					spell["height"] = movcomp.get("mOffsetInitialTargetHeight", 100.0)
					spell["speed"] = movcomp.get("mSpeed", 0.0)
					
			
			spells.append(spell)
			
print(f'Found {len(objs)} units and {len(spells)} spells')
with open("UnitData.json", 'w') as f:
	f.write(json.dumps(objs, indent=4))
	
with open("SpellData.json", 'w') as f:
	f.write(json.dumps(spells, indent=4))
	