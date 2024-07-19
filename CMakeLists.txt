cmake_minimum_required(VERSION 3.28)
project(sparky)

set(CMAKE_CXX_STANDARD 23)

include_directories(third-party/include) # Include the third-party libraries
link_directories(third-party/lib) # Link the third-party libraries

add_executable(${PROJECT_NAME}
        main.cpp
        third-party/src/glad.c
        core/graphics/window.cpp
        core/graphics/window.h
        core/input/InputManager.cpp
        core/input/InputManager.h
        core/maths/vec2.cpp
        core/maths/vec2.h
        core/maths/constants.h
        core/maths/constants.h
        core/maths/vec3.cpp
        core/maths/vec3.h
        core/maths/vec4.h
        core/maths/vec4.cpp
        core/maths/mat4.cpp
        core/maths/mat4.h
        core/maths/Transform.cpp
        core/maths/Transform.h
        core/utils/fileutils.h
        core/graphics/Shader.cpp
        core/graphics/Shader.h
        core/graphics/buffers/VertexBuffer.cpp
        core/graphics/buffers/VertexBuffer.h
        core/graphics/buffers/IndexBuffer.cpp
        core/graphics/buffers/IndexBuffer.h
        core/graphics/buffers/VertexArray.cpp
        core/graphics/buffers/VertexArray.h
        core/graphics/Renderable2D.h
        core/graphics/Simple2DRender2D.cpp
        core/graphics/Simple2DRender2D.h
        core/graphics/Rectangle2D.cpp
        core/graphics/Rectangle2D.h
        core/graphics/BatchRender.cpp
        core/graphics/BatchRender.h
        third-party/include/stb_image.h
)

target_link_libraries(${PROJECT_NAME} glfw3 opengl32)
