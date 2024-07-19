#ifndef BATCHRENDER_H
#define BATCHRENDER_H

#include <set>
#include <unordered_set>
#include <vector>

#include "../maths/vec2.h"
#include "../maths/vec3.h"
#include "../maths/vec4.h"

namespace sparky {
    struct Vertex {
        vec2 position;
        vec2 uv;
        vec4 color;
        float texID;
    };

    struct Sprite {
        vec2 positon;
        vec2 size;
        vec4 color;
        GLuint texID;

        Sprite(const real x, const real y, const real z, const vec2 &size, const vec4 &color, const GLuint tex) {
            positon = vec2(x, y);
            this->color = color;
            this->texID = tex;
            this->size = vec2(1 * size.x, 1 * size.y);
        }
    };

    class BatchRenderer {
    public:
        explicit BatchRenderer(GLuint maxRenderable);

        ~BatchRenderer();

        void Submit(const Sprite *sprite);

        void Render() const;

        static GLuint load_texture(const std::string &filename, float *width, float *height);

    private:
        GLuint m_VAO{}, m_VBO{}, m_IBO{};
        GLuint m_MaxSprite;
        GLuint m_MaxVertices;
        GLuint m_MaxIndices;

        std::vector<Vertex> m_Vertices;
        std::set<GLuint> m_Textures;

        void init();
    };
}
#endif // BATCHRENDER_H
