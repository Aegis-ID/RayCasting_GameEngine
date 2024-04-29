/*
** EPITECH PROJECT, 2024
** draw2Dmap
** File description:
** CSFML
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/OpenGL.h>
#include "ray_casting/funcs.h"

static void draw_cell(sfVector2i *offset, int map_s)
{
    glBegin(GL_QUADS);
    glVertex2i(offset->x + 1, offset->y + 1);
    glVertex2i(offset->x + 1, offset->y + map_s - 1);
    glVertex2i(offset->x + map_s - 1,
        offset->y + map_s - 1);
    glVertex2i(offset->x + map_s - 1, offset->y + 1);
    glEnd();
}

static void colorize_cell(int cell)
{
    if (is_wall(cell))
        glColor3f(1, 1, 1);
    else
        glColor3f(0, 0, 0);
}

void draw_map(maps_t *map, int map_s)
{
    sfVector2i offset = {0};

    for (size_t y = 0; y < map->height; ++y) {
        for (size_t x = 0; x < map->width; ++x) {
            colorize_cell(map->walls[y * map->width + x]);
            offset.x = x * map_s;
            offset.y = y * map_s;
            draw_cell(&offset, map_s);
        }
    }
    return;
}
