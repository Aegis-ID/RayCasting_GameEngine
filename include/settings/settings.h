/*
** EPITECH PROJECT, 2024
** window
** File description:
** Screen settings (change into struct later)
** and retrieve info in a config file)
*/

#ifndef __SETTINGS__
    #define __SETTINGS__
    #include <stdbool.h>

    #define NAME "Aegis Engine"
    #define BITS 64

    // [DISPLAY] --> temporary (in config file)
    #define HEIGHT 720
    #define WIDTH 1280
    #define FRAMES 60
    #define VSYNC 1
    #define FOV 60
    // [GAMEPLAY] --> temporary (in config file)
    #define MAP_S 50
    #define ROT 5

// Settings structs

typedef struct display_s {
    sfVector2i resolution;
    bool windowed;
    bool fullscreen;
    size_t frames;
    bool vsync;
    size_t fov;
}display_t;

typedef struct audio_s {
    float master;
    float vfx;
    float music;
}audio_t;

typedef struct gameplay_s {
    size_t mini_map_size;
    // Camera sensitivity (mouse + keyboard)
    float sensitivity;
}gameplay_t;

typedef struct keybinds_s {
    /*----- EXPLORATION MODE -----*/
    //Movement
    size_t move_forward;
    size_t move_backward;
    size_t move_left;
    size_t move_right;
    //Camera rotation (Keyboard)
    size_t look_left;
    size_t look_right;
    //Hotbar
    size_t hotkey_1;
    size_t hotkey_2;
    size_t hotkey_3;
    size_t hotkey_4;
    size_t hotkey_5;
    //Gameplay
    size_t interact;
    size_t attack;
    size_t shield;
    size_t torch;
    /*----- MANAGEMENT MODE -----*/
    // ...
}keybinds_t;

// Global settings struct

typedef struct settings_s {
    display_t display;
    audio_t audio;
    gameplay_t gameplay;
    keybinds_t keybinds;
}settings_t;

#endif /* !__SETTINGS__ */
