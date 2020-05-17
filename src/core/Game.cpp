
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

	int nrAttributes, nrMaxTexUnits;
	glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
	glGetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS, &nrMaxTexUnits);
	std::cout << "Maximum nr of vertex attributes supported: " << nrAttributes << std::endl;
	std::cout << "Maximum nr of texture units supported: " << nrMaxTexUnits	<< std::endl;


	// Input
	// Input::Init();

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

	basicTexture = Texture("./assets/textures/floorAll.png");
	basicShader = Shader("./assets/shaders/basicShaderES");

	std::cout << "Image Size: " << basicTexture.getSize().x << "x" << basicTexture.getSize().y << std::endl;

	//DISPLAY SETTINGS
	float winWidth = 800.0f;
	float winHeight = 600.0f;
	float camFov = 45.0f;

	//Orthogonal
	camera = new Camera(camFov, winWidth, winHeight, 0.1f, 50.0f, true);

	//camera->toggleProjection();

	camera->getTransform().translate(glm::vec3(0.0f, 0.0f, -3.0f));

	//Input
	SDL_PumpEvents();	//Update Keyboard State
	Input::UpdatePreviousState(); //Assign Previous so no Memory Error

	//------------------------------------------------------------------------------------------------------------


	// int tileXAmnt = 20;
	// int tileYAmnt = 20;
	
	// for (int y = 0; y < tileYAmnt; y++)
	// 	for (int x = 0; x < tileXAmnt; x++)
	// 	{
	// 		quads->push_back( Quad(glm::vec3(1.0f * x, 1.0f * y, 0)) );
	// 	}


	//TEST
	basicShader.bind();

	//2 MESH QUAD ************************************************************************************
	    Vertex vertices[] = {

					//Positions								//Colors						//Texture Coordinates	//TexID
					Vertex(glm::vec3(-1.5,	-0.5,	0),	glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), 	glm::vec2(1.0f, 1.0f), 	0.0f),
					Vertex(glm::vec3(-0.5,	-0.5,	0),	glm::vec4(1.0f,	1.0f, 1.0f, 1.0f), 	glm::vec2(1.0f, 0.0f), 	0.0f),
					Vertex(glm::vec3(-0.5,	0.5,	0),	glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), 	glm::vec2(0.0f, 0.0f), 	0.0f),
					Vertex(glm::vec3(-1.5,	0.5,	0), glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), 	glm::vec2(0.0f, 1.0f), 	0.0f),

					Vertex(glm::vec3(0.5,	-0.5,	0),	glm::vec4(1.0f, 0.0f, 0.0f, 1.0f), 	glm::vec2(1.0f, 1.0f), 	1.0f),
					Vertex(glm::vec3(1.5,	-0.5,	0),	glm::vec4(1.0f,	0.0f, 0.0f, 1.0f), 	glm::vec2(1.0f, 0.0f), 	1.0f),
					Vertex(glm::vec3(1.5,	0.5,	0),	glm::vec4(1.0f, 0.0f, 0.0f, 1.0f), 	glm::vec2(0.0f, 0.0f), 	1.0f),
					Vertex(glm::vec3(0.5,	0.5,	0), glm::vec4(1.0f, 0.0f, 0.0f, 1.0f), 	glm::vec2(0.0f, 1.0f), 	1.0f),

				};

	//Turn into class container (indice holding 3 ints)
	unsigned int indices[] = {
		0, 2, 3,	//first triangle
		0, 1, 2,	//second triangle

		4, 6, 7,
		4, 5, 6

	};

	//**********************************************************************************************

	//Quad quad1 = new Quad( 0, 0, 32, 32)


	// basicMesh = Mesh(vertices, sizeof(vertices)/sizeof(vertices[0]), indices, sizeof(indices)/sizeof(indices[0]));

	Renderer::init();

}

void Game::handleEvents(float dt)
{
	SDL_Event event;
	//Note: SDL_PollEvent UPDATES KEYBOARD STATE!
	
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
					// for (unsigned int i = 0; i < quads->size(); i++)
					// {
					// 	quads->at(i).getShader().bind();
					// 	quads->at(i).getShader().setBool("u_showTexture", false);
					// }
				break;

				case SDLK_RIGHT:
					// for (unsigned int i = 0; i < quads->size(); i++)
					// {basicMesh
					// 	quads->at(i).getShader().bind();
					// 	quads->at(i).getShader().setBool("u_showTexture", true);
					// }

				break;

	
			}
		}
	}
}

