#pragma once
#include "GameObject.h"

class TexturedObject : public GameObject
{
public:
	TexturedObject(sf::Vector2f& m_position, std::string m_tileSetName, TileSetManager& m_tileSetManager, std::string m_state);
	
	void setState(std::string state);
	TileSet& getTileSet();
	void beforeDraw(time_t m_time, sf::RenderWindow& m_window);
	virtual void draw(time_t m_time, sf::RenderWindow& m_window);
protected:
	sf::Vector2f position;
	Animation animation;
	TileSet tileSet;
	sf::RectangleShape shape;
};

