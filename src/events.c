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

static void p_movement(sfEvent *event, player_t *p)
{
    if (event->key.code == sfKeyZ) {
        p->pos.x += p->delta.x;
        p->pos.y += p->delta.y;
    }
    if (event->key.code == sfKeyQ) {
        p->pos.x += p->delta.y;
        p->pos.y -= p->delta.x;
    }
    if (event->key.code == sfKeyS) {
        p->pos.x -= p->delta.x;
        p->pos.y -= p->delta.y;
    }
    if (event->key.code == sfKeyD) {
        p->pos.x -= p->delta.y;
        p->pos.y += p->delta.x;
    }
}

static void p_rotation(sfEvent *event, player_t *p)
{
    if (event->key.code == sfKeyA) {
        p->angle -= 0.1;
        if (p->angle < 0)
            p->angle += 2 * M_PI;
    }
    if (event->key.code == sfKeyE) {
        p->angle += 0.1;
        if (p->angle > (2 * M_PI))
            p->angle -= 2 * M_PI;
    }
    p->delta.x = cos(p->angle) * 5;
    p->delta.y = sin(p->angle) * 5;
}

void events(game_t *game, player_t *player)
{
    sfRenderWindow *window = game->window;
    sfEvent event = game->event;

    if (event.type == sfEvtClosed || event.key.code == sfKeyEscape)
        sfRenderWindow_close(window);
    if (event.type == sfEvtResized)
        glViewport(0, 0, event.size.width, event.size.height);
    p_movement(&event, player);
    p_rotation(&event, player);
}
