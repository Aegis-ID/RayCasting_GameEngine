/*
** EPITECH PROJECT, 2024
** get_data
** File description:
** CSFML
*/

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "lib.h"
#include "settings/settings.h"

static char *format_data(char *data_line)
{
    data_line = clean_str(data_line, ' ');
    return data_line + my_strlen_delim(data_line, '=');
}

static bool check_data(const char *data, const char *data_line)
{
    size_t n = my_strlen_delim(data_line, '=');

    if (strncmp(data, data_line, n) == 0)
        return true;
    return false;
}

bool get_bdata(const char *data, char **file)
{
    char *data_line = NULL;

    for (size_t y = 0; file[y] != 0; ++y)
        if (check_data(data, clean_str(file[y], ' '))) {
            data_line = format_data(file[y]);
            break;
        }
    if (atoi(data_line) == 1)
        return true;
    return false;
}

int get_idata(const char *data, char **file)
{
    char *data_line = NULL;

    for (size_t y = 0; file[y] != 0; ++y)
        if (check_data(data, clean_str(file[y], ' '))) {
            data_line = format_data(file[y]);
            break;
        }
    if (!is_strdigit(data_line))
        return atoi(data_line);
    return INVALID;
}

float get_fdata(const char *data, char **file)
{
    char *data_line = NULL;

    for (size_t y = 0; file[y] != 0; ++y)
        if (check_data(data, clean_str(file[y], ' '))) {
            data_line = format_data(file[y]);
            break;
        }
    if (!is_strfloat(data_line))
        return atof(data_line);
    return INVALID;
}

int get_sdata(const char *data, char **file)
{
    char *data_line = NULL;
    int sfmouse = 0;
    int sfkey = 0;

    for (size_t y = 0; file[y] != 0; ++y)
        if (check_data(data, clean_str(file[y], ' '))) {
            data_line = format_data(file[y]);
            break;
        }
    sfmouse = get_sfmouse(data_line);
    sfkey = get_sfkey(data_line);
    if (sfmouse != INVALID)
        return sfmouse;
    return sfkey;
}
