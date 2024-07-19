#include <chrono>
#include <cmath>

#include "core/graphics/BatchRender.h"
#include "core/graphics/Shader.h"
#include "core/graphics/Window.h"
#include "core/maths/Transform.h"

int main() {
    srand(time(nullptr));
    constexpr int screenWidth = 1200, screenHeight = 800;
    auto window = sparky::Window();
    window.Init(screenWidth, screenHeight, "Sparky");

    const sparky::Shader shader("../core/shaders/basic.vert", "../core/shaders/basic.frag");
    shader.enable();

    auto ortho = sparky::mat4::orthographic(0, screenWidth, 0, screenHeight, -10, 10);
    shader.setUniformMat4("vw_matrix", ortho);

    const GLint textures[32] = {
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
        30, 31
    };
    shader.setUniform1iv("textures", textures, 32);

    constexpr int nbrTile = 10;

    auto batchRender = sparky::BatchRenderer(50000);
    std::vector<sparky::Sprite *> rects;

    float temp;
    sparky::vec2 size[4];
    const GLuint icons[4] = {
        sparky::BatchRenderer::load_texture(std::string("./tile-target.bmp"), &size[0].x, &size[0].y),
        // sparky::BatchRenderer::load_texture(std::string("./tile-wall.bmp"), &size[1].x, &size[1].y),
        // sparky::BatchRenderer::load_texture(std::string("./dialog_pause_button_menu@2x.png"), &size[2].x, &size[2].y),
    };


    GLuint k = 0;
    for (int i = 0; i < nbrTile; i++) {
        for (int j = 0; j < nbrTile; ++j) {
            rects.push_back(new sparky::Sprite(size[0].x * i, size[0].y * j, 0, size[k % 1], sparky::vec4(1, 1, 1, 1),
                                               icons[k % 1]));
            batchRender.Submit(rects.at(k++));
        }
    }

    auto timer = std::chrono::high_resolution_clock::now();

    // Important
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);

    while (!window.IsClosed()) {
        ortho = sparky::mat4::orthographic(0, window.GetSize().x, 0, window.GetSize().y, -10, 10) *
                sparky::Transform::Scale(sparky::vec3(1, 1, 1));
        shader.setUniformMat4("vw_matrix", ortho);

        timer = std::chrono::high_resolution_clock::now();

        shader.setUniform4f("light_pos", sparky::vec4(window.GetMousePosition().x,
                                                      window.GetSize().y - window.GetMousePosition().y, 0, 0));


        glDisable(GL_DEPTH_TEST);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        // glClearColor(1, 1, 1, 1);
        glClearColor(0.21, 0.21, 0.21, 1);
        batchRender.Render();
        window.Update();

        // Calculate the duration
        std::chrono::duration<double> duration = std::chrono::high_resolution_clock::now() - timer;
        // Output the duration in seconds
        // std::cout << "FPS: " << static_cast<int>(1 / duration.count()) << std::endl;
    }
    std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;
    std::cout << rects.size() << " : tiles: " << std::endl;

    window.Quit();

    for (const auto rect: rects)
        delete rect;

    return 0;
}

float q_rsqrt(const float number) {
    float y;
    constexpr float threehalf = 1.5f;

    const float x2 = number * 0.5f;
    y = number;

    long i = *reinterpret_cast<long *>(&y);
    i = 0X5f3759df - (i >> 1);
    y = *reinterpret_cast<float *>(&i);
    y = y * (threehalf - (x2 * y * y));
    y = y * (threehalf - (x2 * y * y));
    y = y * (threehalf - (x2 * y * y));

    return y;
}

void CheckOpenGLError(const char *fname, const int line) {
    const GLenum err = glGetError();
    if (err != GL_NO_ERROR) {
        std::string error;

        switch (err) {
            case GL_INVALID_OPERATION: error = "INVALID_OPERATION";
                break;
            case GL_INVALID_ENUM: error = "INVALID_ENUM";
                break;
            case GL_INVALID_VALUE: error = "INVALID_VALUE";
                break;
            case GL_OUT_OF_MEMORY: error = "OUT_OF_MEMORY";
                break;
            case GL_INVALID_FRAMEBUFFER_OPERATION: error = "INVALID_FRAMEBUFFER_OPERATION";
                break;
            default: ;
        }

        std::cerr << "OpenGL error " << error << " at " << fname << ":" << line << std::endl;
    }
}
