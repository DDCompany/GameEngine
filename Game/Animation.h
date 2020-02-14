#pragma once
#include <string>
#include <SFML\Graphics\Texture.hpp>
#include <memory>

class Animation
{
public:
	Animation();
	Animation(int m_width, int m_height);
	~Animation();

	const std::shared_ptr<sf::Texture>& getFrameAt(size_t m_index);
	const std::shared_ptr<sf::Texture>& getFrame(time_t m_time);
	void build(std::string& m_fileName, int m_amountOfFramesInLine = 1, int offsetX = 0, int offsetY = 0, int m_lines = 1);
	int getWidth();
	int getHeight();
	int getFramesAmount();
private:
	std::vector<std::shared_ptr<sf::Texture>> frames;
	int width;
	int height;
	int animDelay = 200;
};
