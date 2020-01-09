
#ifndef GAME_HPP
#define GAME_HPP


// extern "C"
// {
// 	#include <lua5.3/lua.h>   //Install with liblua5.3
// 	#include <lua5.3/lauxlib.h> 
// 	#include <lua5.3/lualib.h> 
// }

extern "C" //Should not being seeing this in game.hpp (lower level functions)
{ 
	#include <SDL2/SDL.h>

	#include <lua5.1/lua.h>
	#include <lua5.1/lauxlib.h>
	#include <lua5.1/lualib.h>
}

#include <iostream>
#include <string>

#include "Display.hpp"
#include "../graphics/opengl/Shader.hpp"
#include "../graphics/opengl/Mesh.hpp"
#include "../graphics/opengl/Vertex.hpp"
// #include "../graphics/Texture.hpp"

#include "../graphics/Quad.hpp"
#include "../common/Rect.hpp"

// #include <stdio.h>

static Quad quadTest;

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

		bool CheckLua(lua_State *L, int r);


		//Lua thing
		static int LUA_CreateQuad(lua_State *S);
		
		
	private:
		bool isRunning;
		Display display;
		Shader basicShader;
		Mesh triangleMesh1;
		Texture basicTexture;


};

#endif
