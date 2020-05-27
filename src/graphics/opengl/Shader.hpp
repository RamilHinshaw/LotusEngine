#pragma once

extern "C"
{ 
    #include <GL/glew.h>
	// #include "../../thirdparty/glad/glad.h"
    //#include "../../thirdparty/glad/glad.h" //ToDo: Remove relative pathing!
}

#include <string>
#include <fstream>
#include <iostream>
#include <glm/glm.hpp>

#include <glm/gtc/type_ptr.hpp>

class Shader
{

public:
    Shader();
    Shader(const std::string& fileName);

    void bind();    //Use Shader

    ~Shader();

    //void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);
    //std::string Shader::LoadShader(const std::string& fileName);
    //GLuint CreateShader(const std::string& text, GLenum shaderType);

    void setBool(const std::string &name, bool value) const;  
    void setInt(const std::string &name, int value) const;   
    void setFloat(const std::string &name, float value) const;
    void setMat4(const std::string &name, glm::vec4 value) const;
    void setVec2(const std::string &name, const glm::vec2 &value) const;
    void setVec2(const std::string &name, float x, float y) const;
    void setVec3(const std::string &name, const glm::vec3 &value) const;
    void setVec3(const std::string &name, float x, float y, float z) const;
    void setVec4(const std::string &name, const glm::vec4 &value) const;
    void setVec4(const std::string &name, float x, float y, float z, float w) const;
    void setMat2(const std::string &name, const glm::mat2 &mat) const;
    void setMat3(const std::string &name, const glm::mat3 &mat) const;
    void setMat4(const std::string &name, const glm::mat4 &mat) const;
    void setSampler2d(const std::string &name, int value) const;
    

    GLuint GetProgram();
    

    void dispose(); //Refactor from some interface (common pattern)

    protected:
    private:
        static const unsigned int NUM_SHADERS = 2; //Vertex Shader & Fragment Shader
        // Shader(const Shader& other);
        // void operator=(const Shader& other);

        GLuint m_program; //OpenGL keeps track were the program is
        GLuint m_shaders[NUM_SHADERS];

};