#include "Time.hpp"

void Time::init(int targetFPS)
{
    m_counterStart = SDL_GetPerformanceCounter();
    m_targetFPS = targetFPS;
}

void Time::setTargetFPS(int fps)
{
    m_targetFPS = fps;
}

void Time::step()   
{
    //Delta Time stuff (prolly put in own class)
    m_lastTime = m_currentTime;			

    m_currentTime = SDL_GetPerformanceCounter() - m_counterStart;
    m_deltaTime = (m_currentTime - m_lastTime) / 1000000000.0 ;

    updateFPSCounter();
}

void Time::delay()
{
    if (m_deltaTime < m_targetFPS)
    {	
        SDL_Delay( (m_targetFPS - (m_deltaTime / 100.0) ) * 1000.0);
    }
}

int Time::getFPS()
{
    return 	m_calculated_fps;
}

void Time::updateFPSCounter()
{
    m_fpsCounter++;

    //Count FPS
    if (SDL_GetTicks()/1000.0f >= 1.0 * m_fps_timer_interval)
    {			
        m_fps_timer_interval++;
        m_calculated_fps = m_fpsCounter;
        m_fpsCounter = 0;
    }
}

void Time::printFPS()
{
    if (SDL_GetTicks()/1000.0f >= 1.0 * m_fps_timer_interval)
    {			
        std::cout << "[FPS] " << m_calculated_fps << std::endl;
    }
}

float Time::deltaTime()
{
    return m_deltaTime;
}

float Time::fixedTime()
{
    std::cerr << "Not Implemented!" << std::endl;
    return 0;
}

float Time::time()
{
    return SDL_GetTicks();
}

float Time::preciseTime()
{
    return SDL_GetTicks();
}