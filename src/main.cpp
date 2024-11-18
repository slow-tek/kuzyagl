#include <iostream>
#include "display.h"
#include "mesh.h"
#include "shader.h"
#include "texture.h"
#include <GL/glew.h>

int main(void)
{
    Display display(800, 600, "Kuzya!");
    
    //Shader shader("./res/basicShader");
    Vertex vertices[] = { Vertex(glm::vec3(-0.45, -0.5, 0), glm::vec2(0, 1)),
                          Vertex(glm::vec3( 0.45, -0.5, 0), glm::vec2(1, 1)),
                          Vertex(glm::vec3( 0.45,  0.5, 0), glm::vec2(1, 0)),
                          Vertex(glm::vec3( -0.45, 0.5, 0), glm::vec2(0, 0)) };
                         
    Mesh mesh(vertices, sizeof(vertices)/sizeof(vertices[0]));    
    Shader shader("./res/basicShader");
    Texture texture("./res/kuz.jpg");
    
    while(!display.isClosed())
    {
        display.Clear(0, 0, 0, 0);
        shader.Bind();
        texture.Bind(0);
        mesh.Draw();
        
        display.Update();
    }
    return 0;
}