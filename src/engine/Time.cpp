#include "Time.hpp"

void Time::init(int fps)
{
    m_counterStart = SDL_GetPerformanceCounter();
}

void Time::setFPS(int fps)
{

}

void Time::step()
{
    m_deltaTime = (m_currentTime - m_lastTime) / 1000.0 ;
}

float Time::deltaTime()
{
    return 0;
}

float Time::fixedTime()
{
    return 0;
}

float Time::time()
{
    return 0;
}