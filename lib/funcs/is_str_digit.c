/*
** EPITECH PROJECT, 2024
** is_str_digit
** File description:
** new funcs
*/

#include <ctype.h>
#include <stdbool.h>
#include <stddef.h>

bool is_strdigit(const char *str)
{
    for (size_t i = 0; str[i] != '\0'; ++i)
        if (!isdigit(str[i]))
            return false;
    return true;
}
