#include "Input.hpp"

#include <iostream>

void Input::init()
{

}

bool Input::getKey(Key key)
{
    // UpdateCurrentState();
    return currentKeyboardState[key];
}

bool Input::getKeyDown(Key key)
{
    bool buttonState;

    buttonState = (currentKeyboardState[key] && !previousKeyboardState[key])? true : false;
    // UpdatePreviousState();

    return buttonState;
}

bool Input::getKeyUp(Key key)
{
    bool buttonState;

    buttonState = (!currentKeyboardState[key] && previousKeyboardState[key])? true : false;
    // UpdatePreviousState();

    return buttonState;
}

void Input::UpdateCurrentState()
{
    //This automatically gets updated from SDL_PollEvent from Game.cpp
}

void Input::UpdatePreviousState()
{
    //*previousKeyboardState = *currentKeyboardState;
    for (int i = 0; i <= *numKeys; i++)
    {
        previousKeyboardState[i] = currentKeyboardState[i];
    }

    //*previousKeyboardState = *currentKeyboardState;

    // memcpy(previousKeyboardState, currentKeyboardState, 284 * sizeof(const Uint8));
}


void Input::dispose()
{
    delete numKeys;
    numKeys = nullptr;
    delete previousKeyboardState;
    previousKeyboardState = nullptr;
}