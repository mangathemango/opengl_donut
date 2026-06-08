#include <glad/gl.h>
#include <GLFW/glfw3.h>

int main() {
    glfwInit();

    GLFWwindow* window =
        glfwCreateWindow(800, 600, "Hello", nullptr, nullptr);

    glfwMakeContextCurrent(window);

    int version = gladLoadGL(glfwGetProcAddress);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
}