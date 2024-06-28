//
// Created by Toudonou on 6/24/2024.
//

#include "vec4.h"

namespace sparky {
    vec4::vec4() {
        x = 0;
        y = 0;
        z = 0;
        w = 0;
    }

    vec4::vec4(const real _x, const real _y, const real _z, const real _w) : x(_x), y(_y), z(_z), w(_w) {
    }

    vec4::~vec4() = default;

    vec4 vec4::operator+(const vec4 &other) const {
        return {x + other.x, y + other.y, z + other.z, w + other.w};
    }

    void vec4::operator+=(const vec4 &other) {
        x += other.x;
        y += other.y;
    }

    // Scalar product
    vec4 vec4::operator*(const real scalar) const {
        return {x * scalar, y * scalar, z * scalar, w * scalar};
    }

    // Scalar product
    vec4 operator*(const real scalar, const vec4 &other) {
        return other * scalar;
    }

    // Scalar product
    void vec4::operator*=(const real scalar) {
        x *= scalar;
        y *= scalar;
    }

    // Dot product
    real vec4::operator*(const vec4 &other) const {
        return x * other.x + y * other.y;
    }

    vec4 vec4::operator-(const vec4 &other) const {
        return *this + -1 * other;
    }

    void vec4::operator-=(const vec4 &other) {
        *this += -1 * other;
    }
} // sparky
