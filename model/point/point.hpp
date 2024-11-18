#ifndef POINT_HPP
#define POINT_HPP

#include <cstddef>

struct Point {
    size_t x = 0;
    size_t y = 0;

    Point(size_t x, size_t y);

    virtual bool operator==(const Point &other) const;
};

#endif
