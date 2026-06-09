#include <shader_program.h>
#include <string_utils.h>

static GLuint compileShader(
    GLenum type,
    const std::string &source)
{
    GLuint shader =
        glCreateShader(type);

    const char *src =
        source.c_str();

    glShaderSource(
        shader,
        1,
        &src,
        nullptr);

    glCompileShader(shader);

    GLint success;

    glGetShaderiv(
        shader,
        GL_COMPILE_STATUS,
        &success);

    if (!success)
    {
        char infoLog[1024];

        glGetShaderInfoLog(
            shader,
            sizeof(infoLog),
            nullptr,
            infoLog);

        glDeleteShader(shader);

        throw std::runtime_error(
            infoLog);
    }

    return shader;
}

ShaderProgram::ShaderProgram() {
    this->m_id = 0;
}

ShaderProgram::ShaderProgram(
    const std::filesystem::path &vertexPath,
    const std::filesystem::path &fragmentPath)
{
    std::filesystem::path base = SHADER_ASSET_PATH;
    std::string vertexSource =
        readFile(base / vertexPath);

    std::string fragmentSource =
        readFile(base / fragmentPath);
    GLuint vertexShader =
        compileShader(
            GL_VERTEX_SHADER,
            vertexSource);

    GLuint fragmentShader =
        compileShader(
            GL_FRAGMENT_SHADER,
            fragmentSource);
    m_id = glCreateProgram();

    glAttachShader(
        m_id,
        vertexShader);

    glAttachShader(
        m_id,
        fragmentShader);

    glLinkProgram(m_id);

    GLint success;

    glGetProgramiv(
        m_id,
        GL_LINK_STATUS,
        &success);

    if (!success)
    {
        char infoLog[1024];

        glGetProgramInfoLog(
            m_id,
            sizeof(infoLog),
            nullptr,
            infoLog);

        glDeleteProgram(m_id);

        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
        std::cerr << "SHADER COMPILE FAILED:\n" << infoLog << std::endl;
        throw std::runtime_error(
            infoLog);
    }
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

ShaderProgram::~ShaderProgram()
{
    if (m_id != 0)
    {
        glDeleteProgram(m_id);
    }
}

ShaderProgram::ShaderProgram(
    ShaderProgram &&other) noexcept
{
    m_id = other.m_id;
    other.m_id = 0;
}

ShaderProgram &
ShaderProgram::operator=(
    ShaderProgram &&other) noexcept
{
    if (this == &other)
    {
        return *this;
    }

    if (m_id != 0)
    {
        glDeleteProgram(m_id);
    }

    m_id = other.m_id;
    other.m_id = 0;

    return *this;
}

void ShaderProgram::bind() const
{
    glUseProgram(m_id);
}

GLuint ShaderProgram::id() const
{
    return m_id;
}

void ShaderProgram::setMat4(
    std::string_view name,
    const Mat4& value
)
{
    GLint location =
        glGetUniformLocation(
            m_id,
            name.data()
        );

    glUniformMatrix4fv(
        location,
        1,
        GL_TRUE,
        *value.m
    );
}

void ShaderProgram::setVec3(
    std::string_view name,
    const Vec3& value
)
{
    GLint location =
        glGetUniformLocation(
            m_id,
            name.data()
        );

    glUniform3f(
        location,
        value.x,
        value.y,
        value.z
    );
}
void ShaderProgram::setFloat(
    std::string_view name,
    float value
)
{
    GLint location =
        glGetUniformLocation(
            m_id,
            name.data()
        );

    glUniform1f(
        location,
        value
    );
}