//
// Created by Toudonou on 6/24/2024.
//

#ifndef VECTOR3_H
#define VECTOR3_H

#include <string>

#include "constants.h"

namespace sparky {
    struct Vector3 {
        real x, y, z;

        Vector3();

        Vector3(real _x, real _y, real _z);

        ~Vector3();

        Vector3 operator+(const Vector3 &other) const;

        void operator+=(const Vector3 &other);

        Vector3 operator-(const Vector3 &other) const;

        void operator-=(const Vector3 &other);

        Vector3 operator*(real scalar) const; // Scalar product

        void operator*=(real scalar); // Scalar product

        real operator*(const Vector3 &other) const; // Dot product
        __forceinline [[nodiscard]] std::string toString() const {
            return "(" + std::to_string(x) + ", " + std::to_string(y) + std::to_string(z) + ")";
        }

        // Vector3 operator^(Vector3 &other); // Cross product
        //
        // void operator^=(Vector3 &other); // Cross product
    };
} // sparky

#endif //VECTOR3_H
