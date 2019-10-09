
#ifndef GAME_HPP
#define GAME_HPP


//#include "SDL.h"
//#include "SDL_image.h"
//#include "SDL_ttf.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
// #include <stdio.h>

class Game{
	public:
		Game();
		~Game();
		
		void init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen);		
		void handleEvents();	//IO
		void update();
		void render();
		void clean();
		
		bool running(); 	//check if running
		
		
	private:
		bool isRunning;
		SDL_Window *window;
		SDL_Renderer *renderer;
		
		//TEMP
		uint32_t scale = 1;
		int offsetX, offsetY;
};

#endif
