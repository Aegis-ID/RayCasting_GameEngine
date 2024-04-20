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
#include "ray_casting/map.h"
#include <math.h>

void draw2Dmap(const int map[], int map_x, int map_y, int map_s)
{
    sfVector2i origin = {0};

    for (int y = 0; y < map_y; ++y) {
        for (int x = 0; x < map_x; ++x) {
            if (map[y * map_x + x] == 1)
                glColor3f(1, 1, 1);
            else
                glColor3f(0, 0, 0);
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

static void p_draw(game_t *game, player_t *player)
{
    glColor3f(1, 1, 0);
    glPointSize(8);
    glBegin(GL_POINTS);
    glVertex2i(player->pos.x, player->pos.y);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2i(player->pos.x, player->pos.y);
    glVertex2i(player->pos.x + player->delta.x * 5, player->pos.y + player->delta.y * 5);
    glEnd();
}

void display(game_t *game, player_t *player)
{
    //draw with OpenGL
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    draw2Dmap(TEST_MAP, MAP_X, MAP_Y, MAP_S);
    p_draw(game, player);
    // save OpenGL states
    sfRenderWindow_pushGLStates(game->window);
    // draw with CSFML here
    // ...
    sfRenderWindow_display(game->window);
    // restore OpenGL states
    sfRenderWindow_popGLStates(game->window);
}
