#include "Renderer.hpp"

void Renderer::render()
{
    //ToDo: Render based on priorities!
        // Shader
            // Texture
                // Mesh

    batchedDynamicMeshes->at(0).draw();
    

}

void Renderer::sort()
{
    
}

void Renderer::flush()
{
    batchedDynamicMeshes->at(0).
}

void Renderer::staticFlush()
{
    
}

void Renderer::batch(Texture texture)
{
    
}

void Renderer::batch(Vertex vertices[], unsigned int verticeSize, unsigned int indices[], unsigned int indiceSize)
{
    if (batchedDynamicMeshes->size == 0)
    {
        batchedDynamicMeshes->push_back( MeshBuffer() );        
    }

    //ToDo: Should somehow know what index to put it at
    batchedDynamicMeshes->at(0).batch(vertices, verticeSize, indices, indiceSize);
}

void Renderer::staticBatch(Vertex vertices[], unsigned int verticeSize, unsigned int indices[], unsigned int indiceSize)
{
    
}
