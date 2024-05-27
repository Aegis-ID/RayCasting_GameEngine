/*
** EPITECH PROJECT, 2024
** player_movement.c
** File description:
** RPG
*/

#include <math.h>

#include "lib.h"

#include "game.h"

static void p_vertical_mvt(keybinds_t *k, collisions_t *col, entity_t *p)
{
    if (sfKeyboard_isKeyPressed(k->move_forward)) {
        if (col->front >= COL_DIST) {
            p->pos.x += p->delta.x * MVT;
            p->pos.y += p->delta.y * MVT;
        }
    }
    if (sfKeyboard_isKeyPressed(k->move_backward)) {
        if (col->back >= COL_DIST) {
            p->pos.x -= p->delta.x * MVT;
            p->pos.y -= p->delta.y * MVT;
        }
    }
    return;
}

static void p_horizontal_mvt(keybinds_t *k, collisions_t *col, entity_t *p)
{
    if (sfKeyboard_isKeyPressed(k->move_left)) {
        if (col->left >= COL_DIST) {
            p->pos.x += p->delta.y * MVT;
            p->pos.y -= p->delta.x * MVT;
        }
    }
    if (sfKeyboard_isKeyPressed(k->move_right)) {
        if (col->right >= COL_DIST) {
            p->pos.x -= p->delta.y * MVT;
            p->pos.y += p->delta.x * MVT;
        }
    }
    return;
}

static void p_rotation(keybinds_t *k, entity_t *p)
{
    if (sfKeyboard_isKeyPressed(k->look_left)) {
        p->angle += k->sensitivity;
        p->angle = get_deg(p->angle);
        p->delta.x = cos(deg_to_rad(p->angle));
        p->delta.y = -sin(deg_to_rad(p->angle));
    }
    if (sfKeyboard_isKeyPressed(k->look_right)) {
        p->angle -= k->sensitivity;
        p->angle = get_deg(p->angle);
        p->delta.x = cos(deg_to_rad(p->angle));
        p->delta.y = -sin(deg_to_rad(p->angle));
    }
    return;
}

static void mouse_rotation(game_t *game, entity_t *p, keybinds_t *k)
{
    sfRenderWindow *window = &game->game_window.window;
    sfVector2i res = game->settings.display.res;
    sfVector2i mouse_pos =
        sfMouse_getPositionRenderWindow(window);
    float fov = game->settings.display.fov;
    float m_rotation = fov * (res.x / 2 - mouse_pos.x) / res.x;

    res.x /= 2;
    res.y /= 2;
    if (mouse_pos.x != res.x) {
        p->angle = get_degrees(p->angle + m_rotation * k->sensitivity);
        p->angle = get_deg(p->angle);
        p->delta.x = cos(deg_to_rad(p->angle));
        p->delta.y = -sin(deg_to_rad(p->angle));
        sfMouse_setPositionRenderWindow(res, window);
    }
    return;
}

void player_movement(game_t *game, graphics_t *rays)
{
    collisions_t *col = game->gameplay;
    keybinds_t *k = &game->settings.keybinds;

    mouse_rotation(game, &rays->player, k);
    p_rotation(k, &rays->player);
    p_vertical_mvt(k, &col, &rays->player);
    p_horizontal_mvt(k, &col, &rays->player);
    return;
}
