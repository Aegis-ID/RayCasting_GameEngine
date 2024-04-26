/*
** EPITECH PROJECT, 2024
** game
** File description:
** RPG
*/

#ifndef __GAME__
    #define __GAME__
    #include "settings/settings.h"
    #include "ray_casting.h"

enum GAME_MODE {
    MAIN_MENU,
    MANAGEMENT,
    EXPLORATION,
    DEATH_MENU
};

typedef struct game_s {
    settings_t settings;
    sfRenderWindow *window;
    sfEvent event;
    sfClock *clock;
}game_t;

//inits
game_t init_game(void);
ray_casting_t init_rc_mode(void);

//Main functions
void events(game_t *game, ray_casting_t *rc_mode);
void display(game_t *game, ray_casting_t *rc_mode);

#endif /* !__GAME__ */
