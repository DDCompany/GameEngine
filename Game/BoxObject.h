#pragma once
#include "TexturedObject.h"

class BoxObject :
	public TexturedObject
{
public:
	BoxObject(sf::Vector2f& m_position, TileSetManager& m_tileSetManager);
	~BoxObject();
};

