
#include "Game.hpp"


Game::Game()
{	
}
Game::~Game()
{	
}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	//uint32_t flags; //4 bytes for hexidecimal
	int flags = 0;
	
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}
	
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "SDL Initialized!" << std::endl;
		window = SDL_CreateWindow(title, xpos, ypos, width, height, SDL_WINDOW_SHOWN);
		
		if (window)
		{
			std::cout << "Window created!" << std::endl;
		}
			
		renderer = SDL_CreateRenderer(window, -1, 0);
		
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 0xFF, 255, 255, 255);
			std::cout << "Renderer created!" << std::endl;
		}
		
		isRunning = true;
	}
	
	else
		isRunning = false;

}
void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
		case SDL_QUIT:
			isRunning = false;
			break;
			
		default:
			break;		
	}
}

void Game::update()	
{
	
}
void Game::render()
{
	SDL_RenderClear(renderer);
	//Add stuff to renderer
	SDL_RenderPresent(renderer); //Expose to screen
	
	//SDL_Delay(3000);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game Cleaned" << std::endl;
}

bool Game::running() { return isRunning;}