//GAME CODE HERE
void Game::update(float dt)	
{
	//******* INPUT STATE TEMP *************************************************************************

	if (Input::getKey(KEY_W))
		camera->getTransform().translate(dt * glm::vec3(0.0f, 0.0f, 5.0f));

	if (Input::getKey(KEY_A))
		camera->getTransform().translate(dt * glm::vec3(5.0f, 0.0f, 0.0f));

	if (Input::getKey(KEY_S))
		camera->getTransform().translate(dt * glm::vec3(0.0f, 0.0f, -5.0f));

	if (Input::getKey(KEY_D))
		camera->getTransform().translate(dt * glm::vec3(-5.0f, 0.0f, 0.0f));

	if (Input::getKey(KEY_Q))
		camera->getTransform().translate(dt * glm::vec3(0.0f, 5.0f, 0.0f));

	if (Input::getKey(KEY_E))
		camera->getTransform().translate(dt * glm::vec3(0.0f, -5.0f, 0.0f));
	
	if (Input::getKeyDown(KEY_0))
		camera->toggleProjection();

	if (Input::getKeyUp(KEY_1))
		camera->toggleProjection();


	//**************************************************************************************************


	// quads->at(0).getTransform().setRotation(dt * glm::vec3(-55.0f, 0.0f, 0.0f));	//From Quad

	// for (auto it = quads->begin(); it != quads->end(); it++)
	// {
	// 	int index = std::distance(quads->begin(), it);
	// 	it->getTransform().rotate(dt * (index+1) * glm::vec3(-55.0f, 0.0f, 0.0f));
	// }basicMesh

	// quads->at(0).getTransform().translate( dt * (float) glm::sin(Time::time()) * glm::vec3(3,0,0));


	//Move Camera back and forth
	//view = glm::translate(view, dt * glm::sin( SDL_GetTicks()/1000.0f) * 0.5f * glm::vec3(0.0f, 0.0f, -1.0f)); 
	// camera->getTransform().translate(dt * glm::sin( SDL_GetTicks()/1000.0f) * 0.5f * glm::vec3(0.0f, 0.0f, -1.0f));

	// SCROLLING UV TEST!		| ToDo: Put in queue system so don't double bind!
	textureOffset += dt * .25f;// * glm::vec2(1,0);
	basicShader.setVec2("u_texRect", textureOffset.x, textureOffset.y);


	// IF DYNAMIC MESH
	// THEN FLUSH AND UPDATE HERE!


	// for (auto it = quads->begin(); it != quads->end(); it++)
	// {
	// // 	it->getShader().bind();
	// 	it->getShader().setVec2("u_texRect", textureOffset.x, textureOffset.y);
	// }

	
	//**************************************************************************************************

	Input::UpdatePreviousState();
	//SDL_PumpEvents();// 
	lua_update(dt);
}

void Game::draw(float dt)
{
	//Clear Screen
	glClearColor(0.0f,0.15f,0.3f,1.0f); //Clear with this color
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Clears colors and fill
	//-----------------------------------------
	lua_draw(dt);
	Renderer::flush();

	//Draw all objects!
	// for (auto it = quads->begin(); it != quads->end(); it++)
	// {
	// 	// it->draw(view, projection);
	// 	// camera.getTransform().position(glm::vec3(0.0f, 0.0f, -3.0f));
	// 	it->draw( camera->getTransform().getModel(), camera->getProjection() );
	// }

	int sizeX = 100;
	int sizeY = 100;

	for (int y = 0; y < sizeY; y++)
		for (int x = 0; x < sizeX; x++)
		{
			Graphics::DrawQuad(x,y);
		}
	

	// Graphics::DrawQuad(-2,0);
	// Graphics::DrawQuad(-1,0);
	// Graphics::DrawQuad(0,0);
	// Graphics::DrawQuad(1,0);
	// Graphics::DrawQuad(8,0);
	// Graphics::DrawQuad(12,0);


	// IF DYNAMIC MESH
	Renderer::render();
	// THEN FLUSH AND UPDATE HERE!

	basicShader.setMat4("u_transform", glm::mat4(1.0f));
    basicShader.setMat4("u_view", camera->getTransform().getModel());
    basicShader.setMat4("u_projection", camera->getProjection());    

	// basicMesh.draw();



	// Swap | --------------------------------
	window.swapBuffers();

}

void Game::dispose()
{

	// for (auto it = quads->begin(); it != quads->end(); it++)
	// {
	// 	it->dispose();
	// }

	Input::dispose();
	window.dispose();
	SDL_Quit();
	std::cout << "Game Cleaned" << std::endl;
}

bool Game::running() { return isRunning;}
