#pragma once

extern "C"
{ 
	#include "../thirdparty/glad/glad.h"
    #include "../thirdparty/stb/stb_image.h"
}

#include <string>
#include <iostream>


class Texture
{
    public:
        Texture();
        Texture(const std::string& fileName);
        virtual ~Texture();

        //Should have this inherent from some class since this is common
        void bind(unsigned int unit); //Unit for multiple textures
        void dispose();
        //SetMipMap();

    private:

        //Texture(const Texture& other) {} copy constructor
        GLuint m_texture;

        //void operator={const Texture& other) {}
};