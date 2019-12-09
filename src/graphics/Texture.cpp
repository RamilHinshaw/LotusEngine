#include "Texture.hpp"

Texture::Texture(const std::string& fileName)
{
    stbi_load();

    stbi_image_free();
}

Texture::~Texture()
{

}

void Texture::Bind(unsigned int unit)
{


}