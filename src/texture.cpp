#include "texture.h"
#include <assert.h>
#include <iostream>
#include <string>
#include <GL/glew.h>
#include <glm/glm.hpp>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

Texture::Texture(const std::string& fileName)
{
    int width, height, numComponents;
    unsigned char* imageData = stbi_load(fileName.c_str(), &width, &height, &numComponents, 4);
    
    if(imageData == NULL)
        std::cerr << "Texture loading failed!" << std::endl;
    
    glGenTextures(1, &m_texture);
    glBindTexture(GL_TEXTURE_2D, m_texture);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, imageData);
    
    stbi_image_free(imageData);
}

Texture::~Texture()
{
    glDeleteTextures(1, &m_texture);
}

void Texture::Bind(unsigned int uint)
{
    assert(uint >= 0 && uint <= 31);
    glActiveTexture(GL_TEXTURE0 + uint);
    glBindTexture(GL_TEXTURE_2D, m_texture);
}