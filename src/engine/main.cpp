
extern "C"
{ 
	#include <SDL2/SDL.h> //Should not being seeing this in main
}

#include "Game.hpp"
#include <iostream>

#include <thread>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT= 600;


double min(double frameTime, double minDelta) { return (frameTime < minDelta)? minDelta : frameTime; }

int main(int argv, char** args)
{	
	//const uint8_t FPS = 60;
	//const int frameDelay = 1000 / FPS;	

	double lastTime = 0;
	double deltaTime = 0;

	const double FPS = 60.0;
	double targetFPS = 1/FPS;
 
	double fps_timer = 0;
	uint32_t fps_timer_interval = 0;
	int fpsCounter;
	
	//Create Game Object/Game Creates Window also ToDo: *should seperate logic here
	Game game = Game("Lotus Engine",SCREEN_WIDTH, SCREEN_HEIGHT);
	game.init();

	uint64_t counterStart = SDL_GetPerformanceCounter();
	double currentTime = 0;

	// bool firstFrame = false;



	while (game.running())
	{
		fps_timer = (SDL_GetPerformanceCounter()-counterStart)/ 1000000000.0;
		fpsCounter++;
		
		//Delta Time stuff (prolly put in own class)
		lastTime = currentTime;

		//Frame ratio to 1 second, divide by 1000 to turn nano secs to sec
		deltaTime = (currentTime - lastTime) / 1000000000.0 ;

		//MAIN LOGIC
		//To prevent massive framecount at beginning (must settle before determining frames) (LOSES 1 SECOND OF LOAD TIME THOUGH!)
		//IN THEORY NEED TO LOOP AT LEAST ONCE TO LEARN FRAME TIME
		if (SDL_GetTicks()/1000.0 >= targetFPS) 
		{
			// if (!firstFrame)
				// std::cout << "First Frame Init" << std::endl;

			game.handleEvents(deltaTime);
			game.update(1);
			game.draw(deltaTime);
		}
		
		currentTime = SDL_GetPerformanceCounter() - counterStart;

		//std::cout << "Time: " <<  SDL_GetTicks() << " VS " << fps_timer*100000 << std::endl;

		//Count FPS
		if (SDL_GetTicks()/1000.0 >= 1.0 * fps_timer_interval)
		{			
			if (fps_timer_interval != 0)
				std::cout << "Ticks: " << fps_timer_interval << " Time: " << SDL_GetTicks()/1000 << " FPS: " << fpsCounter << std::endl;

			//std::cout << "TEST " << SDL_GetPerformanceCounter() - counterStart << std::endl;
			fps_timer_interval++;
			fps_timer = 0;
			fpsCounter = 0;
		}		

		//DELAY (deltaTime is time between frames)
		if (deltaTime < targetFPS)
		{	
			SDL_Delay( (targetFPS - deltaTime) * 1000.0);
		}

	}
		
	game.dispose();
	
	unsigned int n = std::thread::hardware_concurrency();
    std::cout << n << " concurrent threads are supported.\n";

	return 0;
}
