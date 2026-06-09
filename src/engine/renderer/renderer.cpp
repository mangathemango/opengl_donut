#include <renderer.h>

Renderer::Renderer() {
    this->shaderProgram = ShaderProgram("basic.vert", "basic.frag");
}

Renderer::~Renderer() {
    
}

void Renderer::uploadMesh(Mesh *mesh) {
    if (meshCache.find(mesh) == meshCache.end()) {

        meshCache.try_emplace(mesh, std::move(GpuMesh(*mesh)));
    }
}