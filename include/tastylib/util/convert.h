#ifndef TASTYLIB_CONVERT_H_
#define TASTYLIB_CONVERT_H_

#include "tastylib/internal/base.h"
#include <sstream>
#include <string>
#include <iomanip>

TASTYLIB_NS_BEGIN

/*
Convert an object to a std::string object.
*/
template<typename T>
std::string toString(const T &data) {
    std::ostringstream oss;
    oss << std::setiosflags(std::ios::fixed) << data;
    return oss.str();
}

TASTYLIB_NS_END

#endif