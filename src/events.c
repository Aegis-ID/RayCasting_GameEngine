/*
** EPITECH PROJECT, 2024
** events
** File description:
** CSFML
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/OpenGL.h>
#include <math.h>
#include "global.h"
#include "settings.h"
#include "lib.h"

static void p_movement(player_t *p)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ)) {
        p->pos.x += p->delta.x * MVT;
        p->pos.y += p->delta.y * MVT;
    }
    if (sfKeyboard_isKeyPressed(sfKeyQ)) {
        p->pos.x += p->delta.y * MVT;
        p->pos.y -= p->delta.x * MVT;
    }
    if (sfKeyboard_isKeyPressed(sfKeyS)) {
        p->pos.x -= p->delta.x * MVT;
        p->pos.y -= p->delta.y * MVT;
    }
    if (sfKeyboard_isKeyPressed(sfKeyD)) {
        p->pos.x -= p->delta.y * MVT;
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

void events(game_t *game, player_t *player)
{
    sfRenderWindow *window = game->window;
    sfEvent event = game->event;

    if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape))
        sfRenderWindow_close(window);
    if (event.type == sfEvtResized)
        glViewport(0, 0, event.size.width, event.size.height);
    p_rotation(player);
    p_movement(player);
    return;
}
