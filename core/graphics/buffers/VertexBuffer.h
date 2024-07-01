//
// Created by Toudonou on 7/1/2024.
//

#ifndef VERTEXBUFFER_H
#define VERTEXBUFFER_H
#include <glad/glad.h>
#include <_mingw.h>

namespace sparky {
    class VertexBuffer {
    public:
        VertexBuffer(const GLfloat *data, GLsizei dataCount, GLint componentCount);

        void bind() const;

        void unbind() const;

        __forceinline GLint GetComponentCount() const { return m_ComponentCount; }

    private:
        GLuint m_VertexBuffer{};
        GLint m_ComponentCount;
    };
}


#endif //VERTEXBUFFER_H
