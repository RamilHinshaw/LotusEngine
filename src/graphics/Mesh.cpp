#include "Mesh.hpp"

#include <iostream>
#include <glm/glm.hpp>

Mesh::Mesh()
{

}

Mesh::Mesh(Vertex vertices[], unsigned int verticeSize, unsigned int indices[], unsigned int indiceSize)
{
    m_drawCount = verticeSize;
    //m_indices = indices;
    //std::cout << sizeof(vertices) << " / " << sizeof(Vertex) << " = " << sizeof(vertices)/sizeof(Vertex) << std::endl;

    //VAO
    glGenVertexArrays(1, &m_VAO); //Created space on gpu for VAO of 1 dimension
    glBindVertexArray(m_VAO); //Let the gpu use the VAO to allow gpu functions onto it

    //VBO                      | Create Empty spot in VRAM
    glGenBuffers(NUM_BUFFERS, m_VBO); //ID the buffer
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO[POSITION_VB]); //tell opengl to select the buffer
    glBufferData(GL_ARRAY_BUFFER, m_drawCount * sizeof(Vertex), vertices, GL_STATIC_DRAW);   //Move data into recent new buffer

    //EBO
    m_drawCount = indiceSize;
    glGenBuffers(1, &m_EBO); // Pointer to buffer
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO); //Use buffer
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_drawCount * sizeof(unsigned int), indices, GL_STATIC_DRAW);


    // ***** ATTRIBUTES *****
    //Interpret Data on GPU |   how to read the attributes of the array of what index

    //Position
    glEnableVertexAttribArray(0);  
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0); //This set attribute of first var, vec3 = x,y,z for position   

    //Color
    glEnableVertexAttribArray(1);  
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*) (sizeof(GL_FLOAT) * 3) ); 

    //Texture Coord
    glEnableVertexAttribArray(2);  
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*) (sizeof(GL_FLOAT) * 7) ); 

    glBindVertexArray(0); //Release    
}

Mesh::~Mesh()
{
}

void Mesh::dispose()
{
    glDeleteVertexArrays(1, &m_VAO);
}

void Mesh::draw()
{
    //Select buffer to draw on
    glBindVertexArray(m_VAO);

    //glEnable(GL_PROGRAM_POINT_SIZE);
    //glPointSize(10.0);

    //Triangle mode, start, and endDrawCount
    //glDrawArrays(GL_TRIANGLES, 0, m_drawCount); //Deprecated for indices
    glDrawElements(GL_TRIANGLES, m_drawCount, GL_UNSIGNED_INT, 0);

    glBindVertexArray(0); //Release
}