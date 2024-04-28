/*
** EPITECH PROJECT, 2024
** is_str_float
** File description:
** new funcs
*/

#include <ctype.h>
#include <stdbool.h>
#include <stddef.h>

bool is_strfloat(const char *str)
{
    size_t check = 0;

    for (size_t i = 0; str[i] != '\0'; ++i) {
        if (str[i] == '.')
            check += 1;
        if ((!isdigit(str[i]) && (str[i] != '.')) || ((check > 1)))
            return false;
    }
    return true;
}
