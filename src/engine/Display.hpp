#pragma once

extern "C"
{ 
	#include <SDL2/SDL.h>
}

#include <iostream>

class Display{
	public:
		Display();
		Display(const char *title, int width, int height);	
		~Display();	

        void swapBuffers();
        void Clean();
		
	private:
		void createWindow(const char *title, int width, int height); //ToDo: Create in own class
		void setOpenGLAttributes();


		SDL_Window *window;
        SDL_GLContext glContext;

};