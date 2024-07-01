//
// Created by Toudonou on 7/1/2024.
//

#include "IndexBuffer.h"

namespace sparky {
    IndexBuffer::IndexBuffer(const GLushort *data, const GLsizei dataCount)
    : m_Count(dataCount) {
        glGenBuffers(1, &m_IndexBuffer);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IndexBuffer);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, dataCount * sizeof(GLushort), data, GL_STATIC_DRAW);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

    void IndexBuffer::bind() const {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IndexBuffer);
    }

    void IndexBuffer::unbind() const {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

} // sparky