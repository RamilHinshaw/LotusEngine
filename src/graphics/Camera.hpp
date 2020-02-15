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
        Camera() : Camera(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f)
        {
            //Perspective by default
        }

        //Othorgraphic
        Camera(float left, float right, float bottom, float top, float near, float far)
        {
            projection = glm::ortho(left, right, bottom, top, near, far);
        }

        //Perspective
        Camera(float fov, float screenRatio, float near, float far)
        {
            projection = glm::perspective(fov, screenRatio, near, far);
        }

        glm::mat4 getProjection()
        {
            return projection;
        }

        Transform& getTransform()
        {
            return *transform;
        }


        // void setFOV();

        ~Camera(){ 
            std::cout << "Camera out of scope!" << std::endl;
        }

    private:
        Transform* transform = new Transform();
        glm::mat4 projection;
    // enum Camera_Mode {
    //     ORTHOGRAPHIC,
    //     PERSPECTIVE
    // }


};

