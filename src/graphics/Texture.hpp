#pragma once

extern "C"
{ 
    #include "../engine/glad.h"
    #include "../../thirdparty/stb/stb_image.h"
}

#include <string>
#include <iostream>


class Texture
{
    public:
        Texture(const std::string& fileName);
        virtual ~Texture();

        //Should have this inherent from some class since this is common
        void Bind(unsigned int unit); //Unit for multiple textures
        //SetMipMap();

    private:
        Texture(const Texture& other) {}
        GLuint m_texture;

        //void operator={const Texture& other) {}
};