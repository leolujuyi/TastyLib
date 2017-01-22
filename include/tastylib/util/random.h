#ifndef TASTYLIB_RANDOM_H_
#define TASTYLIB_RANDOM_H_

#include "tastylib/internal/base.h"
#include "tastylib/util/swap.h"
#include <cstdlib>
#include <ctime>
#include <vector>

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

/*
Rearrange the elements in an array randomly.
Reference: https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle

@param arr The array to be processed
*/
template<typename T>
void randChange(std::vector<T> &arr) {
    if (!arr.empty()) {
        for (auto i = arr.size() - 1; i >= 1; --i) {
            swap(arr[i], arr[randInt(0, (unsigned)i)]);
        }
    }
}

TASTYLIB_NS_END

#endif