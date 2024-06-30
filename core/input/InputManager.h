//
// Created by Toudonou on 6/24/2024.
//

#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define MAX_KEYS            1024
#define MAX_MOUSE_BUTTONS   32

namespace sparky {
    class InputManager {
    public:
        InputManager();

        ~InputManager();

        // TODO : I should used weak_ptr
        void Init( GLFWwindow *window);

        void Quit();

        [[nodiscard]] bool IsKeyPressed(unsigned int keycode) const;

        [[nodiscard]] bool IsMouseButtonPressed(unsigned int button) const;

    private:
        static InputManager *s_Instance;

        bool m_Keys[MAX_KEYS]{};

        bool m_MouseButtonKeys[MAX_MOUSE_BUTTONS]{};

        double m_MouseX{}, m_MouseY{};

        bool m_IsInit;

        // Friends functions
        // Callbacks prototyes
        friend  void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);

        friend void mouse_button_callback(GLFWwindow *window, int button, int action, int mods);

        friend void cursor_position_callback(GLFWwindow *window, double xpos, double ypos);
    };
} // sparky

#endif //INPUTMANAGER_H
