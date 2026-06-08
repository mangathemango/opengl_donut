#pragma once
#include <Vec3.h>
#include <vector>
#include <cstdint>   

struct Mesh
{
    std::vector<Vec3> vertices;
    std::vector<Vec3> normals;
    std::vector<uint32_t> indices;

    Mesh() = default;
};

