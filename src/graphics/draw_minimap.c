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
#include "entities.h"
#include "gameplay.h"

static void draw_cell(sfVector2i *offset)
{
    glBegin(GL_QUADS);
    glVertex2i(offset->x + 1, offset->y + 1);
    glVertex2i(
        offset->x + 1,
        offset->y + MAP_RATIO - 1);
    glVertex2i(
        offset->x + MAP_RATIO - 1,
        offset->y + MAP_RATIO - 1);
    glVertex2i(
        offset->x + MAP_RATIO - 1,
        offset->y + 1);
    glEnd();
    return;
}

static void colorize_cell(int cell)
{
    if (is_wall(cell))
        glColor3f(1, 1, 1);
    else
        glColor3f(0, 0, 0);
    return;
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

static void draw_player(entity_t *player)
{
    glColor3f(1, 1, 0);
    glPointSize(8);
    glLineWidth(4);
    glBegin(GL_POINTS);
    glVertex2i(player->pos.x, player->pos.y);
    glEnd();
    return;
}

static void draw_player_direction(entity_t *player)
{
    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2i(player->pos.x, player->pos.y);
    glVertex2i(
        player->pos.x + player->delta.x * COL_DIST,
        player->pos.y + player->delta.y * COL_DIST);
    glEnd();
    return;
}

void draw_minimap(const map_t *map, const entity_t *player)
{
    draw_map(map);
    draw_player(player);
    draw_player_direction(player);
    return;
}
