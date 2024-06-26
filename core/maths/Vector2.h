//
// Created by Toudonou on 6/24/2024.
//

#ifndef VECTOR2_H
#define VECTOR2_H

#include <string>

#include "constants.h"

namespace sparky {
    struct Vector2 {
        real x, y;

        Vector2();

        Vector2(real _x, real _y);

        ~Vector2();

        Vector2 operator+(const Vector2 &other) const;

        void operator+=(const Vector2 &other);

        Vector2 operator-(const Vector2 &other) const;

        void operator-=(const Vector2 &other);

        Vector2 operator*(real scalar) const; // Scalar product

        void operator*=(real scalar); // Scalar product

        real operator*(const Vector2 &other) const; // Dot product

        // toString method
        __forceinline [[nodiscard]] std::string toString() const {
            return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
        }

        // Vector2 operator^(Vector2 &other); // Cross product
        //
        // void operator^=(Vector2 &other); // Cross product
    };
} // sparky

#endif //VECTOR2_H
