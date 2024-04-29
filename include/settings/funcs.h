/*
** EPITECH PROJECT, 2024
** settings
** File description:
** CSFML
*/

#ifndef __SETTINGS__
    #define __SETTINGS__

    #include <stdbool.h>
    #include "settings/structs.h"

    #define INVALID -1

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
