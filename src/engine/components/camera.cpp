#include <camera.h>

void Camera::display(std::ostream& os) const {
    os << "Camera\n";
    os << "\tfov: " << fov << "\n";
}