#include <app.h>
#include <input.h>


/**
 * @brief [PreUpdate] Early frame setup routine 
 * 
 * This function is called every frame of the program BEFORE App_Event_Handler().
 * This routine serves as a system setup for the main frame.
 * 
 * @return int Status code (0 for success)
 */
int App_PreUpdate() {
    Input_PreUpdate();

    return 0;
}