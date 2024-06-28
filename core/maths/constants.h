//
// Created by Toudonou on 6/26/2024.
//

#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace sparky {
    typedef double real;

    inline real toRadian(const real degree) {
        return degree * (std::numbers::pi / 180);
    }
}

#endif //CONSTANTS_H
