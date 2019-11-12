
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
	// int flags = 0;
	//Testing git changes
	
	if (fullscreen)
	{
		//flags = SDL_WINDOW_FULLSCREEN;
		std::cout << "SDL FULLSCREEN!" << std::endl;
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
		//renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);		
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 0xFF, 255, 255, 255);
			std::cout << "Renderer created!" << std::endl;
		}
		
		isRunning = true;
	}
	
	else
		isRunning = false;
	
	SDL_Surface *tmpSurface = IMG_Load("assets/textures/player/player1.png");
// 	SDL_Surface *tmpSurface = IMG_Load("assets/player.png");
	
	if (tmpSurface == NULL)
		std::cout << "Can't Find Image!" << std::endl;
	
	
	playerTex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);

	//Lua Stuff
    // lua_State *L = luaL_newstate(); //vm
    // luaL_openlibs(L); //Load basic set of libraries to lua

	// float deltaTime = 60.0; //FAKE THIS IS TEST FOR FUTURE SINCE I DONT HAVE DELTA TIME YET!
	// // ToDo: Impliment delta time

	// if (CheckLua(L, luaL_dofile(L, "assets/main.lua") ))
	// {
	// 	lua_getglobal(L, "Init"); //ToDo: Check for errors if this function doesnt exist!, adds to stack

	// 	if (lua_isfunction(L, -1))
	// 	{
	// 		lua_pushnumber(L, deltaTime); //Push deltatime for the function, adds to stack
	// 		lua_call(L,1,0); //Execute function passing 1 var 0 then removes off stack of push and function
	// 	}
	// 	else
	// 		std::cout << "Not Function!?" << std::endl;
	// }

	
	// lua_close(L);
	// std::cout << "Lua Done!!!" << std::endl;

}
void Game::handleEvents(float dt)
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
				//std::cout << "Key Up Pressed!" << std::endl;
				break;
					
				case SDLK_DOWN:
				SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);	
				scale--;
				//std::cout << "Key Down Pressed!" << std::endl;
				break;
					
				default:
					break;		
			}
		}
	}
}

void Game::update(double dt)	
{
	destR.h = 32 + scale;
	destR.w = 32 + scale;
	destR.x = offsetX;
	destR.y = offsetY;
	double velocity = 4;
	
	const Uint8 *state = SDL_GetKeyboardState(NULL);

	//if ((velocity * dt) > velocity)
		//std::cout << "FAST! " << (velocity * dt) << std::endl;

	if (state[SDL_SCANCODE_W]) 
		offsetY -= (velocity * dt);
	
	if (state[SDL_SCANCODE_A]) 
		offsetX -= (velocity * dt);

	if (state[SDL_SCANCODE_S])	
		offsetY += (velocity * dt);
	
	if (state[SDL_SCANCODE_D]) 
		offsetX += (velocity * dt);

	if (state[SDL_SCANCODE_Z]) 
		scale++;
	
	if (state[SDL_SCANCODE_X]) 
		scale--;
	
	
	state = nullptr;
	delete state;


	
}
void Game::render(float dt)
{
// 	SDL_SetRenderDrawColor(renderer, 0xFF, 255, 255, 255); //Drawing Color
	SDL_RenderClear(renderer); //Clear with drawing color
	//Add stuff to renderer


	
	SDL_RenderCopy(renderer, playerTex, NULL, &destR);
	
	SDL_RenderPresent(renderer); //Draw to screen | ALSO Halts if VBLANK!
}



void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game Cleaned" << std::endl;
}

bool Game::running() { return isRunning;}

// bool Game::CheckLua(lua_State *L, int r)
// {
// 	if (r != LUA_OK)
// 	{
// 		std::string errormsg = lua_tostring(L, -1);
// 		std::cout << errormsg << std::endl;
// 		return false;
// 	}

// 	else
// 	{
// 		return true;
// 	}
// }
