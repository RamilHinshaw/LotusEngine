#pragma once

#include <glm/glm.hpp>

class Vertex
{
    public:

        Vertex(const glm::vec3& position) //Use member initialization
        {
            this->position = position;
        }

    //Attributes for OpenGL
    private:
        glm::vec3 position;
        glm::vec3 texCoords;
        glm::vec4 color;
        //normal
        //tangent


};