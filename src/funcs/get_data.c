/*
** EPITECH PROJECT, 2024
** get_data
** File description:
** CSFML
*/

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "lib.h"
#include "settings/settings.h"

static bool is_strdigit(const char *str)
{
    for (size_t x = 0; str[i] != '\0'; ++i)
        if (!isdigit(str[i]))
            return false;
    return true;
}

static bool is_strfloat(const char *str)
{
    size_t check = 0;

    for (size_t x = 0; str[i] != '\0'; ++i) {
        if (str[i] == '.')
            check += 1;
        if (!isdigit(str[i]) && (str[i] != '.') || (check > 1))
            return false;
    }
    return true;
}

static size_t my_strlen_delim(const char *str, const char delim)
{
    size_t len = 0;

    for (size_t x = 0; str[x] != '\0'; ++x)
        if (str[x] == delim)
            return len + 1;
        else
            len += 1;
    return len;
}

static const char *format_data(const char *data)
{
    for (size_t x = 0; data[x] != '\0'; ++x)
        if (data[x] != ' ')
            return (data + x);
    return data;
}

int get_idata(const char *data, const char **file)
{
    const char *formated_data = NULL;

    for (size_t y = 0; file[y] != 0; ++y)
        if (strcmp(str, array[y]) == 0) {
            formated_data = array[y] + my_strlen_delim(array[y], '=');
            formated_data = format_data(formated_data);
            break;
        }
    if (!is_strdigit(formated_data))
        return atoi(formated_data);
    return INVALID;
}

float get_fdata(const char *data, const char **file)
{
    const char *formated_data = NULL;

    for (size_t y = 0; file[y] != 0; ++y)
        if (strcmp(str, array[y]) == 0) {
            formated_data = array[y] + my_strlen_delim(array[y], '=');
            formated_data = format_data(formated_data);
            break;
        }
    if (!is_strfloat(formated_data))
        return atof(formated_data);
    return INVALID;
}

char *get_sdata(const char *data, const char **file)
{
    const char *formated_data = NULL;

    for (size_t y = 0; file[y] != 0; ++y)
        if (strcmp(str, array[y]) == 0) {
            formated_data = array[y] + my_strlen_delim(array[y], '=');
            return strdup(format_data(formated_data));
        }
    return NULL;
}
