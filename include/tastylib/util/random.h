#ifndef TASTYLIB_RANDOM_H_
#define TASTYLIB_RANDOM_H_

#include "tastylib/internal/base.h"
#include <cstdlib>
#include <ctime>

TASTYLIB_NS_BEGIN

/*
Return a random number in [0, 1).
*/
inline double rand() {
    static bool seeded = false;
    if (!seeded) {
        std::srand((unsigned)std::time(nullptr));
        seeded = true;
    }
    return (double)std::rand() / RAND_MAX;
}

/*
Return a random positive integer number in [min, max].
*/
inline unsigned randInt(const unsigned min, const unsigned max) {
    return (unsigned)(rand() * (max - min + 1) + min);
}

TASTYLIB_NS_END

#endif