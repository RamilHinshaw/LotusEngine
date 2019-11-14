#include "Display.hpp"
#include <GL/glew.h>
        
Display::Display(const char *title, int width, int height)
{
    //Initialize subsytems, if cant initialize there is an error!
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{	
		//Initialize timer, audio, video, joystick, haptic (feedback), gamectonrller & event subsystems
		std::cout << "SDL Initialized Subsytems!" << std::endl;
		
        //Create Window
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);

		if (window) //Check if window was created successfully
		{
			std::cout << "Window created!" << std::endl;
		}

        // OPENGL
        SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8); //2**8 = 256 shades of red
        SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8); //2**8 = 256 shades of green
        SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8); //2**8 = 256 shades of blue
        SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8); //2**8 = 256 shades of alpha
        SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32); //2**8 = data in bits sdl will allocate for a pixel (8*4 =32)
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1); //Allocate space for a second window to draw on

        //OPENGL Context
        glContext = SDL_GL_CreateContext(window);

        GLenum status = glewInit(); //Finds opengl functions 

        if (status != GLEW_OK)
        {
            std::cerr <<"Glew failed to initialize!" << std::endl;
        }
	}

    else
    {
        std::cerr << "SDL2 failed to initialize!" << std::endl;
    }

}

Display::~Display()
{
    SDL_GL_DeleteContext(glContext);
    SDL_DestroyWindow(window);
}		

void Display::SwapBuffers()
{
    SDL_GL_SwapWindow(window);
}

void Display::Clear()
{
    
}

		