#include "LeagueMemoryReader.h"
#include "windows.h"
#include "Utils.h"
#include "Structs.h"
#include "psapi.h"
#include <limits>
#include <stdexcept>

LeagueMemoryReader::LeagueMemoryReader()
{
	// Some trash object not worth reading
	blacklistedObjectNames.insert("testcube");
	blacklistedObjectNames.insert("testcuberender");
	blacklistedObjectNames.insert("testcuberender10vision");
	blacklistedObjectNames.insert("s5test_wardcorpse");
	blacklistedObjectNames.insert("sru_camprespawnmarker");
	blacklistedObjectNames.insert("sru_plantrespawnmarker");
	blacklistedObjectNames.insert("preseason_turret_shield");
}

bool LeagueMemoryReader::IsLeagueWindowActive() {
	HWND handle = GetForegroundWindow();

	DWORD h;
	GetWindowThreadProcessId(handle, &h);
	return pid == h;
}

bool LeagueMemoryReader::IsHookedToProcess() {
	return Process::IsProcessRunning(pid);
}

void LeagueMemoryReader::HookToProcess() {

	// Find the window
	hWindow = FindWindowA("RiotWindowClass", NULL);
	if (hWindow == NULL) {
		throw WinApiException("League window not found");
	}

	// Get the process ID
	GetWindowThreadProcessId(hWindow, &pid);
	if (pid == NULL) {
		throw WinApiException("Couldn't retrieve league process id");
	}

	// Open the process
	hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
	if (hProcess == NULL) {
		throw WinApiException("Couldn't open league process");
	}

	// Check architecture
	if (0 == IsWow64Process(hProcess, &is64Bit)) {
		throw WinApiException("Failed to identify if process has 32 or 64 bit architecture");
	}

	HMODULE hMods[1024];
	DWORD cbNeeded;
	if (EnumProcessModules(hProcess, hMods, sizeof(hMods), &cbNeeded)) {
		moduleBaseAddr = (DWORD_PTR)hMods[0];
	}
	else {
		throw WinApiException("Couldn't retrieve league base address");
	}

	blacklistedObjects.clear();
}


void LeagueMemoryReader::ReadRenderer(MemSnapshot& ms) {
	high_resolution_clock::time_point readTimeBegin;
	duration<float, std::milli> readDuration;
	readTimeBegin = high_resolution_clock::now();
	
	DWORD rendererAddr = Mem::ReadDWORD(hProcess, moduleBaseAddr + Offsets::Renderer);
	ms.renderer->LoadFromMem(rendererAddr, moduleBaseAddr, hProcess);

	readDuration = high_resolution_clock::now() - readTimeBegin;
	ms.benchmark->readRendererMs = readDuration.count();
}

void LeagueMemoryReader::FindHoveredObject(MemSnapshot& ms) {
	
	int addrObj = Mem::ReadDWORD(hProcess, moduleBaseAddr + Offsets::UnderMouseObject);
	int netId = Mem::ReadDWORD(hProcess, addrObj + Offsets::ObjNetworkID);
	
	auto it = ms.objectMap.find(netId);
	if (it != ms.objectMap.end())
		ms.hoveredObject = it->second;
	else
		ms.hoveredObject = nullptr;
}

