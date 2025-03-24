#pragma once

#include <string>

struct GLFWwindow;

class Window
{
public:
    Window(unsigned int width, unsigned int height, std::string title);
    virtual ~Window();

private:
    GLFWwindow  *m_window;
    unsigned int m_windowWidth;
    unsigned int m_windowHeight;
    std::string  m_windowTitle;
    bool         m_glfwContext;
    bool         m_glewContext;

    static void ErrorCallback(int error, const char* description);
    static void InputCallback(GLFWwindow* window, int key, int scanCode, int actions, int mods);
    static void ResizeCallback(GLFWwindow* window, int width, int height);
    static void FramebufferResizeCallback(GLFWwindow* window, int width, int height);

public:
    void WindowMainLoop();

    int GetWindowWidth() const;
    int GetWindowHeight() const;
    std::string GetWindowTitle() const;

    void SetWindowSize(unsigned int width, unsigned int height);
    void SetWindowTitle(std::string title);
};
