/*
** EPITECH PROJECT, 2024
** my_strlen_delim
** File description:
** new_funcs
*/

#include <stddef.h>

size_t my_strlen_delim(const char *str, const char delim)
{
    size_t len = 0;

    for (size_t x = 0; str[x] != '\0'; ++x)
        if (str[x] == delim)
            return len;
        else
            len += 1;
    return len;
}
