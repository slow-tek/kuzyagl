#ifndef _SHADER_H_
#define _SHADER_H_

#include <string>
#include <GL/glew.h>

class Shader
{
public:
    Shader(const std::string& fileName);
    
    void Bind();
    
    virtual ~Shader();
    
protected:
private:
    static const unsigned int NUM_SHADERS = 2;
    Shader(const Shader& other) { }
    
    GLuint m_program;
    GLuint m_shaders[NUM_SHADERS];
};

#endif // _SHADER_H_