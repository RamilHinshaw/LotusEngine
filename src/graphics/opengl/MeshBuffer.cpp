#include "MeshBuffer.hpp"

#include <iostream>
#include <glm/glm.hpp>

//#define BUFFER_SIZE 10000

// #define BUFFER_SIZE_MORE up to 65545 bytes considering Vertex Size, 65545/VertexSize // play it safe is to use 16-bit (GL_UNSIGNED_SHORT) 

MeshBuffer::MeshBuffer()
{
    //VAO
    glGenVertexArrays(1, &m_VAO); //Created space on gpu for VAO of 1 dimension

    glBindVertexArray(m_VAO); //Let the gpu use the VAO to allow gpu functions onto it

    //VBO                      | Create Empty spot in VRAM
    glGenBuffers(NUM_BUFFERS, m_VBO); //ID the buffer
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO[POSITION_VB]); //tell opengl to select the buffer

    //Create size for the memory
    glBufferData(GL_ARRAY_BUFFER, MaxVertexCount * sizeof(Vertex), nullptr, GL_DYNAMIC_DRAW);   //Move data into recent new buffer

    // //Write ontop of buffer of existing allocated memory
    // glBufferSubData(GL_ARRAY_BUFFER, 0, verticeSize * sizeof(Vertex), vertices); 

    //EBO
    // if (indiceSize != 0)    //Todo: Refactor
    // {
        // m_useElementBuffer = true;
        // m_drawCount = indiceSize;
        glGenBuffers(1, &m_EBO); // Pointer to buffer
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO); //Use buffer
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, MaxIndexCount * sizeof(unsigned int), m_indices, GL_STATIC_DRAW);


    // }

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

// MeshBuffer::MeshBuffer(Vertex vertices[], unsigned int verticeSize, unsigned int indices[], unsigned int indiceSize)
// {
    
// }

// MeshBuffer::MeshBuffer(Vertex vertices[], unsigned int verticeSize, unsigned int indices[], unsigned int indiceSize, GLenum glDrawType) 
// : MeshBuffer(vertices, verticeSize, indices, indiceSize)  //Constructor Delegate
// {
//     m_GLDrawType = glDrawType;
// }

// MeshBuffer::MeshBuffer(Vertex vertices[], unsigned int verticeSize, GLenum glDrawType) 
// : MeshBuffer(vertices, verticeSize, 0, 0)  //Constructor Delegate
// {
//     m_GLDrawType = glDrawType;
// }

MeshBuffer::~MeshBuffer()
{
    std::cout << "Mesh Destructor Called" << std::endl;
}

void MeshBuffer::batch(Vertex vertices[], unsigned int verticeSize, unsigned int indices[], unsigned int indiceSize)
{
    //ToDo: Use Memcopy for this, maybe faster?
    //ToDo: Check if goes over the quad limit!

    glBindBuffer(GL_ARRAY_BUFFER, m_VBO[POSITION_VB]);

    //Add Vertices to buffer
    for (unsigned int i = 0; i < verticeSize; i++)
    {
        m_vertices[i + m_vertexCount] = vertices[i];
    }

    //Write ontop of buffer of existing allocated memory
    glBufferSubData(GL_ARRAY_BUFFER, m_vertexCount * sizeof(Vertex), verticeSize * sizeof(Vertex), vertices); 



    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO); //Use buffer

    //Add and Offset Indices
    for (unsigned int i = 0; i < indiceSize; i++)
    {
        m_indices[i + m_indexCount] = indices[i];
    }    

    glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, m_indexCount * sizeof(unsigned int), indiceSize * sizeof(unsigned int), vertices); 



    //Check if causes off by one byte issue!
    m_vertexCount += verticeSize;
    m_indexCount += indiceSize;

}

void MeshBuffer::flush()
{
    m_vertexCount = 0;
    m_indexCount = 0;
}

void MeshBuffer::dispose()
{
    glDeleteVertexArrays(1, &m_VAO);
}

void MeshBuffer::draw()
{
    //Select buffer to draw on
    glBindVertexArray(m_VAO);

    // //No Indices!
    // if (m_useElementBuffer == false) 
    // {
        glDrawArrays(GL_TRIANGLES, 0, m_vertexCount);
    // }
    
    //Using Indices!
    // else
    // {
        // glDrawElements(m_GLDrawType, m_indexCount, GL_UNSIGNED_INT, 0);
    // }

    // glBindVertexArray(0); //Release
}