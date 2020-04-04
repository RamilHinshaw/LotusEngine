#include "opengl/Mesh.hpp"
#include "opengl/Shader.hpp"
#include "opengl/Texture.hpp"

#pragma once

#include <vector>

class Renderer
{
    public:
        void Render(); //Render All Verticies to buffer
        void Sort(); //Sort State Changes
        void Flush(); //Clean Buffer

    private:
        std::vector<Mesh> meshes;
        std::vector<Shader> shaders;
        std::vector<Texture> textures;
        // List of Meshes
        // List of Shaders
        // List of Textures
}