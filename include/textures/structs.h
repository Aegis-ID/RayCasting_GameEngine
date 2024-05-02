/*
** EPITECH PROJECT, 2024
** textures structs
** File description:
** CSFML
*/

#ifndef __TEXTURES_STRUCTS__
    #define __TEXTURES_STRUCTS__

enum texture_type {
    EMPTY,
    CHECKERBOARD,
    BRICK,
    WINDOW,
    DOOR
};

typedef struct textures_s {
    size_t line_ht;
    size_t line_off;
    sfVector2f pos;
    sfVector2f offset;
    sfVector2f step;
}textures_t;

// TO IMPLEMENT

#endif /* !__TEXTURES_STRUCTS__ */
