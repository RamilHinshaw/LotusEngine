//An actual Static Class and not a singleton (finally)

#pragma once

#include "../common/Rect.hpp"
// #include "../graphics/opengl/Shader.hpp"
#include "../graphics/opengl/Mesh.hpp"
#include "../graphics/opengl/Vertex.hpp"
#include "../graphics/opengl/Texture.hpp"
// #include "../graphics/Camera.hpp"
#include "../graphics/Renderer.hpp"

class Graphics 
{
    public:

        static void DrawQuad(float xPos, float yPos);

        static void DrawSprite(float xPos, float yPos, float height, float width, float xScal, float yScal, float rotation, char color);

        static void DrawGrid();

        static void DrawCube();

        static void DrawSphere();

        static void DrawText();



};