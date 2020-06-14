#define STB_IMAGE_IMPLEMENTATION
#include "Texture.hpp"

Texture::Texture()
{

}

Texture::Texture(const std::string& fileName)
{
    // int width, height, channels;
    // stbi_set_flip_vertically_on_load(true); //Global not thread safe!
    unsigned char* imageData = stbi_load(fileName.c_str(),
                                         &m_width,
                                         &m_height,
                                         &m_channels,
                                         0);

    // m_width = width;
    // m_height = height;
    // m_channels = channels;

    if (imageData)
    {
        GLenum format;
        if (m_channels == 1)
            format = GL_RED;
        else if (m_channels == 3)
            format = GL_RGB;
        else if (m_channels == 4)
            format = GL_RGBA;

        glGenTextures(1, &m_texture); //Create buffer
        glBindTexture(GL_TEXTURE_2D, m_texture);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); //Wrap on X
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); //Wrap on Y

        //Filtering for 3D
        //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR); //Use this instead when using mipmaps
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        glTexImage2D(GL_TEXTURE_2D, 0, format, m_width, m_height, 0, format, GL_UNSIGNED_BYTE, imageData);
        //glGenerateMipmap(GL_TEXTURE_2D);
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

glm::vec2 Texture::getSize()
{
    return glm::vec2(m_width, m_height);
}

void Texture::bind()
{
    std::cout << "bind texture: " << m_texture << std::endl;
    glBindTexture(GL_TEXTURE_2D, m_texture);
}