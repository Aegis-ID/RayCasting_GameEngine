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

static void colorize2Dmap(char cell)
{
    if (cell == '1')
        glColor3f(1, 1, 1);
    else
        glColor3f(0, 0, 0);
}

void draw2Dmap(const char **map)
{
    sfVector2i origin = {0};
    size_t map_s = array_strlen(map);

    for (size_t y = 0; map[y] != 0; ++y) {
        for (size_t x = 0; map[y][x] != '\0'; ++x) {
            colorize2Dmap(map[y][x]);
            origin.x = x * map_s;
            origin.y = y * map_s;
            glBegin(GL_QUADS);
            glVertex2i(origin.x + 1, origin.y + 1);
            glVertex2i(origin.x + 1, origin.y + map_s - 1);
            glVertex2i(origin.x + map_s - 1, origin.y + map_s - 1);
            glVertex2i(origin.x + map_s - 1, origin.y + 1);
            glEnd();
        }
    }
    return;
}

static void p_draw(player_t *player)
{
    glColor3f(1, 1, 0);
    glPointSize(8);
    glBegin(GL_POINTS);
    glVertex2i(player->pos.x, player->pos.y);
    glEnd();

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
    draw2Dmap((const char **)map->map);
    p_draw(player);
    // save OpenGL states
    sfRenderWindow_pushGLStates(game->window);
    // draw with CSFML here
    // ...
    sfRenderWindow_display(game->window);
    // restore OpenGL states
    sfRenderWindow_popGLStates(game->window);
}
