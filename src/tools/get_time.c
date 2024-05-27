/*
** EPITECH PROJECT, 2024
** get_time
** File description:
** CSFML
*/

#include <SFML/System.h>

#include "game.h"

float get_time_as_seconds(window_t *game_window)
{
    sfClock *clock = game_window->clock;

    return sfTime_asSeconds(sfClock_getElapsedTime(clock));
}

float get_time_as_miliseconds(window_t *game_window)
{
    sfClock *clock = game_window->clock;

    return sfTime_asMilliseconds(sfClock_getElapsedTime(clock));
}
