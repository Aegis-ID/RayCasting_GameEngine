/*
** EPITECH PROJECT, 2024
** raycasting project
** File description:
** for myrpg
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/OpenGL.h>
#include <stdio.h>
#include "window.h"
#include "global.h"
#include <math.h>

player_t init_player(void)
{
    player_t player = {0};
    sfVector2f p_pos = (sfVector2f){WIDTH / 2, HEIGHT / 2};
    sfVector2f size = (sfVector2f){5, 5};
    sfRectangleShape *rect = set_rect(p_pos, size, sfYellow);

    player.delta.x = cos(player.angle) * 5;
    player.pos = p_pos;
    player.rect = rect;
    return player;
}

game_t init_game(void)
{
    game_t game = {0};
    sfVideoMode mode = {WIDTH, HEIGHT, BITS};
    sfRenderWindow *window = sfRenderWindow_create(mode, NAME, sfDefaultStyle, NULL);
    sfEvent event = {0};

    //OpenGL
    glClearColor(0.3, 0.3, 0.3, 0);
    gluOrtho2D(0, WIDTH, HEIGHT, 0);
    //SFML
    sfRenderWindow_setFramerateLimit(window, FRAMES);
    sfRenderWindow_setVerticalSyncEnabled(window, VSYNC);
    game.window = window;
    game.event = event;
    return game;
}

int main(void)
{
    game_t game = init_game();
    player_t player = init_player();

    while (sfRenderWindow_isOpen(game.window)) {
        while (sfRenderWindow_pollEvent(game.window, &game.event)) {
            //do events here
            events(&game, &player);
        }
        //display here
        display(&game, &player);
        printf("x: %f -- y: %f\n", player.pos.x, player.pos.y);
    }
    //free here
    sfRenderWindow_destroy(game.window);
    return 0;
}
