#ifndef POINT_HPP
#define POINT_HPP

#include "../vec2/vec2.hpp"

#include <iostream>

struct Point {
    double x = 0;
    double y = 0;

    Point(double x, double y);

    virtual bool operator==(const Point &other) const;

    virtual const Point operator+(const Vec2 &vec) const;
    virtual const Point operator+=(const Vec2 &vec);

    friend std::ostream &operator<<(std::ostream &os, const Point &p);
};

#endif
