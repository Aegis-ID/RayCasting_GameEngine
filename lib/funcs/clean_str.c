/*
** EPITECH PROJECT, 2024
** clean_str
** File description:
** new funcs
*/

#include <stddef.h>

char *clean_str(char *str, const char clean)
{
    size_t size = 0;

    for (size_t i = 0; str[i] != '\0'; ++i) {
        if (str[i] != clean) {
            str[size] = str[i];
            size += 1;
        }
    }
    str[size] = '\0';
    return str;
}
