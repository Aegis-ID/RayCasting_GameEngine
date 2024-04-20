/*
** EPITECH PROJECT, 2024
** display
** File description:
** CSFML
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/OpenGL.h>
#include "global.h"

static void p_draw(game_t *game, player_t *player)
{
    sfRenderWindow_drawCircleShape(game->window, player->circle, NULL);
}

void display(game_t *game, player_t *player)
{
    sfRenderWindow *window = game->window;

    // clear the buffers
    sfRenderWindow_clear(window, sfBlack);
    //draw here
    p_draw(game, player);
    /* // end the current frame (internally swaps the front and back buffers) */
    sfRenderWindow_display(window);
}
