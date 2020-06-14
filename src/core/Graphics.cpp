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
            Vertex(glm::vec3((0.0f + xPos) ,  (-1.0f - yPos ) - height+1, 0),	        glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), 	glm::vec2(0.0f, 1.0f), 	0.0f),      //Top Left
            Vertex(glm::vec3( (1.0f + xPos) + width-1,  (-1.0f - yPos ) - height+1, 0),	glm::vec4(1.0f,	1.0f, 1.0f, 1.0f), 	glm::vec2(1.0f, 1.0f), 	0.0f),      //Top Right
            Vertex(glm::vec3( (1.0f + xPos) + width-1,  (0.0f - yPos)  , 0),	        glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), 	glm::vec2(1.0f, 0.0f), 	0.0f),      //Bot Right
            Vertex(glm::vec3((0.0f + xPos) ,  (0.0f - yPos)  , 0),                      glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), 	glm::vec2(0.0f, 0.0f), 	0.0f)   //Bot Left
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
	Renderer::init();

        // now advance cursors for next glyph
        xPos += (ch.Advance >> 6) * scale; // bitshift by 6 to get value in pixels (1/64th times 2^6 = 64)
        yPos = origYpos;
    }

}

//ToDo: Have resource manager later handle this!
//Create Atlus, Create Empty Texture, Fill Empty Texture
#define MAXWIDTH 256
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
		FT_GlyphSlot g = face->glyph;

		unsigned int roww = 0;
		unsigned int rowh = 0;
		unsigned int w = 0;
		unsigned int h = 0;

		 //memset(c, 0, sizeof c);

		/* Find minimum size for a texture holding all visible ASCII characters */
		for (int i = 32; i < 128; i++) {
			if (FT_Load_Char(face, i, FT_LOAD_RENDER)) {
				fprintf(stderr, "Loading character %c failed!\n", i);
				continue;
			}
			if (roww + g->bitmap.width + 1 >= MAXWIDTH) {
				w = std::max(w, roww);
				h += rowh;
				roww = 0;
				rowh = 0;
			}
			roww += g->bitmap.width + 1;
			rowh = std::max(rowh, g->bitmap.rows);
		}

		w = std::max(w, roww);
		h += rowh;

		/* Create a texture that will be used to hold all ASCII glyphs */
        GLuint tex;
		glActiveTexture(GL_TEXTURE0);
        glGenTextures(1, &tex);
		glBindTexture(GL_TEXTURE_2D, tex);
		//glUniform1i(uniform_tex, 0);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_ALPHA, w, h, 0, GL_ALPHA, GL_UNSIGNED_BYTE, 0);

		/* We require 1 byte alignment when uploading texture data */
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

		/* Clamping to edges is important to prevent artifacts when scaling */
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

		/* Linear filtering usually looks best for text */
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		/* Paste all glyph bitmaps into the texture, remembering the offset */
		int ox = 0;
		int oy = 0;

		rowh = 0;
        int xOffset = 0;


		for (int i = 32; i < 128; i++) 
        {
			if (FT_Load_Char(face, i, FT_LOAD_RENDER)) {
				fprintf(stderr, "Loading character %c failed!\n", i);
				continue;
			}

			if (ox + g->bitmap.width + 1 >= MAXWIDTH) {
				oy += rowh;
				rowh = 0;
				ox = 0;
			}

        glTexSubImage2D(GL_TEXTURE_2D, 0, ox, oy, g->bitmap.width, g->bitmap.rows, GL_ALPHA, GL_UNSIGNED_BYTE, g->bitmap.buffer);
        rowh = std::max(rowh, g->bitmap.rows);
        ox += g->bitmap.width + 1;

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