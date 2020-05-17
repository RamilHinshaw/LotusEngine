#include "Renderer.hpp"

void Renderer::render()
{
    //ToDo: Render based on priorities!
        // Shader
            // Texture
                // Mesh

    
    

}

void Renderer::sort()
{
    
}

void Renderer::flush()
{
    
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
}

void Renderer::staticBatch(Vertex vertices[], unsigned int verticeSize, unsigned int indices[], unsigned int indiceSize)
{
    
}
