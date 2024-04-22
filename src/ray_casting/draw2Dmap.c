/*
** EPITECH PROJECT, 2024
** draw2Dmap
** File description:
** CSFML
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/OpenGL.h>
#include "global.h"

float fix_angle(float angle)
{
    if (angle > 359)
        angle -= 360;
    if (angle < 0)
        angle += 360;
    return angle;
}

void p_draw(player_t *player)
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

static void drawCell(maps_t *map, sfVector2i *offset)
{
    glBegin(GL_QUADS);
    glVertex2i(offset->x + 1, offset->y + 1);
    glVertex2i(offset->x + 1, offset->y + map->cell_size - 1);
    glVertex2i(offset->x + map->cell_size - 1,
        offset->y + map->cell_size - 1);
    glVertex2i(offset->x + map->cell_size - 1, offset->y + 1);
    glEnd();
}

static void colorize_cell(int cell)
{
    if (cell == 1)
        glColor3f(1, 1, 1);
    else
        glColor3f(0, 0, 0);
}

void draw2Dmap(maps_t *map)
{
    sfVector2i offset = {0};

    for (size_t y = 0; y < map->map_ht; ++y) {
        for (size_t x = 0; x < map->map_wd; ++x) {
            colorize_cell(map->map[y * map->map_wd + x]);
            offset.x = x * map->cell_size;
            offset.y = y * map->cell_size;
            drawCell(map, &offset);
        }
    }
    return;
}
