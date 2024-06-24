//
// Created by Toudonou on 6/24/2024.
//

#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace sparky {
    class Window {
    public:
        void Init(int width, int height, const std::string &tilte);

        void Update();

        void Quit();

        Window();

        ~Window();

    private:
        static Window* s_Instance;
        bool m_IsInit;
        int m_Width;
        int m_Height;
        std::string m_Title;
        GLFWwindow *m_Window;

        // Friends functions
        // Callbacks prototyes
        friend void frame_buffer_size_callback(GLFWwindow *window, int width, int height);
    };
} // sparky

#endif //WINDOW_H
