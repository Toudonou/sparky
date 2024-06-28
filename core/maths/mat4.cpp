//
// Created by Toudonou on 6/27/2024.
//

#include "mat4.h"

#include <cmath>

namespace sparky {
    mat4::mat4() {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                element[i][j] = 0;
            }
        }
    }

    mat4::mat4(const real diagonal) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                element[i][j] = 0;
            }
            element[i][i] = diagonal;
        }
    }

    mat4 mat4::identity() {
        return mat4(1);
    }

    mat4 mat4::orthographic(const real left, const real right, const real bottom, const real top, const real near,
                            const real far) {
        auto result = identity();

        result(0, 0) = 2 / (right - left);
        result(1, 1) = 2 / (top - bottom);
        result(2, 2) = 2 / (far - near);

        result(0, 3) = (right + left) / (right - left);
        result(1, 3) = (top + bottom) / (top - bottom);
        result(2, 3) = (far + near) / (far - near);

        return result;
    }

    mat4 mat4::perspective(const real fov, const real aspectRatio, const real near, const real far) {
        auto result = mat4::identity();

        const real q = 1 / tan(toRadian(0.5 * fov));
        const real a = q / aspectRatio;
        const real b = (near + far) / (near - far);
        const real c = (2 * near * far) / (near - far);

        result(0, 0) = a;
        result(1, 1) = q;
        result(2, 2) = b;
        result(3, 3) = -1;
        result(3, 4) = c;

        return result;
    }

    real &mat4::operator()(const int i, const int j) {
        // TODO : Make a checking
        return element[i][j];
    }

    const real &mat4::operator()(const int i, const int j) const {
        // TODO : Make a checking
        return element[i][j];
    }

    mat4 mat4::operator+(const mat4 &other) const {
        auto result = mat4();
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                result(i, j) = (*this)(i, j) + other(i, j);
            }
        }
        return result;
    }

    void mat4::operator+=(const mat4 &other) {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                (*this)(i, j) += other(i, j);
            }
        }
    }

    mat4 mat4::operator-(const mat4 &other) const {
        return (*this) + -1 * other;
    }

    void mat4::operator-=(const mat4 &other) {
        (*this) += -1 * other;
    }

    // Matrix product
    mat4 mat4::operator*(const mat4 &other) const {
        auto result = mat4();
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                for (int k = 0; k < 4; ++k) {
                    result(i, j) += (*this)(i, k) * other(k, j);
                }
            }
        }
        return result;
    }

    // Matrix product
    void mat4::operator*=(const mat4 &other) {
        auto result = mat4();
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                for (int k = 0; k < 4; ++k) {
                    result(i, j) += (*this)(i, k) * other(k, j);
                }
            }
            // Updating the current matrix object
            for (int j = 0; j < 4; j++) {
                (*this)(i, j) = result(i, j);
            }
        }
    }

    // Scalar product
    mat4 mat4::operator*(const real scalar) const {
        auto result = mat4();
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                result(i, j) = (*this)(i, j) * scalar;
            }
        }
        return result;
    }

    // Scalar product
    void mat4::operator*=(const real scalar) {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                (*this)(i, j) *= scalar;
            }
        }
    }

    // Scalar product
    mat4 operator*(const real scalar, const mat4 &other) {
        return other * scalar;
    }
}
