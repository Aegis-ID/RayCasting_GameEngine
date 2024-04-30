/*
** EPITECH PROJECT, 2024
** raycasting project
** File description:
** for myrpg
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "game/funcs.h"
#include "ray_casting/structs.h"

int main(void)
{
    game_t game = init_game();
    ray_casting_t rc_mode = init_rc_mode();

    while (sfRenderWindow_isOpen(game.window)) {
        while (sfRenderWindow_pollEvent(game.window, &game.event))
            events(&game, &rc_mode);
        display(&game, &rc_mode);
    }
    sfRenderWindow_destroy(game.window);
    return 0;
}
