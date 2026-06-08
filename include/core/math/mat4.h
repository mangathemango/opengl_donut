#pragma once

#include <vec3.h>
#include <quat.h>
#include <vec4.h>

struct Mat4 {
    public:
    float m[4][4];

    Mat4();
    Mat4(float m[4][4]);
    Mat4(Vec3 t, Quat r, Vec3 s);
    static Mat4 identity();
    static Mat4 TRS(Vec3 translate, Quat rotate, Vec3 scale);

    Mat4 translate(Vec3 v) const;
    Mat4 rotate(Quat q) const;
    Mat4 scale(Vec3 v) const;

    Mat4 operator*(const Mat4& other) const;
    Vec3 operator*(Vec3 v) const;
    Vec4 operator*(Vec4 v) const;
};

ostream& operator<<(ostream& os, const Mat4& mat);