//
// Created by Toudonou on 6/24/2024.
//

#include "Vector4.h"

namespace sparky {
    Vector4::Vector4() {
        x = 0;
        y = 0;
        z = 0;
        t = 0;
    }

    Vector4::Vector4(const real _x, const real _y, const real _z, const real _t) : x(_x), y(_y), z(_z), t(_t) {
    }

    Vector4::~Vector4() = default;

    Vector4 Vector4::operator+(const Vector4 &other) const {
        return {x + other.x, y + other.y, z + other.z, t + other.t};
    }

    void Vector4::operator+=(const Vector4 &other) {
        x += other.x;
        y += other.y;
    }

    // Scalar product
    Vector4 Vector4::operator*(const real scalar) const {
        return {x * scalar, y * scalar, z * scalar, t * scalar};
    }

    // Scalar product
    Vector4 operator*(const real scalar, const Vector4 &other) {
        return other * scalar;
    }

    // Scalar product
    void Vector4::operator*=(const real scalar) {
        x *= scalar;
        y *= scalar;
    }

    // Dot product
    real Vector4::operator*(const Vector4 &other) const {
        return x * other.x + y * other.y;
    }

    Vector4 Vector4::operator-(const Vector4 &other) const {
        return *this + -1 * other;
    }

    void Vector4::operator-=(const Vector4 &other) {
        *this += -1 * other;
    }
} // sparky
