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
#include <math.h>
#include "window.h"
#include "global.h"
#include "lib.h"

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

player_t init_player(void)
{
    player_t player = {0};

    player.delta.x = cos(player.angle) * 5;
    player.delta.y = sin(player.angle) * 5;
    player.pos = (sfVector2f){300, 300};
    return player;
}

int main(void)
{
    game_t game = init_game();
    player_t player = init_player();
    maps_t map = get_map("maps/test_map.txt", "test_map");

    while (sfRenderWindow_isOpen(game.window)) {
        while (sfRenderWindow_pollEvent(game.window, &game.event)) {
            //do events here
            events(&game, &player);
        }
        //display here
        display(&game, &player, &map);
    }
    //free here
    sfRenderWindow_destroy(game.window);
    return 0;
}
