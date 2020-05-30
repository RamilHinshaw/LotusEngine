#include "Graphics.hpp"

#include <iostream>
#include <algorithm> //For font Load function

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

        int intChar = int(*c);
        float uvOffsetStart = ((intChar-32) * ch.Size.x) / AtlusWidth;
        float charUVWidth = ch.Size.x / AtlusWidth;

        //Set verticies based on parameters
        Vertex vertices[] = {

            //Positions		X,Y             				                            //Colors						    //Texture Coordinates	                //TexID
            Vertex(glm::vec3( (0.0f + xPos) ,  (-1.0f - yPos ) - height+1, 0),	        glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), 	glm::vec2(0.0f, 1.0f), 	0),  //Top-Left
            Vertex(glm::vec3( (1.0f + xPos) + width-1,  (-1.0f - yPos ) - height+1, 0),	glm::vec4(1.0f,	1.0f, 1.0f, 1.0f), 	glm::vec2(1.0f, 1.0f), 	0),  //Top-Right
            Vertex(glm::vec3( (1.0f + xPos) + width-1,  (0.0f - yPos)  , 0),	        glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), 	glm::vec2(1.0f, 0.0f), 	0),  //Bot-Right
            Vertex(glm::vec3( (0.0f + xPos) ,  (0.0f - yPos)  , 0),                     glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), 	glm::vec2(0.0f, 0.0f), 	0)   //Bot-Left
        };

        // uvOffsetStart,              
        // uvOffsetStart + charUVWidth,
        // uvOffsetStart + charUVWidth,
        // uvOffsetStart,              

        unsigned int indices[] = {
            0, 2, 3,	//first triangle
            0, 1, 2,	//second triangle
        };

        // std::cout << charUVWidth << std::endl;

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
//Create Atlus, Create Empty Texture, Fill Empty Texture
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


    FT_GlyphSlot g = face->glyph;
    //int textureID[96];
    unsigned int atlusWidth = 0;
    unsigned int atlusHeight = 0;
    
    //Create Atlus!
    for (GLubyte i = 32; i < 128; i++) // lol see what I did there 
    {
        // load character glyph 
        if (FT_Load_Char(face, i, FT_LOAD_RENDER))
        {
            std::cout << "ERROR::FREETYTPE: Failed to load Glyph" << std::endl;
            continue;
        }

          atlusWidth += g->bitmap.width;
          atlusHeight = std::max(atlusHeight, g->bitmap.rows);   
    }

    AtlusWidth = atlusWidth; //Saved for UV calculations later    
    std::cout << "Atlus Width: " << AtlusWidth << std::endl;

    //CREATE EMPTY TEXTURE
    GLuint tex;
    glActiveTexture(GL_TEXTURE0);
    glGenTextures(1, &tex);
    glBindTexture(GL_TEXTURE_2D, tex);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, atlusWidth, atlusHeight, 0, GL_RED, GL_UNSIGNED_BYTE, 0);

    //FILL EMPTY TEXTURE WITH FONT BITMAPS
    int xOffset = 0;

    for(int i = 32; i < 128; i++) 
    {
        if(FT_Load_Char(face, i, FT_LOAD_RENDER))
            continue;

        //Create texture in one big row
        glTexSubImage2D(GL_TEXTURE_2D, 0, xOffset, 0, g->bitmap.width, g->bitmap.rows, GL_RED, GL_UNSIGNED_BYTE, g->bitmap.buffer);

        // now store character for later use
        Character character = 
        {
            glm::ivec2(face->glyph->bitmap.width, face->glyph->bitmap.rows),    //Size XY
            glm::ivec2(face->glyph->bitmap_left, face->glyph->bitmap_top),      //Bearing XT
            face->glyph->advance.x,                                             //Horizontal Advance X,
            xOffset                                                             //Horizontal offset in atlus for this character
        };
        Characters.insert(std::pair<char, Character>(i, character));
    }

    xOffset += g->bitmap.width;

    // glBindTexture(GL_TEXTURE_2D, 0);

    // destroy FreeType once we're finished
    FT_Done_Face(face);
    FT_Done_FreeType(ft);
}