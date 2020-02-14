#pragma once
#include <string>
#include "Animation.h"
#include <map>
#include <memory>
#include <optional>

class TileSet
{
public:
	TileSet();
	~TileSet();

	void addState(std::string& m_name, Animation& m_animation);
	std::optional<Animation> getDefaultState();
	std::string geRandomState();
	std::optional<Animation> getState(std::string m_name);
private:
	std::map<std::string, Animation> animations;
};