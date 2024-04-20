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

sfCircleShape *set_circle(sfVector2f p_pos, float radius, sfColor color)
{
    sfCircleShape *circle = sfCircleShape_create();

    sfCircleShape_setRadius(circle, radius);
    sfCircleShape_setFillColor(circle, color);
    sfCircleShape_setOrigin(circle, p_pos);
    return circle;
}

player_t init_player(void)
{
    player_t player;
    sfVector2f p_pos = (sfVector2f){WIDTH / 2, HEIGHT / 2};
    sfCircleShape *circle = set_circle(p_pos, 20, sfWhite);

    player.pos = p_pos;
    player.circle = circle;
    return player;
}

game_t init_game(void)
{
    game_t game;
    sfVideoMode mode = {WIDTH, HEIGHT, BITS};
    sfRenderWindow *window = sfRenderWindow_create(mode, NAME, sfDefaultStyle, NULL);
    sfEvent event = {0};

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
