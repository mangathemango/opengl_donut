#include <app.h>

/*
*   @file app_data.c
*   [Data] This file contains the app's data initialization.
*/

AppData app = {
    .resources = {

    },
    .state = {
        .running = true,
    },
    .config = {
        .window_title = "Operation Null Mind" ,
        .window_width = 480 * 2 ,
        .window_height = 288 * 2 ,
        .window_fullscreen = false ,
        .screen_width = 480 ,
        .screen_height = 288 ,
        
        .debug = false,
    },
};