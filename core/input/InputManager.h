//
// Created by Toudonou on 6/24/2024.
//

#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include "../graphics/window.h"

#define MAX_KEYS            1024
#define MAX_MOUSE_BUTTONS   32

namespace sparky {
    class InputManager {
    public:
        void Init(Window &window);

        void Quit();

        static bool isKeyPressed(unsigned int keycode);

        static bool isMouseButtonPressed(unsigned int button);

    private:
        static bool m_Keys[MAX_KEYS];
        static bool m_MouseButtonKeys[MAX_MOUSE_BUTTONS];
        static bool m_MouseX, m_MouseY;

        bool m_IsInit;

        InputManager();

        ~InputManager();

        // Friends functions
        // Callbacks prototyes
        friend void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);

        friend void mouse_button_callback(GLFWwindow *window, int button, int action, int mods);

        friend void cursor_position_callback(GLFWwindow *window, double xpos, double ypos);
    };
} // sparky

#endif //INPUTMANAGER_H
