#include "Animation.h"
#include <iostream>

Animation::Animation()
{
}

Animation::Animation(int m_width, int m_height) : width(m_width), height(m_height)
{
}

Animation::~Animation()
{
}

const std::shared_ptr<sf::Texture>& Animation::getFrameAt(size_t m_index)
{
	return this->frames.at(m_index);
}

const std::shared_ptr<sf::Texture>& Animation::getFrame(time_t m_time)
{
	return this->frames.at((m_time / this->animDelay) % this->getFramesAmount());
}

void Animation::build(std::string& m_fileName, int m_amountOfFramesInLine, int m_offsetX, int m_offsetY, int m_lines)
{
	auto framesAmount = m_amountOfFramesInLine * m_lines;
	for (size_t i = 0; i < framesAmount; i++)
	{
		sf::Texture texture;
		sf::IntRect rect(m_offsetX + i % m_amountOfFramesInLine * this->width,
						 m_offsetY + i / m_amountOfFramesInLine * this->height, this->width, this->height);

		if (!texture.loadFromFile(m_fileName, rect)) {
			printf("Unable to load texture: '%s'", m_fileName.c_str()); //TODO: add dummy texture
		}

		this->frames.push_back(std::make_shared<sf::Texture>(texture));
	}
}

int Animation::getWidth()
{
	return this->width;
}

int Animation::getHeight()
{
	return this->height;
}

int Animation::getFramesAmount()
{
	return this->frames.size();
}
