/*
** EPITECH PROJECT, 2024
** display
** File description:
** CSFML
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/OpenGL.h>
#include <string.h>
#include <math.h>
#include "global.h"
#include "lib.h"
#include "window.h"

static void p_draw(player_t *player)
{
    //draw player body
    glColor3f(1, 1, 0);
    glPointSize(8);
    glBegin(GL_POINTS);
    glVertex2i(player->pos.x, player->pos.y);
    glEnd();
    //draw direction
    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2i(player->pos.x, player->pos.y);
    glVertex2i(player->pos.x + player->delta.x * 5,
        player->pos.y + player->delta.y * 5);
    glEnd();
}

void display(game_t *game, player_t *player, maps_t *map)
{
    //draw with OpenGL
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    draw2Dmap(map);
    draw2Drays(player, map);
    p_draw(player);
    // save OpenGL states
    sfRenderWindow_pushGLStates(game->window);
    // draw with CSFML here
    // ...
    sfRenderWindow_display(game->window);
    // restore OpenGL states
    sfRenderWindow_popGLStates(game->window);
}
