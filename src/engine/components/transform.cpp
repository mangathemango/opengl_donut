#include <transform.h>
#include <format>
Transform::Transform() {
    this->position = Vec3(0,0,0);
    this->rotation = Quat::identity();
    this->scale = Vec3(1,1,1);
}

Transform::Transform(Vec3 position, Quat rotation, Vec3 scale) {
    this->position = position;
    this->rotation = rotation;
    this->scale = scale;
}

Transform& Transform::translate(Vec3 v) {
    this->position += v;
    return *this;
}

Transform& Transform::rotateRadian(Vec3 axis, float angle) {
    this->rotation = this->rotation * Quat(axis, angle);
    return *this;
}

Transform& Transform::rotateDegrees(Vec3 axis, float angle) {
    float radian = angle * M_PI / 180;
    return rotateRadian(axis, radian);
}

Transform Transform::translated(Vec3 v) const {
    Transform result = *this;
    result.translate(v);
    return result;
}

Transform Transform::rotatedRadian(Vec3 axis, float angle) const {
    Transform result = *this;
    result.rotateRadian(axis, angle);
    return result;
}

Transform Transform::rotatedDegrees(Vec3 axis, float angle) const {
    Transform result = *this;
    result.rotateDegrees(axis, angle);
    return result;
}

Vec3 Transform::forward() const {
    return rotation.forward();
}

Vec3 Transform::up() const {
    return rotation.up();
}

Vec3 Transform::right() const {
    return rotation.right();
}

void Transform::display(std::ostream& os) const {
    os << "Transform: \n";
    os << "\tPosition: " << position << "\n";
    os << "\tRotation: " << rotation << "\n";
    os << "\tScale: "    << scale << "\n";
}