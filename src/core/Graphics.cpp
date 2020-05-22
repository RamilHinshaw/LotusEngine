#include "Graphics.hpp"

#include <iostream>

void Graphics::DrawTest(float xPos, float yPos)
{
    Vertex vertices[] = {

                            //Positions					//Colors					//Texture Coordinates	//TexID
            Vertex(glm::vec3(-0.5 + xPos,	-0.5 + yPos,	0),	glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), 	glm::vec2(1.0f, 1.0f), 	0.0f),
            Vertex(glm::vec3(0.5  + xPos,	-0.5 + yPos,	0),	glm::vec4(1.0f,	1.0f, 1.0f, 1.0f), 	glm::vec2(1.0f, 0.0f), 	0.0f),
            Vertex(glm::vec3(0.5  + xPos,	0.5  + yPos,	0),	glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), 	glm::vec2(0.0f, 0.0f), 	0.0f),

            Vertex(glm::vec3(0.5  + xPos,	0.5  + yPos,	0),	glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), 	glm::vec2(0.0f, 0.0f), 	0.0f), // remove dup
            Vertex(glm::vec3(-0.5 + xPos,	0.5  + yPos,	0), glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), 	glm::vec2(0.0f, 1.0f), 	0.0f),
            Vertex(glm::vec3(-0.5 + xPos,	-0.5 + yPos,	0),	glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), 	glm::vec2(1.0f, 1.0f), 	0.0f), // remove dup
        };

    unsigned int indices[] = {
		0, 2, 3,	//first triangle
		0, 1, 2,	//second triangle
	};

    //Then pass to dynamic mesh buffer
    Renderer::batch(vertices, sizeof(vertices)/sizeof(vertices[0]), indices, sizeof(indices)/sizeof(indices[0]));
}

void Graphics::DrawQuad(float xPos, float yPos)
{
    //Set verticies based on parameters
    Vertex vertices[] = {

            //Positions								            //Colors						    //Texture Coordinates	//TexID
            Vertex(glm::vec3(-0.5f + xPos, -0.5f + yPos, 0),	glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), 	glm::vec2(1.0f, 1.0f), 	0.0f),
            Vertex(glm::vec3( 0.5f + xPos, -0.5f + yPos, 0),	glm::vec4(1.0f,	1.0f, 1.0f, 1.0f), 	glm::vec2(1.0f, 0.0f), 	0.0f),
            Vertex(glm::vec3( 0.5f + xPos,  0.5f + yPos, 0),	glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), 	glm::vec2(0.0f, 0.0f), 	0.0f),
            Vertex(glm::vec3(-0.5f + xPos,  0.5f + yPos, 0),    glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), 	glm::vec2(0.0f, 1.0f), 	0.0f)
        };

    unsigned int indices[] = {
		0, 2, 3,	//first triangle
		0, 1, 2,	//second triangle
	};

    //Then pass to dynamic mesh buffer
    Renderer::batch(vertices, sizeof(vertices)/sizeof(vertices[0]), indices, sizeof(indices)/sizeof(indices[0]));
}

void Graphics::DrawSprite(float xPos, float yPos, float width, float height, float xScal, float yScal, float rotation, char color)
{

}

void Graphics::DrawSprite(float xPos, float yPos, float width, float height)
{
    //Set verticies based on parameters
    Vertex vertices[] = {

            //Positions		X,Y             				            //Colors						    //Texture Coordinates	//TexID
            Vertex(glm::vec3((0.0f + xPos) ,  (-1.0f - yPos ) - height+1, 0),	glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), 	glm::vec2(1.0f, 1.0f), 	0.0f),      //Bot Left
            Vertex(glm::vec3( (1.0f + xPos) + width-1,  (-1.0f - yPos ) - height+1, 0),	glm::vec4(1.0f,	1.0f, 1.0f, 1.0f), 	glm::vec2(1.0f, 0.0f), 	0.0f),      //Bot Right
            Vertex(glm::vec3( (1.0f + xPos) + width-1,  (0.0f - yPos)  , 0),	glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), 	glm::vec2(0.0f, 0.0f), 	0.0f),      //Top Right
            Vertex(glm::vec3((0.0f + xPos) ,  (0.0f - yPos)  , 0),    glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), 	glm::vec2(0.0f, 1.0f), 	0.0f)   //Top Left
        };

    unsigned int indices[] = {
		0, 2, 3,	//first triangle
		0, 1, 2,	//second triangle
	};

    //Then pass to dynamic mesh buffer
    Renderer::batch(vertices, sizeof(vertices)/sizeof(vertices[0]), indices, sizeof(indices)/sizeof(indices[0]));
}


void Graphics::DrawGrid()
{
    
}

void Graphics::DrawCube()
{
    
}

void Graphics::DrawSphere()
{
    
}

void Graphics::DrawText()
{
    
}