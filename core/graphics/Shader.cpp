//
// Created by Toudonou on 6/29/2024.
//

#include <iostream>
#include <utility>

#include "Shader.h"
#include "../utils/Fileutils.h"


namespace sparky {
    Shader::Shader(std::string vertPath, std::string fragPath)
        : m_VertPath(std::move(vertPath)), m_FragPath(std::move(fragPath)) {
        m_ShaderID = load();
    }

    Shader::~Shader() {
        glDeleteProgram(m_ShaderID);
    }

    void Shader::setUniform1i(const std::string &name, const int value) const {
        glUniform1i(getUniformLocation(name), value);
    }

    void Shader::setUniform1iv(const std::string &name, const int *value, const int count) const {
        glUniform1iv(getUniformLocation(name), count, value);
    }

    void Shader::setUniform1f(const std::string &name, const float value) const {
        glUniform1f(getUniformLocation(name), value);
    }

    void Shader::setUniform2f(const std::string &name, const vec2 &vector) const {
        glUniform2f(getUniformLocation(name), static_cast<GLfloat>(vector.x), static_cast<GLfloat>(vector.y));
    }

    void Shader::setUniform3f(const std::string &name, const vec3 &vector) const {
        glUniform3f(getUniformLocation(name), static_cast<GLfloat>(vector.x), static_cast<GLfloat>(vector.y),
                    static_cast<GLfloat>(vector.z));
    }

    void Shader::setUniform4f(const std::string &name, const vec4 &vector) const {
        glUniform4f(getUniformLocation(name), static_cast<GLfloat>(vector.x), static_cast<GLfloat>(vector.y),
                    static_cast<GLfloat>(vector.z), static_cast<GLfloat>(vector.w));
    }

    void Shader::setUniformMat4(const std::string &name, mat4 &matrix) const {
        glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, matrix.GetElements());
    }

    void Shader::enable() const {
        glUseProgram(m_ShaderID);
    }

    void Shader::disable() const {
        glUseProgram(0);
    }

    GLuint Shader::load() const {
        const GLuint program = glCreateProgram();
        const GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
        const GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);
        GLint result;
        GLchar errorLog[1024];

        const std::string vertSourceStr = FileUtils::read_file(m_VertPath);
        const std::string fragSourceStr = FileUtils::read_file(m_FragPath);

        if (vertSourceStr.empty()) {
            std::cerr << "Vertex shader source is empty." << std::endl;
            return 0;
        }

        if (fragSourceStr.empty()) {
            std::cerr << "Fragment shader source is empty." << std::endl;
            return 0;
        }

        const char *vertSource = vertSourceStr.c_str();
        const char *fragSource = fragSourceStr.c_str();

        // Vertex Shader
        glShaderSource(vertex, 1, &vertSource, nullptr);
        glCompileShader(vertex);
        glGetShaderiv(vertex, GL_COMPILE_STATUS, &result);
        if (result == GL_FALSE) {
            glGetShaderInfoLog(vertex, sizeof(errorLog), nullptr, errorLog);
            std::cerr << "Error during vertex shader compilation: " << errorLog << std::endl;
            glDeleteShader(vertex);
            return 0;
        }

        // Fragment Shader
        glShaderSource(fragment, 1, &fragSource, nullptr);
        glCompileShader(fragment);
        glGetShaderiv(fragment, GL_COMPILE_STATUS, &result);
        if (result == GL_FALSE) {
            glGetShaderInfoLog(fragment, sizeof(errorLog), nullptr, errorLog);
            std::cerr << "Error during fragment shader compilation: " << errorLog << std::endl;
            glDeleteShader(fragment);
            return 0;
        }

        // Link Shaders
        glAttachShader(program, vertex);
        glAttachShader(program, fragment);
        glLinkProgram(program);
        glGetProgramiv(program, GL_LINK_STATUS, &result);
        if (result == GL_FALSE) {
            glGetProgramInfoLog(program, sizeof(errorLog), nullptr, errorLog);
            std::cerr << "Error during shader program linking: " << errorLog << std::endl;
            glDeleteProgram(program);
            return 0;
        }

        // Validate Program
        glValidateProgram(program);
        glGetProgramiv(program, GL_VALIDATE_STATUS, &result);
        if (result == GL_FALSE) {
            glGetProgramInfoLog(program, sizeof(errorLog), nullptr, errorLog);
            std::cerr << "Error during shader program validation: " << errorLog << std::endl;
            glDeleteProgram(program);
            return 0;
        }

        glDeleteShader(vertex);
        glDeleteShader(fragment);

        return program;
    }

    GLint Shader::getUniformLocation(const std::string &name) const {
        return glGetUniformLocation(m_ShaderID, name.c_str());
    }
} // namespace sparky
