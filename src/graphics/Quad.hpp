#pragma once

#include "opengl/Mesh.hpp"
#include "opengl/Shader.hpp"
// #include "opengl/Vertex.hpp"
#include "../common/Rect.hpp"
#include <glm/glm.hpp>


#define GL_Triangle_Strip  0x005    //More efficient (openGl definition)

class Quad
{
    public:
        Quad();
        Quad(const Rect rect);
        Quad(const Rect &rect, const glm::vec3 &color);
        // Quad(const Rect rect, const Shader &shader); //ToDo: Come back to this!yy

        Shader* getShader();

        ~Quad();

        void virtual draw();
        void virtual dispose();

    protected:
        Rect rect;

    private:
        Mesh* generatePrimative();   //Prepare correctly for Mesh Instancing!
        Shader* generateShader();    //Pull from StateManager!

        Mesh *m_mesh;
        Shader *m_shader;
};
