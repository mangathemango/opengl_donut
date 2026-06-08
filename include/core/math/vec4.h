#pragma once

#include <iostream>
#include <cmath>
#include <vec3.h>

using namespace std;

struct Vec4 {
    public:
    float x,y,z,w;

    Vec4();
    Vec4(float x, float y, float z, float w);
    Vec4(Vec3 v, float w);

    static Vec4 fromVec3(Vec3 v, float w);
    Vec3 toVec3();

    // Operator overrides:
    // Basic operations
    Vec4 operator-() const;
    Vec4 operator+(const Vec4 &other) const;
    Vec4 operator-(const Vec4 &other) const;
    Vec4 operator*(float scalar) const;
    Vec4 operator/(float scalar) const;

    // Some syntax sugar operations
    Vec4& operator+=(const Vec4 &other);
    Vec4& operator-=(const Vec4 &other);
    Vec4& operator*=(float scalar);
    Vec4& operator/=(float scalar);

    // Equality
    bool operator==(const Vec4 &other) const;
    bool operator!=(const Vec4 &other) const;

};

ostream& operator<<(ostream& os, const Vec4& v);