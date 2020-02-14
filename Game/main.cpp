#define SFML_STATIC
#include "Game.h"
#include <iostream>

int main(int argc, char** argv) {
	if (argc > 1) {
		for (size_t i = 1; i < argc; i++)
		{
			std::cout << argv[i] << std::endl; //TODO: add loading from file
		}
	}

	Game game;
	game.init();
	game.run();

	return 0;
}