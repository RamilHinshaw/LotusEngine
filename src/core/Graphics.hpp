#pragma once

#include "../common/Rect.hpp"
#include "../graphics/opengl/Shader.hpp"
#include "../graphics/opengl/Mesh.hpp"
#include "../graphics/opengl/Vertex.hpp"
#include "../graphics/opengl/Texture.hpp"
#include "../graphics/Camera.hpp"

class Graphics 
{
    public:

        static void DrawQuad();

        static void DrawGrid();

        static void DrawCube();

        static void DrawSphere();

        static void DrawText();


};