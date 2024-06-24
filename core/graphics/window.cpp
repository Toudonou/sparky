//
// Created by Toudonou on 6/24/2024.
//

#include "window.h"

namespace sparky {
    Window *Window::s_Instance = nullptr;

    // Callbacks functions
    void frame_buffer_size_callback(GLFWwindow *window, const int width, const int height) {
        if (Window::s_Instance) {
            Window::s_Instance->m_Width = width;
            Window::s_Instance->m_Height = height;
        }
        glViewport(0, 0, width, height);
    };

    Window::Window() {
        m_IsInit = false;
        m_Width = 0;
        m_Height = 0;
        m_Title = "";
        m_Window = nullptr;
        m_InputManager = InputManager();
    }

    Window::~Window() = default;

    bool Window::isKeyPressed(const unsigned int keycode) const {
       return  m_InputManager.isKeyPressed(keycode);
    }

    bool Window::isMouseButtonPressed(const unsigned int button) const {
        return  m_InputManager.isMouseButtonPressed(button);
    }

    void Window::Init(const int width, const int height, const std::string &tilte) {
        // Some kind of singleton partern
        if (m_IsInit || s_Instance) {
            std::cout << "WARNING : Trying to initialize the window twice";
            return;
        }
        // Init GLFW library
        if (!glfwInit()) {
            std::cout << "Error during GLFW initialization" << std::endl;
            return;
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); // Setting up the minor GLFW version
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // Setting up the major GLFW version
        // Telling GLFW that we want to used the core profile
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        // Creating the window
        m_Width = width;
        m_Height = height;
        m_Title = tilte;
        m_Window = glfwCreateWindow(m_Width, m_Height, m_Title.c_str(), nullptr, nullptr);
        if (!m_Window) {
            std::cout << "Failed to create GLFW window\n";
            Quit();
            return;
        }
        glfwMakeContextCurrent(m_Window); // Setting up the window as the current context

        // Initialize GLAD
        if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress))) {
            std::cout << "Failed to initialize GLAD\n";
            Quit();
            return;
        }

        // Start from there everything should be nice
        // So.....
        s_Instance = this; // Maybe not good at all
        m_IsInit = true;
        m_InputManager.Init(m_Window);

        glViewport(0, 0, m_Width, m_Height);

        // Setting up the frame buffer callback function
        glfwSetFramebufferSizeCallback(m_Window, frame_buffer_size_callback);
    }

    void Window::Update() {
        glfwPollEvents();
        // Swapping the buffers
        glfwSwapBuffers(m_Window);
    }

    void Window::Quit() {
        m_IsInit = false;
        s_Instance = nullptr;
        glfwTerminate();
    }

    // Callback functions
} // sparky
