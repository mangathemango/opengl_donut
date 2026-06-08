#include <unordered_map>
#include <gpu_mesh.h>

struct Renderer {
    std::unordered_map<Mesh*, GpuMesh> meshCache;
};  