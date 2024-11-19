#ifndef VEC2_HPP
#define VEC2_HPP

#include <iostream>

struct Vec2 {
    double x;
    double y;

    Vec2(double x, double y);

    double getModule() const;

    const Vec2 &normalize();

    const Vec2 operator*(double scalar) const;

    friend std::ostream &operator<<(std::ostream &os, const Vec2 &p);
};

#endif
