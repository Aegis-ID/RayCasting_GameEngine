/*
** EPITECH PROJECT, 2024
** display
** File description:
** CSFML
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/OpenGL.h>
#include "ray_casting/funcs.h"
#include "game/structs.h"

void display(game_t *game, ray_casting_t *rc_mode)
{
    //draw with OpenGL
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    draw_map(&rc_mode->maps, game->settings.gameplay.map_s);
    draw_player(&rc_mode->player);
    ray_casting(game, &rc_mode->player, &rc_mode->maps);
    // save OpenGL states
    sfRenderWindow_pushGLStates(game->window);
    // draw with CSFML here
    // ...
    sfRenderWindow_display(game->window);
    // restore OpenGL states
    sfRenderWindow_popGLStates(game->window);
}
