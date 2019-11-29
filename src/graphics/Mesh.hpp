#pragma once


extern "C"
{ 
	#include <GL/glew.h>
}

#include "Vertex.hpp"

class Mesh
{    
    public:
        Mesh(Vertex vertices[], unsigned int arraySize);
        //Mesh(Vertex* vertices, unsigned int numVertices);
        virtual ~Mesh();

        void Draw();

    private:
        Mesh(const Mesh& other);
        void operator=(const Mesh& other);

        enum
        {
            POSITION_VB,
            NUM_BUFFERS
        };

        GLuint m_vertexArrayObject; //VAO
        GLuint m_vertexArrayBuffers[NUM_BUFFERS]; //VAB
        unsigned int m_drawCount;
};

