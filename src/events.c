/*
** EPITECH PROJECT, 2024
** events
** File description:
** CSFML
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/OpenGL.h>
#include "ray_casting.h"
#include "game.h"

void events(game_t *game, ray_casting_t *rc_mode)
{
    sfRenderWindow *window = game->window;
    sfEvent event = game->event;

    if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape))
        sfRenderWindow_close(window);
    if (event.type == sfEvtResized)
        glViewport(0, 0, event.size.width, event.size.height);
    player_movement(&rc_mode->player, &rc_mode->maps);
    return;
}
