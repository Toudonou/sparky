//
// Created by Toudonou on 6/24/2024.
//

#include "vec2.h"

namespace sparky {
    vec2::vec2() {
        x = 0;
        y = 0;
    }

    vec2::vec2(const real _x, const real _y) : x(_x), y(_y) {
    }

    vec2::~vec2() = default;

    vec2 vec2::operator+(const vec2 &other) const {
        return {x + other.x, y + other.y};
    }

    void vec2::operator+=(const vec2 &other) {
        x += other.x;
        y += other.y;
    }

    // Scalar product
    vec2 vec2::operator*(const real scalar) const {
        return {x * scalar, y * scalar};
    }

    // Scalar product
    vec2 operator*(const real scalar, const vec2 &other) {
        return other * scalar;
    }

    // Scalar product
    void vec2::operator*=(const real scalar) {
        x *= scalar;
        y *= scalar;
    }

    // Dot product
    real vec2::operator*(const vec2 &other) const {
        return x * other.x + y * other.y;
    }

    vec2 vec2::operator-(const vec2 &other) const {
        return *this + -1 * other;
    }

    void vec2::operator-=(const vec2 &other) {
        *this += -1 * other;
    }
} // sparky
