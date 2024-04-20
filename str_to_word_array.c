/*
** EPITECH PROJECT, 2024
** str_to_word_array
** File description:
** new func
*/

#include "lib.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>

static size_t get_array_size(const char *str, const char *delim)
{
    size_t size = 0;

    for (size_t i = 0; str[i] != '\0'; ++i) {
        if (!is_in_str(str[i], delim) &&
            (is_in_str(str[i + 1], delim) ||
            (str[i + 1] == '\0'))) {
            size += 1;
        }
    }
    return size;
}

static size_t get_str_size(const char *str, const char *delim,
    int unsigned begin)
{
    size_t size = 0;

    for (size_t i = begin; str[i] != '\0'; ++i) {
        if (is_in_str(str[i], delim))
            return size;
        size += 1;
    }
    return size;
}

static void check_begin(const char *str, const char *delim,
    unsigned int *begin)
{
    size_t size = strlen(str);

    if (is_in_str(str[*begin], delim))
        while (is_in_str(str[*begin], delim) && *begin < size)
            *begin += 1;
    return;
}

char **str_to_word_array(const char *str, const char *delim)
{
    size_t size = get_array_size(str, delim);
    char **array = malloc(sizeof(char *) * (size + 1));
    unsigned int begin = 0;
    size_t str_size = 0;

    for (size_t y = 0; y < size; ++y) {
        check_begin(str, delim, &begin);
        str_size = get_str_size(str, delim, begin);
        array[y] = strndup(str + begin, str_size);
        begin += str_size + 1;
    }
    array[size] = 0;
    return array;
}
