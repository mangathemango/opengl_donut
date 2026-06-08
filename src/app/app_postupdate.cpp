#include <app.h>
#include <input.h>


/**
 * @brief [PostUpdate] Main game update routine
 * 
 * This function is called every frame of the program AFTER App_Event_Handler(). 
 * This is suitable for rendering and updating the game.
 * 
 * @return int Status code (0 for success)
 */
int App_PostUpdate() {
    GameObj* cube = app.state.scene.objs[1];
    Transform* cameraTf = app.state.scene.objs[0]->getComponent<Transform>();
    float sensitivity = 0.5;
    // if (Input->keyboard.keys[SDL_SCANCODE_RIGHT].held) cameraTf->rotateDegrees(Vec3::up(), sensitivity);
    // if (Input->keyboard.keys[SDL_SCANCODE_LEFT].held) cameraTf->rotateDegrees(Vec3::up(), -sensitivity);
    // if (Input->keyboard.keys[SDL_SCANCODE_UP].held) cameraTf->rotateDegrees(Vec3::right(), -sensitivity);
    // if (Input->keyboard.keys[SDL_SCANCODE_DOWN].held) cameraTf->rotateDegrees(Vec3::right(), sensitivity);
    // if (Input->keyboard.keys[SDL_SCANCODE_W].held) cameraTf->translate( Vec3::forward()  * sensitivity);
    // if (Input->keyboard.keys[SDL_SCANCODE_A].held) cameraTf->translate( Vec3::left()     * sensitivity);
    // if (Input->keyboard.keys[SDL_SCANCODE_S].held) cameraTf->translate( Vec3::backward() * sensitivity);
    // if (Input->keyboard.keys[SDL_SCANCODE_D].held) cameraTf->translate( Vec3::right()    * sensitivity);
    return 0;
}