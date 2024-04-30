/*
** EPITECH PROJECT, 2024
** p interact.c
** File description:
** RPG
*/

#include "ray_casting/funcs.h"
#include "textures/structs.h"

void player_interactions(game_t *game, player_t *player, maps_t *m)
{
    collisions_t col = get_collisions(player, game->settings.gameplay.map_s);
    enum texture_type;
    int interact = game->settings.keybinds.interact;

    if (sfKeyboard_isKeyPressed(interact)) {
        if (m->walls[col.offset_add.y * m->width + col.offset_add.x] == DOOR) {
            m->walls[col.offset_add.y * m->width + col.offset_add.x] = 0;
        }
    }
}
