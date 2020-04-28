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

class MeshBuffer
{    
    public:
        MeshBuffer();
        MeshBuffer(Vertex vertices[], unsigned int verticeSize);
        MeshBuffer(Vertex vertices[], unsigned int verticeSize, unsigned int indices[], unsigned int indiceSize);
        MeshBuffer(Vertex vertices[], unsigned int verticeSize, unsigned int indices[], unsigned int indiceSize, GLenum glDrawType);
        MeshBuffer(Vertex vertices[], unsigned int verticeSize, GLenum glDrawType);
        //MeshBuffer(Vertex* vertices, unsigned int numVertices);
        virtual ~MeshBuffer();

        void draw();
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

        bool m_useElementBuffer; 

        unsigned int m_drawCount;
};

