#pragma once

extern "C"
{ 
	#include <SDL2/SDL.h>
}

#include <iostream>

class Time
{
    public:

        static void init(int fps);
        static void setTargetFPS(int fps);
        static void step();     //Used to update basic timer values every frame
        static void delay();    //Delays based on set targeted fps
        static int getFPS();
        static float deltaTime();
        static float fixedTime();
        static float time();
        static float preciseTime();

    private:
        Time();
        ~Time();


};
        //ToDo scope this correctly!
        static int m_fps;
        static int m_targetFPS;
        static int m_fpsCounter;
        static float m_deltaTime;
        static float m_currentTime;
        static float m_lastTime;
        static unsigned long m_counterStart;