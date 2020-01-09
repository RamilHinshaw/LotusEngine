#pragma once

#include "opengl/Mesh.hpp"
#include "opengl/Shader.hpp"

class Quad
{
    public:
        Quad();
        Quad(const Shader &shader);
        ~Quad();

    private:
        Mesh mesh;
        Shader shader;
};
