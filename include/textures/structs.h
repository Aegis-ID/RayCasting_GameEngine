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
    size_t wall_ht;
    size_t wall_ht_off;
    sfVector2f pos;
    sfVector2f offset;
    sfVector2f step;
}textures_t;

#endif /* !__TEXTURES_STRUCTS__ */
