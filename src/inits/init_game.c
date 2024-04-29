/*
** EPITECH PROJECT, 2024
** init game
** File description:
** CSFML
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/OpenGL.h>
#include "game/funcs.h"
#include "settings/funcs.h"

static sfRenderWindow *init_game_window(display_t *display)
{
    sfVideoMode mode = {display->resolution.x, display->resolution.y, BITS};
    sfRenderWindow *window = sfRenderWindow_create(mode, NAME,
        sfTitlebar | sfClose, NULL);
    //OpenGL
    glClearColor(0.3, 0.3, 0.3, 0);
    gluOrtho2D(0, display->resolution.x, display->resolution.y, 0);
    //SFML
    sfRenderWindow_setVerticalSyncEnabled(window, display->vsync);
    sfRenderWindow_setFramerateLimit(window, display->frames);
    return window;
}

game_t init_game(void)
{
    game_t game = {0};

    game.settings = get_settings();
    game.window = init_game_window(&game.settings.display);
    game.event = (sfEvent){0};
    game.clock = sfClock_create();
    return game;
}
