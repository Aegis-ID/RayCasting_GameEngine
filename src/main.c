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
        while (sfRenderWindow_pollEvent(game.window, &game.event)) {
            //do events here
            events(&game, &rc_mode);
        }
        //display here
        display(&game, &rc_mode);
    }
    //free here
    sfRenderWindow_destroy(game.window);
    return 0;
}
