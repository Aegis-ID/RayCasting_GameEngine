/*
** EPITECH PROJECT, 2024
** p interact.c
** File description:
** RPG
*/

#include <stdio.h>

#include <SFML/System.h>

#include "entities.h"

#include "game.h"

static void door_interaction(
    keybinds_t *keybinds, collisions_t *col, int *walls)
{
    enum texture_type;

    if (sfKeyboard_isKeyPressed(keybinds->interact) &&
        (col->front_wall == DOOR)) {
        if ((col->front <= (COL_DIST * INTERACTION_DIST)))
            walls[col->front_wall_pos] = 0;
    }
    return;
}

static void int_key_interaction(game_t *game, graphics_t *rays)
{
    keybinds_t *keybinds = &game->settings.keybinds;
    collisions_t col =
        get_collisions(&rays->player, &rays->map);

    door_interaction(keybinds, &col, rays->map.walls);
    return;
}

static void map_interaction(
    keybinds_t *keybinds, gameplay_t *gameplay)
{
    if (sfKeyboard_isKeyPressed(keybinds->map)) {
        if (gameplay->mini_map == false)
            gameplay->mini_map = true;
        else
            gameplay->mini_map = false;
    }
    return;
}

static void left_hand_interaction(
    keybinds_t *keybinds, gameplay_t *gameplay)
{
    if (sfMouse_isButtonPressed(keybinds->left_hand))
        printf("left_click\n");
    return;
}

static void right_hand_interaction(
    keybinds_t *keybinds, gameplay_t *gameplay)
{
    if (sfMouse_isButtonPressed(keybinds->right_hand))
        gameplay->r_hand = true;
    return;
}

void player_interactions(game_t *game, graphics_t *rays)
{
    keybinds_t *keybinds = &game->settings.keybinds;
    gameplay_t *gameplay = &game->gameplay;

    left_hand_interaction(keybinds, gameplay);
    right_hand_interaction(keybinds, gameplay);
    int_key_interaction(game, rays);
    map_interaction(keybinds, gameplay);
    return;
}
