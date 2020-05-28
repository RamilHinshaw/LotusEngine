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

            //Positions		X,Y             				                            //Colors						    //Texture Coordinates	//TexID
            Vertex(glm::vec3((0.0f + xPos) ,  (-1.0f - yPos ) - height+1, 0),	        glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), 	glm::vec2(1.0f, 1.0f), 	0.0f),      //Bot Left
            Vertex(glm::vec3( (1.0f + xPos) + width-1,  (-1.0f - yPos ) - height+1, 0),	glm::vec4(1.0f,	1.0f, 1.0f, 1.0f), 	glm::vec2(1.0f, 0.0f), 	0.0f),      //Bot Right
            Vertex(glm::vec3( (1.0f + xPos) + width-1,  (0.0f - yPos)  , 0),	        glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), 	glm::vec2(0.0f, 0.0f), 	0.0f),      //Top Right
            Vertex(glm::vec3((0.0f + xPos) ,  (0.0f - yPos)  , 0),                      glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), 	glm::vec2(0.0f, 1.0f), 	0.0f)   //Top Left
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
    glActiveTexture(GL_TEXTURE0);
    int i = 0;
    float origYpos = yPos;

    std::string::const_iterator c;
    for (c = text.begin(); c != text.end(); c++)
    {
        Character ch = Characters[*c];

        // xPos = xPos + ch.Bearing.x * scale;
        //yPos = yPos + (Characters['H'].Size.y - ch.Bearing.y) * scale;
        // yPos = yPos - (ch.Size.y - ch.Bearing.y) * scale;
        yPos = (yPos + (Characters['H'].Size.y - ch.Size.y) + (ch.Size.y - ch.Bearing.y)) * scale;
        // std::cout << "CH: " << i++ << " size.y: " << ch.Size.y << " | Bearing.y: " << ch.Bearing.y << std::endl;

        float width = ch.Size.x * scale;
        float height = ch.Size.y * scale;

        //Set verticies based on parameters
        Vertex vertices[] = {

            //Positions		X,Y             				                            //Colors						    //Texture Coordinates	//TexID
            Vertex(glm::vec3( (0.0f + xPos) ,  (-1.0f - yPos ) - height+1, 0),	        glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), 	glm::vec2(0.0f, 1.0f), 	ch.TextureID),  //Top-Left
            Vertex(glm::vec3( (1.0f + xPos) + width-1,  (-1.0f - yPos ) - height+1, 0),	glm::vec4(1.0f,	1.0f, 1.0f, 1.0f), 	glm::vec2(1.0f, 1.0f), 	ch.TextureID),  //Top-Right
            Vertex(glm::vec3( (1.0f + xPos) + width-1,  (0.0f - yPos)  , 0),	        glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), 	glm::vec2(1.0f, 0.0f), 	ch.TextureID),  //Bot-Right
            Vertex(glm::vec3( (0.0f + xPos) ,  (0.0f - yPos)  , 0),                     glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), 	glm::vec2(0.0f, 0.0f), 	ch.TextureID)   //Bot-Left
        };

        unsigned int indices[] = {
            0, 2, 3,	//first triangle
            0, 1, 2,	//second triangle
        };

        // std::cout << ch.TextureID << std::endl;

        //Renderer::getShader()->setSampler2d("u_texture", ch.TextureID-1);

        //Then pass to dynamic mesh buffer
        Renderer::batch(vertices, sizeof(vertices)/sizeof(vertices[0]), indices, sizeof(indices)/sizeof(indices[0]));

        // std::cout << "Added to Batch!" << std::endl;

        // now advance cursors for next glyph
        xPos += (ch.Advance >> 6) * scale; // bitshift by 6 to get value in pixels (1/64th times 2^6 = 64)
        yPos = origYpos;
    }

}

//ToDo: Have resource manager later handle this!
void Graphics::TestLoadFont(std::string path, unsigned int fontSize)
{
    Characters.clear();



    FT_Library ft;    
    if (FT_Init_FreeType(&ft)) // all functions return a value different than 0 whenever an error occurred
        std::cout << "ERROR::FREETYPE: Could not init FreeType Library" << std::endl;

    // load font as face
    FT_Face face;
    if (FT_New_Face(ft, path.c_str(), 0, &face))
        std::cout << "ERROR::FREETYPE: Failed to load font" << std::endl;

    FT_Set_Pixel_Sizes(face, 0, fontSize);

    // disable byte-alignment restriction
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1); 


    //TEXTURE ARRAY TEST ********
    // unsigned int textureArraySize = 128;    // Get maximum number in slots (must be same width and height)
    unsigned int textureID[128]; //This is shared for all images in same slot,
    glGenTextures(128, textureID);   // HERE WE SPECIFY SLOTS IN THAT TEXTURE ID and textureID is assigned from GPU

    // unsigned int temp_texture;
    // glGenTextures(1, &temp_texture);
    

    for (GLubyte c = 0; c < 128; c++) // lol see what I did there 
    {
        // load character glyph 
        if (FT_Load_Char(face, c, FT_LOAD_RENDER))
        {
            std::cout << "ERROR::FREETYTPE: Failed to load Glyph" << std::endl;
            continue;
        }

        // generate texture    
        glActiveTexture(GL_TEXTURE0 + c); //Start with index slot 0 then increase!
        glBindTexture(GL_TEXTURE_2D, textureID[c]);
        glTexImage2D(
            GL_TEXTURE_2D,
            0,
            GL_RED,
            face->glyph->bitmap.width,
            face->glyph->bitmap.rows,
            0,
            GL_RED,
            GL_UNSIGNED_BYTE,
            face->glyph->bitmap.buffer
            );

        // set texture options
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


       
        // now store character for later use
        Character character = {
            textureID[c],
            glm::ivec2(face->glyph->bitmap.width, face->glyph->bitmap.rows),
            glm::ivec2(face->glyph->bitmap_left, face->glyph->bitmap_top),
            face->glyph->advance.x
        };
        Characters.insert(std::pair<char, Character>(c, character));
    }    

    int textureIDArray[128]; //Used to pass to sampler
    for (int i = 0; i < 128; i++)
    {
        textureIDArray[i] = i;
        // std::cout << textureIDArray[i] << std::endl;
    }

   Renderer::getShader()->setSampler2dArray("u_texture", 128, textureIDArray);

    glBindTexture(GL_TEXTURE_2D, 0);

    //std::cout << "Texture Text Bind: " << textureID << std::endl;
    // destroy FreeType once we're finished
    FT_Done_Face(face);
    FT_Done_FreeType(ft);
}