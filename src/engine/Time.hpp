#pragma once

class Time
{
    public:
        Time();
        ~Time();

        void setFPS(int fps);
        float deltaTime();
        float fixedTime();
        float time();

    private:
        int m_fps;
};