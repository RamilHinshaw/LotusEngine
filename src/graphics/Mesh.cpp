#include "Mesh.hpp"

Mesh::Mesh(Vertex* vertices, unsigned int numVertices)
{
    m_drawCount = numVertices;

    glGenVertexArrays(1, &m_vertexArrayObject); //Created space on gpu for VAO of 1 dimension
    glBindVertexArray(m_vertexArrayObject); //Let the gpu use the VAO to allow gpu functinos onto it

    //Move array buffer onto GPU
    glGenBuffers(NUM_BUFFERS, m_vertexArrayBuffers);
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[POSITION_VB]);
    glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(vertices[0]), vertices, GL_STATIC_DRAW);

    //Interpret Data on GPU
    glEnableVertexAttribArray(0);  //how to read the attributes of the array?
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0); //This set attribute of first var, vec3 = x,y,z for position

    glBindVertexArray(0); //Release
}

Mesh::~Mesh()
{
    glDeleteVertexArrays(1, &m_vertexArrayObject);
}


void Mesh::Draw()
{
    glBindVertexArray(m_vertexArrayObject);

    //Triangle mode, start, and endDrawCount
    glDrawArrays(GL_TRIANGLES, 0, m_drawCount);

    glBindVertexArray(0); //Release
}