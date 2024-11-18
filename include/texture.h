#ifndef _TEXTURE_H_
#define _TEXTURE_H_

#include <string>
#include <GL/glew.h>

class Texture
{
public:
    Texture(const std::string& fileName);
    
    void Bind(unsigned int uint);
    
    virtual ~Texture();
    
protected:
private:
    GLuint m_texture;
};

#endif