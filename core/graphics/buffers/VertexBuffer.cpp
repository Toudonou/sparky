//
// Created by Toudonou on 7/1/2024.
//

#include "VertexBuffer.h"



sparky::VertexBuffer::VertexBuffer(const GLfloat *data, const GLsizei dataCount, const GLint componentCount)
    : m_ComponentCount(componentCount) {
    glGenBuffers(1, &m_VertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, m_VertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, dataCount * sizeof(GLfloat), data, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void sparky::VertexBuffer::bind() const {
    glBindBuffer(GL_ARRAY_BUFFER, m_VertexBuffer);
}

void sparky::VertexBuffer::unbind() const {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
