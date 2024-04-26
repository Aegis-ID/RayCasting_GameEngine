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

    #define ROT 5

typedef struct audio_s {
    float master;
    float vfx;
    float music;
}audio_t;

typedef struct gameplay_s {
    size_t fov;
    size_t mini_map_size;
    float rotation;
}gameplay_t;

typedef struct keybinds_s {
    //player movement
    int move_forward;
    int move_backward;
    int move_left;
    int move_right;
    //player rotation
    int look_left;
    int look_right;
}keybinds_t;

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
