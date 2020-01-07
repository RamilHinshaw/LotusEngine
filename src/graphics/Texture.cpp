#define STB_IMAGE_IMPLEMENTATION
#include "Texture.hpp"

Texture::Texture()
{

}

Texture::Texture(const std::string& fileName)
{
    int width, height, channels;
    stbi_set_flip_vertically_on_load(true); //Global not thread safe!
    unsigned char* imageData = stbi_load(fileName.c_str(),
                                         &width,
                                         &height,
                                         &channels,
                                         STBI_rgb_alpha);

    if (imageData)
    {
        glGenTextures(1, &m_texture); //Create buffer
        glBindTexture(GL_TEXTURE_2D, m_texture);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); //Wrap on X
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); //Wrap on Y

        //Filtering for 3D
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR); //Use this instead when using mipmaps
        //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, imageData);
        glGenerateMipmap(GL_TEXTURE_2D);
    }

    else
    {
        std::cout << "Failed to load texture " + fileName << std::endl;
    }

    stbi_image_free(imageData);
}

Texture::~Texture()
{

}

void Texture::dispose()
{
    glDeleteTextures(0, &m_texture);
}


void Texture::bind(unsigned int unit)
{
    glBindTexture(GL_TEXTURE_2D, m_texture);
}