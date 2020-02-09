
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
	// std::cout << "[C++] Created Quad" << std::endl;
	// Quad *quad = new Quad();
	// quads.push_back(quad);
	// std::cout << "End Quad Func" << std::endl;
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
		window = Display(title, width, height); //Window also created here

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
	//---------------------------------------------------


	glEnable(GL_DEPTH_TEST);  //ToDo: Put somewhere else


 
}

Game::~Game()
{	
	std::cout << "Game Deconstructor is Called!" << std::endl;
}

void Game::PrintUniformValue(GLint program, std::string name)
{	
	GLint prog = program;
	std::string namee = name;
	GLuint location = glGetUniformLocation(prog, namee.c_str());
	GLfloat params;
	glGetUniformfv(prog, location, &params);

	std::cout << namee << " Value: " << params << std::endl;
}

//GAME START CODE HERE!
void Game::init()
{
	lua_init();
	//--------------- INIT CODE BELOW ----------------------------------------------------------------------------

	basicTexture = Texture("./assets/textures/floor1.png");

	view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f)); 
	//projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
	
	camera = new Camera(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
	camera->getTransform().translate(glm::vec3(0.0f, 0.0f, -3.0f));

	//------------------------------------------------------------------------------------------------------------


	quads->push_back( Quad(glm::vec3(0.0f, 0.0f, -3.0f)) );
	quads->push_back( Quad(glm::vec3(1.0f, 1.0f, 0.0f)) );	
	quads->push_back( Quad(glm::vec3(-3.0f, 0.0f, -4.0f)) );	
	quads->push_back( Quad(glm::vec3(0.0f, -3.0f, -7.0f)) );

	// quads->at(0).getTransform().setPosition( glm::vec3(0.0f, 0.0f, -3.0f) );
	// quads->at(1).getTransform().setPosition( glm::vec3(1.0f, 1.0f, 0.0f) );

	quads->at(0).getTransform().position( glm::vec3(-1.0f, -1.0f, 0.0f));



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
					// for (unsigned int i = 0; i < quads.size(); i++)
						// quads[i]->getShader()->setBool("showTexture", false);
				break;

				case SDLK_RIGHT:
					// for (unsigned int i = 0; i < quads.size(); i++)
						// quads[i]->getShader()->setBool("showTexture", true);

				break;

				case SDLK_w:
					camera->getTransform().translate(dt * glm::vec3(0.0f, 0.0f, 5.0f));
				break;

				case SDLK_a:
					camera->getTransform().translate(dt * glm::vec3(5.0f, 0.0f, 0.0f));
				break;

				case SDLK_s:
					camera->getTransform().translate(dt * glm::vec3(0.0f, 0.0f, -5.0f));
				break;

				case SDLK_d:
					camera->getTransform().translate(dt * glm::vec3(-5.0f, 0.0f, 0.0f));
				break;

				case SDLK_q:
					camera->getTransform().translate(dt * glm::vec3(0.0f, 5.0f, 0.0f));
				break;

				case SDLK_e:
					camera->getTransform().translate(dt * glm::vec3(0.0f, -5.0f, 0.0f));
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
	//******* INPUT STATE TEMP *************************************************************************


	// if (inputState[SDL_SCANCODE_W])
	// 	camera->getTransform().translate(dt * glm::vec3(0.0f, 0.0f, 5.0f));

	


	//**************************************************************************************************


	// quads->at(0).getTransform().setRotation(dt * glm::vec3(-55.0f, 0.0f, 0.0f));	//From Quad

	for (auto it = quads->begin(); it != quads->end(); it++)
	{
		int index = std::distance(quads->begin(), it);
		it->getTransform().rotate(dt * (index+1) * 2 * glm::vec3(-55.0f, 0.0f, 0.0f));
	}

	quads->at(0).getTransform().translate( dt * (float) glm::sin(Time::time()) * glm::vec3(3,0,0));


	//Move Camera back and forth
	//view = glm::translate(view, dt * glm::sin( SDL_GetTicks()/1000.0f) * 0.5f * glm::vec3(0.0f, 0.0f, -1.0f)); 
	camera->getTransform().translate(dt * glm::sin( SDL_GetTicks()/1000.0f) * 0.5f * glm::vec3(0.0f, 0.0f, -1.0f));
	
	lua_update(dt);
}

void Game::draw(float dt)
{
	//Clear Screen
	glClearColor(0.0f,0.15f,0.3f,1.0f); //Clear with this color
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Clears colors and fill
	//-----------------------------------------
	lua_draw(dt);

	//Draw all objects!
	for (auto it = quads->begin(); it != quads->end(); it++)
	{
		// it->draw(view, projection);
		// camera.getTransform().position(glm::vec3(0.0f, 0.0f, -3.0f));
		it->draw( camera->getTransform().getModel(), camera->getProjection() );
	}

	// Swap | --------------------------------
	window.swapBuffers();
}

void Game::dispose()
{

	for (auto it = quads->begin(); it != quads->end(); it++)
	{
		it->dispose();
	}

	window.dispose();
	SDL_Quit();
	std::cout << "Game Cleaned" << std::endl;
}

bool Game::running() { return isRunning;}
