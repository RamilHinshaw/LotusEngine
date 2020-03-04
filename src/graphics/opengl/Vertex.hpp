#pragma once

#include <glm/glm.hpp>

class Vertex
{
    public:

        Vertex(const glm::vec3& position) //ToDo: Use member initialization & put into cpp instead!
        {
            this->position = position;
        }

        Vertex(const glm::vec3& position, const glm::vec4& color) //Use member initialization
        {
            this->position = position;
            this->color = color;
        }

        Vertex(const glm::vec3& position, const glm::vec2& texCoords) //Use member initialization
        {
            this->position = position;
            this->texCoords = texCoords;
        }

        Vertex(const glm::vec3& position, const glm::vec4& color, const glm::vec2& texCoords) //Use member initialization
        {
            this->position = position;
            this->color = color;
            this->texCoords = texCoords;
        }

        Vertex(const glm::vec3& position, const glm::vec4& color, const glm::vec2& texCoords, const float& texID) //Use member initialization
        {
            this->position = position;
            this->color = color;
            this->texCoords = texCoords;
            this->texID = texID;
        }

    //Attributes for OpenGL
    private:
        glm::vec3 position;
        glm::vec4 color;
        glm::vec2 texCoords;
        float texID = 0;
        //normal
        //tangent


};