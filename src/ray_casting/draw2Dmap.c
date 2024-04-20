/*
** EPITECH PROJECT, 2024
** draw2Dmap
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

static void colorizeCell(char cell)
{
    if (cell == '1')
        glColor3f(1, 1, 1);
    else
        glColor3f(0, 0, 0);
}

static void drawCell(maps_t *map, sfVector2i *offset)
{
    glBegin(GL_QUADS);
    glVertex2i(offset->x + 1, offset->y + 1);
    glVertex2i(offset->x + 1, offset->y + map->map_size - 1);
    glVertex2i(offset->x + map->map_size - 1,
        offset->y + map->map_size - 1);
    glVertex2i(offset->x + map->map_size - 1, offset->y + 1);
    glEnd();
}

void draw2Dmap(maps_t *map)
{
    sfVector2i offset = {0};

    for (size_t y = 0; map->map[y] != 0; ++y) {
        for (size_t x = 0; map->map[y][x] != '\0'; ++x) {
            colorizeCell(map->map[y][x]);
            offset.x = x * map->map_size;
            offset.y = y * map->map_size;
            drawCell(map, &offset);
        }
    }
    return;
}
