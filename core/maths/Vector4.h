//
// Created by Toudonou on 6/24/2024.
//

#ifndef VECTOR4_H
#define VECTOR4_H

#include <string>

#include "constants.h"

namespace sparky {
    struct Vector4 {
        real x, y, z, t;

        Vector4();

        Vector4(real _x, real _y, real _z, real _t);

        ~Vector4();

        Vector4 operator+(const Vector4 &other) const;

        void operator+=(const Vector4 &other);

        Vector4 operator-(const Vector4 &other) const;

        void operator-=(const Vector4 &other);

        Vector4 operator*(real scalar) const; // Scalar product

        void operator*=(real scalar); // Scalar product

        real operator*(const Vector4 &other) const; // Dot product

        __forceinline [[nodiscard]] std::string toString() const {
            return "(" + std::to_string(x) + ", " + std::to_string(y) + std::to_string(z) + ", " + std::to_string(t) +
                   ")";
        }

        // Vector4 operator^(Vector4 &other); // Cross product
        //
        // void operator^=(Vector4 &other); // Cross product
    };
} // sparky

#endif //VECTOR4_H
