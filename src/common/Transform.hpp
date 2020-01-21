#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Transform
{
    public:
        Transform() : m_model(glm::mat4(1.0f))
        {
            
        }

        ~Transform(){};

        inline void translate(glm::vec3 vec3)
        {
            m_model = glm::translate(m_model, vec3);
        }

        inline void rotate(glm::vec3 vec3,float degrees)
        {
            m_model = glm::rotate(m_model, glm::radians(degrees), vec3);
        }

        inline void scale(glm::vec3 vec3)
        {
            m_model = glm::scale(m_model, vec3);
        }

        glm::mat4 getModel()
        {
            return m_model;
        }
    
    private:
        glm::mat4 m_model = glm::mat4(1.0f);  //Used for shader calculation

};
