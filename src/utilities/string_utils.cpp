#include <string_utils.h>

std::string readFile(
    const std::filesystem::path& path
)
{
    std::ifstream file(path);

    if (!file)
    {
        throw std::runtime_error(
            "Failed to open shader: "
            + path.string()
        );
    }

    std::stringstream buffer;
    buffer << file.rdbuf();

    return buffer.str();
}