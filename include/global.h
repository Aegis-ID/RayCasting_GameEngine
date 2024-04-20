/*
** EPITECH PROJECT, 2024
** global
** File description:
** CSFML
*/

#ifndef __GLOBAL__
    #define __GLOBAL__
    #include <SFML/Graphics.h>

typedef struct player_s {
    sfVector2f pos;
    sfCircleShape *circle;
} player_t;

typedef struct game_s {
    sfRenderWindow *window;
    sfEvent event;
}game_t;

enum GAME_MODE {
    MAIN_MENU,
    REST,
    EXPLORATION,
    COMBAT
};

void events(game_t *game, player_t *player);
void display(game_t *game, player_t *player);

#endif /* !__GLOBAL__ */
