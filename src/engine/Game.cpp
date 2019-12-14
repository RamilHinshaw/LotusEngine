
#include "Game.hpp"
#include <glm/glm.hpp>


SDL_Texture *playerTex;
SDL_Rect srcR, destR;

Game::Game()
{	}
Game::~Game()
{	}

void Game::init(const char *title, int width, int height)
{
	//Initialize subsytems, if cant initialize there is an error!
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{	
		//Initialize timer, audio, video, joystick, haptic (feedback), gamecontroller & event subsystems
		std::cout << "SDL Initialized Subsystems!" << std::endl;

		//Function here to Create Window then bind to display
		
		display = new Display(title, width, height); //Window also created here

		//TEST
		basicShader = new Shader("./assets/shaders/basicShader"); //Load Shaders (both vertext and fragment)

		Vertex vertices1[] = {
							Vertex(glm::vec3(-0.5,	0.5,	0)),
							Vertex(glm::vec3(-0.5,	-0.5,	0)),
							Vertex(glm::vec3(0.5,	0.5,	0)),
			

							Vertex(glm::vec3(0.5,	0.5,	0)),
							Vertex(glm::vec3(-0.5,	-0.5,	0)),
							Vertex(glm::vec3(0.5,	-0.5,	0))
							};

		Vertex vertices2[] = {
					Vertex(glm::vec3(0.5,	0.5,	0)),
					Vertex(glm::vec3(0.5,	-0.5,	0)),
					Vertex(glm::vec3(-0.5,	-0.5,	0))
					};

		
		//Vertex test = Vertex(glm::vec3(-0.5,	-0.5,	0));


		//std::cout << sizeof(Vertex) << " VS " << sizeof(vertices)/sizeof(vertices[0]) << std::endl;
		//std::cout << sizeof(vertices) << " / " << sizeof(vertices[0]) << " = " << sizeof(vertices)/sizeof(vertices[0]) << std::endl;
		//std::cout << "Test: " << sizeof(test) << std::endl;

		triangleMesh1 = new Mesh(vertices1, sizeof(vertices1)/sizeof(vertices1[0]));
		triangleMesh2 = new Mesh(vertices2, sizeof(vertices2)/sizeof(vertices2[0]));




		//------------------------------------------------------

		isRunning = true;

	}

    else
    {
        std::cerr << "SDL2 failed to initialize!" << std::endl;
    }



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

void Game::update(double dt)	
{

}
void Game::draw(float dt)
{
	//Clear Screen
	glClearColor(0.0f,0.15f,0.3f,1.0f); //Clear with this color
	glClear(GL_COLOR_BUFFER_BIT); //Clears colors and fill
	//-----------------------------------------

	//Selects shader
	basicShader->bind();

	//Selects Buffer & DRAW
	triangleMesh1->Draw();
	//triangleMesh2->Draw();
	



	// Swap | --------------------------------
	display->swapBuffers();
}

void Game::clean()
{
	display->~Display();
	SDL_Quit();
	std::cout << "Game Cleaned" << std::endl;

	//TEST
	delete triangleMesh1;
	delete triangleMesh2;
	delete basicShader;
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
