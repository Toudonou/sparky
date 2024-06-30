//
// Created by Toudonou on 6/29/2024.
//

#ifndef SHADER_H
#define SHADER_H

#include <string>

#include <glad/glad.h>
#include <GLFW/glfw3.h>


namespace sparky {
    class Shader {
    public:
        Shader(std::string vertPath, std::string fragPath);

        ~Shader();

        void enable() const;

        void disable() const;

    private:
        GLuint m_ShaderID;
        std::string m_VertPath, m_FragPath;

        [[nodiscard]] GLuint load() const;
    };
} // sparky

#endif //SHADER_H
