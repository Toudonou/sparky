//
// Created by Toudonou on 7/1/2024.
//

#ifndef INDEXBUFFER_H
#define INDEXBUFFER_H

#include <glad/glad.h>
#include <_mingw.h>

namespace sparky {
    class IndexBuffer {
    public:
        IndexBuffer(const GLushort *data, GLsizei dataCount);

        void bind() const;

        void unbind() const;

        __forceinline GLuint GetCount() const { return m_Count; }

    private:
        GLuint m_IndexBuffer{};
        GLuint m_Count;
    };
}


#endif //INDEXBUFFER_H
