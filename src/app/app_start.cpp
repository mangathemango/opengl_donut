#include <gl.h>
#include <app.h>
#include <random.h>
#include <input.h>
#include <meshrenderer.h>
#include <cubemesh.h>
#include <component.h>


/*
*   [Start] This function is called at the start of the program.
?   It initializes everything needed for the program to run. Like the window, renderer, and later, the game.

?   Updated by Mango on 08/03/2025
*/
int App_Start() {
    RandomInit();

    if (!glfwInit())
    {
        std::cerr << "Failed to initialize GLFW\n";
        return 1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE,
                   GLFW_OPENGL_CORE_PROFILE);

    app.resources.window = glfwCreateWindow(
        app.config.window_width,
        app.config.window_height,
        app.config.window_title,
        nullptr,
        nullptr);

    if (!app.resources.window)
    {
        std::cerr << "Failed to create window\n";
        glfwTerminate();
        return 1;
    }

    glfwMakeContextCurrent(app.resources.window);

    if (!gladLoadGL(glfwGetProcAddress))
    {
        std::cerr << "Failed to initialize GLAD\n";
        return 1;
    }

    glfwSwapInterval(1); // vsync

    glViewport(
        0,
        0,
        app.config.screen_width,
        app.config.screen_height);

    glEnable(GL_DEPTH_TEST);
    GameObj* cameraObj = new GameObj();
    Camera* camera = cameraObj->addComponent<Camera>();
    camera->fov = 90;
    camera->tf = cameraObj->getComponent<Transform>();
    camera->tf->rotateDegrees(Vec3::up(), 30);
    app.state.scene.mainCamera = camera;


    GameObj* cube = new GameObj();
    MeshRenderer* mr = cube->addComponent<MeshRenderer>();
    mr->mesh = new CubeMesh(2.0f);
    cube->getComponent<Transform>()->position = Vec3(0,-3,20);
    
    return 0;
}
