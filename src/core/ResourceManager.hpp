#pragma once

#include <map>
#include <string>

#include "../graphics/opengl/Shader.hpp"
#include "../graphics/opengl/Mesh.hpp"
#include "../graphics/opengl/Vertex.hpp"
#include "../graphics/opengl/Texture.hpp"

class ResourceManager 
{
    public:

        static Texture LoadTexture(const std::string &file);
        static Texture GetTexture(const std::string &file);
        static void Clearextures();

        static Texture LoadShader(const std::string &file);
        static Texture GetShader(const std::string &file);
        static void ClearShaders();

        static Texture LoadFont(const std::string &file);
        static Texture GetFont(const std::string &file);
        static void ClearTextures();

        static void Clear(); //Flushes everything!




    private:
        ResourceManager(){}

        static std::map<std::string, Texture>  Textures;
        static std::map<std::string, Shader>  Shaders;

};
