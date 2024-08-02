//
// Created by Toudonou on 7/9/2024.
//

#define STB_IMAGE_IMPLEMENTATION
#include "BatchRender.h"

#include <iostream>
#include <stb_image.h>

namespace sparky {
    constexpr GLubyte NUM_SPRITE_VERTICES = 4;
    constexpr GLubyte NUM_SPRITE_INDICES = 6;

    template<typename T>
    int indexOf(const std::set<T> &mySet, const T &value) {
        auto it = mySet.find(value);
        if (it == mySet.end()) {
            // Element not found
            return -1;
        }

        int index = 0;
        for (auto itr = mySet.begin(); itr != it; ++itr) {
            ++index;
        }
        return index;
    }

    BatchRenderer::BatchRenderer(const GLuint maxRenderable) : m_MaxSprite(maxRenderable) {
        m_MaxVertices = m_MaxSprite * NUM_SPRITE_VERTICES;
        m_MaxIndices = m_MaxSprite * NUM_SPRITE_INDICES;
        init();
    }

    BatchRenderer::~BatchRenderer() {
        glDeleteVertexArrays(1, &m_VAO);
        glDeleteBuffers(1, &m_VBO);
        glDeleteBuffers(1, &m_IBO);
        for (GLuint texture: m_Textures) {
            glDeleteTextures(1, &texture);
        }
    }

    void BatchRenderer::Submit(const Sprite *sprite) {
        m_Textures.insert(sprite->texID);
        const int index = indexOf(m_Textures, sprite->texID);

        m_Vertices.push_back(Vertex{
            .position = vec3(sprite->positon.x, sprite->positon.y, 0), .uv = vec2(0.0f, 1.0f), .color = sprite->color,
            .texID = static_cast<float>(index)
        }); // 0
        m_Vertices.push_back(Vertex{
            .position = vec3(sprite->positon.x, sprite->positon.y, 0) + vec3(sprite->size.x, 0, 0),
            .uv = vec2(1.0f, 1.0f),
            .color = sprite->color, .texID = static_cast<float>(index)
        }); // 1
        m_Vertices.push_back(Vertex{
            .position = vec3(sprite->positon.x, sprite->positon.y, 0) + vec3(0, sprite->size.y, 0),
            .uv = vec2(0.0f, 0.0f),
            .color = sprite->color, .texID = static_cast<float>(index)
        }); // 2
        m_Vertices.push_back(Vertex{
            .position = vec3(sprite->positon.x, sprite->positon.y, 0) + vec3(sprite->size.x, sprite->size.y, 0),
            .uv = vec2(1.0f, 0.0f),
            .color = sprite->color, .texID = static_cast<float>(index)
        }); // 3
    }

    void BatchRenderer::Render() const {
        int i = 0;
        for (const GLuint texture: m_Textures) {
            glActiveTexture(GL_TEXTURE0 + i++);
            glBindTexture(GL_TEXTURE_2D, texture);

            std::cout << "Texture index : " << i << std::endl;
            std::cout << "Texture value : " << texture << std::endl;
        }

        glBindVertexArray(m_VAO);
        glBindBuffer(GL_ARRAY_BUFFER, m_VBO);


        glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(Vertex) * m_Vertices.size(), m_Vertices.data());
        constexpr GLfloat indicesFactor = static_cast<GLfloat>(NUM_SPRITE_INDICES) / NUM_SPRITE_VERTICES;
        glDrawElements(GL_TRIANGLES, m_Vertices.size() * indicesFactor, GL_UNSIGNED_INT, nullptr);

        glBindVertexArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindTexture(GL_TEXTURE_2D, 0);
    }

    void BatchRenderer::init() {
        // VAO
        glGenVertexArrays(1, &m_VAO);
        glBindVertexArray(m_VAO);

        // VBO
        glGenBuffers(1, &m_VBO);
        glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
        glBufferData(GL_ARRAY_BUFFER, m_MaxVertices * sizeof(Vertex), nullptr, GL_DYNAMIC_DRAW);

        // Layout attribution
        glEnableVertexAttribArray(0); // position
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                              reinterpret_cast<void *>(offsetof(Vertex, Vertex::position)));

        glEnableVertexAttribArray(1); // uv
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                              reinterpret_cast<void *>(offsetof(Vertex, Vertex::uv)));

        glEnableVertexAttribArray(2); // color
        glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                              reinterpret_cast<void *>(offsetof(Vertex, Vertex::color)));

        glEnableVertexAttribArray(3); // texID
        glVertexAttribPointer(3, 1, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                              reinterpret_cast<void *>(offsetof(Vertex, Vertex::texID)));

        // IBO
        std::vector<GLuint> indices;
        indices.resize(m_MaxIndices);

        GLuint offset = {0};
        for (int i = 0; i < m_MaxIndices; i += NUM_SPRITE_INDICES) {
            indices[i + 0] = 0 + offset;
            indices[i + 1] = 1 + offset;
            indices[i + 2] = 2 + offset;

            indices[i + 3] = 1 + offset;
            indices[i + 4] = 2 + offset;
            indices[i + 5] = 3 + offset;

            offset += NUM_SPRITE_VERTICES;
        }
        glGenBuffers(1, &m_IBO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_MaxIndices * sizeof(GLuint), indices.data(), GL_DYNAMIC_DRAW);

        glBindVertexArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    GLuint BatchRenderer::load_texture(const std::string &filename, float *width, float *height) {
        GLuint tex;
        glGenTextures(1, &tex);
        glBindTexture(GL_TEXTURE_2D, tex);

        int temp_width, temp_height, channels;
        unsigned char *image = stbi_load(filename.c_str(), &temp_width, &temp_height, &channels, 0);

        *width = temp_width;
        *height = temp_height;

        if (channels == 3)
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB8, temp_width, temp_height, 0, GL_RGB, GL_UNSIGNED_BYTE, nullptr);
        if (channels == 4)
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, temp_width, temp_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        if (channels == 3)
            glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, temp_width, temp_height, GL_RGB, GL_UNSIGNED_BYTE, image);
        else if (channels == 4)
            glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, temp_width, temp_height, GL_RGBA, GL_UNSIGNED_BYTE, image);

        glGenerateMipmap(GL_TEXTURE_2D);

        glBindTexture(GL_TEXTURE_2D, 0);

        stbi_image_free(image);

        return tex;
    }
}
