#include "shader.h"

#include <string>
#include <fstream>
#include <iostream>

static std::string LoadShader(const std::string& fileName);
static void CheckShadeError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);
static GLuint CreateShader(const std::string& text, GLenum shaderType);

Shader::Shader(const std::string& fileName)
{
    m_program = glCreateProgram();
    m_shaders[0] = CreateShader(LoadShader(fileName + ".vs"), GL_VERTEX_SHADER);
    m_shaders[1] = CreateShader(LoadShader(fileName + ".fs"), GL_FRAGMENT_SHADER);
    
    for(unsigned int i = 0; i < NUM_SHADERS; i++)
        glAttachShader(m_program, m_shaders[i]);
   
    glBindAttribLocation(m_program, 0, "position");
    glBindAttribLocation(m_program, 1, "texCoord");
        
    glLinkProgram(m_program);
    CheckShadeError(m_program, GL_LINK_STATUS, true, "Error: Program linking failed: ");
    
    glValidateProgram(m_program);
    CheckShadeError(m_program, GL_VALIDATE_STATUS, true, "Error: Invalid program: ");
}

Shader::~Shader()
{
    for(unsigned int i = 0; i < NUM_SHADERS; i++)
    {
        glDetachShader(m_program, m_shaders[i]);
        glDeleteShader(m_shaders[i]);
    }
    glDeleteProgram(m_program);
}

void Shader::Bind()
{
    glUseProgram(m_program);
}

static GLuint CreateShader(const std::string& text, GLenum shaderType)
{
    GLuint shader = glCreateShader(shaderType);
    
    if(shader == 0)
        std::cerr << "Error: Shader creation failed!" << std::endl;
        
    const GLchar* shaderSourceStrings[1];
    GLint shaderSourceStringLengths[1];
    
    shaderSourceStrings[0] = text.c_str();
    shaderSourceStringLengths[0] = text.length();
    
    glShaderSource(shader, 1, shaderSourceStrings, shaderSourceStringLengths);
    glCompileShader(shader);
    /*
    int shaderCompiled = GL_FALSE;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &shaderCompiled);
    if(!shaderCompiled)
    {
        GLchar InfoLog[256] = { 0 };
        glGetShaderInfoLog(shader, sizeof(InfoLog), NULL, InfoLog);
        std::cout << "Error compiling shader: '" << InfoLog << "'" << std::endl;
    }
    */
    
    CheckShadeError(shader, GL_COMPILE_STATUS, false, "Error: Shader compilation failed: ");
    
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

static void CheckShadeError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage)
{
    GLint success = 0;
    GLchar error[1024] = { 0 };
    
    if(isProgram)
        glGetProgramInfoLog(shader, sizeof(error), NULL, error);
    else
        glGetShaderInfoLog(shader, sizeof(error), NULL, error);
        
    std::cerr << errorMessage << ": '" << error << "'" << std::endl;
}