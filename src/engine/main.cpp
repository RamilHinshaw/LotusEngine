
extern "C"
{ 
	#include <SDL2/SDL.h> //Should not being seeing this in main
}

#include "Game.hpp"
#include "Time.hpp"
#include <iostream>

#include <thread>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT= 600;

//Virtual Width = 432
//Virtual Height = 243

int main(int argv, char** args)
{	
	//ToDo: Create Game Object/Game Creates Window also ToDo: *should seperate logic here
	Game game = Game("Lotus Engine",SCREEN_WIDTH, SCREEN_HEIGHT);
	game.init();	

	const double FPS = 60.0;
	double targetFPS = 1/FPS;
	Time::init(targetFPS);

	//Main Game Loop
	while (game.running())
	{
		float dt = Time::deltaTime();

		game.handleEvents(dt);
		game.update(dt);
		game.draw(dt);
		
		Time::printFPS();	//Debug
		Time::step(); 		//FPS Calculations
		Time::delay();		//Delay to target FPS
	}
		
	game.dispose();
	
	unsigned int n = std::thread::hardware_concurrency();
    std::cout << n << " concurrent threads are supported.\n";

	return 0;
}
