
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
	//ToDo: Create Game Object/Game Creates Window also. ToDo: *should seperate logic here
	Game game = Game("Lotus Engine",SCREEN_WIDTH, SCREEN_HEIGHT);
	
	//Set target FPS
	const double FPS = 60.0;
	Time::init(FPS);

	game.init();	//Run Global Game Start Functions
	float dt;	//Used to pass deltaTime

	//Main Game Loop
	while (game.running())
	{
		dt = Time::deltaTime();
		//std::cout << "Dt: " << dt;

		game.handleEvents(dt);
		game.update(dt);
		game.draw(dt);	//ToDo: Draw for each window
		
		Time::printFPS();	//Debug
		Time::step(); 		//FPS Calculations
		
		//ToDo: Give options for uncapped, delay, or vertical sync
		Time::delay();		//Delay to target FPS
	}
		
	game.dispose();
	
	unsigned int n = std::thread::hardware_concurrency();
    std::cout << n << " concurrent threads are supported.\n";

	return 0;
}
