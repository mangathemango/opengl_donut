#include <cube_mesh.h>

CubeMesh::CubeMesh(float length)
{
    this->vertices = {
        Vec3(length, length, length),
        Vec3(-length, length, length),
        Vec3(-length, -length, length),
        Vec3(length, -length, length),

        Vec3(length, length, -length),
        Vec3(-length, length, -length),
        Vec3(-length, -length, -length),
        Vec3(length, -length, -length),
    };
    this->indices = {
        0, 1, 2,
        2, 3, 0,
        4, 5, 7,
        7, 6, 4,
        0, 4, 7,
        7, 3, 0,
        1, 5, 6,
        6, 2, 1,
        3, 7, 6,
        6, 2, 3,
        0, 1, 5,
        5, 4, 0};
    this->normals = {
        Vec3(length, length, length),
        Vec3(-length, length, length),
        Vec3(-length, -length, length),
        Vec3(length, -length, length),

        Vec3(length, length, -length),
        Vec3(-length, length, -length),
        Vec3(length, -length, -length),
        Vec3(-length, -length, -length)};
}