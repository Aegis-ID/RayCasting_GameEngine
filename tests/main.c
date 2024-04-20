/*
** EPITECH PROJECT, 2024
** raycasting project
** File description:
** for myrpg
*/

#include <stdio.h>

char **str_to_word_array(const char *str, const char *delim);

int main()
{
    char *str = "Je suis Iron Man\n";
    char **array = str_to_word_array(str, " \n\t");

    for (size_t y = 0; array[y] != 0; ++y)
        printf("%s\n", array[y]);
    return 0;
}