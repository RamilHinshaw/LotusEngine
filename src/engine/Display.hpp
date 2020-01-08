#pragma once

extern "C"
{ 
	#include <SDL2/SDL.h>
	#include "../thirdparty/glad/glad.h"
}

#include <iostream>

class Display{
	public:
		Display();
		Display(const char *title, int width, int height);	
		~Display();	

        void swapBuffers();
        void dispose();
		
	private:
		void createWindow(const char *title, int width, int height); //ToDo: Create in own class
		void setOpenGLAttributes();


		SDL_Window *window;
        SDL_GLContext glContext;

};