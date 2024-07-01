//
// Created by Toudonou on 6/29/2024.
//

#ifndef SHADER_H
#define SHADER_H

#include <string>

#include <glad/glad.h>

#include "../maths/vec2.h"
#include "../maths/vec3.h"
#include "../maths/vec4.h"
#include "../maths/mat4.h"

namespace sparky {
    struct vec3;

    class Shader {
    public:
        Shader(std::string vertPath, std::string fragPath);

        ~Shader();

        void setUniform1i(const std::string &name, int value) const;

        void setUniform1f(const std::string &name, float value) const;

        void setUniform2f(const std::string &name, const vec2 &vector) const;

        void setUniform3f(const std::string &name, const vec3 &vector) const;

        void setUniform4f(const std::string &name, const vec4 &vector) const;

        void Shader::setUniformMat4(const std::string &name, mat4 &matrix) const;

        void enable() const;

        void disable() const;

    private:
        GLuint m_ShaderID;
        std::string m_VertPath, m_FragPath;

        [[nodiscard]] GLuint load() const;

        [[nodiscard]] GLint getUniformLocation(const std::string &name) const;
    };
} // sparky

#endif //SHADER_H
