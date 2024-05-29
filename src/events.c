/*
** EPITECH PROJECT, 2024
** events
** File description:
** CSFML
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/OpenGL.h>

#include "game.h"
#include "gameplay.h"

static void exploration_events(game_t *game)
{
    window_t *game_window = &game->game_window;

    sfRenderWindow_setMouseCursorVisible(game_window->window, false);
    game_window->elapsed_time = get_time_as_seconds(game_window->clock);
    if (game_window->elapsed_time >= TICKS) {
        sfClock_restart(game_window->clock);
        player_movement(game);
        player_actions(game);
    }
    return;
}

void events(game_t *game)
{
    sfRenderWindow *window = game->game_window.window;
    sfEvent *event = game->game_window.event;

    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        sfRenderWindow_close(window);
    if (event->type == sfEvtResized)
        glViewport(0, 0, event->size.width, event->size.height);
    if (game->game_state == EXPLORATION)
        exploration_events(game);
    return;
}
