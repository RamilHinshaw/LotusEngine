//Used for text rendering

#pragma once

extern "C"
{ 
    #include <GL/glew.h>
	// #include "../../thirdparty/glad/glad.h"
    //#include "../../thirdparty/glad/glad.h" //ToDo: Remove relative pathing!
}

#include "Vertex.hpp"
#include <map>
#include <ft2build.h>
#include FT_FREETYPE_H


/// Holds all state information relevant to a character as loaded using FreeType
struct Character {
    unsigned int TextureID; // ID handle of the glyph texture
    glm::ivec2   Size;      // size of glyph
    glm::ivec2   Bearing;   // offset from baseline to left/top of glyph
    unsigned int Advance;   // horizontal offset to advance to next glyph
};


// A renderer class for rendering text displayed by a font loaded using the 
// FreeType library. A single font is loaded, processed into a list of Character
// items for later rendering.
class TextMeshBuffer
{
public:
    // holds a list of pre-compiled Characters
    std::map<char, Character> Characters; 
    
    // shader used for text rendering
    // Shader TextShader;

    TextMeshBuffer();

    //void load(std::string font, unsigned int fontSize); //Unique from mesh buffer, must turn freetype to buffer and store it!
    void batch();

    void draw(std::string text, float xPos, float yPos, float scaleFont, glm::vec3 color = glm::vec3(1.0f));
private:
    // render state
    GLuint VAO, VBO;
};