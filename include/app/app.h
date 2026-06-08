/**
 * @file app.h
 * @brief This file contains the definition of the AppData struct, and the 6 main routine functions inside main.c
 * 
 * @author Mango (杜明日) 
 * @date 2025-03-22
 */

#pragma once

#include <stdbool.h>
#include <scene.h>

typedef bool flag;



/**
 * @brief A struct containing the app's resources like the window, renderer, and fonts.
 */
typedef struct AppResources {

} AppResources;

/**
 * @brief A struct containing the app's states like fps, current scene, and a flag for running.
 */
typedef struct AppState {
    bool running; /**< Flag indicating if the app is running */
    Scene scene;
} AppState;

/**
 * @brief A struct containing the app's configurations like window size, title, and fullscreen mode.
 */
typedef struct AppConfig {
    char* window_title; /**< The window title */
    int window_width; /**< The window width */
    int window_height; /**< The window height */
    bool window_fullscreen; /**< Flag indicating if the window is fullscreen */
    int screen_width; /**< The screen width */
    int screen_height; /**< The screen height */

    bool debug; /**< Flag indicating if debug mode is enabled */
} AppConfig;

/**
 * @brief A struct containing the app's resources, state, and configurations. Used by the app variable.
 */
typedef struct AppData {
    AppResources resources; /**< The app's resources */
    AppState state; /**< The app's state */
    AppConfig config; /**< The app's configurations */
} AppData;


extern AppData app;

/**
 * @brief Initializes the app and starts the game loop
 * 
 * @return int Status code (0 for success, non-zero for error)
 */
int App_Start();

/**
 * @brief Performs operations before updating the current scene
 * 
 * @return int Status code (0 for success, non-zero for error)
 */
int App_PreUpdate();

/**
 * @brief Performs operations after updating the current scene
 * 
 * @return int Status code (0 for success, non-zero for error)
 */
int App_PostUpdate();

/**
 * @brief Renders the current scene to the screen
 * 
 * @return int Status code (0 for success, non-zero for error)
 */
int App_Render();

/**
 * @brief Handles SDL events
 * 
 * @param[in] event Pointer to the SDL event to handle
 * @return int Status code (0 for success, non-zero for error)
 */
int App_Event_Handler();

/**
 * @brief Cleans up resources and quits the application
 * 
 * @return int Status code (0 for success, non-zero for error)
 */
int App_Quit();