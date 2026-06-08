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
