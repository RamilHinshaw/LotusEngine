#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
// #include <SDL2/SDL_ttf.h>
#include <iostream>
// #include <stdio.h>

class Display{
	public:
		Display(const char *title, int width, int height);
		~Display();		

        void SwapBuffers();
        void Clear();
		
	private:
		SDL_Window *window;
        SDL_GLContext glContext;

};