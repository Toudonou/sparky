//
// Created by Toudonou on 6/27/2024.
//

#ifndef MAT4_H
#define MAT4_H
#include "constants.h"


namespace sparky {
    struct mat4 {
        mat4();

        explicit mat4(real diagonal);

        static mat4 identity();

        static mat4 orthographic(real left, real right, real bottom, real top, real near, real far);

        static mat4 perspective(real fov, real aspectRatio, real near, real far);

        real &operator()(int i, int j);

        const real &operator()(int i, int j) const;

        // Addition and Sum
        mat4 operator+(const mat4 &other) const;

        void operator+=(const mat4 &other);

        mat4 operator-(const mat4 &other) const;

        void operator-=(const mat4 &other);

        // Matrix product
        mat4 operator*(const mat4 &other) const;

        // Matrix product
        void operator*=(const mat4 &other);

        // Scalar product
        mat4 operator*(real scalar) const;

        // Scalar product
        void operator*=(real scalar);

        // vec4 times mat4
        // mat4 operator*(const vec4 &vector);

    private:
        real element[4][4]{};
    };

    // Scalar product
    mat4 operator*(real scalar, const mat4 &other);
}


#endif //MAT4_H
