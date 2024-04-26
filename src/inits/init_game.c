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
    sfRenderWindow *window = init_game_window();
    sfEvent event = {0};
    sfClock *clock = sfClock_create();
    game.window = window;
    game.event = event;
    game.clock = clock;
    return game;
}
