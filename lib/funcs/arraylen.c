/*
** EPITECH PROJECT, 2024
** arraylen
** File description:
** new_funcs
*/

#include <stddef.h>

size_t arraylen(char **array)
{
    size_t size = 0;

    while (array[size] != 0)
        size += 1;
    return size;
}
