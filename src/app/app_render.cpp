#include <glfw3.h>
#include <app.h>
#include <input.h>

/**
 * @brief [Render] Handles the main rendering of the game, like players, game environments, etc.
 *
 * This function is called inside App_Render().
 *
 * @return int Status code (0 for success)
 */
int App_RenderMain()
{
    return 0;
}

/**
 * @brief [Render] Renders the current frame of the game.
 *
 * Includes the main rendering function and the final rendering to the window.
 * This function is called every frame after all the updating is complete.
 *
 * @return int Status code (0 for success)
 */
int App_Render()
{

    glClear(GL_COLOR_BUFFER_BIT |
            GL_DEPTH_BUFFER_BIT);

    App_RenderMain();

    glfwSwapBuffers(app.resources.window);
    return 0;
}