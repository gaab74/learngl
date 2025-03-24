// #include "GL/glew.h"

#include "window.hpp"

int main()
{
    Window *w = new Window(800, 600, "Learning OpenGL 3.3");

    w->WindowMainLoop();

    delete w; w = nullptr;
    
    return 0;
}
