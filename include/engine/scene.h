#pragma once
#include <camera.h>
#include <gameobj.h>
#include <vector>

struct Scene {
    std::vector<GameObj*> objs;
    Camera* mainCamera;

    void render();
};