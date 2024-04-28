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
    if ((dp->fullscreen == INVALID) || dp->fullscreen > 1)
        dp->fullscreen = 0;
    if ((dp->windowed == INVALID) || (dp->windowed > 1))
        dp->windowed = 0;
    if ((dp->vsync == INVALID) || (dp->vsync > 1))
        dp->vsync = 0;
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

void check_keybinds(keybinds_t *keybinds)
{
    return;
}
