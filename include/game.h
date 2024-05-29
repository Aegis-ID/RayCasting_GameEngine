/*
** EPITECH PROJECT, 2024
** game
** File description:
** RPG
*/

#ifndef __GAME__
    #define __GAME__

    #include "graphics.h"
    #include "gameplay.h"
    #include "settings.h"
    #include "entities.h"
    #include "ui.h"

    #define MAP_FILE "maps/map.txt"

    #define NAME "Aegis Engine"

    #define BITS 64

    #define TICKS 0.02f

enum game_state_list {
    MAIN_MENU,
    MANAGEMENT,
    EXPLORATION
};

typedef struct window_s {
    sfRenderWindow *window;
    sfEvent *event;
    sfClock *clock;
    double elapsed_time;
}window_t;

typedef struct game_s {
    size_t game_state;
    settings_t settings;
    window_t game_window;
    entity_t **entities;
    graphics_t graphics;
    gameplay_t gameplay;
    ui_t ui;
}game_t;

// Inits
game_t init_game(void);

// Main functions
void events(game_t *game);
void display(game_t *game);

// Tools
float get_time_as_seconds(window_t *game_window);
float get_time_as_miliseconds(window_t *game_window);
float get_ratio(sfVector2i vector);
float get_fov(sfVector2i res, float default_fov);

// Player Movements
void player_movement(window_t *game_window, keybinds_t *keybinds, entity_t *player);
void mouse_rotation(window_t *game_window, keybinds_t *k, entity_t *p, const float fov);

// Player Actions
void player_actions(keybinds_t *keybinds, gameplay_t *gameplay, entity_t *player);


#endif /* !__GAME__ */
