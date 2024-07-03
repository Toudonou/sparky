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
        __forceinline [[nodiscard]] vec2 GetSize() const {
            return {static_cast<real>(m_Width), static_cast<real>(m_Height)};
        }

        Window();

        ~Window();

        // Not good at all
        // Very dumb
        [[nodiscard]] bool IsKeyPressed(unsigned int keycode) const;

        [[nodiscard]] bool IsMouseButtonPressed(unsigned int button) const;

        __forceinline [[nodiscard]] vec2 GetMousePosition() const { return m_InputManager.GetMousePosition(); }

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
