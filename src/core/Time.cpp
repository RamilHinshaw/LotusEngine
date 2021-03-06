#include "Time.hpp"

void Time::init(int targetFPS)
{
    #ifdef _WIN32 
        m_counterStart = SDL_GetTicks();
    #else
        m_counterStart = SDL_GetPerformanceCounter();
    #endif

    m_targetFPS = 1.0/targetFPS;
}

void Time::setTargetFPS(int fps)
{
    m_targetFPS = fps;
}

void Time::step()   
{
    //Delta Time stuff (prolly put in own class)
    m_lastTime = m_currentTime;			


    #ifdef _WIN32 
        m_currentTime = SDL_GetTicks() - m_counterStart;
        m_deltaTime = (m_currentTime - m_lastTime) / 1000.0 ;
    #else
        m_currentTime = SDL_GetPerformanceCounter() - m_counterStart;
        m_deltaTime = (m_currentTime - m_lastTime) / 1000000000.0 ;
    #endif

    updateFrameCounter();
}

void Time::delay()
{
    // std::cout << "dt: " << m_deltaTime << " VS tFPS " << m_targetFPS << std::endl;

    if (m_deltaTime < m_targetFPS)
    {	
        SDL_Delay( (m_targetFPS - (m_deltaTime / 100.0) ) * 1000.0);
    }
}

int Time::getFPS()
{
    return 	m_calculated_fps;
}

void Time::updateFrameCounter()   //count frames
{
    m_fpsCounter++;

    //Count FPS
    if (SDL_GetTicks()/1000.0f >= 1.0 * m_fps_timer_interval)
    {
        m_calculated_fps = m_fpsCounter;
        m_fpsCounter = 0;

        m_total_fps += m_calculated_fps;
        m_avg_fps = m_total_fps/m_fps_timer_interval;

        // std::cout << "[div by] " << m_fps_timer_interval << std::endl;

        m_fps_timer_interval++;
    }
}

void Time::printFPS()
{
    if (SDL_GetTicks()/1000.0f >= 1.0 * m_fps_timer_interval)
    {			
        std::cout << "[Step] " << m_fps_timer_interval;
        std::cout << " [FPS] " << m_calculated_fps << " [Avg] " << m_avg_fps << std::endl;
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
    return SDL_GetTicks()/1000.0f;
}

float Time::preciseTime()
{
    return SDL_GetTicks();
}