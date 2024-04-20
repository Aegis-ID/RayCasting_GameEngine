/*
** EPITECH PROJECT, 2024
** free_array
** File description:
** new funcs
*/

#include <stdlib.h>

void free_array(char **array)
{
    for (size_t y = 0; array[y] != 0; ++y)
        free(array[y]);
    free(array);
}
