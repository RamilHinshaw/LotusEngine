
#include <SDL2/SDL.h>
#include "Game.hpp"
#include <iostream>

#include <thread>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT= 600;

Game *game = nullptr;

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
	game = new Game();
	game->init("Lotus Engine",SCREEN_WIDTH, SCREEN_HEIGHT);

	

	//u_int32_t frameStart;
	//u_int32_t frameTime;
	// const double frameDelay = 1000 / FPS;

	uint64_t counterStart = SDL_GetPerformanceCounter();
	double currentTime = 0;

	while (game->running())
	{
		//frameStart = SDL_GetTicks();


		fps_timer = (SDL_GetPerformanceCounter()-counterStart)/ 1000000000.0;
		fpsCounter++;
		
		//Delta Time stuff (prolly put in own class)
		lastTime = currentTime;

		//currentTime = SDL_GetPerformanceCounter();


		//Frame ratio to 1 second, divide by 1000 to turn nano secs to sec
		deltaTime = (currentTime - lastTime) / 1000000000.0 ;

		//if (lastTime == 0) continue;



		//deltaTime = min(deltaTime, targetFPS);
		//std::cout << "FrameTime: " << deltaTime << std::endl;
		//deltaTime = ((currentTime - lastTime)*1000 / (doubtargetFPSle)SDL_GetPerformanceFrequency() );


		//std::cout << (SDL_GetPerformanceCounter()-counterStart)/ 1000000000.0  << std::endl;


		//std::cout << &currentTime << " AND " << &lastTime << std::endl;
		//std::cout << currentTime << " - " << lastTime << " = " << deltaTime << std::endl;
		//std::cout << SDL_GetTicks() << std::endl;
		//std::cout << (SDL_GetPerformanceCounter() - counterStart)/1000000.0 << std::endl;



				
		game->handleEvents(deltaTime);
		game->update(1);
		game->draw(deltaTime);


		
		//continue;

		
		//frameTime = SDL_GetTicks() - frameStart;


		double test = currentTime - lastTime;
		currentTime = SDL_GetPerformanceCounter() - counterStart;

		//std::cout << deltaTime << std::endl;

		if (fps_timer >= 1.0 * fps_timer_interval)
		{			
			//std::cout << fps_timer << std::endl;
			std::cout << "Ticks: " << fps_timer << " FPS: " << fpsCounter << std::endl;//" FrameTime: " << deltaTime << " Together: " << ((double)fpsCounter*deltaTime) << std::endl;

			fps_timer_interval++;
			fps_timer = 0;
			fpsCounter = 0;
		}
		
		//std::cout << SDL_GetTicks() << " - " << frameStart << " = " << frameTime << std::endl;
		//std::cout << currentTime << " - " << lastTime << " = " << test << std::endl;

		//std::cout << deltaTime*100000.0 << " VS " << frameTime << std::endl;
		// if (frameDelay > frameTime)
		// {
		// 	//I don't like this simply because wasting cpu potential just to wait, need to find alternative
		// 	SDL_Delay(frameDelay - frameTime);
		// }
		
		if (deltaTime < targetFPS)
		{
			//I don't like this simply because wasting cpu potential just to wait, need to find alternative
			//std::cout << ((targetFPS*1000.0) - deltaTime*1000.0) << " VS " << (frameDelay - frameTime) << std::endl;
			//std::cout << ((targetFPS*1000.0)) << " VS " << deltaTime*1000.0 << std::endl;
			//SDL_Delay( (1000/FPS) - frameTime);
			SDL_Delay( (targetFPS - deltaTime) * 1000.0);
		}

	}
		
	game->clean();
	
	unsigned int n = std::thread::hardware_concurrency();
    std::cout << n << " concurrent threads are supported.\n";
    std::cout << n << " TEST.\n";
	

	return 0;
}
