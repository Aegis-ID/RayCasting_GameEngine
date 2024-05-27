/*
** EPITECH PROJECT, 2024
** raycasting project
** File description:
** for myrpg
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>

#include "game.h"

int main(void)
{
    game_t game = init_game();
    sfRenderWindow *window = &game.game_window.window;
    sfEvent *event = &game.game_window.event;

    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, event))
            events(&game);
        display(&game);
    }
    sfRenderWindow_destroy(window);
    return 0;
}
