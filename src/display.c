/*
** EPITECH PROJECT, 2024
** display
** File description:
** CSFML
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/OpenGL.h>

#include "game.h"
#include "graphics.h"

void display(game_t *game)
{
    sfRenderWindow *window = &game->game_window.window;

    game->settings.display.res =
        sfRenderWindow_getSize(&game->game_window.window);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    if (game->game_state == EXPLORATION)
        display_exploration(game);
    sfRenderWindow_pushGLStates(window);
    if (game->game_state == EXPLORATION)
        display_exploration_hud(game);
    sfRenderWindow_display(window);
    sfRenderWindow_popGLStates(window);
    return;
}
