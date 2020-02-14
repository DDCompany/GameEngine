#include "TileSet.h"
#include "SFML\Graphics.hpp"
#include <iostream>

TileSet::TileSet()
{
}

TileSet::~TileSet()
{
}

void TileSet::addState(std::string& m_name, Animation& m_animation)
{
	if (this->animations.find(m_name) != this->animations.end()) {
		printf("Animation already registered: '%s'", m_name.c_str());
		return;
	}

	this->animations.insert(std::pair<std::string, Animation>(m_name, m_animation));
}

std::optional<Animation> TileSet::getDefaultState()
{
	return this->getState("default");
}

std::string TileSet::geRandomState()
{ //TODO: add compulsary one state
	auto iter = this->animations.begin();
	std::advance(iter, round(rand() % this->animations.size()));
	return iter->first;
}

std::optional<Animation> TileSet::getState(std::string m_name)
{
	try {
		return std::make_optional(this->animations.at(m_name));
	}
	catch (std::out_of_range e) {
		return std::nullopt;
	}
}
