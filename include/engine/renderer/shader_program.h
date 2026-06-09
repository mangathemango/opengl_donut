#include <gl.h>
#include <string>
#include <filesystem>

class ShaderProgram {
    GLuint m_id = 0;

    public:
    ShaderProgram(const std::filesystem::path& vertexPath, const std::filesystem::path& fragmentPath);

    ~ShaderProgram();

    ShaderProgram(const ShaderProgram&) = delete;
    ShaderProgram& operator=(const ShaderProgram&) = delete;

    ShaderProgram(ShaderProgram&& other) noexcept;
    ShaderProgram& operator=(ShaderProgram&& other) noexcept;

    void bind() const;
    GLuint id() const;
};