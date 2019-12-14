
#ifndef GAME_HPP
#define GAME_HPP


// extern "C"
// {
// 	#include <lua5.3/lua.h>   //Install with liblua5.3
// 	#include <lua5.3/lauxlib.h> 
// 	#include <lua5.3/lualib.h> 
// }

extern "C" //Should not being seeing this in game
{ 
	#include <SDL2/SDL.h>
	#include <GL/glew.h>
}

#include <iostream>
#include "Display.hpp"
#include "../graphics/Shader.hpp"
#include "../graphics/Mesh.hpp"
#include "../graphics/Vertex.hpp"

// #include <stdio.h>

class Game{
	public:
		Game(const char *title, int width, int height);
		~Game();
		
		void init();		
		void handleEvents(float dt);	//IO
		void update(double dt);
		void draw(float dt);
		void dispose();
		
		bool running(); 	//check if running

		//bool CheckLua(lua_State *L, int r);
		
		
	private:
		bool isRunning;
		Display display;
		Shader basicShader;
		Mesh triangleMesh1;
		Mesh* triangleMesh2;
};

#endif
