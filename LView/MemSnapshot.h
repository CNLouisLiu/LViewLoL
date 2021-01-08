#pragma once
#include <vector>
#include <set>
#include <map>
#include "Benchmark.h"
#include "GameRenderer.h"
#include "GameObject.h"
#include "MapObject.h"

/// Object encapsulating league's game state
struct MemSnapshot {

	/* Lists of objects by category */
	std::vector<std::shared_ptr<GameObject>>      champions;
	std::vector<std::shared_ptr<GameObject>>      minions;
	std::vector<std::shared_ptr<GameObject>>      jungle;
	std::vector<std::shared_ptr<GameObject>>      turrets;
	std::vector<std::shared_ptr<GameObject>>      missiles;
	std::vector<std::shared_ptr<GameObject>>      others;

	/* A map between the network id of the object and the object itself */
	std::map<int, std::shared_ptr<GameObject>>    objectMap;
	std::map<short, int>                          indexToNetId;

	/* Used to clear objectMap for objects that are no longer in game */
	std::set<int>                                 updatedThisFrame;

	/* The champion of the player running the app */
	std::shared_ptr<GameObject>                   player = nullptr;

	/* The object below the mouse */
	std::shared_ptr<GameObject>                   hoveredObject = nullptr;

	/* Game renderer info */
	std::unique_ptr<GameRenderer>                 renderer = std::unique_ptr<GameRenderer>(new GameRenderer());

	/* How many seconds have elapsed since the game started */
	float                                         gameTime = 0.f;

	/* Stuff about the map the players are currently on */
	std::shared_ptr<MapObject>                    map;
									             
	/* Minimap related stuff */		             
	Vector2                                       minimapPos;
	Vector2                                       minimapSize;
									             
	/* Memory reading benchmarks */	             
	std::unique_ptr<ReadBenchmark>                benchmark = std::unique_ptr<ReadBenchmark>(new ReadBenchmark());

};