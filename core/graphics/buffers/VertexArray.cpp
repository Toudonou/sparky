//
// Created by Toudonou on 7/1/2024.
//

#include "VertexArray.h"

namespace sparky {
    VertexArray::VertexArray() {
        glGenVertexArrays(1, &m_ArrayID);
    }

    VertexArray::~VertexArray() {
        glDeleteVertexArrays(1, &m_ArrayID);
        for (const auto m_vertex_buffer: m_VertexBuffers)
            delete m_vertex_buffer;
    }

    void VertexArray::addVertexBuffer(const VertexBuffer *vertexBuffer, const GLuint index) {
        bind();
        vertexBuffer->bind();
        glEnableVertexAttribArray(index);
        glVertexAttribPointer(index, vertexBuffer->GetComponentCount(), GL_FLOAT, GL_FALSE, 0,
                              nullptr);
        vertexBuffer->unbind();
        unbind();

        m_VertexBuffers.push_back(const_cast<VertexBuffer *>(vertexBuffer));
    }

    void VertexArray::bind() const {
        glBindVertexArray(m_ArrayID);
    }

    void VertexArray::unbind() const {
        glBindVertexArray(0);
    }
} // sparky
