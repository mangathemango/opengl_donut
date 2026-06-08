/**
 * @file input.c
 * @brief Input handling system
 *
 * Manages keyboard, mouse and controller input,
 * providing a consistent interface for detecting
 * button presses, releases, and held states.
 *
 * @author Mango
 * @date 2025-03-06
 */

//? Updated by Mango on 06/03/2025

#include <input.h>
#include <app.h>
#include <cstring>

static InputEvent _input;
const InputEvent * const Input = &_input; // This ensures that the Input variable is read-only to other files.

// Add previous frame state tracking
static bool wasHeld[NUM_SCANCODES];
static bool mouseWasHeld[3];  // For left, right, middle buttons

/**
 * @brief Presses a button
 *
 * @param button The button to press. Can either be a key button or a mouse button
 */
void Press_Button(ButtonState *button) {
    button->pressed = !button->held;  // Only true if wasn't held last frame
    button->held = true;
    button->released = false;
}

/**
 * @brief Releases a button
 *
 * @param button The button to release. Can either be a key button or a mouse button
 */
void Release_Button(ButtonState *button) {
    button->released = button->held;  // Only true if was held last frame
    button->held = false;
    button->pressed = false;
}

/**
 * @brief Resets a button's pressed and released states
 *
 * This function is called every frame to ensure that the button's pressed and released 
 * states are only true for one frame.
 *
 * @param button The button to release. Can either be a key button or a mouse button
 */
void Reset_Button(ButtonState *button) {
    button->pressed = false;
    button->released = false;
}

/**
 * @brief This function is called inside App_PreUpdate()
 *
 * It retrieves the mouse's state and resets all the mouse/keyboard buttons.
 */
void Input_PreUpdate() {
    // Store previous frame's held states
    for (int i = 0; i < NUM_SCANCODES; i++) {
        wasHeld[i] = _input.keyboard.keys[i].held;
    }
    mouseWasHeld[0] = _input.mouse.leftButton.held;
    mouseWasHeld[1] = _input.mouse.rightButton.held;
    mouseWasHeld[2] = _input.mouse.middleButton.held;

    // Reset pressed/released states (they only last one frame)
    Reset_Button(&_input.mouse.leftButton);
    Reset_Button(&_input.mouse.rightButton);
    Reset_Button(&_input.mouse.middleButton);
    for (int i = 0; i < NUM_SCANCODES; i++) {
        Reset_Button(&_input.keyboard.keys[i]);
    }

    // Preserve held states from last frame
    for (int i = 0; i < NUM_SCANCODES; i++) {
        _input.keyboard.keys[i].held = wasHeld[i];
    }
    _input.mouse.leftButton.held = mouseWasHeld[0];
    _input.mouse.rightButton.held = mouseWasHeld[1];
    _input.mouse.middleButton.held = mouseWasHeld[2];

    // Reset and update anyKey state
    Reset_Button(&_input.anyKey);
    for (int i = 0; i < NUM_SCANCODES; i++) {
        if (_input.keyboard.keys[i].pressed) _input.anyKey.pressed = true;
        if (_input.keyboard.keys[i].released) _input.anyKey.released = true;
        if (_input.keyboard.keys[i].held) _input.anyKey.held = true;
    }

    // Reset other input states
    _input.mouse.scrollUp = false;
    _input.mouse.scrollDown = false;
    _input.mouse.motion = Vec2(0, 0);
    
    // Update mouse position
    int windowMouseX, windowMouseY;
    float screenMouseX = 0, screenMouseY = 0;
    // TODO
    _input.mouse.position = Vec2(screenMouseX, screenMouseY);
}


/**
 * @brief This function is called inside App_Event_Handler()
 *
 * It updates the InputEvent struct based on the SDL_Event.
 *
 * @param event The SDL_Event to update the InputEvent struct with
 */
void Input_Event_Handler() {

}

// Initialize default bindings
void Input_Init() {
    // Initialize previous state arrays
    memset(wasHeld, 0, sizeof(wasHeld));
    memset(mouseWasHeld, 0, sizeof(mouseWasHeld));
}



