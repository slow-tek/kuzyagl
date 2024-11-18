#ifndef _MESH_H_
#define _MESH_H_

#include <glm/glm.hpp>
#include <GL/glew.h>

class Vertex
{
public:
    Vertex(const glm::vec3& pos, const glm::vec2& texCoord): pos(pos), texCoord(texCoord) { };
    
    inline glm::vec3* GetPos() { return &pos; }
    inline glm::vec2* GetTexCoord() { return &texCoord; }
protected:
private:
    glm::vec3 pos;
    glm::vec2 texCoord;
};

class Mesh
{
public:
    Mesh(Vertex* vertices, unsigned int numVertices);
    void Draw();
    virtual ~Mesh();
protected:
private:
    Mesh(const Mesh& other);
    
    enum
    {
        POSITION_VB,
        TEXCOORD_VB,
        
        NUM_BUFFERS
    };
    
    GLuint m_vertexArrayObject;
    GLuint m_vertexArrayBuffers[NUM_BUFFERS];
    unsigned int m_drawCount;
};

#endif //_MESH_H_