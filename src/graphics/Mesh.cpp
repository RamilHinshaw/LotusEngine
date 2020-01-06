#include "Mesh.hpp"

#include <iostream>
#include <glm/glm.hpp>

Mesh::Mesh()
{

}

Mesh::Mesh(Vertex vertices[], unsigned int arraySize)
{
    m_drawCount = arraySize;
    //std::cout << sizeof(vertices) << " / " << sizeof(Vertex) << " = " << sizeof(vertices)/sizeof(Vertex) << std::endl;

    //VAO
    glGenVertexArrays(1, &m_vertexArrayObject); //Created space on gpu for VAO of 1 dimension
    glBindVertexArray(m_vertexArrayObject); //Let the gpu use the VAO to allow gpu functions onto it

    //Create Empty spot in VRAM
    glGenBuffers(NUM_BUFFERS, m_vertexArrayBuffers); //ID the buffer
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[POSITION_VB]); //tell opengl to select the buffer

    //Move data into recent new buffer
    glBufferData(GL_ARRAY_BUFFER, m_drawCount * sizeof(Vertex), vertices, GL_STATIC_DRAW);

    //Interpret Data on GPU |   how to read the attributes of the array of what index

    //Position
    glEnableVertexAttribArray(0);  
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0); //This set attribute of first var, vec3 = x,y,z for position

    //Texture Coord
    glEnableVertexAttribArray(1);  
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*) (sizeof(GL_FLOAT) * 3) ); 

    //Color
    glEnableVertexAttribArray(1);  
    glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*) (sizeof(GL_FLOAT) * 6) ); 

    glBindVertexArray(0); //Release    
}

Mesh::~Mesh()
{
}

void Mesh::dispose()
{
    glDeleteVertexArrays(1, &m_vertexArrayObject);
}

void Mesh::draw()
{
    //Select buffer to draw on
    glBindVertexArray(m_vertexArrayObject);

    //glEnable(GL_PROGRAM_POINT_SIZE);
    //glPointSize(10.0);

    //Triangle mode, start, and endDrawCount
    glDrawArrays(GL_TRIANGLES, 0, m_drawCount);

    glBindVertexArray(0); //Release
}