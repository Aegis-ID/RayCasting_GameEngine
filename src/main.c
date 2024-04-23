/*
** EPITECH PROJECT, 2024
** raycasting project
** File description:
** for myrpg
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/OpenGL.h>
#include <math.h>
#include "global.h"
#include "settings.h"
#include "lib.h"

sfRenderWindow *init_game_window(void)
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

player_t init_player(void)
{
    player_t player = {0};

    player.pos = (sfVector2f){50, 50};
    player.angle = 90;
    player.delta.x = cos(deg_to_rad(player.angle)) * 5;
    player.delta.y = -sin(deg_to_rad(player.angle)) * 5;
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
            events(&game, &player, &map);
        }
        //display here
        display(&game, &player, &map);
    }
    //free here
    sfRenderWindow_destroy(game.window);
    return 0;
}
