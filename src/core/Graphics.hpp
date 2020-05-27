//An actual Static Class and not a singleton (finally)

#pragma once

#include "../common/Rect.hpp"
// #include "../graphics/opengl/Shader.hpp"
#include "../graphics/opengl/Mesh.hpp"
#include "../graphics/opengl/Vertex.hpp"
#include "../graphics/opengl/Texture.hpp"
// #include "../graphics/Camera.hpp"
#include "../graphics/Renderer.hpp"
#include <glm/glm.hpp>

#include "../thirdparty/freetype2/include/ft2build.h"
// #include "../thirdparty/freetype2/include/freetype/fterrors.h"
#include "../thirdparty/freetype2/include/freetype/freetype.h"
#include FT_FREETYPE_H

#include <map>

class Graphics 
{
    public:

        static void DrawTest(float xPos, float yPos);

        static void DrawQuad(float xPos, float yPos);

        static void DrawSprite(float xPos, float yPos, float width, float height);

        static void DrawSprite(float xPos, float yPos, float width, float height, float xScal, float yScal, float rotation, glm::vec3 color);

        static void DrawGrid();

        static void DrawCube();

        static void DrawSphere();

        static void DrawText(std::string text, float xPos, float yPos, float scale = 1.0f);

        static void TestLoadFont(std::string path, unsigned int fontSize);

};

struct Character {
    float TextureID; // ID handle of the glyph texture
    glm::ivec2   Size;      // size of glyph
    glm::ivec2   Bearing;   // offset from baseline to left/top of glyph
    unsigned int Advance;   // horizontal offset to advance to next glyph
};

static std::map<char, Character> Characters; 

