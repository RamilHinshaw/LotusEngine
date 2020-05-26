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

void Graphics::DrawSprite(float xPos, float yPos, float width, float height, float xScal, float yScal, float rotation, glm::vec3 color)
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

void Graphics::DrawText(std::string text, float xPos, float yPos, float scale)
{

    // std::string::const_iterator c;
    // for (c = text.begin(); c != text.end(); c++)
    // {
    //     Character ch = Characters[*c];

    //     float xpos = xPos + ch.Bearing.x * scale;
    //     float ypos = yPos + (this->Characters['H'].Bearing.y - ch.Bearing.y) * scale;

    //     float w = ch.Size.x * scale;
    //     float h = ch.Size.y * scale;
    //     // update VBO for each character
    //     float vertices[6][4] = {
    //         { xpos,     ypos + h,   0.0f, 1.0f },
    //         { xpos + w, ypos,       1.0f, 0.0f },
    //         { xpos,     ypos,       0.0f, 0.0f },

    //         { xpos,     ypos + h,   0.0f, 1.0f },
    //         { xpos + w, ypos + h,   1.0f, 1.0f },
    //         { xpos + w, ypos,       1.0f, 0.0f }
    //     };
    //     // render glyph texture over quad
    //     glBindTexture(GL_TEXTURE_2D, ch.TextureID);
    //     // update content of VBO memory
    //     glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
    //     glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices); // be sure to use glBufferSubData and not glBufferData
    //     glBindBuffer(GL_ARRAY_BUFFER, 0);
    //     // render quad
    //     glDrawArrays(GL_TRIANGLES, 0, 6);
    //     // now advance cursors for next glyph
    //     x += (ch.Advance >> 6) * scale; // bitshift by 6 to get value in pixels (1/64th times 2^6 = 64)
    // }

    //Set verticies based on parameters
    // Vertex vertices[] = {

    //         //Positions		X,Y             				            //Colors						    //Texture Coordinates	//TexID
    //         Vertex(glm::vec3((0.0f + xPos) ,  (-1.0f - yPos ) - height+1, 0),	glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), 	glm::vec2(1.0f, 1.0f), 	0.0f),      //Bot Left
    //         Vertex(glm::vec3( (1.0f + xPos) + width-1,  (-1.0f - yPos ) - height+1, 0),	glm::vec4(1.0f,	1.0f, 1.0f, 1.0f), 	glm::vec2(1.0f, 0.0f), 	0.0f),      //Bot Right
    //         Vertex(glm::vec3( (1.0f + xPos) + width-1,  (0.0f - yPos)  , 0),	glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), 	glm::vec2(0.0f, 0.0f), 	0.0f),      //Top Right
    //         Vertex(glm::vec3((0.0f + xPos) ,  (0.0f - yPos)  , 0),    glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), 	glm::vec2(0.0f, 1.0f), 	0.0f)   //Top Left
    //     };

    // unsigned int indices[] = {
	// 	0, 2, 3,	//first triangle
	// 	0, 1, 2,	//second triangle
	// };

    // //Then pass to dynamic mesh buffer
    // Renderer::batch(vertices, sizeof(vertices)/sizeof(vertices[0]), indices, sizeof(indices)/sizeof(indices[0]));
}