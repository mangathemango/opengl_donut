#pragma once
#include <component.h>
#include <transform.h>

struct Camera: public Component {
    float fov;
    Transform* tf;

    void display(std::ostream& os) const;
};
