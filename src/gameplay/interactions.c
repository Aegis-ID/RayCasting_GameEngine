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

static void door_action(keybinds_t *keybinds, collisions_t *col, int *walls)
{
    enum texture_type;

    if (sfKeyboard_isKeyPressed(keybinds->interact) && (col->front_wall == DOOR))
        if ((col->front <= (COL_DIST * INTERACTION_DIST)))
            walls[col->front_wall_pos] = 0;
    return;
}

static void int_key_action(keybinds_t *keybinds, collisions_t *col, int *walls)
{
    door_action(keybinds, &col, walls);
    return;
}

static void map_action(keybinds_t *keybinds, gameplay_t *gameplay)
{
    if (sfKeyboard_isKeyPressed(keybinds->map))
        if (gameplay->minimap == false)
            gameplay->minimap = true;
        else
            gameplay->minimap = false;
    return;
}

static void left_hand_action(keybinds_t *keybinds, gameplay_t *gameplay)
{
    if (sfMouse_isButtonPressed(keybinds->left_hand))
        printf("left_click\n");
    return;
}

static void right_hand_action(keybinds_t *keybinds, gameplay_t *gameplay)
{
    if (sfMouse_isButtonPressed(keybinds->right_hand))
        gameplay->r_hand = true;
    return;
}

void player_actions(keybinds_t *keybinds, gameplay_t *gameplay, entity_t *player)
{
    left_hand_action(keybinds, gameplay);
    right_hand_action(keybinds, gameplay);
    int_key_action(keybinds, &player->collisions, &gameplay->map.walls);
    map_action(keybinds, gameplay);
    return;
}
