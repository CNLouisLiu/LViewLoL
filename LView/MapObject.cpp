#include "MapObject.h"
#include <fstream>
#include "Utils.h"

std::array<std::shared_ptr<MapObject>, 2> MapObject::maps = std::array<std::shared_ptr<MapObject>, 2>({ nullptr, nullptr });
const float                               MapObject::HEIGHT_MAP_SIZE_RATIO = SIZE_HEIGHT_MAP / 15000.f;

void MapObject::Load(const char* heightMapFile)
{
	std::ifstream input(heightMapFile, std::ios::binary);
	if (!input.is_open())
		throw std::runtime_error("No height_map.bin file");

	for (int i = 0; i < SIZE_HEIGHT_MAP; ++i) {
		input.read((char*)heightMap[i].data(), SIZE_HEIGHT_MAP * sizeof(float));
	}
}

float MapObject::GetHeightAt(float x, float z)
{
	int ix = Clamp( (int)(HEIGHT_MAP_SIZE_RATIO*x), 0, SIZE_HEIGHT_MAP - 1);
	int iz = Clamp( (int)(HEIGHT_MAP_SIZE_RATIO*z), 0, SIZE_HEIGHT_MAP - 1);
	return heightMap[ix][iz];
}

std::shared_ptr<MapObject>& MapObject::Get(MapType type)
{
	if (maps[type] == nullptr) {
		maps[type] = std::shared_ptr<MapObject>(new MapObject());
		maps[type]->type = type;
	}
	return maps[type];
}
