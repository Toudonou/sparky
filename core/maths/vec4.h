//
// Created by Toudonou on 6/24/2024.
//

#ifndef VECT4_H
#define VECT4_H

#include <string>

#include "constants.h"

namespace sparky {
    struct vec4 {
        real x, y, z, w;

        vec4();

        vec4(real _x, real _y, real _z, real _w);

        ~vec4();

        vec4 operator+(const vec4 &other) const;

        void operator+=(const vec4 &other);

        vec4 operator-(const vec4 &other) const;

        void operator-=(const vec4 &other);

        vec4 operator*(real scalar) const; // Scalar product

        void operator*=(real scalar); // Scalar product

        real operator*(const vec4 &other) const; // Dot product

        __forceinline [[nodiscard]] std::string toString() const {
            return "(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ", " +
                   std::to_string(w) + ")";
        }
    };
} // sparky

#endif //VECT4_H
