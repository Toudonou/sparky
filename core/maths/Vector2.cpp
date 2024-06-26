//
// Created by Toudonou on 6/24/2024.
//

#include "Vector2.h"

namespace sparky {
    Vector2::Vector2() {
        x = 0;
        y = 0;
    }

    Vector2::Vector2(const real _x, const real _y) : x(_x), y(_y) {
    }

    Vector2::~Vector2() = default;

    Vector2 Vector2::operator+(const Vector2 &other) const {
        return {x + other.x, y + other.y};
    }

    void Vector2::operator+=(const Vector2 &other) {
        x += other.x;
        y += other.y;
    }

    // Scalar product
    Vector2 Vector2::operator*(const real scalar) const {
        return {x * scalar, y * scalar};
    }

    // Scalar product
    Vector2 operator*(const real scalar, const Vector2 &other) {
        return other * scalar;
    }

    // Scalar product
    void Vector2::operator*=(const real scalar) {
        x *= scalar;
        y *= scalar;
    }

    // Dot product
    real Vector2::operator*(const Vector2 &other) const {
        return x * other.x + y * other.y;
    }

    Vector2 Vector2::operator-(const Vector2 &other) const {
        return *this + -1 * other;
    }

    void Vector2::operator-=(const Vector2 &other) {
        *this += -1 * other;
    }
} // sparky
