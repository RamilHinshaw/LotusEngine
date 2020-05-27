#include "Renderer.hpp"

#include <iostream>

void Renderer::init()
{
    batchedDynamicMeshes->push_back( MeshBuffer() );   
    batchedTextMeshes->push_back( MeshBuffer() );   

    flush();

    // Vertex vertices[] = {

    //                         //Positions					//Colors					//Texture Coordinates	//TexID
    //         Vertex(glm::vec3(-0.5,	-0.5,	0),	glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), 	glm::vec2(1.0f, 1.0f), 	0.0f),
    //         Vertex(glm::vec3(0.5,	-0.5,	0),	glm::vec4(1.0f,	1.0f, 1.0f, 1.0f), 	glm::vec2(1.0f, 0.0f), 	0.0f),
    //         Vertex(glm::vec3(0.5,	0.5,	0),	glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), 	glm::vec2(0.0f, 0.0f), 	0.0f),

    //         Vertex(glm::vec3(0.5,	0.5,	0),	glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), 	glm::vec2(0.0f, 0.0f), 	0.0f), // remove dup
    //         Vertex(glm::vec3(-0.5,	0.5,	0), glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), 	glm::vec2(0.0f, 1.0f), 	0.0f),
    //         Vertex(glm::vec3(-0.5,	-0.5,	0),	glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), 	glm::vec2(1.0f, 1.0f), 	0.0f), // remove dup
    //     };

    // unsigned int indices[] = {
	// 	0, 2, 3,	//first triangle
	// 	0, 1, 2,	//second triangle
	// };

    // batchedDynamicMeshes->at(0).batch(vertices, sizeof(vertices)/sizeof(vertices[0]), indices, sizeof(indices)/sizeof(indices[0]));
    
	// basicTexture = Texture("./assets/textures/floor4.png");
	// basicShader = Shader("./assets/shaders/basicShaderES");
    basicShader = new Shader("./assets/shaders/textShader");
    basicShader->bind();
	// basicTexture.bind();
}

void Renderer::render(Camera *camera)
{
    //ToDo: Render based on priorities!
        // Shader1 bind
            // Texture1 bind
                // Mesh1 draw
            // Texture2 bind
                // Mesh2 draw                
        // Shader2 bind
            // Texture3 bind
                // Mesh3 draw        


    //Shader Projection from this camera Camera
    basicShader->setMat4("u_transform", glm::mat4(1.0f));
    basicShader->setMat4("u_view", camera->getTransform().getModel());
    basicShader->setMat4("u_projection", camera->getProjection());  


    batchedDynamicMeshes->at(0).draw();
    // batchedTextMeshes->at(0).draw();
    // textMeshBuffer.draw();
    
    flush();
}

void Renderer::sort()
{
    
}

void Renderer::flush()
{
    batchedDynamicMeshes->at(0).flush();
}

void Renderer::staticFlush()
{
    
}

void Renderer::batch(Texture texture)
{
    
}

void Renderer::batch(Vertex vertices[], unsigned int verticeSize, unsigned int indices[], unsigned int indiceSize)
{
    // if (batchedDynamicMeshes->size() == 0)
    // {
    //     batchedDynamicMeshes->push_back( MeshBuffer() );   
    //     std::cout << "batchedDynamicMesh created!" << std::endl;     
    // }

    //ToDo: Should somehow know what index to put it at
    batchedDynamicMeshes->at(0).batch(vertices, verticeSize, indices, indiceSize);
}

void Renderer::staticBatch(Vertex vertices[], unsigned int verticeSize, unsigned int indices[], unsigned int indiceSize)
{
    
}

void textBatch(Vertex vertices[], unsigned int verticeSize, unsigned int indices[], unsigned int indiceSize)
{
    // textMeshBuffer.batch(vertices, verticeSize, indices, indiceSize);

    batchedTextMeshes->at(0).batch(vertices, verticeSize, indices, indiceSize);
}

void Renderer::setActiveWindow(const Display &window)
{
    activeWindow = window;
}

Display Renderer::getActiveWindow()
{
    return activeWindow;
}

void Renderer::dispose()
{
    // basicShader.dispose();
	// basicTexture.dispose();
}

//TEST

Shader* Renderer::getShader()
{
    return basicShader;
}