/*
** EPITECH PROJECT, 2024
** get_collisions.c
** File description:
** CSFML
*/

#include "ray_casting/funcs.h"

collisions_t get_collisions(player_t *p, int map_s)
{
    collisions_t col = {0};
    sfVector2i offset = {0};

    if (p->delta.x < 0)
        offset.x = -COL_DIST;
    else
        offset.x = COL_DIST;
    if (p->delta.y < 0)
        offset.y = -COL_DIST;
    else
        offset.y = COL_DIST;
    col.pos.x = p->pos.x / map_s;
    col.pos.y = p->pos.y / map_s;
    col.offset_add.x = (p->pos.x + offset.x) / map_s;
    col.offset_add.y = (p->pos.y + offset.y) / map_s;
    col.offset_sub.x = (p->pos.x - offset.x) / map_s;
    col.offset_sub.y = (p->pos.y - offset.y) / map_s;
    return col;
}
