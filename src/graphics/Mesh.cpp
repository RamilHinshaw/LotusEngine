#include "Mesh.hpp"

#include <iostream>

Mesh::Mesh(Vertex vertices[], unsigned int arraySize)
{
    m_drawCount = arraySize;
    //std::cout << sizeof(vertices) << " / " << sizeof(Vertex) << " = " << sizeof(vertices)/sizeof(Vertex) << std::endl;

    glGenVertexArrays(1, &m_vertexArrayObject); //Created space on gpu for VAO of 1 dimension
    glBindVertexArray(m_vertexArrayObject); //Let the gpu use the VAO to allow gpu functions onto it

    //Create Empty spot in VRAM
    glGenBuffers(NUM_BUFFERS, m_vertexArrayBuffers); //ID the buffer
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[POSITION_VB]); //tell opengl to select the buffer

    //Move data into recent new buffer
    glBufferData(GL_ARRAY_BUFFER, m_drawCount * sizeof(Vertex), vertices, GL_STATIC_DRAW);

    //Interpret Data on GPU
    glEnableVertexAttribArray(0);  //how to read the attributes of the array of what index
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0); //This set attribute of first var, vec3 = x,y,z for position

    glBindVertexArray(0); //Release
}

Mesh::~Mesh()
{
    glDeleteVertexArrays(1, &m_vertexArrayObject);
}


void Mesh::Draw()
{
    //Select buffer to draw on
    glBindVertexArray(m_vertexArrayObject);

    //Triangle mode, start, and endDrawCount
    glDrawArrays(GL_TRIANGLES, 0, m_drawCount);

    glBindVertexArray(0); //Release
}