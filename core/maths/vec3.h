//
// Created by Toudonou on 6/24/2024.
//

#ifndef VECT3_H
#define VECT3_H

#include <string>

#include "constants.h"

namespace sparky {
    struct vec3 {
        real x, y, z;

        vec3();

        vec3(real _x, real _y, real _z);

        ~vec3();

        vec3 operator+(const vec3 &other) const;

        void operator+=(const vec3 &other);

        vec3 operator-(const vec3 &other) const;

        void operator-=(const vec3 &other);

        vec3 operator*(real scalar) const; // Scalar product

        void operator*=(real scalar); // Scalar product

        real operator*(const vec3 &other) const; // Dot product
        __forceinline [[nodiscard]] std::string toString() const {
            return "(" + std::to_string(x) + ", " + std::to_string(y) + std::to_string(z) + ")";
        }

        // Vector3 operator^(Vector3 &other); // Cross product
        //
        // void operator^=(Vector3 &other); // Cross product
    };
} // sparky

#endif //VECT3_H
