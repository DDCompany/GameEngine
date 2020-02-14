#pragma once
#include <string>
#include "SFML\Graphics.hpp"
#include "TileSetManager.h"

class GameObject
{
public:
	GameObject();
	~GameObject();

	virtual void draw(time_t time, sf::RenderWindow& m_window) = 0;
};

