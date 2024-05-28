/*
** EPITECH PROJECT, 2024
** display_exploration;c
** File description:
** CSFML
*/

#include <stdio.h>


#include "game.h"
#include "entities.h"

static void interactions_display(game_t *game, graphics_t *rays)
{
    gameplay_t *gameplay = &game->gameplay;

    if (gameplay->mini_map)
        draw_minimap(rays);
    return;
}

void display_exploration(game_t *game, graphics_t *rays)
{
    draw_sky(game->settings.display.res, rays->player.angle,
        CONST_SHADE * BRIGHTNESS);
    ray_casting(rays, game->settings.display.res,
        game->settings.display.fov);
    interactions_display(game, rays);
    return;
}
