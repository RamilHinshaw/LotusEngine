#include "opengl/Mesh.hpp"
#include "opengl/Shader.hpp"
#include "opengl/Texture.hpp"
#include "opengl/Vertex.hpp"

#include "../common/Rect.hpp"
#include <glm/glm.hpp>

#pragma once

#include <vector>

//Works as a manager

class Renderer
{
    public:
        void render(); //Render All Verticies to buffer
        void sort(); //Sort State Changes
        void flush(); //Clean Buffer

        //Texture Functions
        void batch(Texture texture);

        //Mesh Functions
        void batch(Rect rect);
        void batch(Rect rect, glm::vec4 color);

        //void

    private:
        std::vector<Texture> batchedTextures;
        std::vector<Mesh> batchedDynamicMeshes;
        std::vector<Mesh> batchedStaticMeshes;
        std::vector<Shader> shaders;

}