#pragma once

class Rect
{
    public:

        Rect(float x, float y, float width, float height) //ToDo: Use member initialization & put into cpp instead!
        {
            Set(x, y, width, height);
        }

        void Set(float x, float y, float width, float height)
        {
            this->x = x;
            this->y = x;
            this->width = width;
            this->height = height;
        }

    //Attributes for OpenGL
    private:

        float x;
        float y;
        float width;
        float height;


};