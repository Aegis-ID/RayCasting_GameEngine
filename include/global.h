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
    sfRectangleShape *rect;
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

char **get_map(const char *filepath);
void free_array(char **array);

void events(game_t *game, player_t *player);
void display(game_t *game, player_t *player);

sfCircleShape *set_circle(sfVector2f p_pos, float radius, sfColor color);
sfRectangleShape *set_rect(sfVector2f pos, sfVector2f size, sfColor color);

#endif /* !__GLOBAL__ */
