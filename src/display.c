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
#include "settings.h"

void display(game_t *game, player_t *player, maps_t *map)
{
    //draw with OpenGL
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    draw_map(map);
    draw_player(player);
    ray_casting(player, map);
    // save OpenGL states
    sfRenderWindow_pushGLStates(game->window);
    // draw with CSFML here
    // ...
    sfRenderWindow_display(game->window);
    // restore OpenGL states
    sfRenderWindow_popGLStates(game->window);
}
