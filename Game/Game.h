#pragma once
#include <vector>
#include "TileSetManager.h"
#include <SFML\Graphics.hpp>
#include "GameObject.h"
#include <chrono>
#include "PlayerEntity.h"

const float MAX_ZOOM = 5.0f;

class Game
{
public:
	Game();
	~Game();

	void init();
	void run();
	void update();
	long long getElapsedMs();
	void setWindowSize(sf::Vector2i& m_size);
	void setViewSize(sf::Vector2f& m_size);
	void setViewSize(sf::Vector2i& m_size);
	void setClearColor(sf::Color& m_color);
	sf::RenderWindow& getWindow();
	TileSetManager& getTileSetManager();
private:
	std::vector<std::shared_ptr<GameObject>> objects;
	std::vector<std::shared_ptr<EntityObject>> entities;
	std::shared_ptr<PlayerEntity> player;
	sf::VideoMode videoMode;
	sf::View view;
	sf::Color clearColor = sf::Color::Black;
	sf::Event event;
	sf::RenderWindow window;
	TileSetManager tileSetManager;
	
	void handleKeyEvent(sf::Event event);
};