#include <gl.h>
#include <string>
#include <filesystem>
#include <mat4.h>
#include <vec3.h>

#define SHADER_ASSET_PATH "assets/shaders/"
class ShaderProgram {
    GLuint m_id = 0;

    public:
    ShaderProgram();
    ShaderProgram(const std::filesystem::path& vertexPath, const std::filesystem::path& fragmentPath);

    ~ShaderProgram();

    ShaderProgram(const ShaderProgram&) = delete;
    ShaderProgram& operator=(const ShaderProgram&) = delete;

    ShaderProgram(ShaderProgram&& other) noexcept;
    ShaderProgram& operator=(ShaderProgram&& other) noexcept;

    void bind() const;
    GLuint id() const;

    void setMat4(
        std::string_view name,
        const Mat4& value
    );

    void setVec3(
        std::string_view name,
        const Vec3& value
    );

    void setFloat(
        std::string_view name,
        float value
    );
};