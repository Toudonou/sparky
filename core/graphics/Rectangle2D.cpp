//
// Created by Toudonou on 7/2/2024.
//

#include "Rectangle2D.h"

namespace sparky {
    Rectangle2D::Rectangle2D(const real x, const real y, const real z, const real width, const real height,
                             const vec4 &color)
        : m_Position(vec3(x, y, z)), m_Size(vec2(width, height)), m_Color(color) {
        const GLushort indices[] = {
            0, 1, 2,
            1, 2, 3
        };

        const GLfloat vertices[] = {
            m_Position.x, m_Position.y, m_Position.z,
            m_Position.x + m_Size.x, m_Position.y, m_Position.z,
            m_Position.x, m_Position.y + m_Size.y, m_Position.z,
            m_Position.x + m_Size.x, m_Position.y + m_Size.y, m_Position.z
        };

        const GLfloat colors[] = {
            m_Color.x, m_Color.y, m_Color.z, m_Color.w,
            m_Color.x, m_Color.y, m_Color.z, m_Color.w,
            m_Color.x, m_Color.y, m_Color.z, m_Color.w,
            m_Color.x, m_Color.y, m_Color.z, m_Color.w
        };

        m_VAO = new VertexArray();
        m_IBO = new IndexBuffer(indices, 6);
        m_PositonBuffer = new VertexBuffer(vertices, 4 * 3, 3);
        m_ColorBuffer = new VertexBuffer(colors, 4 * 4, 4);

        m_VAO->addVertexBuffer(m_PositonBuffer, 0);
        m_VAO->addVertexBuffer(m_ColorBuffer, 1);
    }

    Rectangle2D::~Rectangle2D() = default;
} // sparky
