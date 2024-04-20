/*
** EPITECH PROJECT, 2024
** events
** File description:
** CSFML
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/OpenGL.h>
#include "global.h"
#include <math.h>

static void p_movement(sfEvent *event, player_t *player)
{
    if (event->key.code == sfKeyZ) {
        player->pos.x += player->delta.x;
        player->pos.y += player->delta.y;
    }
    if (event->key.code == sfKeyS) {
        player->pos.x -= player->delta.x;
        player->pos.y -= player->delta.y;
    }
}

static void p_rotation(sfEvent *event, player_t *player)
{
    if (event->key.code == sfKeyQ) {
        player->angle -= 0.1;
        if (player->angle < 0)
            player->angle += 2 * M_PI;
        player->delta.x = cos(player->angle) * 5;
        player->delta.y = sin(player->angle) * 5;
    }
    if (event->key.code == sfKeyD) {
        player->angle += 0.1;
        if (player->angle > 2 * M_PI)
            player->angle += 2 * M_PI;
        player->delta.x = cos(player->angle) * 5;
        player->delta.y = sin(player->angle) * 5;
    }
}

void events(game_t *game, player_t *player)
{
    sfRenderWindow *window = game->window;
    //event copy, not game's event varaible, no need to modify an event
    sfEvent event = game->event;

    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    else if (event.type == sfEvtResized)
        glViewport(0, 0, event.size.width, event.size.height);
    p_movement(&event, player);
    p_rotation(&event, player);
}