///		This method reads the game objects from memory. It reads the tree structure of a std::map<int, GameObject*>
/// in this std::map reside Champions, Minions, Turrets, Missiles, Jungle mobs etc. Basically non static objects.
void LeagueMemoryReader::ReadObjects(MemSnapshot& ms) {

	static const int maxObjects = 500;
	static int pointerArray[maxObjects];

	high_resolution_clock::time_point readTimeBegin;
	duration<float, std::milli> readDuration;
	readTimeBegin = high_resolution_clock::now();

	ms.champions.clear();
	ms.minions.clear();
	ms.jungle.clear();
	ms.missiles.clear();
	ms.turrets.clear();
	ms.others.clear();

	int objectManager = Mem::ReadDWORD(hProcess, moduleBaseAddr + Offsets::ObjectManager);
	
	static char buff[0x500];
	Mem::Read(hProcess, objectManager, buff, 0x100);

	int numMissiles, rootNode;
	memcpy(&numMissiles, buff + Offsets::ObjectMapCount, sizeof(int));
	memcpy(&rootNode, buff + Offsets::ObjectMapRoot, sizeof(int));

	std::queue<int> nodesToVisit;
	std::set<int> visitedNodes;
	nodesToVisit.push(rootNode);

	// Read object pointers from tree
	int nrObj = 0;
	int reads = 0;
	int childNode1, childNode2, childNode3, node;
	while (reads < maxObjects && nodesToVisit.size() > 0) {
		node = nodesToVisit.front();
		nodesToVisit.pop();
		if (visitedNodes.find(node) != visitedNodes.end())
			continue;

		reads++;
		visitedNodes.insert(node);
		Mem::Read(hProcess, node, buff, 0x30);

		memcpy(&childNode1, buff, sizeof(int));
		memcpy(&childNode2, buff + 4, sizeof(int));
		memcpy(&childNode3, buff + 8, sizeof(int));

		nodesToVisit.push(childNode1);
		nodesToVisit.push(childNode2);
		nodesToVisit.push(childNode3);

		unsigned int netId = 0;
		memcpy(&netId, buff + Offsets::ObjectMapNodeNetId, sizeof(int));

		// Network ids of the objects we are interested in start from 0x40000000. We do this check for performance reasons.
		if (netId - (unsigned int)0x40000000 > 0x100000) 
			continue;

		int addr;
		memcpy(&addr, buff + Offsets::ObjectMapNodeObject, sizeof(int));
		if (addr == 0)
			continue;

		pointerArray[nrObj] = addr;
		nrObj++;
	}

	// Read objects from the pointers we just read
	for (int i = 0; i < nrObj; ++i) {
		int netId;
		Mem::Read(hProcess, pointerArray[i] + Offsets::ObjNetworkID, &netId, sizeof(int));
		if (blacklistedObjects.find(netId) != blacklistedObjects.end())
			continue;

		std::shared_ptr<GameObject> obj;
		auto it = ms.objectMap.find(netId);
		if (it == ms.objectMap.end()) {
			obj = std::shared_ptr<GameObject>(new GameObject());
			obj->LoadFromMem(pointerArray[i], hProcess, true);
			ms.objectMap[obj->networkId] = obj;
		}
		else {
			obj = it->second;
			obj->LoadFromMem(pointerArray[i], hProcess, false);

			// If the object changed its id for whatever the fuck reason then we update the map with the new index
			if (netId != obj->networkId) {
				ms.objectMap[obj->networkId] = obj;
			}
		}

		if (obj->isVisible) {
			obj->lastVisibleAt = ms.gameTime;
		}

		if (obj->networkId != 0) {
			ms.indexToNetId[obj->objectIndex] = obj->networkId;
			ms.updatedThisFrame.insert(obj->networkId);

			if (obj->name.size() <= 2 || blacklistedObjectNames.find(obj->name) != blacklistedObjectNames.end())
				blacklistedObjects.insert(obj->networkId);
			else if (obj->HasUnitTags(Unit_Champion))
				ms.champions.push_back(obj);
			else if (obj->HasUnitTags(Unit_Minion_Lane))
				ms.minions.push_back(obj);
			else if (obj->HasUnitTags(Unit_Monster))
				ms.jungle.push_back(obj);
			else if (obj->HasUnitTags(Unit_Structure_Turret))
				ms.turrets.push_back(obj);
			else if (obj->spellInfo != GameData::UnknownSpell)
				ms.missiles.push_back(obj);
			else
				ms.others.push_back(obj);
		}
	}

	readDuration = high_resolution_clock::now() - readTimeBegin;
	ms.benchmark->readObjectsMs = readDuration.count();
}

void LeagueMemoryReader::ReadMinimap(MemSnapshot & snapshot) {
	int minimapObj = Mem::ReadDWORD(hProcess, moduleBaseAddr + Offsets::MinimapObject);
	int minimapHud = Mem::ReadDWORD(hProcess, minimapObj + Offsets::MinimapObjectHud);

	static char buff[0x80];
	Mem::Read(hProcess, minimapHud, buff, 0x80);
	memcpy(&snapshot.minimapPos, buff + Offsets::MinimapHudPos, sizeof(Vector2));
	memcpy(&snapshot.minimapSize, buff + Offsets::MinimapHudSize, sizeof(Vector2));
}

void LeagueMemoryReader::FindPlayerChampion(MemSnapshot & snapshot) {
	int netId = 0;
	Mem::Read(hProcess, Mem::ReadDWORD(hProcess, moduleBaseAddr + Offsets::LocalPlayer) + Offsets::ObjNetworkID, &netId, sizeof(int));
	
	auto it = snapshot.objectMap.find(netId);
	if (it != snapshot.objectMap.end())
		snapshot.player = it->second;
	else // If we can't find the local player either the offset is wrong or we are watching a replay
		snapshot.player = (snapshot.champions.size() > 0 ? snapshot.champions[0] : nullptr);
}

void LeagueMemoryReader::ClearMissingObjects(MemSnapshot & ms) {
	auto it = ms.objectMap.begin();
	while (it != ms.objectMap.end()) {
		if (ms.updatedThisFrame.find(it->first) == ms.updatedThisFrame.end()) {
			it = ms.objectMap.erase(it);
		}
		else
			++it;
	}
}

void LeagueMemoryReader::MakeSnapshot(MemSnapshot& ms) {
	
	Mem::Read(hProcess, moduleBaseAddr + Offsets::GameTime, &ms.gameTime, sizeof(float));

	if (ms.gameTime > 2) {
		ms.updatedThisFrame.clear();
		ReadRenderer(ms);
		ReadMinimap(ms);
	    ReadObjects(ms);
		ClearMissingObjects(ms);
		FindPlayerChampion(ms);
		FindHoveredObject(ms);

		ms.map = std::shared_ptr<MapObject>(MapObject::Get(ms.turrets.size() > 10 ? SUMMONERS_RIFT : HOWLING_ABYSS));
	}
}