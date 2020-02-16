#include "PlayerEntity.h"

PlayerEntity::PlayerEntity(sf::Vector2f& m_position, TileSetManager& m_tileSetManager)
	: EntityObject(m_position, "player", m_tileSetManager, "top")
{
}

void PlayerEntity::draw(time_t m_time, sf::RenderWindow& m_window)
{
	this->beforeDraw(m_time, m_window);

	this->shape.setPosition(m_window.getView().getCenter());
	m_window.draw(this->shape);
}

Animation& PlayerEntity::getAnimation()
{
	if (this->walkingTop) {
		return this->tileSet.getState("top").value();
	}else if (this->walkingRight) {
		return this->tileSet.getState("right").value();
	}else if (this->walkingLeft) {
		return this->tileSet.getState("left").value();
	}
	else {
		return this->tileSet.getState("bottom").value();
	}
}
