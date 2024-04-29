/*
** EPITECH PROJECT, 2024
** player_movement.c
** File description:
** RPG
*/

#include <math.h>
#include "lib.h"
#include "ray_casting/funcs.h"
#include "settings/structs.h"

static collisions_t get_collisions(player_t *p, int map_s)
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

static void p_vertical_mvt(player_t *p, maps_t *m, collisions_t *col,
    keybinds_t *k)
{
    if (sfKeyboard_isKeyPressed(k->move_forward)) {
        if (!is_wall(m->walls[col->pos.y * m->width + col->offset_add.x]))
            p->pos.x += p->delta.x * MVT;
        if (!is_wall(m->walls[col->offset_add.y * m->width + col->pos.x]))
            p->pos.y += p->delta.y * MVT;
    }
    if (sfKeyboard_isKeyPressed(k->move_backward)) {
        if (!is_wall(m->walls[col->pos.y * m->width + col->offset_sub.x]))
            p->pos.x -= p->delta.x * MVT;
        if (!is_wall(m->walls[col->offset_sub.y * m->width + col->pos.x]))
            p->pos.y -= p->delta.y * MVT;
    }
    return;
}

static void p_horizontal_mvt(player_t *p, maps_t *m, collisions_t *col,
    keybinds_t *k)
{
    if (sfKeyboard_isKeyPressed(k->move_left)) {
        if (!is_wall(m->walls[col->pos.y * m->width + col->offset_add.x]))
            p->pos.x += p->delta.y * MVT;
        if (!is_wall(m->walls[col->offset_sub.y * m->width + col->pos.x]))
            p->pos.y -= p->delta.x * MVT;
    }
    if (sfKeyboard_isKeyPressed(k->move_right)) {
        if (!is_wall(m->walls[col->pos.y * m->width + col->offset_sub.x]))
            p->pos.x -= p->delta.y * MVT;
        if (!is_wall(m->walls[col->offset_add.y * m->width + col->pos.x]))
            p->pos.y += p->delta.x * MVT;
    }
    return;
}

static void p_rotation(player_t *p, gameplay_t *gp, keybinds_t *k)
{
    if (sfKeyboard_isKeyPressed(k->look_left)) {
        p->angle += gp->sensitivity;
        p->angle = update_angle(p->angle);
        p->delta.x = cos(deg_to_rad(p->angle));
        p->delta.y = -sin(deg_to_rad(p->angle));
    }
    if (sfKeyboard_isKeyPressed(k->look_right)) {
        p->angle -= gp->sensitivity;
        p->angle = update_angle(p->angle);
        p->delta.x = cos(deg_to_rad(p->angle));
        p->delta.y = -sin(deg_to_rad(p->angle));
    }
    return;
}

void player_movement(game_t *game, player_t *player, maps_t *walls)
{
    collisions_t col = get_collisions(player,
        game->settings.gameplay.map_s);

    p_rotation(player, &game->settings.gameplay, &game->settings.keybinds);
    p_vertical_mvt(player, walls, &col, &game->settings.keybinds);
    p_horizontal_mvt(player, walls, &col, &game->settings.keybinds);
    return;
}
