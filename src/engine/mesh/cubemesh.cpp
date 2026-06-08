#include <cubemesh.h>

CubeMesh::CubeMesh(float length) {
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
        Vec3(0, 1, 2),
        Vec3(2, 3, 0),
        Vec3(4, 5, 7),
        Vec3(7, 6, 4),
        Vec3(0, 4, 7),
        Vec3(7, 3, 0),
        Vec3(1, 5, 6),
        Vec3(6, 2, 1),
        Vec3(3, 7, 6),
        Vec3(6, 2, 3),
        Vec3(0, 1, 5),
        Vec3(5, 4, 0)
    };
    this->normals = {
        Vec3(length, length, length),
        Vec3(-length, length, length),
        Vec3(-length, -length, length),
        Vec3(length, -length, length),
        
        Vec3(length, length, -length),
        Vec3(-length, length, -length),
        Vec3(length, -length, -length),
        Vec3(-length, -length, -length)
    };
}