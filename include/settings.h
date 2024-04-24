/*
** EPITECH PROJECT, 2024
** window
** File description:
** Screen settings (change into struct later,
** and retrieve info in a config file)
*/

#ifndef __SETTINGS__
    #define __SETTINGS__

    #define NAME "Aegis Engine"

    #define HEIGHT 720
    #define WIDTH 1280
    #define BITS 64

    #define FRAMES 60
    #define VSYNC 1

typedef struct game_s {
    sfRenderWindow *window;
    sfEvent event;
    sfClock *clock;
}game_t;

enum GAME_MODE {
    MAIN_MENU,
    MANAGEMENT,
    EXPLORATION
};

#endif /* !__SETTINGS__ */
