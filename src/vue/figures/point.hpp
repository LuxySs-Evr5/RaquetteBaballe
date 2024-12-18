/**
 * @file point.hpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Definition of the Point struct
 * @date 16/11/2024
 *
 */

#ifndef POINT_HPP
#define POINT_HPP

struct Point {
    float x = 0, y = 0; // Coordinates of the point

    /**
     * @brief Construct a new Point object
     * 
     * @param valX Value of x coordinate to set
     * @param valY Value of y coordinate to set
     */
    Point(float valX, float valY);

    /**
     * @brief Destruct a Point object
     * 
     */
    ~Point() = default;

};

#endif // POINT_HPP