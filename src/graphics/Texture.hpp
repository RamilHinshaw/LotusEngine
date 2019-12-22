#pragma once

extern "C"
{ 
	#include <GL/glew.h>
    #include "../../thirdparty/stb/stb_image.h"
}

#include <string>


class Texture
{
    public:
        Texture(const std::string& fileName);
        virtual ~Texture();

        //Should have this inherent from some class since this is common
        void Bind(unsigned int unit); //Unit for multiple textures

    private:
        Texture(const Texture& other) {}

        //void operator={const Texture& other) {}
};