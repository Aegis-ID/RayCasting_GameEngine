/*
** EPITECH PROJECT, 2024
** draw2Dmap
** File description:
** CSFML
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/OpenGL.h>
#include "ray_casting.h"

static void draw_cell(sfVector2i *offset)
{
    glBegin(GL_QUADS);
    glVertex2i(offset->x + 1, offset->y + 1);
    glVertex2i(offset->x + 1, offset->y + MAP_S - 1);
    glVertex2i(offset->x + MAP_S - 1,
        offset->y + MAP_S - 1);
    glVertex2i(offset->x + MAP_S - 1, offset->y + 1);
    glEnd();
}

static void colorize_cell(int cell)
{
    if (cell == 1)
        glColor3f(1, 1, 1);
    else
        glColor3f(0, 0, 0);
}

void draw_map(maps_t *map)
{
    sfVector2i offset = {0};

    for (size_t y = 0; y < map->map_ht; ++y) {
        for (size_t x = 0; x < map->map_wd; ++x) {
            colorize_cell(map->map[y * map->map_wd + x]);
            offset.x = x * MAP_S;
            offset.y = y * MAP_S;
            draw_cell(&offset);
        }
    }
    return;
}
