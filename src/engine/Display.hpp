#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
// #include <SDL2/SDL_ttf.h>
#include <iostream>
// #include <stdio.h>

class Display{
	public:
		Display(const char *title, int xpos, int ypos, int width, int height, bool fullscreen);
		~Display();		
		
	private:
		SDL_Window *window;

};