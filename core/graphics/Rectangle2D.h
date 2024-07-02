//
// Created by Toudonou on 7/2/2024.
//

#ifndef RECTANGLE2D_H
#define RECTANGLE2D_H
#include "Renderable2D.h"
#include "../maths/vec2.h"
#include "../maths/vec3.h"
#include "../maths/vec4.h"

namespace sparky {
    class Rectangle2D : public Renderable2D {
    public:
        Rectangle2D(real x, real y, real z, real width, real height, const vec4 &color);

        ~Rectangle2D() override;

        __forceinline [[nodiscard]] VertexArray *getVertexArray() override { return m_VAO; }

        __forceinline [[nodiscard]] IndexBuffer *getIndexBuffer() override { return m_IBO; }

        __forceinline [[nodiscard]] VertexBuffer *getPositionBuffer() override { return m_PositonBuffer; }

        __forceinline [[nodiscard]] VertexBuffer *getColorBuffer() override { return m_ColorBuffer; }

    private:
        vec3 m_Position;
        vec2 m_Size;
        vec4 m_Color;

        VertexArray *m_VAO;
        IndexBuffer *m_IBO;
        VertexBuffer *m_PositonBuffer;
        VertexBuffer *m_ColorBuffer;
    };
} // sparky

#endif //RECTANGLE2D_H
