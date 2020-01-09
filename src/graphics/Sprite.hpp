#pragma once

#include <string>
#include "../common/Rect.hpp"
#include "opengl/Shader.hpp"
// #include "opengl/Mesh.hpp"
#include "Quad.hpp"
#include "opengl/Texture.hpp"
#include "opengl/Vertex.hpp"

class Sprite
{

    public:
        Sprite(const Rect &rect, const std::string texturePath);
        ~Sprite();

    private:
        Rect rect;

        Shader shader;
        Texture texture;
        Quad quad;


};

