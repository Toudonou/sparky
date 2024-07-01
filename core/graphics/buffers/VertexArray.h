//
// Created by Toudonou on 7/1/2024.
//

#ifndef VERTEXARRAY_H
#define VERTEXARRAY_H
#include <vector>
#include <glad/glad.h>

#include "VertexBuffer.h"

namespace sparky {
    class VertexArray {
    public:
        VertexArray();

        ~VertexArray();

        void addVertexBuffer(const VertexBuffer *vertexBuffer, GLuint index);

        void bind() const;

        void unbind() const;

    private:
        GLuint m_ArrayID{};
        std::vector<VertexBuffer *> m_VertexBuffers;
    };
} // sparky

#endif //VERTEXARRAY_H
