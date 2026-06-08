#pragma once
#include <stdbool.h>
#include <iostream>
using namespace std;

struct Vec2 {
    public:

    float x,y,z;
    Vec2();
    Vec2(float size); // For squares
    Vec2(float x, float y);

    // Operator overrides:
    // Basic operations
    Vec2 operator-() const;
    Vec2 operator+(const Vec2 &other) const;
    Vec2 operator-(const Vec2 &other) const;
    Vec2 operator*(float scalar) const;
    Vec2 operator/(float scalar) const;

    // Some syntax sugar operations
    Vec2& operator+=(const Vec2 &other);
    Vec2& operator-=(const Vec2 &other);
    Vec2& operator*=(float scalar);
    Vec2& operator/=(float scalar);

    // Equality
    bool operator==(const Vec2 &other) const;
    bool operator!=(const Vec2 &other) const;

    // Direction vector
    Vec2 up();
    Vec2 down();
    Vec2 right();
    Vec2 left();
    Vec2 forward();
    Vec2 backward();

    // More operations
    float cross(const Vec2 &other) const;
    float dot(const Vec2 &other) const;
    Vec2 abs() const;
    Vec2 normalize() const;
    float magnitude() const;
    float distance(const Vec2 &other) const;
    Vec2 lerp(const Vec2 &other, float t) const;

    Vec2 rotateRadian(float angle) const;
    Vec2 rotateDegrees(float angle) const;
    Vec2 rotateRadianAround(float angle, const Vec2& other) const;
    Vec2 rotateDegreesAround(float angle, const Vec2& other) const;
    float angleBetween(const Vec2& other) const;
};
 
ostream& operator<<(ostream& os, const Vec2& v);

