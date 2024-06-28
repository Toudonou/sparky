//
// Created by Toudonou on 6/24/2024.
//

#ifndef VECT2_H
#define VECT2_H

#include <string>

#include "constants.h"

namespace sparky {
    struct vec2 {
        real x, y;

        vec2();

        vec2(real _x, real _y);

        ~vec2();

        vec2 operator+(const vec2 &other) const;

        void operator+=(const vec2 &other);

        vec2 operator-(const vec2 &other) const;

        void operator-=(const vec2 &other);

        vec2 operator*(real scalar) const; // Scalar product

        void operator*=(real scalar); // Scalar product

        real operator*(const vec2 &other) const; // Dot product

        // toString method
        __forceinline [[nodiscard]] std::string toString() const {
            return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
        }
    };
} // sparky

#endif //VECT2_H
