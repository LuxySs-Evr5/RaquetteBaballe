#ifndef VEC2_HPP
#define VEC2_HPP

#include "../../vue/figures/point.hpp"

#include <iostream>

struct Vec2 {
    double x;
    double y;

    Vec2();
    Vec2(double X, double Y);

    double getModule() const;

    const Vec2 &normalize();

    Vec2 clamped(const Vec2 &min, const Vec2 &max) const;

    bool operator==(const Vec2 &other) const;

    Vec2 operator+(const Vec2 &vec) const;

    Vec2 &operator+=(const Vec2 &vec);

    Vec2 operator-(const Vec2 &vec) const;

    Vec2 &operator-=(const Vec2 &vec);

    Vec2 operator-() const;

    Vec2 operator*(double scalar) const;

    Vec2 &operator*=(double scalar);

    // TODO: this is very stupid and should be changed
    Point toPoint() const;

    operator std::string() const;

    friend std::ostream &operator<<(std::ostream &os, const Vec2 &p);
};

#endif
