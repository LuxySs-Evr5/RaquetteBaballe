#ifndef VEC2_HPP
#define VEC2_HPP

#include "../point/point.hpp"

struct Vec2 {
    double x;
    double y;

    Vec2(Point point);
    Vec2(double x, double y);

    double getModule() const;

    Point getComponents() const;

    Point toPoint() const;

    const Vec2 &normalize();
};

#endif
