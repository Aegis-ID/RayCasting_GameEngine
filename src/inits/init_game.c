/*
** EPITECH PROJECT, 2024
** init game
** File description:
** CSFML
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/OpenGL.h>
#include "game.h"

static sfRenderWindow *init_game_window(void)
{
    sfVideoMode mode = {WIDTH, HEIGHT, BITS};
    sfRenderWindow *window = sfRenderWindow_create(mode, NAME,
        sfTitlebar | sfClose, NULL);
    //OpenGL
    glClearColor(0.3, 0.3, 0.3, 0);
    gluOrtho2D(0, WIDTH, HEIGHT, 0);
    //SFML
    sfRenderWindow_setFramerateLimit(window, FRAMES);
    sfRenderWindow_setVerticalSyncEnabled(window, VSYNC);
    return window;
}

game_t init_game(void)
{
    game_t game = {0};

    game.settings = get_settings();
    game.window = init_game_window();
    game.event = {0};
    game.clock = sfClock_create();
    return game;
}
