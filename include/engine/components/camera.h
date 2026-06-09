#pragma once
#include <component.h>
#include <transform.h>
#include <mat4.h>
struct Camera: public Component {
    float fov = 90.0f;
    float aspect = 16.0f / 9.0f;
    float near = 0.1f;
    float far = 100.0f;
    Transform* tf;

    void display(std::ostream& os) const;
    Mat4 viewMatrix() const;
    Mat4 projectionMatrix() const;
};
