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

    #define INVALID -1

typedef struct display_s {
    sfVector2i res;
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

typedef struct keybinds_s {
    // Camera sensitivity (mouse + keyboard)
    float sensitivity;
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
    int map;
}keybinds_t;

typedef struct settings_s {
    display_t display;
    audio_t audio;
    keybinds_t keybinds;
}settings_t;

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
void check_keybinds(keybinds_t *keybinds);

// init_settings.c
settings_t init_settings(void);

#endif /* !__SETTINGS_STRUCTS__ */
