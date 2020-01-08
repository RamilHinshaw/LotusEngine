#pragma once


extern "C"
{ 
	#include "../thirdparty/glad/glad.h"
    //#include "../../thirdparty/glad/glad.h" //ToDo: Remove relative pathing!
}

#include "Vertex.hpp"
#include "Texture.hpp"

class Mesh
{    
    public:
        Mesh();
        Mesh(Vertex vertices[], unsigned int verticeSize, unsigned int indices[], unsigned int indiceSize);
        //Mesh(Vertex vertices[], unsigned int arraySize, Texture texture);
        //Mesh(Vertex* vertices, unsigned int numVertices);
        virtual ~Mesh();

        void draw();
        void dispose(); //Refactor from some interface (common pattern)

    private:
        // Mesh(const Mesh& other);
        // void operator=(const Mesh& other);

        enum
        {
            POSITION_VB,
            NUM_BUFFERS
        };

        GLuint m_VAO; //Vertex Array Objects
        GLuint m_VBO[NUM_BUFFERS]; //Vertex Buffer Object
        GLuint m_EBO;   // Element buffer Object

        unsigned int m_drawCount;
};

