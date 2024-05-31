/*
** EPITECH PROJECT, 2024
** display_exploration;c
** File description:
** CSFML
*/

#include <stdio.h>

#include "game.h"
#include "entities.h"

static void interactions_display(
    const gameplay_t *gameplay, const entity_t *player)
{
    if (gameplay->minimap)
        draw_minimap(gameplay->map, player);
    return;
}

void display_exploration(game_t *game, graphics_t *graphics)
{
    entity_t *player = game->entities[PLAYER];
    map_t *map = &game->gameplay.map;
    float fov = game->settings.display.fov;

    graphics->res = game->settings.display.res;
    draw_sky(graphics->res, player->angle, CONST_SHADE * BRIGHTNESS);
    ray_casting(graphics, player, map, fov);
    interactions_display(&game->gameplay, player);
    return;
}
