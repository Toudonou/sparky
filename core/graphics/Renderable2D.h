//
// Created by Toudonou on 7/2/2024.
//

#ifndef RENDERABLE2D_H
#define RENDERABLE2D_H

#include "buffers/VertexArray.h"
#include "buffers/IndexBuffer.h"
#include "buffers/VertexBuffer.h"

namespace sparky {
    class Renderable2D {
    public:
        virtual ~Renderable2D() = default;

        [[nodiscard]] virtual VertexArray *getVertexArray() = 0;

        [[nodiscard]] virtual IndexBuffer *getIndexBuffer() = 0;

        [[nodiscard]] virtual VertexBuffer *getPositionBuffer() = 0;

        [[nodiscard]] virtual VertexBuffer *getColorBuffer() = 0;
    };
}

#endif //RENDERABLE2D_H
