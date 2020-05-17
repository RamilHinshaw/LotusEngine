
#ifndef GAME_HPP
#define GAME_HPP

//ToDo: Cut the bloat, class used for hardcoded Testing purposes!

extern "C" //Should not being seeing this in game.hpp (lower level functions)
{ 
	#include <SDL2/SDL.h>

	#include <lua5.1/lua.h>
	#include <lua5.1/lauxlib.h>
	#include <lua5.1/lualib.h>
	// #include <python3.6/Python.h>
}

#include <iostream>
#include <string>

#include "Display.hpp"
#include "Time.hpp"

#include "../graphics/opengl/Shader.hpp"
#include "../graphics/opengl/Mesh.hpp"
#include "../graphics/opengl/Vertex.hpp"
#include "../graphics/opengl/Texture.hpp"
#include "../graphics/Camera.hpp"


// #include "../graphics/MeshObject2D.hpp"
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

#include "../input/Input.hpp"

//CORE
#include "Graphics.hpp"



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
		Display window;

		Camera* camera;

		Texture basicTexture;
		Shader basicShader;
		Mesh basicMesh;

		const Uint8 *keyboardState = SDL_GetKeyboardState(NULL);
		// const Uint8 *buttonState = SDL_GameControllerGetButton
		//const Uint8 *mouseState = SDL_GetMouseState(NULL, NULL);

		std::vector<Quad> *quads = new std::vector<Quad>;

		//LUA / SOL
		//ToDo swap with sol::protected_function
		sol::state lua;
		sol::function lua_init, lua_update, lua_draw;

		glm::vec2 textureOffset;

};

#endif
