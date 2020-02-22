#pragma once

#include "InputConstants.hpp"

extern "C"
{ 
	#include <SDL2/SDL.h>
}


class Input 
{
    public:

        static void init();
    
        static bool getKey(Key key);

        static bool getKeyDown(Key key);

        static bool getKeyUp(Key key);

        static void dispose();


    // private:
        static void UpdateCurrentState();
        static void UpdatePreviousState();


};
static int *numKeys = new int(284);
static const Uint8 *currentKeyboardState = SDL_GetKeyboardState(numKeys);
static Uint8 *previousKeyboardState = new Uint8[*numKeys];