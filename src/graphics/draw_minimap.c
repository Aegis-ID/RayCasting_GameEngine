/*
** EPITECH PROJECT, 2024
** draw2Dmap
** File description:
** CSFML
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/OpenGL.h>

#include "lib.h"
#include "settings.h"
#include "graphics.h"

static void draw_cell(sfVector2i *offset)
{
    glBegin(GL_QUADS);
    glVertex2i(offset->x + 1, offset->y + 1);
    glVertex2i(offset->x + 1, offset->y + MAP_RATIO - 1);
    glVertex2i(offset->x + MAP_RATIO - 1,
        offset->y + MAP_RATIO - 1);
    glVertex2i(offset->x + MAP_RATIO - 1, offset->y + 1);
    glEnd();
}

static void colorize_cell(int cell)
{
    if (is_wall(cell))
        glColor3f(1, 1, 1);
    else
        glColor3f(0, 0, 0);
}

static void draw_map(map_t *map)
{
    sfVector2i offset = {0};

    for (size_t y = 0; (int)y < map->height; ++y) {
        for (size_t x = 0; (int)x < map->width; ++x) {
            colorize_cell(map->walls[y * map->width + x]);
            offset.x = x * MAP_RATIO;
            offset.y = y * MAP_RATIO;
            draw_cell(&offset);
        }
    }
    return;
}

static void draw_player(entity_t *p)
{
    glColor3f(1, 1, 0);
    glPointSize(8);
    glLineWidth(4);
    glBegin(GL_POINTS);
    glVertex2i(p->pos.x, p->pos.y);
    glEnd();
    return;
}

static void draw_player_direction(entity_t *p)
{
    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2i(p->pos.x, p->pos.y);
    glVertex2i(
        p->pos.x + p->delta.x * COL_DIST, p->pos.y + p->delta.y * COL_DIST);
    glEnd();
    return;
}

void draw_minimap(graphics_t *rays)
{
    draw_map(&rays->map);
    draw_player(&rays->player);
    draw_player_direction(&rays->player);
    return;
}
