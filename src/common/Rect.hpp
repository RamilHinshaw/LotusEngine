#pragma once

class Rect
{
    public:
        
        Rect(){}

        Rect(float x, float y, float width, float height) //ToDo: Use member initialization & put into cpp instead!
        {
            Set(x, y, width, height);
        }

        void Set(const float& x, const float& y, const float& width, const float& height)
        {
            this->x = x;
            this->y = x;
            this->width = width;
            this->height = height;
        }

        const float& Width() const
        {
            return width;
        }

        const float& Height() const
        {
            return height;
        }
        
        const float& X() const
        {
            return x;
        }

        const float& Y() const
        {
            return y;
        }

    //Attributes for OpenGL
    private:

        float x;
        float y;
        float width;
        float height;


};