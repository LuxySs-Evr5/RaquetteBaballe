#ifndef VEC2_HPP
#define VEC2_HPP

#include "../../vue/figures/point.hpp"

#include <iostream>

struct Vec2 {
    double x;
    double y;

    /**
     * @brief Constructs a new Vec2.
     */
    Vec2();

    /**
     * @brief Constructs a new Vec2.
     *
     * @param xComponent The x component.
     * @param yComponent The y component.
     */
    Vec2(double xComponent, double yComponent);

    Vec2(const Vec2 &) = default;
    Vec2(Vec2 &&) = default;
    Vec2 &operator=(const Vec2 &) = default;
    Vec2 &operator=(Vec2 &&) = default;

    virtual ~Vec2() = default;

    /**
     * @brief Returns the vector's module.
     */
    double getModule() const;

    /**
     * @brief Normalizes the vector.
     */
    const Vec2 &normalize();

    /**
     * @brief Returns a new vector where each component is clamped within the
     * specified ranges.
     *
     * @param min The vector containing the minimum bounds.
     * @param max The vector containing the maximum bounds.
     */
    Vec2 clamped(const Vec2 &min, const Vec2 &max) const;

    /**
     * @brief Compares two vectors.
     */
    bool operator==(const Vec2 &other) const;

    /**
     * @brief Adds the components of the two vectors and returns the resulting
     * vector.
     *
     * @param vec The vector to be added to this vector.
     */
    Vec2 operator+(const Vec2 &vec) const;

    /**
     * @brief Adds the components of the given vector to this vector.
     *
     * @param vec The vector to be added to this vector.
     */
    Vec2 &operator+=(const Vec2 &vec);

    /**
     * @brief Subtracts the components of the given vector from this vector and
     * returns the resulting vector.
     *
     * @param vec The vector to be subtracted from this vector.
     */
    Vec2 operator-(const Vec2 &vec) const;

    /**
     * @brief Subtracts the components of the given vector from this vector.
     *
     * @param vec The vector to be subtracted from this vector.
     */
    Vec2 &operator-=(const Vec2 &vec);

    /**
     * @brief Negates the components of this vector and returns the resulting
     * vector.
     */
    Vec2 operator-() const;

    /**
     * @brief Multiplies each component of this vector by the given scalar and
     * returns the resulting vector.
     *
     * @param scalar The scalar value to multiply with.
     */
    Vec2 operator*(double scalar) const;

    /**
     * @brief Multiplies each component of this vector by the given scalar.
     *
     * @param scalar The scalar value to multiply with.
     */
    Vec2 &operator*=(double scalar);

    // TODO: this is very stupid and should be changed
    /**
     * @brief Converts the vector into a simple Point instance.
     */
    Point toPoint() const;

    /**
     * @brief Converts the vector to a string representation.
     *
     * @return A string representing the vector's components.
     */
    operator std::string() const;

    /**
     * @brief Outputs the vector components to the given output stream.
     *
     * @param os The output stream to write to.
     * @param p The vector to output.
     * @return A reference to the output stream after the operation.
     */
    friend std::ostream &operator<<(std::ostream &os, const Vec2 &p);
};

/**
 * Clamps a numeric value within the specified range.
 *
 * @param value The value to clamp.
 * @param min The lower bound.
 * @param max The upper bound.
 */
double clampedNum(double value, double min, double max);

#endif
