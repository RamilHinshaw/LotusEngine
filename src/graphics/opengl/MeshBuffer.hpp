//WIP WILL REPLACE MESH AND MESH WILL JUST BE USED FOR COLLECTION OF VERTEX!

// DOES 3 THINGS
// COLLECTION OF VERTICES
// COLLECTION OF INDICES
// DRAW TYPE (Triangle, Grid, Etc)

#pragma once


extern "C"
{ 
    #include <GL/glew.h>
	// #include "../../thirdparty/glad/glad.h"
    //#include "../../thirdparty/glad/glad.h" //ToDo: Remove relative pathing!
}

#include "Vertex.hpp"
#include "Texture.hpp"

#define MAXQUADS 10000

const size_t MaxQuadCount = 10000;
const size_t MaxVertexCount = MaxQuadCount * 4;
const size_t MaxIndexCount = MaxQuadCount * 6;

class MeshBuffer
{    
    public:
        MeshBuffer();
        // MeshBuffer(Vertex vertices[], unsigned int verticeSize);
        // MeshBuffer(Vertex vertices[], unsigned int verticeSize, unsigned int indices[], unsigned int indiceSize);
        // MeshBuffer(Vertex vertices[], unsigned int verticeSize, unsigned int indices[], unsigned int indiceSize, GLenum glDrawType);
        // MeshBuffer(Vertex vertices[], unsigned int verticeSize, GLenum glDrawType);
        //MeshBuffer(Vertex* vertices, unsigned int numVertices);
        virtual ~MeshBuffer();

        void batch(Vertex vertices[], unsigned int verticeSize, unsigned int indices[], unsigned int indiceSize);
        void draw();

        void flush();
        void dispose(); //Refactor from some interface (common pattern)

    private:
        // MeshBuffer(const Mesh& other);
        // void operator=(const Mesh& other);

        enum
        {
            POSITION_VB,
            NUM_BUFFERS
        };

        GLuint m_VAO; //Vertex Array Objects
        GLuint m_VBO[NUM_BUFFERS]; //Vertex Buffer Object
        GLuint m_EBO;   // Element buffer Object
        GLenum m_GLDrawType = GL_TRIANGLES;

        // bool m_useElementBuffer; 

        // unsigned int m_drawCount;

        Vertex m_vertices[40000];
        // Vertex *m_vertices = new Vertex[40000];

        unsigned int m_indices[60000];
        // unsigned int *m_indices = new unsigned int[60000];        

        unsigned int m_vertexCount = 0;
        unsigned int m_indexCount = 0;
};

