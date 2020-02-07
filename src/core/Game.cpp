
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

	basicTexture = Texture("./assets/textures/floor1.png");
	shader1 = Shader("./assets/shaders/basicShader"); //Load Shaders (both vertext and fragment)

	Vertex vertices[] = {

				//Positions								//Colors						//Texture Coordinates
				Vertex(glm::vec3(0.5,	0.5,	0),	glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), 	glm::vec2(1.0f, 1.0f)),
				Vertex(glm::vec3(0.5,	-0.5,	0),	glm::vec4(1.0f,	1.0f, 1.0f, 1.0f), 	glm::vec2(1.0f, 0.0f)),
				Vertex(glm::vec3(-0.5,	-0.5,	0),	glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), 	glm::vec2(0.0f, 0.0f)),
				Vertex(glm::vec3(-0.5,	0.5,	0), glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), 	glm::vec2(0.0f, 1.0f)),


				//Vertex(glm::vec3(0.5,	-0.5,	0),	glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), 	glm::vec2(1.0f, 0.0f)),
				//Vertex(glm::vec3(0.5,	0.5,	0),	glm::vec4(1.0f,	1.0f, 1.0f, 1.0f), 	glm::vec2(1.0f, 1.0f))

			};

	//Turn into class container (indice holding 3 ints)
	unsigned int indices[] = {
		0, 2, 3,	//first triangle
		0, 1, 2		//second triangle
	};


	mesh1 = Mesh(vertices, sizeof(vertices)/sizeof(vertices[0]), indices, sizeof(indices)/sizeof(indices[0]));


	view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f)); 
	projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);

	shader1.setMat4("model", model1);
	shader1.setMat4("view", view);
	shader1.setMat4("projection", projection);


	//------------------------------------------------------------------------------------------------------------

	shader2 = Shader("./assets/shaders/basicShader"); //Load Shaders (both vertext and fragment)

	mesh2 = Mesh(vertices, sizeof(vertices)/sizeof(vertices[0]), indices, sizeof(indices)/sizeof(indices[0]));

	model2 = glm::translate(model2, glm::vec3(1.0f, 1.0f, 0.0f)); 

	shader2.setMat4("model", model2);
	shader2.setMat4("view", view);
	shader2.setMat4("projection", projection);

	lua_init();
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

					// for (unsigned int i = 0; i < quads.size(); i++)
						// quads[i]->getShader()->setBool("showTexture", false);
				break;

				case SDLK_RIGHT:
					// quadTest.getShader().setBool("showTexture", true);
					// glActiveTexture(GL_TEXTURE_2D); glDisable(GL_TEXTURE_2D);

					// for (unsigned int i = 0; i < quads.size(); i++)
						// quads[i]->getShader()->setBool("showTexture", true);

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

	//Make Model1 Spin
	model1 = glm::rotate(model1, dt * glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f)); 

	//Move Camera back and forth
	view = glm::translate(view, dt * glm::sin( SDL_GetTicks()/1000.0f) * 0.5f * glm::vec3(0.0f, 0.0f, -1.0f)); 
	
	lua_update(dt);
}

void Game::draw(float dt)
{
	//Clear Screen
	glClearColor(0.0f,0.15f,0.3f,1.0f); //Clear with this color
	glClear(GL_COLOR_BUFFER_BIT); //Clears colors and fill
	//-----------------------------------------
	lua_draw(dt);


	//Use Shader
	shader1.bind();	
	//Update Transform in Camera Space
	shader1.setMat4("model", model1);
	shader1.setMat4("view", view);

	if (test == 0)
		shader1.setMat4("projection", projection);

	//Draw Mesh
	mesh1.draw();

	shader2.bind();
	shader2.setMat4("model", model2);
	shader2.setMat4("view", view);

	if (test == 0)
		shader2.setMat4("projection", projection);

	mesh2.draw();

	test++;

	// Swap | --------------------------------
	window.swapBuffers();
}

void Game::dispose()
{

	// quadTest.dispose();
	mesh1.dispose();
	basicTexture.dispose();
	shader1.dispose();


	//TEST
	//delete triangleMesh1;
	//delete triangleMesh2;
	//delete basicShader;

	// for (unsigned int i = 0; i < quads.size(); i++)
	// {
	// 	quads[i]->dispose();
	// }


	window.dispose();
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
