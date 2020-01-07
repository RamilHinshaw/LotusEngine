
#include "Game.hpp"
#include <glm/glm.hpp>
// #include "glad.h"

// SDL_Texture *playerTex;
// SDL_Rect srcR, destR;

Game::Game(const char *title, int width, int height)
{	
	//Initialize subsytems, if cant initialize there is an error!
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{	
		//Initialize timer, audio, video, joystick, haptic (feedback), gamecontroller & event subsystems
		std::cout << "SDL Initialized Subsystems!" << std::endl;

		//Function here to Create Window then bind to display
		
		display = Display(title, width, height); //Window also created here

		isRunning = true;
	}

    else
    {
        std::cerr << "SDL2 failed to initialize!" << std::endl;
    }

	int nrAttributes;
	glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
	std::cout << "Maximum nr of vertex attributes supported: " << nrAttributes << std::endl;
}

Game::~Game()
{	}

//GAME START CODE HERE!
void Game::init()
{
	//TEST
	basicShader = Shader("./assets/shaders/basicShader"); //Load Shaders (both vertext and fragment)
	basicTexture = Texture("./assets/textures/floor2.png");

	Vertex vertices1[] = {

					//Positions								//Colors						//Texture Coordinates
					Vertex(glm::vec3(0.5,	0.5,	0),	glm::vec4(1.0f, 1.0f, 1.0f, 0.1f), 	glm::vec2(0.0f, 0.0f)),
					Vertex(glm::vec3(-0.5,	0.5,	0), glm::vec4(1.0f, 1.0f, 1.0f, 0.1f), 	glm::vec2(1.0f, 0.0f)),
					Vertex(glm::vec3(-0.5,	-0.5,	0),	glm::vec4(1.0f,	1.0f, 1.0f, 0.1f), 	glm::vec2(1.0f, 1.0f)),

					Vertex(glm::vec3(-0.5,	-0.5,	0),	glm::vec4(1.0f, 1.0f, 1.0f, 0.1f), 	glm::vec2(0.0f, 0.0f)),
					Vertex(glm::vec3(0.5,	-0.5,	0),	glm::vec4(1.0f, 1.0f, 1.0f, 0.1f), 	glm::vec2(1.0f, 0.0f)),
					Vertex(glm::vec3(0.5,	0.5,	0),	glm::vec4(1.0f,	1.0f, 1.0f, 0.1f), 	glm::vec2(1.0f, 1.0f))

				};

	// Vertex vertices2[] = {

	// 				Vertex(glm::vec3(0.5,	0.5,	0)),
	// 				Vertex(glm::vec3(0.5,	-0.5,	0)),
	// 				Vertex(glm::vec3(-0.5,	-0.5,	0))
	// 			};

	
	//Vertex test = Vertex(glm::vec3(-0.5,	-0.5,	0));


	//std::cout << sizeof(Vertex) << " VS " << sizeof(vertices)/sizeof(vertices[0]) << std::endl;
	//std::cout << sizeof(vertices) << " / " << sizeof(vertices[0]) << " = " << sizeof(vertices)/sizeof(vertices[0]) << std::endl;
	//std::cout << "Test: " << sizeof(test) << std::endl;

	triangleMesh1 = Mesh(vertices1, sizeof(vertices1)/sizeof(vertices1[0]));

	//triangleMesh2 = new Mesh(vertices2, sizeof(vertices2)/sizeof(vertices2[0]));
}
void Game::handleEvents(float dt)
{
	SDL_Event event;
	
	while (	SDL_PollEvent(&event) != 0)
	{
		
		if (event.type == SDL_QUIT)
			isRunning = false;
		
		// else if (event.type == SDL_KEYDOWN)
		// {
		// 	switch (event.key.keysym.sym)
		// 	{
		// 		case SDLK_UP:
		// 		SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);	
		// 		scale++;
		// 		//std::cout << "Key Up Pressed!" << std::endl;
		// 		break;
					
		// 		case SDLK_DOWN:
		// 		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);	
		// 		scale--;
		// 		//std::cout << "Key Down Pressed!" << std::endl;
		// 		break;
					
		// 		default:
		// 			break;		
		// 	}
		// }
	}
}

//GAME CODE HERE
void Game::update(double dt)	
{
    //UNIFORM COLOR TEST
    float timeValue = SDL_GetTicks()/1000.0;
    float greenValue = (sin(timeValue) / 2.0f) + 0.5f;
    int vertexColorLocation = glGetUniformLocation(basicShader.GetProgram(), "ourColor"); //Can error check this
    glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);
}

void Game::draw(float dt)
{
	//Clear Screen
	glClearColor(0.0f,0.15f,0.3f,1.0f); //Clear with this color
	glClear(GL_COLOR_BUFFER_BIT); //Clears colors and fill
	//-----------------------------------------



	//Selects shader
	basicShader.bind();

	//Selects texture
	basicTexture.bind(0);

	//Selects Buffer & DRAW
	triangleMesh1.draw();

	//triangleMesh2->Draw();
	



	// Swap | --------------------------------
	display.swapBuffers();
}

void Game::dispose()
{
	display.dispose();
	SDL_Quit();
	std::cout << "Game Cleaned" << std::endl;

	triangleMesh1.dispose();
	basicShader.dispose();
	basicTexture.dispose();

	//TEST
	//delete triangleMesh1;
	//delete triangleMesh2;
	//delete basicShader;
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
