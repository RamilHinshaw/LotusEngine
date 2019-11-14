
#ifndef GAME_HPP
#define GAME_HPP


// extern "C"
// {
// 	#include <lua5.3/lua.h>   //Install with liblua5.3
// 	#include <lua5.3/lauxlib.h> 
// 	#include <lua5.3/lualib.h> 
// }

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
// #include <SDL2/SDL_ttf.h>
#include <iostream>
// #include <stdio.h>

class Game{
	public:
		Game();
		~Game();
		
		void init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen);		
		void handleEvents(float dt);	//IO
		void update(double dt);
		void draw(float dt);
		void clean();
		
		bool running(); 	//check if running

		//bool CheckLua(lua_State *L, int r);
		
		
	private:
		bool isRunning;
		SDL_Window *window;
		SDL_Renderer *renderer;
		
		//TEMP
		double scale = 1;
		double offsetX, offsetY;
};

#endif
