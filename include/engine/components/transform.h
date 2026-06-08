#pragma once
#include <component.h>
#include <vec3.h>
#include <quat.h>

struct Transform: public Component {
    Vec3 position;
    Quat rotation;
    Vec3 scale; 

    Transform();
    Transform(Vec3 position, Quat rotation, Vec3 scale);
    Transform& translate(Vec3 v);
    Transform& rotateRadian(Vec3 axis, float angle);
    Transform& rotateDegrees(Vec3 axis, float angle);

    Transform translated(Vec3 v) const;
    Transform rotatedRadian(Vec3 axis, float angle) const;
    Transform rotatedDegrees(Vec3 axis, float angle) const;

    Vec3 forward() const;
    Vec3 up() const;
    Vec3 right() const;

    void display(std::ostream& os) const;
};

