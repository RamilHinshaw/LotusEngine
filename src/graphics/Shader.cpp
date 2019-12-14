#include "Shader.hpp"

static void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);
static std::string LoadShader(const std::string& fileName);
static GLuint CreateShader(const std::string& text, GLenum shaderType);

Shader::Shader()
{
    
}

Shader::Shader(const std::string& fileName)
{
    m_program = glCreateProgram();

    //Building shader
    m_shaders[0] = CreateShader(LoadShader(fileName + ".vs"), GL_VERTEX_SHADER);    //Load Vertex Shader
    m_shaders[1] = CreateShader(LoadShader(fileName + ".fs"), GL_FRAGMENT_SHADER);  //Load Fragment Shader

    //Takes program and adds a shader to it
    for (unsigned int i = 0; i < NUM_SHADERS; i++) 
        glAttachShader(m_program, m_shaders[i]);
    
    //Tells opengl what part of the data to read and variable in shader program
    glBindAttribLocation(m_program, 0, "position");

    //Link Shaders
    glLinkProgram(m_program);
    CheckShaderError(m_program, GL_LINK_STATUS, true, "Error: Program linking failed: ");

    //Validate Shaders
    glValidateProgram(m_program);
    CheckShaderError(m_program, GL_VALIDATE_STATUS, true, "Error: Program is invalid: ");
}

void Shader::bind()
{
    glUseProgram(m_program);
}

Shader::~Shader()
{
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

    CheckShaderError(shader, GL_COMPILE_STATUS, false, "Error: Shader compliation failed: ");

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