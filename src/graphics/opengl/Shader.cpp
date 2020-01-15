#include "Shader.hpp"

//Test
#include <SDL2/SDL.h>

static void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);
static std::string LoadShader(const std::string& fileName);
static GLuint CreateShader(const std::string& text, GLenum shaderType);

Shader::Shader()
{
    std::cout << "Shader Empty Constructor Called???" << std::endl;
}

Shader::Shader(const std::string& fileName)
{
    m_program = glCreateProgram();

    std::string esFileSuffix = "";

    #if defined(__arm__)
        esFileSuffix = "ES";
    #endif

    //Load shader
    m_shaders[0] = CreateShader(LoadShader(fileName + esFileSuffix + ".vs"), GL_VERTEX_SHADER);    //Load Vertex Shader
    m_shaders[1] = CreateShader(LoadShader(fileName + esFileSuffix + ".fs"), GL_FRAGMENT_SHADER);  //Load Fragment Shader

    //Takes program and adds a shader to it
    for (unsigned int i = 0; i < NUM_SHADERS; i++) 
        glAttachShader(m_program, m_shaders[i]);
    
    //Tells opengl what part of the data to read and variable in shader program *I really dont know about these functions
    // glBindAttribLocation(m_program, 0, "position");// Saves OpenGL the headache don't need this though
    // glBindAttribLocation(m_program, 1, "color");

    //Link Shaders
    glLinkProgram(m_program);
    CheckShaderError(m_program, GL_LINK_STATUS, true, "Error: Program linking failed: ");

    //Validate Shaders
    glValidateProgram(m_program);
    CheckShaderError(m_program, GL_VALIDATE_STATUS, true, "Error: Program is invalid: ");

    std::cout << "pg: " << m_program << std::endl;
}

void Shader::bind()
{
    // std::cout << "bind: " << m_program << std::endl;
    glUseProgram(m_program);
}

Shader::~Shader()
{
    std::cout << "Shader Destructor Called" << std::endl;
} 

//From learnopengl.com
void Shader::setBool(const std::string &name, bool value) const
{         
    glUniform1i(glGetUniformLocation(m_program, name.c_str()), (int)value); 
}
// ------------------------------------------------------------------------
void Shader::setInt(const std::string &name, int value) const
{ 
    glUniform1i(glGetUniformLocation(m_program, name.c_str()), value); 
}
// ------------------------------------------------------------------------
void Shader::setFloat(const std::string &name, float value) const
{ 
    glUniform1f(glGetUniformLocation(m_program, name.c_str()), value); 
}
// ------------------------------------------------------------------------
void Shader::setVec2(const std::string &name, const glm::vec2 &value) const
{ 
    glUniform2fv(glGetUniformLocation(m_program, name.c_str()), 1, &value[0]); 
}
void Shader::setVec2(const std::string &name, float x, float y) const
{ 
    glUniform2f(glGetUniformLocation(m_program, name.c_str()), x, y); 
}
// ------------------------------------------------------------------------
void Shader::setVec3(const std::string &name, const glm::vec3 &value) const
{ 
    glUniform3fv(glGetUniformLocation(m_program, name.c_str()), 1, &value[0]); 
}
void Shader::setVec3(const std::string &name, float x, float y, float z) const
{ 
    glUniform3f(glGetUniformLocation(m_program, name.c_str()), x, y, z); 
}
// ------------------------------------------------------------------------
void Shader::setVec4(const std::string &name, const glm::vec4 &value) const
{ 
    glUniform4fv(glGetUniformLocation(m_program, name.c_str()), 1, &value[0]); 
}
void Shader::setVec4(const std::string &name, float x, float y, float z, float w) const
{ 
    glUniform4f(glGetUniformLocation(m_program, name.c_str()), x, y, z, w); 
}
// ------------------------------------------------------------------------
void Shader::setMat2(const std::string &name, const glm::mat2 &mat) const
{
    glUniformMatrix2fv(glGetUniformLocation(m_program, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}
// ------------------------------------------------------------------------
void Shader::setMat3(const std::string &name, const glm::mat3 &mat) const
{
    glUniformMatrix3fv(glGetUniformLocation(m_program, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}
// ------------------------------------------------------------------------
void Shader::setMat4(const std::string &name, const glm::mat4 &mat) const
{
    glUniformMatrix4fv(glGetUniformLocation(m_program, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}
//------------------------------------------------------------------------------------

GLuint Shader::GetProgram()
{
    return m_program;
}

void Shader::dispose()
{
    std::cout << "Shader Disposed!" << std::endl;
    std::cout << "pg: " << m_program << std::endl;

    for (unsigned int i = 0; i < NUM_SHADERS; i++) 
    {
        //glDetachShader(m_program, m_shaders[i]); //Detaches both vertex and fragment shader from program
        glDeleteShader(m_shaders[i]); //Delete both vertex and fragment shader from gpu memory
    }

    glDeleteProgram(m_program); //Delete program
}

static GLuint CreateShader(const std::string& text, GLenum shaderType)
{
    GLuint shader = glCreateShader(shaderType);

    if (shader == 0)
        std::cerr << "Error: Shader creation failed!" << std::endl;

    const GLchar* shaderSourceStrings[1];
    GLint shaderSourcesStringLengths[1];

    shaderSourceStrings[0] = text.c_str();
    shaderSourcesStringLengths[0] = text.length();

    glShaderSource(shader, 1, shaderSourceStrings, shaderSourcesStringLengths);
    glCompileShader(shader); 

    CheckShaderError(shader, GL_COMPILE_STATUS, false, "Error: Shader compliation failed in " + text + " : ");

    return shader;
}


static std::string LoadShader(const std::string& fileName)
{
    std::ifstream file;
    file.open((fileName).c_str());

    std::string output;
    std::string line;

    if(file.is_open())
    {
        while(file.good())
        {
            getline(file, line);
			output.append(line + "\n");
        }
    }
    else
    {
		std::cerr << "Unable to load shader: " << fileName << std::endl;
    }

    return output;
}

static void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage)
{
    GLint success = 0;
    GLchar error[1024] = { 0 };

    if(isProgram)
        glGetProgramiv(shader, flag, &success);
    else
        glGetShaderiv(shader, flag, &success);

    if(success == GL_FALSE)
    {
        if(isProgram)
            glGetProgramInfoLog(shader, sizeof(error), NULL, error);
        else
            glGetShaderInfoLog(shader, sizeof(error), NULL, error);

        std::cerr << errorMessage << ": '" << error << "'" << std::endl;
    }
}