
#include <SDL2/SDL.h>
#include "Game.hpp"
#include <iostream>

#include <thread>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT= 600;

Game *game = nullptr;

int main(int argv, char** args)
{	
	//const uint8_t FPS = 60;
	//const int frameDelay = 1000 / FPS;
	
	uint64_t currentTime = 0;
	uint64_t lastTime = 0;
	double deltaTime = 0;
	uint64_t counterStart = SDL_GetPerformanceCounter();

	uint32_t fps_timer = 0;
	uint32_t fps_timer_interval = 0;
	int fps;
	
	//Create Game Object/Game Creates Window also ToDo: *should seperate logic here
	game = new Game();
	game->init("Lotus Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, false);

	
	while (game->running())
	{
		fps_timer = (SDL_GetTicks()/1000.0);

		if (fps_timer >= 1.0 * fps_timer_interval)
		{			
			//std::cout << fps_timer << std::endl;
			std::cout << "Ticks: " << (double)(SDL_GetTicks()/1000.0) << " FPS: " << fps << " FrameTime: " << deltaTime << std::endl;

			fps_timer_interval++;
			fps_timer = 0;
			fps = 0;
		}
		else
			fps++;
		
		//Delta Time stuff (prolly put in own class)
		lastTime = currentTime;
		currentTime = SDL_GetPerformanceCounter();

		//Frame ratio to 1 second, divide by 1000 to turn nano secs to sec
		deltaTime = (currentTime - lastTime) / 1000000.0 ;
		//deltaTime = ((currentTime - lastTime)*1000 / (double)SDL_GetPerformanceFrequency() );


		//std::cout << SDL_GetPerformanceFrequency() << std::endl;


		//std::cout << &currentTime << " AND " << &lastTime << std::endl;
		//std::cout << currentTime << " - " << lastTime << " = " << deltaTime << std::endl;
		//std::cout << SDL_GetTicks() << std::endl;
		//std::cout << SDL_GetPerformanceCounter() - counterStart << std::endl;
				
		game->handleEvents(deltaTime);
		game->update(1);
		game->render(deltaTime);


		
		//continue;




		
		// if (frameDelay > frameTime)
		// {
		// 	//I don't like this simply because wasting cpu potential just to wait, need to find alternative
		// 	SDL_Delay(frameDelay - frameTime);
		// }
	}
		
	game->clean();
	
	unsigned int n = std::thread::hardware_concurrency();
    std::cout << n << " concurrent threads are supported.\n";
    std::cout << n << " TEST.\n";
	

	return 0;
}
