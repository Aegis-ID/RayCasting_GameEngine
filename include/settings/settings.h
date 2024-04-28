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

    #define INVALID -1

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
    int mini_map_size;
    // Camera sensitivity (mouse + keyboard)
    float sensitivity;
}gameplay_t;

typedef struct keybinds_s {
    /*----- EXPLORATION MODE -----*/
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

/* ----- FUNCS ----- */
//get_bindings.c
int get_sfkey(const char *str);
int get_sfmouse(const char *str);
// get_data.c
bool get_bdata(const char *data, char **file);
int get_idata(const char *data, char **file);
float get_fdata(const char *data, char **file);
int get_sdata(const char *data, char **file);
//check_settings.c
void check_display(display_t *display);
void check_audio(audio_t *audio);
void check_gameplay(gameplay_t *gameplay);
void check_keybinds(keybinds_t *keybinds);
// get_settings.c
settings_t get_settings(void);

#endif /* !__SETTINGS__ */
