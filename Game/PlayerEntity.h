#pragma once
#include "EntityObject.h"

class PlayerEntity : public EntityObject
{
public:
	static inline int BASE_SPEED = 5;
	bool walkingTop = false;
	bool walkingDown = false;
	bool walkingLeft = false;
	bool walkingRight = false;
	PlayerEntity(sf::Vector2f& m_position, TileSetManager& m_tileSetManager);

	void draw(time_t m_time, sf::RenderWindow& m_window);
	Animation& getAnimation();
};

