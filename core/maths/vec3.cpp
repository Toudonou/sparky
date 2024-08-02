//
// Created by Toudonou on 6/24/2024.
//

#include "vec3.h"

#include <cmath>

namespace sparky {
    vec3::vec3() {
        x = 0;
        y = 0;
        z = 0;
    }

    vec3::vec3(const real _x, const real _y, const real _z) : x(_x), y(_y), z(_z) {
    }

    vec3::~vec3() = default;

    real vec3::length() const {
        return std::sqrt(squareLength());
    }

    real vec3::squareLength() const {
        return x * x + y * y + z * z;
    }

    vec3 vec3::normalized() const {
        if (squareLength() == 0) return {0, 0, 0};
        return *this * (1 / length());
    }

    vec3 vec3::operator+(const vec3 &other) const {
        return {x + other.x, y + other.y, z + other.z};
    }

    void vec3::operator+=(const vec3 &other) {
        x += other.x;
        y += other.y;
    }

    // Scalar product
    vec3 vec3::operator*(const real scalar) const {
        return {x * scalar, y * scalar, z * scalar};
    }

    // Scalar product
    vec3 operator*(const real scalar, const vec3 &other) {
        return other * scalar;
    }

    // Scalar product
    void vec3::operator*=(const real scalar) {
        x *= scalar;
        y *= scalar;
    }

    // Dot product
    real vec3::operator*(const vec3 &other) const {
        return x * other.x + y * other.y + z * other.z;
    }

    vec3 vec3::operator-(const vec3 &other) const {
        return *this + -1 * other;
    }

    void vec3::operator-=(const vec3 &other) {
        *this += -1 * other;
    }
} // sparky
