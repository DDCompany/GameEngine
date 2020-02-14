#include "EntityObject.h"

const float BASE_FRICTION = 0.25;

EntityObject::EntityObject(sf::Vector2f& m_position, std::string m_tileSetName, TileSetManager& m_tileSetManager, std::string m_state)
	: TexturedObject(m_position, m_tileSetName, m_tileSetManager, m_state)
{
}

void EntityObject::update()
{
	this->position.x += this->velocity.x;
	this->position.y += this->velocity.y;

	this->velocity.x = this->velocity.x > 0 ? this->velocity.x - BASE_FRICTION : this->velocity.x + BASE_FRICTION;
	this->velocity.y = this->velocity.y > 0 ? this->velocity.y - BASE_FRICTION : this->velocity.y + BASE_FRICTION;
}

void EntityObject::setVelocityX(float m_value)
{
	this->velocity.x = m_value;
}

void EntityObject::setVelocityY(float m_value)
{
	this->velocity.y = m_value;
}

sf::Vector2f& EntityObject::getVelocity()
{
	return this->velocity;
}
