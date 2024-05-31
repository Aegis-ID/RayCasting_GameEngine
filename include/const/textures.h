/*
** EPITECH PROJECT, 2024
** textures
** File description:
** CSFML
*/

#ifndef __TXR_CONST__
    #define __TXR_CONST__

    #include <stddef.h>

    #include "../assets/textures/FLOOR_TXR.ppm"
    #include "../assets/textures/BRICK_TXR.ppm"
    #include "../assets/textures/BRICK_VAR_TXR.ppm"
    #include "../assets/textures/DOOR_TXR.ppm"
    #include "../assets/textures/FINAL_DOOR_TXR.ppm"

    #define TXR_S 32
    #define TXR_NB 5

const size_t *ALL_TXR[] = {
    FLOOR_TXR,
    BRICK_TXR,
    BRICK_VAR_TXR,
    DOOR_TXR,
    FINAL_DOOR_TXR,
    NULL
};

#endif
