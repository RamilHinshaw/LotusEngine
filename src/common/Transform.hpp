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

        inline void setPosition(glm::vec3 vec3)
        {
            m_model = glm::translate(m_model, vec3);
            m_pos = vec3;
        }

        inline void setRotation(glm::vec3 vec3)
        {
            m_model = glm::rotate(m_model, glm::radians(vec3.x), glm::vec3(1,0,0)); //X
            m_model = glm::rotate(m_model, glm::radians(vec3.y), glm::vec3(0,1,0)); //Y
            m_model = glm::rotate(m_model, glm::radians(vec3.z), glm::vec3(0,0,1)); //Z
            m_rot = vec3;
        }

        inline void setScale(glm::vec3 vec3)
        {
            m_model = glm::scale(m_model, vec3);
            m_scale = vec3;
        }

        inline glm::vec3 getPosition(glm::vec3 vec3)
        {
            return m_pos;
        }

        inline glm::vec3 getRotation(glm::vec3 vec3,float degrees)
        {
            return m_rot;
        }

        inline glm::vec3 getScale(glm::vec3 vec3)
        {
            return m_scale;
        }

        glm::mat4 getModel()
        {
            return m_model;
        }
    
    private:
        glm::mat4 m_model = glm::mat4(1.0f);  //Used for shader calculation

        glm::vec3 m_pos;
        glm::vec3 m_rot;
        glm::vec3 m_scale;


};
