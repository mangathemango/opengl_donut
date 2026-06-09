#include <camera.h>

void Camera::display(std::ostream& os) const {
    os << "Camera\n";
    os << "\tfov: " << fov << "\n";
}
Mat4 Camera::viewMatrix() const
{
    // inverse rotation
    Quat invRot = tf->rotation.inverse(); // or inverse()

    // inverse position
    Vec3 invPos = -(tf->position);

    Mat4 rot = Mat4::identity().rotate(invRot);
    Mat4 trans = Mat4::identity().translate(invPos);

    return rot * trans;
}

Mat4 Camera::projectionMatrix() const
{
    float aspect = 16.0f / 9.0f;
    float near = 0.1f;
    float far = 100.0f;

    float f = 1.0f / tanf(fov * 0.5f);

    Mat4 result;

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            result.m[i][j] = 0;

    result.m[0][0] = f / aspect;
    result.m[1][1] = f;

    result.m[2][2] = (far + near) / (near - far);
    result.m[2][3] = (2 * far * near) / (near - far);

    result.m[3][2] = -1.0f;

    return result;
}