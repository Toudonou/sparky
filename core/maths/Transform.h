//
// Created by Toudonou on 6/28/2024.
//

#ifndef TRANSFORM_H
#define TRANSFORM_H
#include "mat4.h"
#include "vec3.h"

namespace sparky {
    class Transform {
    public:
        static mat4 Translate(const vec3 &vector);

        static mat4 Scale(const vec3 &vector);

        static mat4 Rotate(real angle, const vec3 &axis);
    };
} // sparky

#endif //TRANSFORM_H
