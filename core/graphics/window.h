//
// Created by Toudonou on 6/24/2024.
//

#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "../input/InputManager.h"

namespace sparky {
    class Window {
    public:
        void Init(int width, int height, const std::string &tilte);

        void Update();

        __forceinline [[nodiscard]] bool IsClosed() const { return glfwWindowShouldClose(m_Window); }

        void Quit();

        __forceinline [[nodiscard]] GLFWwindow *GetWindow() const { return m_Window; }

        Window();

        ~Window();

        // Not good at all
        // Very dumb
        [[nodiscard]] bool IsKeyPressed(unsigned int keycode) const;

        [[nodiscard]] bool IsMouseButtonPressed(unsigned int button) const;

    private:
        static Window *s_Instance;

        bool m_IsInit;

        int m_Width;

        int m_Height;

        std::string m_Title;

        GLFWwindow *m_Window;

        InputManager m_InputManager;

        // Friends functions
        // Callbacks prototyes
        friend void frame_buffer_size_callback(GLFWwindow *window, int width, int height);
    };
} // sparky

#endif //WINDOW_H
