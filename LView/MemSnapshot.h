#pragma once
#include <vector>
#include <set>
#include <map>
#include "Benchmark.h"
#include "GameRenderer.h"
#include "GameObject.h"
#include "MapObject.h"

struct MemSnapshot {

	/* Lists of objects by category */
	std::vector<std::shared_ptr<GameObject>>      champions;
	std::vector<std::shared_ptr<GameObject>>      minions;
	std::vector<std::shared_ptr<GameObject>>      jungle;
	std::vector<std::shared_ptr<GameObject>>      turrets;
	std::vector<std::shared_ptr<GameObject>>      others;

	std::vector<std::shared_ptr<GameObject>>      missiles;

	/* A map between the indexObject member of the object and the object itself */
	std::map<short, std::shared_ptr<GameObject>>  idxToObjectMap;
	/* Used to clear idxToObjectMap for objects that are no longer in game */
	std::set<short>                               updatedThisFrame;

	/* The champion of the player running the app */
	std::shared_ptr<GameObject>                   localChampion = nullptr;
	/* The object below the mouse */
	std::shared_ptr<GameObject>                   hoveredObject = nullptr;

	/* Game renderer info */
	std::unique_ptr<GameRenderer>                 renderer = std::unique_ptr<GameRenderer>(new GameRenderer());

	/* How many seconds have elapsed since the game started */
	float                                gameTime = 0.f;
	std::shared_ptr<MapObject>           map;
	
	std::unique_ptr<ReadBenchmark>       benchmark = std::unique_ptr<ReadBenchmark>(new ReadBenchmark());

};