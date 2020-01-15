
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
#include "../graphics/opengl/Texture.hpp"

#include "../graphics/Quad.hpp"
#include "../common/Rect.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// #include <stdio.h>

//TEST
#include <vector>
#include "../thirdparty/sol/sol.hpp"
#include <memory>
// #include "Time.hpp"



class Game{
	public:
		Game(const char *title, int width, int height);
		~Game();
		
		void init();		
		void handleEvents(float dt);	//IO
		void update(float dt);
		void draw(float dt);
		void dispose();
		
		bool running(); 	//check if running

		bool CheckLua(lua_State *L, int r);


		//Lua thing
		void LUA_CreateQuad();
		void LUA_PrintTest();

		//TEST
		void PrintUniformValue(GLint program, std::string name);
		
		
	private:
		bool isRunning;
		Display display;

		Shader shader1;
		Mesh mesh1;
		glm::mat4 model1 = glm::mat4(1.0f);

		Shader shader2;
		Mesh mesh2;
		glm::mat4 model2 = glm::mat4(1.0f);



		Texture basicTexture;

		glm::mat4 model = glm::mat4(1.0f);
		glm::mat4 view = glm::mat4(1.0f);
		glm::mat4 projection;

		std::vector<Quad*> quads;
		//std::vector<std::make_unique<Quad>> quads;	//Look into using make_unique to encapsulate objects

		//LUA / SOL
		//ToDo swap with sol::protected_function
		sol::state lua;
		sol::function lua_init, lua_update, lua_draw;

		int test = 0;

};

#endif
