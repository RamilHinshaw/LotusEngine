#pragma once

extern "C"
{ 
	#include <SDL2/SDL.h>
	#include <GL/glew.h>
	//#include "../thirdparty/glad/glad.h"
}

#include <iostream>

class Display{
	public:
		Display();
		Display(const char *title, int width, int height);	
		~Display();	

        void swapBuffers();
        void dispose();

		float getHeight();
		float getWidth();
		
	private:
		void createWindow(const char *title, int width, int height); //ToDo: Create in own class
		void setOpenGLAttributes();


		SDL_Window *window;
        SDL_GLContext glContext;

		int m_height, m_width;
		bool test; //need this here to prevent shader from glitching????(float xPos, float yPos, float size)

};