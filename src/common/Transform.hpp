#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

class Transform
{
    public:
        Transform() : m_model(glm::mat4(1.0f))
        {  }

        ~Transform(){ 
            std::cout << "Transform out of scope!" << std::endl;
        }

        inline void translate(glm::vec3 vec3)
        {
            m_model = glm::translate(m_model, vec3);
            m_pos = vec3;
        }

        inline void position(glm::vec3 vec3)
        {
            //ToDo: Find more optimize way for this
            m_pos = vec3;

            m_model = glm::mat4(1.0f);
            translate(m_pos);
            rotate(m_rot);
            scale(m_scale);
        }

        inline void rotate(glm::vec3 vec3)
        {
            m_model = glm::rotate(m_model, glm::radians(vec3.x), glm::vec3(1,0,0)); //X
            m_model = glm::rotate(m_model, glm::radians(vec3.y), glm::vec3(0,1,0)); //Y
            m_model = glm::rotate(m_model, glm::radians(vec3.z), glm::vec3(0,0,1)); //Z
            m_rot = vec3;
        }

        inline void scale(glm::vec3 vec3)
        {
            m_model = glm::scale(m_model, vec3);
            m_scale = vec3;
        }

        inline glm::vec3 getPosition()
        {
            return m_pos;
        }

        inline glm::vec3 getRotation()
        {
            return m_rot;
        }

        inline glm::vec3 getScale()
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
        glm::vec3 m_scale = glm::vec3(1.0f);


};
