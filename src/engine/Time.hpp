#pragma once

extern "C"
{ 
	#include <SDL2/SDL.h>
}

class Time
{
    public:

        static void init(int fps);
        static void setFPS(int fps);
        static void step();
        static float deltaTime();
        static float fixedTime();
        static float time();

    private:
        Time();
        ~Time();


};
        //ToDo scope this correctly!
        static int m_fps;
        static int m_fpsTarget;
        static int m_fpsCounter;
        static float m_deltaTime;
        static float m_currentTime;
        static float m_lastTime;
        static unsigned long m_counterStart;