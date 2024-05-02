/*
** EPITECH PROJECT, 2024
** window
** File description:
** Screen settings (change into struct later)
** and retrieve info in a config file)
*/

#ifndef __SETTINGS_STRUCTS__
    #define __SETTINGS_STRUCTS__

    #include <SFML/System.h>
    #include <stdbool.h>

// Settings structs

typedef struct display_s {
    sfVector2i resolution;
    bool fullscreen;
    bool windowed;
    bool vsync;
    int frames;
    int fov;
}display_t;

typedef struct audio_s {
    float master;
    float vfx;
    float music;
}audio_t;

typedef struct gameplay_s {
    // Mini map size (may be optionnal)
    int map_s;
    // Camera sensitivity (mouse + keyboard)
    float sensitivity;
}gameplay_t;

typedef struct keybinds_s {
    //Movement
    int move_forward;
    int move_backward;
    int move_left;
    int move_right;
    //Camera rotation (Keyboard)
    int look_left;
    int look_right;
    //Hotbar
    int hotkey_1;
    int hotkey_2;
    int hotkey_3;
    int hotkey_4;
    int hotkey_5;
    //Gameplay
    int interact;
    int right_hand;
    int left_hand;
    int torch;
}keybinds_t;

// Global settings struct

typedef struct settings_s {
    display_t display;
    audio_t audio;
    gameplay_t gameplay;
    keybinds_t keybinds;
}settings_t;

#endif /* !__SETTINGS_STRUCTS__ */
