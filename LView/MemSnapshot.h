#pragma once
#include <vector>
#include <set>
#include <map>
#include "Benchmark.h"
#include "Champion.h"
#include "GameRenderer.h"
#include "GameObject.h"

struct MemSnapshot {

	/* Lists of objects by category */
	std::vector<Champion*>      champions;
	std::vector<GameObject*>    minions;
	std::vector<GameObject*>    jungle;
	std::vector<GameObject*>    turrets;
	std::vector<GameObject*>    others;

	/* A map between the indexObject member of the object and the object itself */
	std::map<int, GameObject*>  idxToObjectMap;
	/* Used to clear idxToObjectMap for objects that are no longer in game */
	std::set<int>               updatedThisFrame;

	/* The champion of the player running the app */
	Champion*                            localChampion = nullptr;
	/* The object below the mouse */
	GameObject*                          hoveredObject = nullptr;

	/* Game renderer info */
	GameRenderer*                        renderer = new GameRenderer();

	/* How many seconds have elapsed since the game started */
	float                                gameTime = 0.f;
	
	ReadBenchmark*                       benchmark = new ReadBenchmark();

};