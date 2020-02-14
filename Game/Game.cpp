#include "Game.h"
#include "BoxObject.h"
#include <iostream>

sf::Vector2i defaultWindowSize(800, 600);

Game::Game()
{
	this->setWindowSize(defaultWindowSize);
	this->setViewSize(defaultWindowSize);
}

Game::~Game() 
{
}

void Game::init()
{
	this->window.create(this->videoMode, "Game");
	this->window.setFramerateLimit(60);
	this->window.setView(view);

	/*ONLY FOR TESTS*/

	TileSet tileSetBox;

	Animation animCactus(33, 39);
	animCactus.build(std::string{ "assets/cactus.png" }, 6);

	Animation animCoin(32, 34);
	animCoin.build(std::string{ "assets/coin.png" }, 6);

	tileSetBox.addState(std::string {"cactus"}, animCactus);
	tileSetBox.addState(std::string{ "coin" }, animCoin);

	/**/

	TileSet tileSetPlayer;

	Animation animPlayerBottom(32, 48);
	animPlayerBottom.build(std::string{ "assets/player.png" }, 4);

	Animation animPlayerLeft(32, 48);
	animPlayerLeft.build(std::string{ "assets/player.png" }, 4, 0, 48);

	Animation animPlayerRight(32, 48);
	animPlayerRight.build(std::string{ "assets/player.png" }, 4, 0, 48 * 2);

	Animation animPlayerTop(32, 48);
	animPlayerTop.build(std::string{ "assets/player.png" }, 4, 0, 48 * 3);

	tileSetPlayer.addState(std::string{ "bottom" }, animPlayerBottom);
	tileSetPlayer.addState(std::string{ "left" }, animPlayerLeft);
	tileSetPlayer.addState(std::string{ "right" }, animPlayerRight);
	tileSetPlayer.addState(std::string{ "top" }, animPlayerTop);

	/**/

	tileSetManager.addTileSet(std::string{ "box" }, tileSetBox);
	tileSetManager.addTileSet(std::string{ "player" }, tileSetPlayer);

	this->entities.push_back(std::make_shared<PlayerEntity>(PlayerEntity{ sf::Vector2f{20.0f, 20.0f}, this->tileSetManager }));

	/**/

	for (size_t i = 0; i < 20; i++)
	{
		BoxObject box{ sf::Vector2f(rand() % 300, rand() % 300), this->tileSetManager };
		box.setState(box.getTileSet().geRandomState());
		this->objects.push_back(std::make_shared<BoxObject>(box));
	}
}

void Game::run()
{
	while (this->window.isOpen()) {
		if (this->window.pollEvent(this->event)) {
			switch (this->event.type) {
			case sf::Event::MouseWheelScrolled:
				std::cout << event.mouseWheelScroll.delta << std::endl;
				this->view.zoom(1 - event.mouseWheelScroll.delta / 0.85); //TODO: add zoom
				this->window.setView(this->view);
				break;
			case sf::Event::Closed:
				this->window.close();
				break;
			case sf::Event::KeyPressed:
				this->handleKeyEvent(event);
				break;
			}
		}

		this->window.clear(this->clearColor);
		this->update();
		this->window.display();
	}
}

void Game::update()
{
	this->view.move(this->entities[0]->getVelocity().x, this->entities[0]->getVelocity().y);
	this->window.setView(this->view);
	std::cout << this->entities[0]->getVelocity().x << std::endl;
	auto elapsedMs = this->getElapsedMs();
	for each (auto object in this->objects)
	{
		object->draw(elapsedMs, this->window);
	}

	for each (auto entity in this->entities)
	{
		entity->draw(elapsedMs, this->window);
		entity->update();
	}
}

long long Game::getElapsedMs()
{
	return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

void Game::setWindowSize(sf::Vector2i& m_size)
{
	this->videoMode.width = m_size.x;
	this->videoMode.height = m_size.y;
}

void Game::setViewSize(sf::Vector2f& m_size)
{
	this->view.setSize(m_size);
	this->view.setCenter(sf::Vector2f{m_size.x / 2, m_size.y / 2});
}

void Game::setViewSize(sf::Vector2i& m_size)
{
	this->setViewSize(sf::Vector2f{m_size.x + 0.0f, m_size.y + 0.0f});
}

void Game::setClearColor(sf::Color& m_color)
{
	this->clearColor = m_color;
}

sf::RenderWindow & Game::getWindow()
{
	return this->window;
}

TileSetManager & Game::getTileSetManager()
{
	return this->tileSetManager;
}

void Game::handleKeyEvent(sf::Event event)
{
	auto player = this->entities[0];

	switch (event.key.code)
	{
	case sf::Keyboard::W:
		std::cout << "W" << std::endl;
		player->setVelocityY(-10.0);
		break;
	case sf::Keyboard::S:
		player->setVelocityY(10.0);
		break;
	default:
		break;
	}
}
