
#include "Game.hpp"

SDL_Texture *playerTex;
SDL_Rect srcR, destR;

Game::Game()
{	}
Game::~Game()
{	}

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
		//Initialize timer, audio, video, joystick, haptic (feedback), gamectonrller & event subsystems
		std::cout << "SDL Initialized Subsytems!" << std::endl;
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
	
	SDL_Surface *tmpSurface = IMG_Load("assets/player/player1.png");
// 	SDL_Surface *tmpSurface = IMG_Load("assets/player.png");
	
	if (tmpSurface == NULL)
		std::cout << "Can't Find Image!" << std::endl;
	
	
	playerTex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);

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
	destR.h = 32;
	destR.w = 32;
	destR.x += 1;
}
void Game::render()
{
// 	SDL_SetRenderDrawColor(renderer, 0xFF, 255, 255, 255); //Drawing Color
	SDL_RenderClear(renderer); //Clear with drawing color
	//Add stuff to renderer


	
	SDL_RenderCopy(renderer, playerTex, NULL, &destR);
	
	SDL_RenderPresent(renderer); //Draw to screen
}



void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game Cleaned" << std::endl;
}

bool Game::running() { return isRunning;}
