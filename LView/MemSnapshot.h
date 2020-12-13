#pragma once
#include <vector>
#include <set>
#include <map>
#include "Benchmark.h"
#include "Champion.h"
#include "Renderer.h"
#include "GameObject.h"

struct MemSnapshot {

	/* Lists of objects by category */
	std::vector<Champion*>      champions;
	std::vector<GameObject*>    minions;
	std::vector<GameObject*>    jungle;
	std::vector<GameObject*>    turrets;
	std::vector<GameObject*>    others;

	/* A map between the indexObject member of the object and the object itself */
	std::map<unsigned int, GameObject*>  idxToObjectMap;
	/* Used to clear idxToObjectMap for objects that are no longer in game */
	std::set<unsigned int>               updatedThisFrame;

	Champion*                            localChampion = nullptr;
	GameObject*                          hoveredObject = nullptr;

	Renderer*                            renderer = new Renderer();
	ReadBenchmark*                       benchmark = new ReadBenchmark();
	int			                         numSnapshot = 0;
	float                                gameTime;
};