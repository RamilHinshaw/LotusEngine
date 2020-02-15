#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "../common/Transform.hpp"

#include <iostream>

// #define MODE_OTHORGRAPHIC   0
// #define MODE_PERSPECTIVE    1


// typedef bool CAMERA_MODE;

class Camera
{
    public:
        Camera()
        : m_fov(45), m_width(800), m_height(600), m_near(1), m_far(100), m_isPerspective(true)
        {
            updateProjection();
        }

        Camera(float fov, float width, float height, float near, float far, bool perspective)
        : m_fov(fov), m_width(width), m_height(height), m_near(near), m_far(far), m_isPerspective(perspective)
        {    
            updateProjection();
        }

        glm::mat4 getProjection()
        {
            return projection;
        }

        Transform& getTransform()
        {
            return *transform;
        }

        void toggleProjection()
        {
            m_isPerspective = !m_isPerspective;
            updateProjection();
        }

        void SetProjection(float fov, float width, float height, float near, float far, bool perspective)
        {
            m_fov = fov;
            m_width = width;
            m_height = height;
            m_near = near;
            m_far = far;
            m_isPerspective = perspective;

            updateProjection();
        }

        void setFov(float fov)
        {
            m_fov = fov;

            updateProjection();
        }


        // void setFOV();

        ~Camera(){ 
            std::cout << "Camera out of scope!" << std::endl;
        }

    private:
        void updateProjection() //Updates with give member values
        {
            if (m_isPerspective) //perspective
            {
                //projection = glm::perspective(glm::radians(45.0f), (float)800/(float)600, 0.1f, 100.0f);
                projection = glm::perspective(m_fov, m_width/m_height, m_near, m_far);
            }

            else    //orthogonal
            {
                projection = glm::ortho(0.0f, m_width/m_fov, 0.0f, m_height/m_fov, m_near, m_far);
            }
            
        }

        float m_fov = 45.0f;
        float m_width, m_height;
        float m_near, m_far;
        bool m_isPerspective = true;

        Transform* transform = new Transform();
        glm::mat4 projection;
};

