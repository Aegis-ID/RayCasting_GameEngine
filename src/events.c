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

static void p_movement(sfEvent *event, player_t *player)
{
    sfVector2f *player_pos = &player->pos;

    if (event->key.code == sfKeyQ)
        player_pos->x -= 5;
    if (event->key.code == sfKeyD)
        player_pos->x += 5;
    if (event->key.code == sfKeyZ)
        player_pos->y -= 5;
    if (event->key.code == sfKeyS)
        player_pos->y += 5;
    sfCircleShape_setPosition(player->circle, player->pos);
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
}
