/*
** EPITECH PROJECT, 2024
** player_movement.c
** File description:
** RPG
*/

#include <math.h>
#include "lib.h"
#include "ray_casting.h"
#include "settings/settings.h"

static collisions_t get_collisions(player_t *p)
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
    col.pos.x = p->pos.x / MAP_S;
    col.pos.y = p->pos.y / MAP_S;
    col.offset_add.x = (p->pos.x + offset.x) / MAP_S;
    col.offset_add.y = (p->pos.y + offset.y) / MAP_S;
    col.offset_sub.x = (p->pos.x - offset.x) / MAP_S;
    col.offset_sub.y = (p->pos.y - offset.y) / MAP_S;
    return col;
}

static void p_vertical_mvt(player_t *p, maps_t *m, collisions_t *col)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ)) {
        if (m->map[col->pos.y * m->map_wd + col->offset_add.x] == 0)
            p->pos.x += p->delta.x * MVT;
        if (m->map[col->offset_add.y * m->map_wd + col->pos.x] == 0)
            p->pos.y += p->delta.y * MVT;
    }
    if (sfKeyboard_isKeyPressed(sfKeyS)) {
        if (m->map[col->pos.y * m->map_wd + col->offset_sub.x] == 0)
            p->pos.x -= p->delta.x * MVT;
        if (m->map[col->offset_sub.y * m->map_wd + col->pos.x] == 0)
            p->pos.y -= p->delta.y * MVT;
    }
    return;
}

static void p_horizontal_mvt(player_t *p, maps_t *m, collisions_t *col)
{
    if (sfKeyboard_isKeyPressed(sfKeyQ)) {
        if (m->map[col->pos.y * m->map_wd + col->offset_add.x] == 0)
            p->pos.x += p->delta.y * MVT;
        if (m->map[col->offset_sub.y * m->map_wd + col->pos.x] == 0)
            p->pos.y -= p->delta.x * MVT;
    }
    if (sfKeyboard_isKeyPressed(sfKeyD)) {
        if (m->map[col->pos.y * m->map_wd + col->offset_sub.x] == 0)
            p->pos.x -= p->delta.y * MVT;
        if (m->map[col->offset_add.y * m->map_wd + col->pos.x] == 0)
            p->pos.y += p->delta.x * MVT;
    }
    return;
}

static void p_rotation(player_t *p)
{
    if (sfKeyboard_isKeyPressed(sfKeyA)) {
        p->angle += ROT;
        p->angle = update_angle(p->angle);
        p->delta.x = cos(deg_to_rad(p->angle));
        p->delta.y = -sin(deg_to_rad(p->angle));
    }
    if (sfKeyboard_isKeyPressed(sfKeyE)) {
        p->angle -= ROT;
        p->angle = update_angle(p->angle);
        p->delta.x = cos(deg_to_rad(p->angle));
        p->delta.y = -sin(deg_to_rad(p->angle));
    }
    return;
}

void player_movement(player_t *player, maps_t *map)
{
    collisions_t col = get_collisions(player);

    p_rotation(player);
    p_vertical_mvt(player, map, &col);
    p_horizontal_mvt(player, map, &col);
    return;
}
