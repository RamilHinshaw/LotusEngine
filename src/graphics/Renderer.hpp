//Singleton :/

#include "opengl/Mesh.hpp"
#include "opengl/MeshBuffer.hpp"
#include "opengl/TextMeshBuffer.hpp"

#include "opengl/Shader.hpp"
#include "opengl/Texture.hpp"
#include "opengl/Vertex.hpp"

#include "../common/Rect.hpp"
#include <glm/glm.hpp>

#include "../core/Display.hpp"

#include "Camera.hpp"


#pragma once

#include <vector>

//Works as a manager

class Renderer
{
    public:
        static void init(); //Load after resource manager!
        static void render(Camera *camera); //Render All Verticies to buffer
        static void sort(); //Sort State Changes
        static void flush(); //Clears Buffer in dynamic
        static void staticFlush(); //Clears Buffer in static
        static void organize(); //Organize based on priority to decrease draw calls

        //Texture Functions
        static void batch(Texture texture);

        //Mesh Functions (dynamic batch, and static batch)
        static void batch(Vertex vertices[], unsigned int verticeSize, unsigned int indices[], unsigned int indiceSize);
        static void staticBatch(Vertex vertices[], unsigned int verticeSize, unsigned int indices[], unsigned int indiceSize);

        //Text Batch
        static void textBatch(Vertex vertices[], unsigned int verticeSize, unsigned int indices[], unsigned int indiceSize);

        static void setActiveWindow(const Display &window);
        static Display getActiveWindow();

        static void dispose();

        //TEST!
        static Shader* getShader();
    private:
        Renderer(){}

};
        static std::vector<Texture> *batchedTextures;
        static std::vector<MeshBuffer> *batchedDynamicMeshes = new std::vector<MeshBuffer>;
        static std::vector<MeshBuffer> *batchedStaticMeshes;
        //static TextMeshBuffer textMeshBuffer; //Maybe an array based on bitmap types? or keep them in texture slots when generated?
        static std::vector<MeshBuffer> *batchedTextMeshes = new std::vector<MeshBuffer>;
        // static MeshBuffer *textMeshBuffer = new MeshBuffer();

        //Use Resource manager here instead!?!?!? Or helps load it here
        static std::vector<Shader> shaders;
        //And Textures!?!?!?

        //Window
       static Display activeWindow;


       //TEST!!!
        // static Texture basicTexture;
		static Shader *basicShader;
