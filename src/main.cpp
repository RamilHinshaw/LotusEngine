
#include <SDL2/SDL.h>
#include "Game.hpp"
#include <iostream>

#include <thread>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT= 600;

Game *game = nullptr;

int main()
{
	
	const uint8_t FPS = 60;
	const int frameDelay = 1000 / FPS;
	
	Uint32 frameStart;
	Uint32 frameTime;
	
	game = new Game();
	game->init("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, false);
	
	while (game->running())
	{
		frameStart = SDL_GetTicks();
				
		game->handleEvents();;
		game->update();
		game->render();
		
		//continue;
		
		frameTime = SDL_GetTicks() - frameStart;

		
		if (frameDelay > frameTime)
		{
			//I don't like this simply because wasting cpu potential just to wait, need to find alternative
			SDL_Delay(frameDelay - frameTime);
		}
	}
		
	game->clean();
	
	unsigned int n = std::thread::hardware_concurrency();
    std::cout << n << " concurrent threads are supported.\n";
    std::cout << n << " TEST.\n";
	

	return 0;
}
