#include <gpu_mesh.h>

GpuMesh::GpuMesh(const Mesh& mesh) {
    this->upload(mesh);
}

void GpuMesh::upload(const Mesh& mesh)
{
    std::cout << "I sure hope this doesnt fail" << std::endl;
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ebo);
    
    glBindVertexArray(vao);
    std::cout << "vaoing it" << std::endl;
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    std::cout << "oh no err " << mesh.vertices.size() << std::endl;
    glBufferData(
        GL_ARRAY_BUFFER, 
        mesh.vertices.size() * sizeof(Vec3), 
        mesh.vertices.data(), 
        GL_STATIC_DRAW
    );
    std::cout << "vboing it" << std::endl;
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(
        GL_ELEMENT_ARRAY_BUFFER, 
        mesh.indices.size() * sizeof(unsigned int), 
        mesh.indices.data(), 
        GL_STATIC_DRAW
    );
    std::cout << "eboing it" << std::endl;
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vec3), nullptr);
    std::cout << "enabling" << std::endl;
    glEnableVertexAttribArray(0);
    std::cout << "done" << std::endl;
}

GpuMesh::GpuMesh(GpuMesh&& other) noexcept {
    vao = other.vao;
    vbo = other.vbo;
    ebo = other.ebo;
    indexCount = other.indexCount;
}

GpuMesh& GpuMesh::operator=(GpuMesh&& other) noexcept {
    vao = other.vao;
    vbo = other.vbo;
    ebo = other.ebo;
    indexCount = other.indexCount;
    return *this;
}

