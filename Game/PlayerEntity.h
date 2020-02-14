#pragma once
#include "EntityObject.h"

class PlayerEntity : public EntityObject
{
public:
	PlayerEntity(sf::Vector2f& m_position, TileSetManager& m_tileSetManager);

	void draw(time_t m_time, sf::RenderWindow& m_window);
};

