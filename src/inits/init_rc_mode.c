/*
** EPITECH PROJECT, 2024
** init_rc_mode
** File description:
** CSFML
*/

#include <math.h>
#include "lib.h"
#include "ray_casting.h"

static player_t init_player(void)
{
    player_t player = {0};

    player.pos = (sfVector2f){225, 225};
    player.angle = 90;
    player.delta.x = cos(deg_to_rad(player.angle)) * 5;
    player.delta.y = -sin(deg_to_rad(player.angle)) * 5;
    return player;
}

ray_casting_t init_rc_mode(void)
{
    ray_casting_t rc_mode = {0};

    rc_mode.player = init_player();
    rc_mode.maps = get_map("maps/test_map.txt", "test_map");
    return rc_mode;
}
