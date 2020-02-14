#pragma once
#include "TexturedObject.h"

class EntityObject :
	public TexturedObject
{
public:
	EntityObject(sf::Vector2f& m_position, std::string m_tileSetName, TileSetManager& m_tileSetManager, std::string m_state);

	void update();
	void setVelocityX(float m_value);
	void setVelocityY(float m_value);
	sf::Vector2f& getVelocity();
private:
	sf::Vector2f velocity;
};

