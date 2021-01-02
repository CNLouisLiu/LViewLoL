#include "LeagueMemoryReader.h"
#include "windows.h"
#include "Utils.h"
#include "Structs.h"
#include "psapi.h"
#include "Missile.h"
#include <limits>
#include <stdexcept>

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

void LeagueMemoryReader::ReadChampions(MemSnapshot& ms) {
	high_resolution_clock::time_point readTimeBegin;
	duration<float, std::milli> readDuration;
	readTimeBegin = high_resolution_clock::now();

	ReadGameObjectList<Champion>(ms.champions, numMaxChamps, Offsets::HeroList, 0x8, 0x4, ms);

	readDuration = high_resolution_clock::now() - readTimeBegin;
	ms.benchmark->readChampsMs = readDuration.count();
}

void LeagueMemoryReader::ReadTurrets(MemSnapshot& ms) {
	high_resolution_clock::time_point readTimeBegin;
	duration<float, std::milli> readDuration;
	readTimeBegin = high_resolution_clock::now();

	ReadGameObjectList<GameObject>(ms.turrets, numMaxTurrets, Offsets::TurretList, 0x8, 0x4, ms);
	for (auto it = ms.turrets.begin(); it != ms.turrets.end(); ++it) {
		auto obj = *it;
		obj->type = GameObjectType::TURRET;
		obj->targetRadius = 100.f;
		obj->baseAttackRange = 850.f;
	}

	readDuration = high_resolution_clock::now() - readTimeBegin;
	ms.benchmark->readTurretsMs = readDuration.count();
}

void LeagueMemoryReader::ReadMobs(MemSnapshot& ms) {
	high_resolution_clock::time_point readTimeBegin;
	duration<float, std::milli> readDuration;
	readTimeBegin = high_resolution_clock::now();

	ReadGameObjectList<GameObject>(ms.others, numMaxMobs, Offsets::MinionList, 0x8, 0x4, ms);

	// Filter minions e.g wards, jungle, minions etc
	ms.minions.clear();
	ms.jungle.clear();
	auto it = ms.others.begin();
	while (it != ms.others.end()) {
		auto obj = *it;
		GameObjectType type = obj->type;
		if (type & GameObjectType::JUNGLE) {
			ms.jungle.push_back(obj);
			it = ms.others.erase(it);
		}
		else if (type & GameObjectType::MINION) {
			ms.minions.push_back(obj);
			it = ms.others.erase(it);
		}
		else
			++it;
	}

	readDuration = high_resolution_clock::now() - readTimeBegin;
	ms.benchmark->readMobsMs = readDuration.count();
}

std::shared_ptr<GameObject> LeagueMemoryReader::FindHoveredObject(MemSnapshot& ms) {
	
	Vector2 cursorPos = Input::GetCursorPosition();
	float minDistance = std::numeric_limits<float>::infinity();
	float distance;
	std::shared_ptr<GameObject> hoveredObject = nullptr;

	for (auto it = ms.idxToObjectMap.begin(); it != ms.idxToObjectMap.end(); ++it) {
		distance = League::Distance(cursorPos, ms.renderer->WorldToScreen(it->second->position));
		if (distance < minDistance && distance < it->second->targetRadius) {
			hoveredObject = it->second;
			minDistance = distance;
		}
	}

	return hoveredObject;
}


void LeagueMemoryReader::ReadMissiles(MemSnapshot& ms) {

	high_resolution_clock::time_point readTimeBegin;
	duration<float, std::milli> readDuration;
	readTimeBegin = high_resolution_clock::now();

	ms.missiles.clear();
	int missileMap = Mem::ReadDWORD(hProcess, moduleBaseAddr + Offsets::MissileMap);
	
	static char buff[0x500];
	Mem::Read(hProcess, missileMap, buff, 0x100);

	int numMissiles, rootNode;
	memcpy(&numMissiles, buff + Offsets::MissileMapCount, sizeof(int));
	memcpy(&rootNode, buff + Offsets::MissileMapRoot, sizeof(int));

	std::queue<int> nodesToVisit;
	std::set<int> visitedNodes;
	nodesToVisit.push(rootNode);

	int childNode1, childNode2, childNode3, node;
	while (nodesToVisit.size() > 0 && visitedNodes.size() < numMissiles*2) {	
		node = nodesToVisit.front();
		nodesToVisit.pop();
		visitedNodes.insert(node);

		Mem::Read(hProcess, node, buff, 0x50);
		memcpy(&childNode1, buff, sizeof(int));
		memcpy(&childNode2, buff + 4, sizeof(int));
		memcpy(&childNode3, buff + 8, sizeof(int));

		if (visitedNodes.find(childNode1) == visitedNodes.end())
			nodesToVisit.push(childNode1);
		if (visitedNodes.find(childNode2) == visitedNodes.end())
			nodesToVisit.push(childNode2);
		if (visitedNodes.find(childNode3) == visitedNodes.end())
			nodesToVisit.push(childNode3);

		unsigned int netId = 0;
		memcpy(&netId, buff + Offsets::MissileMapKey, sizeof(int));

		// Actual missiles net_id start from 0x40000000. So we use this to check if missiles are valid
		//if (netId - (unsigned int)0x40000000 > 0x100000) 
		//	continue;

		int addr;
		memcpy(&addr, buff + Offsets::MissileMapVal, sizeof(int));
		if (addr == 0)
			continue;

		addr = Mem::ReadDWORD(hProcess, addr + 0x4);
		if (addr == 0)
			continue;
		
		addr = Mem::ReadDWORD(hProcess, addr + 0x10);
		if (addr == 0)
			continue;

		auto m = std::unique_ptr<Missile>(new Missile());
		m->LoadFromMem(addr, hProcess);

		// Check one more time that we read a valid missile
		if (m->networkId != netId)
			continue;

		ms.missiles.push_back(std::move(m));
	}

	readDuration = high_resolution_clock::now() - readTimeBegin;
	ms.benchmark->readMissilesMs = readDuration.count();
}

void LeagueMemoryReader::MakeSnapshot(MemSnapshot& ms) {
	
	Mem::Read(hProcess, moduleBaseAddr + Offsets::GameTime, &ms.gameTime, sizeof(float));

	if (ms.gameTime > 2) {
		ms.updatedThisFrame.clear();

		ReadChampions(ms);
		ReadRenderer(ms);
		ReadMobs(ms);
		ReadTurrets(ms);
	    ReadMissiles(ms);

		ms.localChampion = ms.champions[0];

		// Clear up objects that were deleted in game
		auto it = ms.idxToObjectMap.begin();
		while (it != ms.idxToObjectMap.end()) {
			if (ms.updatedThisFrame.find(it->first) == ms.updatedThisFrame.end()) {
				it = ms.idxToObjectMap.erase(it);
			}
			else
				++it;
		}

		ms.hoveredObject = FindHoveredObject(ms);
	}
}