#include <app.h>
#include <glfw3.h>
#include <input.h>
#include <mesh_renderer.h>

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

    app.resources.renderer->shaderProgram.bind();
    for (GameObj* obj : app.state.scene.objs) {
        MeshRenderer* mr = obj->getComponent<MeshRenderer>();
        if (mr == nullptr) continue;
        app.resources.renderer->uploadMesh(mr->mesh);
    }

    glfwSwapBuffers(app.resources.window);
    return 0;
}