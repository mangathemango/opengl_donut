#pragma once
#include <Vec3.h>
#include <vector>

struct Mesh {
    std::vector<Vec3> vertices;
    std::vector<Vec3> normals;
    std::vector<Vec3> indices;
};