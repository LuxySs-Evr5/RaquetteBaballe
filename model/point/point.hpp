#ifndef POINT_HPP
#define POINT_HPP

struct Point {
    double x = 0;
    double y = 0;

    Point(double x, double y);

    virtual bool operator==(const Point &other) const;
};

#endif
