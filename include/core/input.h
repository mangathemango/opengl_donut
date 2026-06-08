#ifndef INPUT_H
#define INPUT_H    
#include <vec2.h>
#include <stdbool.h>
#include <stdio.h>

#define NUM_SCANCODES 10

typedef struct ButtonState {
    bool pressed;   // Value is True on the FIRST frame the button is pressed
    bool released;  // Value is True on the FIRST frame the button is released
    bool held;      // Value is True on EVERY frame the button is pressed
} ButtonState;

typedef struct MouseState {
    Vec2 position;          // Position of the mouse
    Vec2 motion;            // Motion of the mouse
    ButtonState leftButton;     // State of the left mouse button - either pressed, released, or held
    ButtonState rightButton;    // State of the right mouse button - either pressed, released, or held
    ButtonState middleButton;   // State of the middle mouse button - either pressed, released, or held
    bool scrollUp;              // Value is True when the scroll wheel is scrolled up
    bool scrollDown;            // Value is True when the scroll wheel is scrolled down
} MouseState;

typedef struct KeyboardState {
    ButtonState keys[NUM_SCANCODES];
} KeyboardState;

typedef struct InputEvent {
    MouseState mouse;       // State of the mouse
    KeyboardState keyboard; // State of the keyboard
    ButtonState anyKey;     // State of any key - pressed, released, or held
} InputEvent;

extern const InputEvent * const Input;

void Input_Init();
void Input_PreUpdate();
void Input_Event_Handler();

#endif