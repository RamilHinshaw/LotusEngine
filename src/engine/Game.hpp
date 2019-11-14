
#ifndef GAME_HPP
#define GAME_HPP


// extern "C"
// {
// 	#include <lua5.3/lua.h>   //Install with liblua5.3
// 	#include <lua5.3/lauxlib.h> 
// 	#include <lua5.3/lualib.h> 
// }

#include <SDL2/SDL.h>
#include <iostream>
#include "Display.hpp"
// #include <stdio.h>

class Game{
	public:
		Game();
		~Game();
		
		void init(const char *title, int width, int height);		
		void handleEvents(float dt);	//IO
		void update(double dt);
		void draw(float dt);
		void clean();
		
		bool running(); 	//check if running

		//bool CheckLua(lua_State *L, int r);
		
		
	private:
		bool isRunning;
		//SDL_Window *window;
		//SDL_Renderer *renderer;
		Display* display;
		
		//TEMP
		//double scale = 1;
		//double offsetX, offsetY;
};

#endif
