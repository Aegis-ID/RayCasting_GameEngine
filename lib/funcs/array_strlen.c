/*
** EPITECH PROJECT, 2024
** array_strlen
** File description:
** CSFML
*/

#include <stddef.h>
#include <string.h>

size_t array_strlen(const char **array)
{
    size_t size = 0;

    for (size_t y = 0; array[y] != 0; ++y)
        for (size_t x = 0; array[y][x] != '\0'; ++x)
            size += 1;
    return size;
}
