#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include <SDL2/SDL.h>
#include <string>
class Display
{
public:
    Display(int width, int height, const std::string& title);
    
    void SwapBuffers();
    void Clear(float r, float g, float b, float a);
    bool isClosed();
    void Update();
    
    virtual ~Display();
protected:
private:
    Display(const Display& other) { }
    
    SDL_Window* m_window;
    SDL_GLContext m_glContext;
    bool m_isClosed;
};

#endif // _DISPLAY_H_