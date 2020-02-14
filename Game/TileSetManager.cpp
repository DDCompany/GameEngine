#include "TileSetManager.h"
#include <stdexcept>

TileSetManager::TileSetManager()
{
}

void TileSetManager::addTileSet(std::string& m_name, TileSet & m_tileSet)
{
	//TODO: error when already added
	this->tileSets[m_name] = m_tileSet;
}

std::optional<TileSet> TileSetManager::getTileSet(std::string& m_name)
{
	try {
		return std::make_optional(this->tileSets.at(m_name));
	}
	catch (std::out_of_range e) {
		return std::nullopt;
	}
}
