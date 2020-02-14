#pragma once
#include "TileSet.h"
#include <map>

class TileSetManager {
public:
	TileSetManager();
	void addTileSet(std::string& m_name, TileSet& m_tileSet);
	std::optional<TileSet> getTileSet(std::string& m_tileSetName); 
private:
	std::map<std::string, TileSet> tileSets;
};