/*
** EPITECH PROJECT, 2024
** check_settings
** File description:
** CSFML
*/

#include <string.h>
#include <stdbool.h>
#include "lib.h"
#include "settings/bindings.h"
#include "settings/settings.h"

void check_display(display_t *dp)
{
    if ((dp->resolution.y == INVALID) || (dp->resolution.x == INVALID))
        dp->resolution = (sfVector2i){800, 600};
    if (dp->frames == INVALID)
        dp->frames = 60;
    if (dp->fov == INVALID)
        dp->fov = 60;
    return;
}

void check_audio(audio_t *audio)
{
    if (audio->master == INVALID)
        audio->master = 50;
    else if (audio->master > 100)
        audio->master = 100;
    if ((audio->vfx == INVALID) || (audio->vfx > 100))
        audio->vfx = 100;
    if ((audio->music == INVALID) || (audio->music > 100))
        audio->music = 100;
    return;
}

void check_gameplay(gameplay_t *gameplay)
{
    if (gameplay->mini_map_size == INVALID)
        gameplay->mini_map_size = 25;
    if (gameplay->sensitivity == INVALID)
        gameplay->sensitivity = 1;
    return;
}

static void check_mvt_keys(keybinds_t *kb)
{
    if (kb->move_forward == INVALID)
        kb->move_forward = get_sfkey("Z");
    if (kb->move_backward == INVALID)
        kb->move_backward = get_sfkey("S");
    if (kb->move_left == INVALID)
        kb->move_left = get_sfkey("Q");
    if (kb->move_right == INVALID)
        kb->move_right = get_sfkey("D");
    if (kb->look_left == INVALID)
        kb->look_left = get_sfkey("LeftKey");
    if (kb->look_right == INVALID)
        kb->look_right = get_sfkey("RightKey");
    return;
}

static void check_hotbar_keys(keybinds_t *kb)
{
    if (kb->hotkey_1 == INVALID)
        kb->hotkey_1 = get_sfkey("1");
    if (kb->hotkey_2 == INVALID)
        kb->hotkey_2 = get_sfkey("2");
    if (kb->hotkey_3 == INVALID)
        kb->hotkey_3 = get_sfkey("3");
    if (kb->hotkey_4 == INVALID)
        kb->hotkey_4 = get_sfkey("4");
    if (kb->hotkey_5 == INVALID)
        kb->hotkey_5 = get_sfkey("5");
    return;
}

static void check_gameplay_keys(keybinds_t *kb)
{
    if (kb->interact == INVALID)
        kb->interact = get_sfkey("E");
    if (kb->right_hand == INVALID)
        kb->right_hand = get_sfmouse("RMB");
    if (kb->left_hand == INVALID)
        kb->left_hand = get_sfmouse("LMB");
    if (kb->torch == INVALID)
        kb->torch = get_sfkey("F");
    return;
}

void check_keybinds(keybinds_t *kb)
{
    check_mvt_keys(kb);
    check_hotbar_keys(kb);
    check_gameplay_keys(kb);
    return;
}
