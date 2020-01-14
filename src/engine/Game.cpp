
#include "Game.hpp"
#include <glm/glm.hpp>

#define LUA_OK 0

bool Game::CheckLua(lua_State *L, int r)
{
	if (r != LUA_OK)
	{
		std::string errormsg = lua_tostring(L, -1);
		std::cout << errormsg << std::endl;
		return false;
	}

	return true;
}

void Game::LUA_CreateQuad()
{
	std::cout << "[C++] Created Quad" << std::endl;
	Quad quad = Quad();
	quads.push_back(quad);
	std::cout << "End Quad Func" << std::endl;
}

void Game::LUA_PrintTest()
{
	std::cout << "[C++] Test Print" << std::endl;
}

Game::Game(const char *title, int width, int height)
{	
	//Initialize subsytems, if cant initialize there is an error!
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{	
		//Initialize timer, audio, video, joystick, haptic (feedback), gamecontroller & event subsystems
		std::cout << "SDL Initialized Subsystems!" << std::endl;

		//Function here to Create Window then bind to display
		
		display = Display(title, width, height); //Window also created here
    // if (outColor == 0)
    // {
    //     outColor = vec4(1.0,1.0,1.0,1.0);
    // }
		isRunning = true;
	}

    else
    {
        std::cerr << "SDL2 failed to initialize!" << std::endl;
    }

	int nrAttributes;
	glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
	std::cout << "Maximum nr of vertex attributes supported: " << nrAttributes << std::endl;

	//LUA STUFF
	//sol::state lua;
	lua.open_libraries(sol::lib::base);

	lua.set_function("CreateQuad", &Game::LUA_CreateQuad, this);
	lua.set_function("PrintTest", &Game::LUA_PrintTest, this);

	lua.do_file("assets/main.lua");

	lua_init = lua["Init"];
	lua_update = lua["Update"];
	lua_draw = lua["Draw"];
}

Game::~Game()
{	}

//GAME START CODE HERE!
void Game::init()
{
	//TEST
	// basicShader = Shader("./assets/shaders/basicShader"); //Load Shaders (both vertext and fragment)
	basicTexture = Texture("./assets/textures/floor1.png");

	// quadTest = Quad(Rect(0,0,32,32));


	//LUA
	// lua_State *L = luaL_newstate();
	// luaL_openlibs(L);

	// lua_register(L, "Double", LUA_Double);
	// lua_register(L, "CreateQuad", LUA_CreateQuad);

	// luaL_dofile(L, "assets/main.lua");
	// std::cout << "[C++] ENDED Quad?" << std::endl;

	// if (CheckLua(L, luaL_dofile(L, "assets/main.lua")))
	// {
	// 	lua_getglobal(L, "a");	//Add to stack
	// 	std::cout << "PASSED!" << std::endl;

	// 	if (lua_isnumber(L, -1))	//Read top of stack
	// 	{
	// 		float a_in_cpp = (float)lua_tonumber(L, -1);
	// 		std::cout << "a_in_cpp = " << a_in_cpp << std::endl;
	// 	}
	// 	else
	// 		std::cout << "NOT NUMBER!" << std::endl;
	// }
	// else
	// {
	// 	std::cout << "FAILED!" << std::endl;
	// }

	//lua_call(L,0,0);


	// lua_close(L);	




	// lua["PrintTest"] = LUA_PrintTest;
	// lua.set_function("CreateQuad",&LUA_CreateQuad);




	// std::cout << "A" << std::endl;
	// LUA_CreateQuad();
	// std::cout << "B" << std::endl;

	//CAMERA STUFF
	// model = glm::rotate(model, SDL_GetTicks() * glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f)); 
	//model = glm::translate(model, glm::vec3(-1.0f,0.0f,0.0f));

	view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f)); 
	projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);

	//Call Init
	lua_init();
	// lua_update(0);
	// lua_draw(0);

}

void Game::handleEvents(float dt)
{
	SDL_Event event;
	int shaderID;
	
	while (	SDL_PollEvent(&event) != 0)
	{
		
		if (event.type == SDL_QUIT)
			isRunning = false;
		
		else if (event.type == SDL_KEYDOWN)
		{
			switch (event.key.keysym.sym)
			{
				case SDLK_UP:
					glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
				break;
					
				case SDLK_DOWN:
					glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
				break;

				case SDLK_LEFT:
					// quadTest.getShader().setBool("showTexture", false);
					// glActiveTexture(GL_TEXTURE_2D); glDisable(GL_TEXTURE_2D);

					for (unsigned int i = 0; i < quads.size(); i++)
						quads[i].getShader().setBool("showTexture", false);
				break;

				case SDLK_RIGHT:
					// quadTest.getShader().setBool("showTexture", true);
					// glActiveTexture(GL_TEXTURE_2D); glDisable(GL_TEXTURE_2D);

					for (unsigned int i = 0; i < quads.size(); i++)
						quads[i].getShader().setBool("showTexture", true);

				break;
					
				default:
					break;		
			}
		}
	}
}

//GAME CODE HERE
void Game::update(float dt)	
{
	float modifier = (glm::sin(SDL_GetTicks()/1000.0f));
	//model = glm::translate(model,  modifier * glm::vec3(-1.0f,0.0f,0.0f) * dt);
	model = glm::rotate(model, dt * glm::radians(-55.0f), glm::vec3(0.0f, 0.0f, 1.0f)); 
	//view = glm::translate(view, glm::sin( SDL_GetTicks()/1000.0f) * 0.5f * glm::vec3(0.0f, 0.0f, -1.0f)); 

	for (unsigned int i = 0; i < quads.size(); i++)
	{
		quads[i].getShader().setMat4("model", model);
		quads[i].getShader().setMat4("view", view);
		quads[i].getShader().setMat4("projection", projection);
	}

	// std::cout << (glm::sin(SDL_GetTicks()/1000.0f)) << std::endl;

	// quadTest.getShader().setMat4("model", model);
	// quadTest.getShader().setMat4("view", view);
	// quadTest.getShader().setMat4("projection", projection);
	
	lua_update(dt);
}

void Game::draw(float dt)
{
	//Clear Screen
	glClearColor(0.0f,0.15f,0.3f,1.0f); //Clear with this color
	glClear(GL_COLOR_BUFFER_BIT); //Clears colors and fill
	//-----------------------------------------

	lua_draw(dt);

	for (unsigned int i = 0; i < quads.size(); i++)
	{
		quads[i].draw();
	}
	

	// //Selects shader
	// basicShader.bind();

	// //Selects texture
	// basicTexture.bind(0);

	// //Selects Buffer & DRAW
	// triangleMesh1.draw();

	// quadTest.draw();
	



	// Swap | --------------------------------
	display.swapBuffers();
}

void Game::dispose()
{

	// quadTest.dispose();
	// triangleMesh1.dispose();
	// basicTexture.dispose();
	// basicShader.dispose();


	//TEST
	//delete triangleMesh1;
	//delete triangleMesh2;
	//delete basicShader;

	for (unsigned int i = 0; i < quads.size(); i++)
	{
		quads[i].dispose();
	}


	display.dispose();
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
