
#ifndef GAME_HPP
#define GAME_HPP


// extern "C"
// {
// 	#include <lua5.3/lua.h>   //Install with liblua5.3
// 	#include <lua5.3/lauxlib.h> 
// 	#include <lua5.3/lualib.h> 
// }

extern "C"
{ 
	#include <SDL2/SDL.h>
}

#include <iostream>
#include "Display.hpp"
#include "../graphics/Shader.hpp"
#include "../graphics/Mesh.hpp"

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
		Display* display;
		Shader* basicShader;
		Mesh* triangleMesh;
};

#endif
