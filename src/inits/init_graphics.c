/*
** EPITECH PROJECT, 2024
** init_rays
** File description:
** CSFML
*/

#include <math.h>

#include "lib.h"
#include "game.h"
#include "graphics.h"

static graphics_t init_graphics(void)
{
    graphics_t graphics = {0};

    graphics.player = init_player();
    graphics.map = init_map(MAP_FILE);

    return graphics;
}
