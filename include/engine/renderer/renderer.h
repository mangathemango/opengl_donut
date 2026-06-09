#include <unordered_map>
#include <gpu_mesh.h>
#include <shader_program.h>
#include <memory>
struct Renderer {
    std::unordered_map<Mesh*, GpuMesh> meshCache;
    ShaderProgram shaderProgram;

    void uploadMesh(Mesh *mesh);
    Renderer();
    ~Renderer();
};  