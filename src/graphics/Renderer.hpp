//Singleton :/

#include "opengl/Mesh.hpp"
#include "opengl/MeshBuffer.hpp"

#include "opengl/Shader.hpp"
#include "opengl/Texture.hpp"
#include "opengl/Vertex.hpp"

#include "../common/Rect.hpp"
#include <glm/glm.hpp>

#include "../core/Display.hpp"


#pragma once

#include <vector>

//Works as a manager

class Renderer
{
    public:
        static void init(); //Load after resource manager!
        static void render(); //Render All Verticies to buffer
        static void sort(); //Sort State Changes
        static void flush(); //Clears Buffer in dynamic
        static void staticFlush(); //Clears Buffer in static
        static void organize(); //Organize based on priority to decrease draw calls

        //Texture Functions
        static void batch(Texture texture);

        //Mesh Functions (dynamic batch, and static batch)
        static void batch(Vertex vertices[], unsigned int verticeSize, unsigned int indices[], unsigned int indiceSize);
        static void staticBatch(Vertex vertices[], unsigned int verticeSize, unsigned int indices[], unsigned int indiceSize);

        static void setActiveWindow(const Display &window);
        static Display getActiveWindow();

};
        static std::vector<Texture> *batchedTextures;
        static std::vector<MeshBuffer> *batchedDynamicMeshes = new std::vector<MeshBuffer>;
        static std::vector<MeshBuffer> *batchedStaticMeshes;
        static std::vector<Shader> shaders;

        //Window
       static Display activeWindow;

