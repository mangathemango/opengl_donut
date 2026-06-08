#pragma once
#include <vec3.h>

// A Quaternion describes rotation/direction in the 3D space
struct Quat {
    public:
    float w, x, y, z;

    Quat();
    Quat(Vec3 axis, float angle);
    Quat(float w, float x, float y, float z);

    static Quat identity();
    Quat inverse() const;
    Quat normalise() const;

    Vec3 operator*(Vec3 v) const;
    Quat operator*(Quat q) const;

    Vec3 up() const;
    Vec3 right() const;
    Vec3 forward() const;
};  

ostream& operator<<(ostream& os, Quat q);