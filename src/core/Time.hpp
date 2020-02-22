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
        static void printFPS();  //Debug use only
        static float deltaTime();
        static float fixedTime();
        static float time();
        static float preciseTime();

    private:
    
        static void updateFrameCounter();
        // Time();
        // ~Time();
};

        //ToDo: scope this correctly!
        // static int m_fps;           //
        static double m_targetFPS;     //fps engine will try to reach

        static int m_fpsCounter = 0;            //used to count for fps every frame
        static int m_fps_timer_interval = 1;    //used to calculate next frameStep
        static int m_calculated_fps = -1;       //calculated fps between frames
        static int m_total_fps;
        static int m_avg_fps;

        static float m_deltaTime;   //Time between frams
        static uint64_t m_currentTime; //used for delta time
        static uint64_t m_lastTime;    //used for delta time
        static uint64_t m_counterStart; //used to subtract initial startup time for more accurate delta time