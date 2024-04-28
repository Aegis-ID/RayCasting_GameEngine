/*
** EPITECH PROJECT, 2024
** window
** File description:
** Screen settings (change into struct later)
** and retrieve info in a config file)
*/

#ifndef __SETTINGS__
    #define __SETTINGS__
    #include <SFML/System.h>

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

    #define INVALID -1

// Settings structs

typedef struct display_s {
    sfVector2i resolution;
    bool fullscreen;
    bool windowed;
    bool vsync;
    size_t frames;
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
    char *move_forward;
    char *move_backward;
    char *move_left;
    char *move_right;
    //Camera rotation (Keyboard)
    char *look_left;
    char *look_right;
    //Hotbar
    char *hotkey_1;
    char *hotkey_2;
    char *hotkey_3;
    char *hotkey_4;
    char *hotkey_5;
    //Gameplay
    char *interact;
    char *right_hand;
    char *left_hand;
    char *torch;
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

// Funcs

// get_data.c
int get_idata(const char *data, const char **file);
float get_fdata(const char *data, const char **file);
int *get_sdata(const char *data, const char **file);
//check_settings.c
void check_display(display_t *display);
void check_audio(audio_t *audio);
void check_gameplay(gameplay_t *gameplay);
void check_keybinds(keybinds_t *keybinds);
// get_settings.c
settings_t get_settings(void);

#endif /* !__SETTINGS__ */
