#ifndef VEC2_HPP
#define VEC2_HPP

#include "../../vue/figures/point.hpp"

#include <iostream>

struct Vec2 {
    double x;
    double y;

    Vec2();
    Vec2(double x, double y);

    virtual double getModule() const;

    virtual const Vec2 &normalize();

    virtual Vec2 clamped(const Vec2 &min, const Vec2 &max) const;

    virtual bool operator==(const Vec2 &other) const;

    virtual Vec2 operator+(const Vec2 &vec) const;

    virtual Vec2 &operator+=(const Vec2 &vec);

    virtual Vec2 operator-(const Vec2 &vec) const;

    virtual Vec2 &operator-=(const Vec2 &vec);

    virtual Vec2 operator-() const;

    virtual Vec2 operator*(double scalar) const;

    virtual Vec2 &operator*=(double scalar);

    // TODO: this is very stupid and should be changed
    virtual Point toPoint() const;

    virtual operator std::string() const;

    friend std::ostream &operator<<(std::ostream &os, const Vec2 &p);
};

#endif
