//
// Created by Toudonou on 6/24/2024.
//

#include <iostream>

#include "InputManager.h"

namespace sparky {
    InputManager *InputManager::s_Instance = nullptr;

    // Callbacks functions
    void key_callback(GLFWwindow *window, const int key, int scancode, const int action, int mods) {
        if (InputManager::s_Instance) {
            InputManager::s_Instance->m_Keys[key] = action != GLFW_RELEASE;
        }
    }

    void mouse_button_callback(GLFWwindow *window, const int button, const int action, int mods) {
        if (InputManager::s_Instance) {
            InputManager::s_Instance->m_MouseButtonKeys[button] = action != GLFW_RELEASE;
        }
    }

    void cursor_position_callback(GLFWwindow *window, const double xpos, const double ypos) {
        if (InputManager::s_Instance) {
            InputManager::s_Instance->m_MouseX = static_cast<float>(xpos);
            InputManager::s_Instance->m_MouseY = static_cast<float>(ypos);
        }
    }

    InputManager::InputManager() {
        m_IsInit = false;
    };

    InputManager::~InputManager() = default;


    void InputManager::Init(GLFWwindow *window) {
        if (m_IsInit || s_Instance) {
            std::cout << "WARNING : Trying to initialize the input manager twice";
            return;
        }

        if (!window) {
            std::cout << "ERROR : Window should be valid; Input manager initialization failed" << std::endl;
            return;
        }
        m_IsInit = true;
        s_Instance = this;

        glfwSetKeyCallback(window, key_callback);
        glfwSetMouseButtonCallback(window, mouse_button_callback);
        glfwSetCursorPosCallback(window, cursor_position_callback);
    }

    void InputManager::Quit() {
        m_IsInit = false;
        s_Instance = nullptr;
    }

    bool InputManager::IsKeyPressed(const unsigned int keycode) const {
        // TODO : Print a log message
        if (keycode >= MAX_KEYS) {
            return false;
        }
        return m_Keys[keycode];
    }

    bool InputManager::IsMouseButtonPressed(const unsigned int button) const {
        // TODO : Print a log message
        if (button >= MAX_MOUSE_BUTTONS) {
            return false;
        }
        return m_MouseButtonKeys[button];
    }
} // sparky
