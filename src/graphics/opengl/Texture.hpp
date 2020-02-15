#pragma once

extern "C"
{ 
    #include <GL/glew.h>
	//#include "../../thirdparty/glad/glad.h"
    #include "../../thirdparty/stb/stb_image.h"
}

#include <string>
#include <iostream>
#include <glm/glm.hpp>


class Texture
{
    public:
        Texture();
        Texture(const std::string& fileName);
        virtual ~Texture();

        //Should have this inherent from some class since this is common
        void bind(unsigned int unit); //Unit for multiple textures
        void dispose();
        glm::vec2 getSize();
        //SetMipMap();

    private:

        //Texture(const Texture& other) {} copy constructor
        int m_width, m_height, m_channels;
        char giveByteToOpenglGOD; //This is here to fix some VERY odd opengl bug, prevents textures from being weird, must appease the opengl god | Error

        GLuint m_texture;

        //void operator={const Texture& other) {}
};