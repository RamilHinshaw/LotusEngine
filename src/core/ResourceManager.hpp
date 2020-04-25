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

    static void Clear();




    static std::map<std::string, Shader>  Shaders;

    private:
    ResourceManager(){}


};
