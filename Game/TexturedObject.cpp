#include "TexturedObject.h"

TexturedObject::TexturedObject(sf::Vector2f& m_position, std::string m_tileSetName, TileSetManager& m_tileSetManager, std::string m_state)
	: position(m_position), GameObject()
{
	auto tileSetOpt = m_tileSetManager.getTileSet(m_tileSetName);
	if (tileSetOpt != std::nullopt) {
		this->tileSet = tileSetOpt.value();
	}
	else {
		printf("Invalid tileset name: '%s'", m_tileSetName.c_str());
	}

	this->setState(m_state);
}

void TexturedObject::setState(std::string state)
{
	auto stateOpt = tileSet.getState(state);
	if (stateOpt != std::nullopt) {
		this->animation = stateOpt.value();
	}
	else {
		printf("Invalid state name: '%s'", state.c_str());
	}
}

TileSet& TexturedObject::getTileSet()
{
	return this->tileSet;
}

void TexturedObject::beforeDraw(time_t m_time, sf::RenderWindow& m_window)
{
	this->shape.setSize(sf::Vector2f{ animation.getWidth() + 0.0f, animation.getHeight() + 0.0f });
	this->shape.setTexture(this->getAnimation().getFrame(m_time).get());
}

void TexturedObject::draw(time_t m_time, sf::RenderWindow& m_window)
{
	this->beforeDraw(m_time, m_window);
	this->shape.setPosition(this->position);
	m_window.draw(this->shape);
}

Animation& TexturedObject::getAnimation()
{
	return this->animation;
}
