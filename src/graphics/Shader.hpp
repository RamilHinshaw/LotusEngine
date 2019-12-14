#pragma once

extern "C"
{ 
	#include <GL/glew.h>
}

#include <string>
#include <fstream>
#include <iostream>

class Shader
{

public:
    Shader();
    Shader(const std::string& fileName);

    void bind();

    virtual ~Shader();


    //void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);
    //std::string Shader::LoadShader(const std::string& fileName);
    //GLuint CreateShader(const std::string& text, GLenum shaderType);

    protected:
    private:
        static const unsigned int NUM_SHADERS = 2; //Vertex Shader & Fragment Shader
        // Shader(const Shader& other);
        // void operator=(const Shader& other);

        GLuint m_program; //OpenGL keeps track were the program is
        GLuint m_shaders[NUM_SHADERS];

};