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
    static bool flag = true;
    if (flag) {
        std::cout << "Rendering first frame..." << std::endl;
    }
    glClear(GL_COLOR_BUFFER_BIT |
            GL_DEPTH_BUFFER_BIT);
    
    if (flag) std::cout << "Binding shader program" << std::endl;
    app.resources.renderer->shaderProgram.bind();
    for (GameObj* obj : app.state.scene.objs) {
        MeshRenderer* mr = obj->getComponent<MeshRenderer>();
        if (mr == nullptr) continue;
        if (flag) std::cout << "Uploading mesh" << std::endl;
        GpuMesh& gpuMesh = app.resources.renderer->getGpuMesh(mr->mesh.get());
    }

    glfwSwapBuffers(app.resources.window);

    if (flag) {
        std::cout << "Rendering first frame done" << std::endl;
        flag = false;
    }
    return 0;
}