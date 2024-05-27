/*
** EPITECH PROJECT, 2024
** textures
** File description:
** CSFML
*/

#ifndef __TEXTURES_CONST__
    #define __TEXTURES_CONST__

    #include <stddef.h>

    #include "../assets/textures/FLOOR_TEXT.ppm"
    #include "../assets/textures/BRICK_TEXT.ppm"
    #include "../assets/textures/BRICK_VAR_TEXT.ppm"
    #include "../assets/textures/DOOR_TEXT.ppm"
    #include "../assets/textures/FINAL_DOOR_TEXT.ppm"
    #include "../assets/textures/SKY_TEXT.ppm"

    #define TEXTURES_S 32
    #define TEXTURES_NB 5

    #define SKY_WD 120
    #define SKY_HT 60

const size_t *ALL_TEXTURES[] = {
    FLOOR_TEXT,
    BRICK_TEXT,
    BRICK_VAR_TEXT,
    DOOR_TEXT,
    FINAL_DOOR_TEXT,
    NULL
};

#endif
