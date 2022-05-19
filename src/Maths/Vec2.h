//
// Created by fgdou on 5/19/22.
//

#ifndef PROJPROG2022_VEC2_H
#define PROJPROG2022_VEC2_H

#include <memory>

class Vec2
{
public:
    static double toRadians(double degrees);
    static double toDegrees(double radians);

    Vec2();
    Vec2(const Vec2 &copy);
    Vec2(double x, double y);
    Vec2(double v);

    Vec2 rotate(double radian) const;
    Vec2 normalize() const;
    double norm() const;
    double norm2() const;

    bool operator!=(const Vec2 &other);
    bool operator==(const Vec2 &other);
    Vec2 operator+(const Vec2 &other) const;
    Vec2 operator-(const Vec2 &other) const;
    Vec2 operator/(const Vec2 &other) const;
    Vec2 operator*(const Vec2 &other) const;

    Vec2 &operator+=(const Vec2 &other);
    Vec2 &operator-=(const Vec2 &other);
    Vec2 &operator/=(const Vec2 &other);
    Vec2 &operator*=(const Vec2 &other);

    double distance(const Vec2 &other) const;
    double angleBetween(const Vec2 &other) const;
    double dot(const Vec2 &other) const;
    double angle() const;

    Vec2 lookAt(const Vec2 &other) const;

    Vec2 screenToWorld() const;
    Vec2 worldToScreen() const;
    Vec2 screenToWorldScale() const;
    Vec2 worldToScreenScale() const;

    double x, y;

    void print() const;
};

#endif // PROJPROG2022_VEC2_H
