
// #include <SDL2/SDL.h>
#include "Game.hpp"
#include <iostream>

#include <thread>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT= 600;

Game *game = nullptr;

int main()
{
	
	game = new Game();
	game->init("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, false);
	
	while (game->running())
	{
		game->handleEvents();;
		game->update();
		game->render();
	}
	
	unsigned int n = std::thread::hardware_concurrency();
    std::cout << n << " concurrent threads are supported.\n";
	
	
	game->clean();
	return 0;
}
