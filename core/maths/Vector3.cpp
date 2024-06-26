//
// Created by Toudonou on 6/24/2024.
//

#include "Vector3.h"

namespace sparky {
    Vector3::Vector3() {
        x = 0;
        y = 0;
        z = 0;
    }

    Vector3::Vector3(const real _x, const real _y, const real _z) : x(_x), y(_y), z(_z) {
    }

    Vector3::~Vector3() = default;

    Vector3 Vector3::operator+(const Vector3 &other) const {
        return {x + other.x, y + other.y, z + other.z};
    }

    void Vector3::operator+=(const Vector3 &other) {
        x += other.x;
        y += other.y;
    }

    // Scalar product
    Vector3 Vector3::operator*(const real scalar) const {
        return {x * scalar, y * scalar, z * scalar};
    }

    // Scalar product
    Vector3 operator*(const real scalar, const Vector3 &other) {
        return other * scalar;
    }

    // Scalar product
    void Vector3::operator*=(const real scalar) {
        x *= scalar;
        y *= scalar;
    }

    // Dot product
    real Vector3::operator*(const Vector3 &other) const {
        return x * other.x + y * other.y;
    }

    Vector3 Vector3::operator-(const Vector3 &other) const {
        return *this + -1 * other;
    }

    void Vector3::operator-=(const Vector3 &other) {
        *this += -1 * other;
    }
} // sparky
