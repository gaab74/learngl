#include "window.hpp"
#include "GL/glew.h"
#include "GLFW/glfw3.h"

Window::Window(unsigned int width, unsigned int height, std::string title)
    :m_window(nullptr),
     m_windowWidth(width),
     m_windowHeight(height),
     m_windowTitle(title),
     m_glfwContext(false),
     m_glewContext(false)
{
    // set errors callback
    glfwSetErrorCallback(ErrorCallback);

    // initialize glfw
    m_glfwContext = glfwInit();
    if (!m_glfwContext) {
        fprintf(stderr, "Couldn't initialize GLFW!\n");
        exit(-1);
    }

    // set OpenGL version
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // create window
    m_window = glfwCreateWindow(m_windowWidth, m_windowHeight, m_windowTitle.c_str(), nullptr, nullptr);
    if (m_window == nullptr) {
        fprintf(stderr, "Couldn't create a GLFW window!\n");
        exit(-1);
    }

    // other callbacks
    glfwSetKeyCallback(m_window, InputCallback);
    glfwSetFramebufferSizeCallback(m_window, FramebufferResizeCallback);
    glfwSetWindowSizeCallback(m_window, ResizeCallback);

    // a pointer to our own window instance
    glfwSetWindowUserPointer(m_window, reinterpret_cast<void *>(this));

    // set context
    glfwMakeContextCurrent(m_window);
    printf("OpenGL Version %s\n", glGetString(GL_VERSION));

    // initialize glew
    GLenum err = glewInit();
    if (GLEW_OK != err)
    {
        fprintf(stderr, "Couldn't initialize GLEW!\n");
        exit(-1);
    }
}

Window::~Window()
{
    // destroy window
    if (m_window)
    {
        glfwDestroyWindow(m_window);
        m_window = nullptr;
    }

    // destroy glfw
    if (m_glfwContext)
    {
        glfwTerminate();
        m_glfwContext = false;
    }
}

void Window::ErrorCallback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

void Window::InputCallback(GLFWwindow* window, int key, int scanCode, int action, int mods)
{
    // Window *win = reinterpret_cast<Window *>(glfwGetWindowUserPointer(window));
    // if (win == nullptr) {
    //     exit(-1);
    // }
    // if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
    //     glfwSetWindowShouldClose(win->m_window, GLFW_TRUE);
    // }
}

void Window::ResizeCallback(GLFWwindow* window, int width, int height)
{
}

void Window::FramebufferResizeCallback(GLFWwindow* window, int width, int height)
{
    Window *win = reinterpret_cast<Window *>(glfwGetWindowUserPointer(window));
    if (win == nullptr) {
        exit(-1);
    }

    win->m_windowWidth  = width;
    win->m_windowHeight = height;
}

void Window::WindowMainLoop()
{
    while (!glfwWindowShouldClose(m_window))
    {
        glfwGetFramebufferSize(m_window, (int*)(&m_windowWidth), (int*)(&m_windowHeight));
        glViewport(0, 0, m_windowWidth, m_windowHeight);

        glClearColor(0.08f, 0.08f, 0.08f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwPollEvents();
        glfwSwapBuffers(m_window);
    }
}

int Window::GetWindowWidth() const
{
    return m_windowWidth;
}

int Window::GetWindowHeight() const
{
    return m_windowHeight;
}

std::string Window::GetWindowTitle() const
{
    return m_windowTitle;
}

void Window::SetWindowSize(unsigned int width, unsigned int height)
{
    glfwSetWindowSize(m_window, width, height);
}

void Window::SetWindowTitle(std::string title)
{
    glfwSetWindowTitle(m_window, title.c_str());
    m_windowTitle = title;
}
