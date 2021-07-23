#pragma once
#include <array>
#include <memory>

enum MapType {
	SUMMONERS_RIFT = 0,
	HOWLING_ABYSS  = 1
};

class MapObject {

public:
	/// Loads map data from disk
	void                               Load(const char* heightMapFile);
	
	/// Returns the ground Y coordinate. Uses a preloaded height map.
	float                              GetHeightAt(float x, float z);
	
public:
	MapType type;
	
	static const int                                                SIZE_HEIGHT_MAP = 512;
	static const float                                              HEIGHT_MAP_SIZE_RATIO;
	std::array<std::array<float, SIZE_HEIGHT_MAP>, SIZE_HEIGHT_MAP> heightMap;

	static std::shared_ptr<MapObject>& Get(MapType type);

private:
	static std::array<std::shared_ptr<MapObject>, 2> maps;
};