#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <app.h>

int main()
{
    App_Start();
    while (app.state.running)
    {
        glfwPollEvents();
        App_Update();
        App_Render();
    }
    App_Quit();
    return 0;
}