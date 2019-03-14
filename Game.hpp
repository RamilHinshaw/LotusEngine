
#ifndef GAME_HPP
#define GAME_HPP

#include <SDL2/SDL.h>
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
};

#endif
