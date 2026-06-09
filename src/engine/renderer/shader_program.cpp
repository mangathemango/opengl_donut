#include <shader_program.h>
#include <string_utils.h>

static GLuint compileShader(
    GLenum type,
    const std::string& source
)
{
    GLuint shader =
        glCreateShader(type);

    const char* src =
        source.c_str();

    glShaderSource(
        shader,
        1,
        &src,
        nullptr
    );

    glCompileShader(shader);

    GLint success;

    glGetShaderiv(
        shader,
        GL_COMPILE_STATUS,
        &success
    );

    if (!success)
    {
        char infoLog[1024];

        glGetShaderInfoLog(
            shader,
            sizeof(infoLog),
            nullptr,
            infoLog
        );

        glDeleteShader(shader);

        throw std::runtime_error(
            infoLog
        );
    }

    return shader;
}

ShaderProgram::ShaderProgram(
    const std::filesystem::path& vertexPath,
    const std::filesystem::path& fragmentPath
)
{
    std::string vertexSource =
        readFile(vertexPath);

    std::string fragmentSource =
        readFile(fragmentPath);

    GLuint vertexShader =
        compileShader(
            GL_VERTEX_SHADER,
            vertexSource
        );

    GLuint fragmentShader =
        compileShader(
            GL_FRAGMENT_SHADER,
            fragmentSource
        );

    m_id = glCreateProgram();

    glAttachShader(
        m_id,
        vertexShader
    );

    glAttachShader(
        m_id,
        fragmentShader
    );

    glLinkProgram(m_id);

    GLint success;

    glGetProgramiv(
        m_id,
        GL_LINK_STATUS,
        &success
    );

    if (!success)
    {
        char infoLog[1024];

        glGetProgramInfoLog(
            m_id,
            sizeof(infoLog),
            nullptr,
            infoLog
        );

        glDeleteProgram(m_id);

        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);

        throw std::runtime_error(
            infoLog
        );
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
    ShaderProgram&& other
) noexcept
{
    m_id = other.m_id;
    other.m_id = 0;
}

ShaderProgram&
ShaderProgram::operator=(
    ShaderProgram&& other
) noexcept
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

GLuint ShaderProgram::id() const {
    return m_id;
}