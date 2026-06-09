#include <gl.h>
#include <cstdint>
#include <mesh.h>

class GpuMesh
{
public:
    GLuint vao = 0;
    GLuint vbo = 0;
    GLuint ebo = 0;

    size_t indexCount = 0;

    GpuMesh() = default;
    GpuMesh(const Mesh& mesh);
    // ~GpuMesh();

    GpuMesh(const GpuMesh&) = delete;
    GpuMesh& operator=(const GpuMesh&) = delete;

    GpuMesh(GpuMesh&&) noexcept;
    GpuMesh& operator=(GpuMesh&&) noexcept;

    void upload(const Mesh& mesh);
    void bind();
};