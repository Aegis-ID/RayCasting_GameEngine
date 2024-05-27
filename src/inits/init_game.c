/*
** EPITECH PROJECT, 2024
** init game
** File description:
** CSFML
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/OpenGL.h>

#include <stdlib.h>
#include "game.h"
#include "graphics.h"
#include "gameplay.h"
#include "settings.h"
#include "entities.h"
#include "ui.h"

static window_t init_game_window(display_t *display)
{
    window_t game_window = {0};
    sfRenderWindow *window = &game_window.window;
    sfVideoMode mode = {display->res.x, display->res.y, BITS};

    window =
        sfRenderWindow_create(mode, NAME, sfTitlebar | sfClose, NULL);
    glClearColor(0.5, 0.5, 0.5, 0.5);
    gluOrtho2D(0, display->res.x, display->res.y, 0);
    sfRenderWindow_setVerticalSyncEnabled(window, display->vsync);
    sfRenderWindow_setFramerateLimit(window, display->frames);
    game_window.event = NULL;
    game_window.clock = sfClock_create();
    game_window.elapsed_time = 0;
    return game_window;
}

game_t init_game(void)
{
    game_t game = {0};

    game.game_state = MAIN_MENU;
    game.settings = init_settings();
    game.game_window = init_game_window(&game.settings.display);
    game.entities = init_entities();
    game.graphics = init_graphics();
    game.gameplay = init_gameplay();
    game.ui = init_interface();
    return game;
}
