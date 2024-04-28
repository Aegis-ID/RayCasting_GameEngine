/*
** EPITECH PROJECT, 2024
** str_to_sfkey.c
** File description:
** CSFML
*/

#include <string.h>
#include "settings/keys.h"
#include "settings/settings.h"

int get_sfkey(const char *str)
{
    for (size_t i = 0; KEYS_CODE[i] != NULL; ++i)
        if (strcmp(str, KEYS_CODE[i]) == 0)
            return i;
    return INVALID;
}

int get_sfmouse(const char *str)
{
    for (size_t i = 0; MOUSE_CODE[i] != NULL; ++i)
        if (strcmp(str, MOUSE_CODE[i]) == 0)
            return i;
    return INVALID;
}
