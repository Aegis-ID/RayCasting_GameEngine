/*
** EPITECH PROJECT, 2024
** game_structs
** File description:
** CSFML
*/

#ifndef __GAME_STRUCTS__
    #define __GAME_STRUCTS__

    #include <SFML/System.h>
    #include "settings/structs.h"

enum GAME_MODE {
    MAIN_MENU,
    LEVEL_EDITOR,
    MANAGEMENT,
    EXPLORATION
};

typedef struct game_s {
    settings_t settings;
    sfRenderWindow *window;
    sfEvent event;
    sfClock *clock;
    size_t game_state;
}game_t;

#endif /* !__GAME_STRUCTS__ */
