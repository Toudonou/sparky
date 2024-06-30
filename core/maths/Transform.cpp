//
// Created by Toudonou on 6/28/2024.
//

#include "Transform.h"

#include <cmath>

namespace sparky {
    mat4 Transform::Translation(const vec3 &vector) {
        auto result = mat4::identity();

        result(0, 3) = vector.x;
        result(1, 3) = vector.y;
        result(2, 3) = vector.z;

        return result;
    }

    mat4 Transform::Scale(const vec3 &vector) {
        auto result = mat4::identity();

        result(0, 0) = vector.x;
        result(1, 1) = vector.y;
        result(2, 2) = vector.z;

        return result;
    }

    mat4 Transform::Rotation(const real angle, const vec3 &axis) {
        auto result = mat4::identity();

        const real r = toRadian(angle);
        const real s = sin(r);
        const real c = cos(r);
        const real omc = 1 - c;

        const real x = axis.x;
        const real y = axis.y;
        const real z = axis.z;

        result(0, 0) = x * x * omc + c;
        result(0, 1) = x * y * omc + z * s;
        result(0, 2) = x * z * omc + y * s;
        result(0, 3) = 0;

        result(1, 0) = x * y * omc + z * s;
        result(1, 1) = c + y * y * omc;
        result(1, 2) = y * z * omc - x * s;
        result(1, 3) = 0;

        result(2, 0) = x * z * omc - y * s;
        result(2, 1) = y * z * omc + x * s;
        result(2, 2) = c + z * z * omc;
        result(2, 3) = 0;

        result(3, 0) = 0;
        result(3, 1) = 0;
        result(3, 2) = 0;
        result(3, 3) = 1;

        return result;
    }
} // sparky