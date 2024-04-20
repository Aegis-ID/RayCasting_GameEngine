/*
** EPITECH PROJECT, 2024
** array_strlen
** File description:
** CSFML
*/

#include <stddef.h>
#include <string.h>

size_t array_lstrlen(const char **array)
{
    size_t size = 0;

    for (size_t y = 0; array[y] != 0; ++y)
        if (strlen(array[y]) >= size)
            size = strlen(array[y]);
    return size;
}
