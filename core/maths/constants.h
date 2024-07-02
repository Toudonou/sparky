//
// Created by Toudonou on 6/26/2024.
//

#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <numbers>
#include <glad/glad.h>

namespace sparky {
    typedef GLfloat real;

    inline real toRadian(const real degree) {
        constexpr real pi_over_180 = std::numbers::pi / 180; // For optimization
        return degree * pi_over_180;
    }
}

#endif //CONSTANTS_H
