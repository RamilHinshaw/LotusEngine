#include "MeshBuffer.hpp"

#include <iostream>
#include <glm/glm.hpp>

#define BUFFER_SIZE 1000
// #define BUFFER_SIZE_MORE up to 65545 bytes considering Vertex Size, 65545/VertexSize // play it safe is to use 16-bit (GL_UNSIGNED_SHORT) 

MeshBuffer::MeshBuffer()
{
    std::cout << "Mesh Empty  Constructor Called???" << std::endl;
}

MeshBuffer::MeshBuffer(Vertex vertices[], unsigned int verticeSize, unsigned int indices[], unsigned int indiceSize)
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

    //Allocate the memory
    glBufferData(GL_ARRAY_BUFFER, BUFFER_SIZE * sizeof(Vertex), nullptr, GL_DYNAMIC_DRAW);   //Move data into recent new buffer

    glBufferSubData(GL_ARRAY_BUFFER, 0, verticeSize * sizeof(Vertex), vertices);

    //EBO
    if (indiceSize != 0)    //Todo: Refactor
    {
        m_useElementBuffer = true;
        m_drawCount = indiceSize;
        glGenBuffers(1, &m_EBO); // Pointer to buffer
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO); //Use buffer
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_drawCount * sizeof(unsigned int), indices, GL_STATIC_DRAW);
    }

    // ***** ATTRIBUTES *****
    //Interpret Data on GPU |   how to read the attributes of the array of what index

    //Position  - Layout 0
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0); //This set attribute of first var, vec3 = x,y,z for position  
    glEnableVertexAttribArray(0);   

    //Color - Layout 1
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*) (sizeof(GL_FLOAT) * 3) ); 
    glEnableVertexAttribArray(1);  

    //Texture Coord - Layout 2
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*) (sizeof(GL_FLOAT) * 7) ); 
    glEnableVertexAttribArray(2);  

    //Texture ID - Layout 3
    glVertexAttribPointer(3, 1, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*) (sizeof(GL_FLOAT) * 9) ); 
    glEnableVertexAttribArray(3);  

    // **********************

    glBindBuffer(GL_ARRAY_BUFFER, 0); //Can safetly unbound this but keep EBO
    glBindVertexArray(0); //Release    
}

MeshBuffer::MeshBuffer(Vertex vertices[], unsigned int verticeSize, unsigned int indices[], unsigned int indiceSize, GLenum glDrawType) 
: Mesh(vertices, verticeSize, indices, indiceSize)  //Constructor Delegate
{
    m_GLDrawType = glDrawType;
}

MeshBuffer::MeshBuffer(Vertex vertices[], unsigned int verticeSize, GLenum glDrawType) 
: MeshBuffer(vertices, verticeSize, 0, 0)  //Constructor Delegate
{
    m_GLDrawType = glDrawType;
}

MeshBuffer::~MeshBuffer()
{
    std::cout << "Mesh Destructor Called" << std::endl;
}

void MeshBuffer::dispose()
{
    glDeleteVertexArrays(1, &m_VAO);
}

void MeshBuffer::draw()
{
    //Select buffer to draw on
    glBindVertexArray(m_VAO);

    //glEnable(GL_PROGRAM_POINT_SIZE);
    //glPointSize(10.0);

    //Triangle mode, start, and endDrawCount

    if (m_useElementBuffer == false) 
    {
        glDrawArrays(GL_TRIANGLES, 0, m_drawCount);
    }
    
    else
    {
        glDrawElements(m_GLDrawType, m_drawCount, GL_UNSIGNED_INT, 0);
    }

    // glBindVertexArray(0); //Release
}