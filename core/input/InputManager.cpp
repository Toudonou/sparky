//
// Created by Toudonou on 6/24/2024.
//

#include "InputManager.h"

namespace sparky {
    bool InputManager::m_Keys[MAX_KEYS];
    bool InputManager::m_MouseButtonKeys[MAX_MOUSE_BUTTONS];
    bool InputManager::m_MouseX = false;
    bool InputManager::m_MouseY = false;

    // Callbacks functions
    void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        if (key == GLFW_KEY_E && action == GLFW_PRESS)
            // activate_airship();
    }

    void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
    {
        if (button == GLFW_KEY_E && action == GLFW_PRESS)
            // activate_airship();
    }

    void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
    {
    }


    void InputManager::Init(Window &window) {
        if(m_IsInit) {
            std::cout << "WARNING : Trying to initialize the window twice";
            return;
        }
        glfwSetKeyCallback(window, key_callback);
    }

    void InputManager::Quit() {
    }

    bool InputManager::isKeyPressed(unsigned int keycode) {
        // TODO : Print a log message
        if (keycode >= MAX_KEYS) {
            return false;
        }
        return m_Keys[keycode];
    }

    bool InputManager::isMouseButtonPressed(unsigned int button) {
        // TODO : Print a log message
        if (button >= MAX_MOUSE_BUTTONS) {
            return false;
        }
        return m_MouseButtonKeys[button];
    }

    InputManager::InputManager() {
        m_IsInit = false;
    };

    InputManager::~InputManager() = default;
} // sparky
