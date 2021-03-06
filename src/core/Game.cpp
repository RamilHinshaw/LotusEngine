
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

	//Set Active Window
	Renderer::setActiveWindow(window);

	//Debug Information
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

	//Disable for 2D!
	// glEnable(GL_DEPTH_TEST);  //ToDo: Put somewhere else



 
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

	// basicTexture = Texture("./assets/textures/floor4.png");
	// basicShader = Shader("./assets/shaders/textShader");

	//std::cout << "Image Size: " << basicTexture.getSize().x << "x" << basicTexture.getSize().y << std::endl;



	//DISPLAY SETTINGS
	float winWidth = 800.0f;
	float winHeight = 600.0f;
	float camFov = 45.0f;

	//Orthogonal
	camera = new Camera(camFov, winWidth, winHeight, 0.1f, 50.0f, true);

	camera->toggleProjection();

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
	// basicShader.bind();
	// basicTexture.bind();

	//CORE

	Audio::init();

	// Graphics::TestLoadFont("./assets/fonts/8-Bit Madness.ttf", 32);

	Renderer::init();
	Graphics::TestLoadFont("./assets/fonts/Arial.ttf", 32);	//This test generates its own texture and binds it so renderer::init goes last to get my texture


	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);  


	//**********************************************************************************************



	//BASICALLY STATIC, NOT PUSHED EVERY FRAME

	// int sizeX = 100;
	// int sizeY = 100;

	// for (int y = 0; y < sizeY; y++)
	// 	for (int x = 0; x < sizeX; x++)
	// 	{
	// 		Graphics::DrawQuad(x,y);
	// 	}
	std::cout << "Vertex Byte Size: " << sizeof(Vertex) << std::endl;

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
					// 	quads->at(i).getShader().s	// int sizeX = 100;
	// int sizeY = 100;

	// for (int y = 0; y < sizeY; y++)
	// 	for (int x = 0; x < sizeX; x++)
	// 	{
	// 		Graphics::DrawQuad(x,y);
	// 	}etBool("u_showTexture", false);
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
		camera->getTransform().translate(dt * glm::vec3(0.0f, 0.0f, 32.0f * sprintSpeed));

	if (Input::getKey(KEY_A))
		camera->getTransform().translate(dt * glm::vec3(32.0f * sprintSpeed, 0.0f, 0.0f));

	if (Input::getKey(KEY_S))
		camera->getTransform().translate(dt * glm::vec3(0.0f, 0.0f, -32.0f * sprintSpeed));

	if (Input::getKey(KEY_D))
		camera->getTransform().translate(dt * glm::vec3(-32.0f * sprintSpeed, 0.0f, 0.0f));

	if (Input::getKey(KEY_Q))
		camera->getTransform().translate(dt * glm::vec3(0.0f, 32.0f * sprintSpeed, 0.0f));

	if (Input::getKey(KEY_E))
		camera->getTransform().translate(dt * glm::vec3(0.0f, -32.0f * sprintSpeed, 0.0f));

	if (Input::getKeyDown(KEY_LSHIFT))
	{
		sprintSpeed = 6.0f;
	}

	if (Input::getKeyUp(KEY_LSHIFT))
	{
		sprintSpeed = 1.0f;
	}
	
	if (Input::getKeyDown(KEY_O))
		camera->toggleProjection();

	// if (Input::getKeyDown(KEY_1))
	// 	camera->toggleProjection();

	//FOV Change!
	if (Input::getKey(KEY_2))
	{
		float fov = camera->getFov() - 8.0f * dt;
		camera->setFov(fov);
		std::cout << fov << std::endl;
	}

	if (Input::getKey(KEY_3))
	{
		float fov = camera->getFov() + 8.0f * dt;
		camera->setFov(fov);
		std::cout << fov << std::endl;
	}

	//Othor graphic zoom
	if (Input::getKey(KEY_4))
	{
		float zoom = camera->getOthoZoom() - 12.0f * dt;
		camera->setOthoZoom(zoom);
		std::cout << zoom << std::endl;
	}

	if (Input::getKey(KEY_5))
	{
		float zoom = camera->getOthoZoom() + 12.0f * dt;
		camera->setOthoZoom(zoom);
		std::cout << zoom << std::endl;
	}

	if (Input::getKeyDown(KEY_M))
	{
		Audio::playMusic("./assets/audio/Music.wav", 0.025f, -1);
	}

	if (Input::getKeyDown(KEY_9))
	{
		Renderer::getShader()->setBool("u_showTexture", true);
	}

	if (Input::getKeyDown(KEY_0))
	{
		Renderer::getShader()->setBool("u_showTexture", false);
	}



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
	// basicShader.setVec2("u_texRect", textureOffset.x, textureOffset.y);


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
	// glClearColor(0.0f,0.0f,0.0f,1.0f); //Clear with this color
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Clears colors and fill
	//-----------------------------------------
	lua_draw(dt);
	// Renderer::flush();



	// Graphics::DrawSprite(0 * 32, 0 * 32, 32, 32);
	// Graphics::DrawSprite(1 * 32, 0 * 32, 32, 32);
	// Graphics::DrawSprite(2 * 32, 0 * 32, 32, 32);	

	// Graphics::DrawSprite(0 * 32, 1 * 32, 32, 32);
	// Graphics::DrawSprite(0 * 32, 2 * 32, 32, 32);	

	//USED TO TEST TEXTURE ATLUS
	Graphics::DrawSprite(0, 0 , 128*4, 128*4);
	// Graphics::DrawText("the quick brown fox jumped over the lazy dog!", 0, 0 * 32);
	
	// Graphics::DrawText("the quick brown fox jumped over the lazy dog.!?", 0, 1 * 32);
	// Graphics::DrawText("THE QUICK BROWN FOX JUMPED OVER THE LAZY DOG.!?", 0, 2 * 32);

	double targetRefreshRate = 1.0/60.0f;

	//Adding to static batch cuz flush is disabled!
	// if (targetRefreshRate >= dt)
	// {
	// 	int xPos = quadCount / 100;
	// 	int yPos = quadCount % 100;
		
	// 	Graphics::DrawQuad(xPos, yPos);

	// 	quadCount++;
	// }

	// else
	// {
	// 	std::cout << quadCount << std::endl;
	// }


	// IF DYNAMIC MESH
	Renderer::render(camera);
	Renderer::dispose();
	// THEN FLUSH AND UPDATE HERE!

	// basicShader.setMat4("u_transform", glm::mat4(1.0f));
    // basicShader.setMat4("u_view", camera->getTransform().getModel());
    // basicShader.setMat4("u_projection", camera->getProjection());    

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
	Renderer::flush();
	Audio::flush();
	Input::dispose();
	window.dispose();
	Mix_Quit();
	SDL_Quit();
	std::cout << "Game Cleaned" << std::endl;
}

bool Game::running() { return isRunning;}
