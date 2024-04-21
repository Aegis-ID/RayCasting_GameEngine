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

static void drawCell(maps_t *map, sfVector2i *offset)
{
    glBegin(GL_QUADS);
    glVertex2i(offset->x + 1, offset->y + 1);
    glVertex2i(offset->x + 1, offset->y + map->m_size - 1);
    glVertex2i(offset->x + map->m_size - 1,
        offset->y + map->m_size - 1);
    glVertex2i(offset->x + map->m_size - 1, offset->y + 1);
    glEnd();
}

void draw2Dmap(maps_t *map)
{
    sfVector2i offset = {0};

    for (size_t y = 0; y < map->m_height; ++y) {
        for (size_t x = 0; x < map->m_width; ++x) {
            colorizeCell(map->map[y * map->m_width + x]);
            offset.x = x * map->m_size;
            offset.y = y * map->m_size;
            drawCell(map, &offset);
        }
    }
    return;
}
