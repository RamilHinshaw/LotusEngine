
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
		
		window = SDL_CreateWindow(title, xpos, ypos, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);		
		if (window)
		{
			std::cout << "Window created!" << std::endl;
		}
			
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);		
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
	
	while (	SDL_PollEvent(&event) != 0)
	{
		
		if (event.type == SDL_QUIT)
			isRunning = false;
		
		else if (event.type == SDL_KEYDOWN)
		{
			switch (event.key.keysym.sym)
			{
				case SDLK_UP:
				SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);	
				scale++;
				std::cout << "Key Up Pressed!" << std::endl;
				break;
					
				case SDLK_DOWN:
				SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);	
				scale--;
				std::cout << "Key Down Pressed!" << std::endl;
				break;
					
				default:
					break;		
			}
		}
	}
}

void Game::update()	
{
	destR.h = 32 + scale;
	destR.w = 32 + scale;
	destR.x = offsetX;
	destR.y = offsetY;
	//destR.x += 1;
	
	const Uint8 *state = SDL_GetKeyboardState(NULL);
	if (state[SDL_SCANCODE_W]) 
	{
// 		SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
		offsetY-=4;
		std::cout << "Key W Pressed!" << std::endl;
	}
	
	if (state[SDL_SCANCODE_S]) 
	{
// 		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);	
		offsetY+=4;
		std::cout << "Key S Pressed!" << std::endl;
	}
	
	if (state[SDL_SCANCODE_A]) 
		offsetX-=4;
	
	if (state[SDL_SCANCODE_D]) 
		offsetX+=4;

	if (state[SDL_SCANCODE_Z]) 
		scale++;
	
	if (state[SDL_SCANCODE_X]) 
		scale--;
	
	
	state = nullptr;
	delete state;
	
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
