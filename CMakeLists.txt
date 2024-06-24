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
)

target_link_libraries(${PROJECT_NAME} glfw3 opengl32)
