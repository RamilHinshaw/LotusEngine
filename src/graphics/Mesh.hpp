#pragma once


extern "C"
{ 
	#include <GL/glew.h>
}

#include "Vertex.hpp"

class Mesh
{    
    public:
        Mesh();
        Mesh(Vertex vertices[], unsigned int arraySize);
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

        GLuint m_vertexArrayObject; //VAO
        GLuint m_vertexArrayBuffers[NUM_BUFFERS]; //VAB
        GLuint m_indexBufferObject; //Remove duplicates

        unsigned int m_drawCount;
};

