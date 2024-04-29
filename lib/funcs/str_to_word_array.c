/*
** EPITECH PROJECT, 2024
** str_to_word_array
** File description:
** new func
*/

#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

static bool is_in_str(const char c, const char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == c)
            return true;
    return false;
}

static size_t get_array_size(const char *str, const char *delim)
{
    size_t size = 0;

    for (size_t i = 0; str[i] != '\0'; ++i)
        if (!is_in_str(str[i], delim) && (is_in_str(str[i + 1], delim) ||
            (str[i + 1] == '\0')))
            size += 1;
    return size;
}

static size_t get_str_size(const char *str, const char *delim,
    size_t str_pos)
{
    size_t size = 0;

    for (size_t i = str_pos; str[i] != '\0'; ++i) {
        if (is_in_str(str[i], delim))
            return size;
        size += 1;
    }
    return size;
}

static void format_str(const char *str, const char *delim,
    size_t *str_pos)
{
    if (is_in_str(str[*str_pos], delim))
        while (is_in_str(str[*str_pos], delim) && *str_pos < strlen(str))
            *str_pos += 1;
}

char **str_to_word_array(const char *str, const char *delim)
{
    size_t array_size = get_array_size(str, delim);
    char **array = malloc(sizeof(char *) * (array_size + 1));
    size_t str_pos = 0;
    size_t str_size = 0;

    if (array == NULL)
        return NULL;
    for (size_t y = 0; y < array_size; ++y) {
        format_str(str, delim, &str_pos);
        str_size = get_str_size(str, delim, str_pos);
        array[y] = strndup(str + str_pos, str_size);
        str_pos += str_size + 1;
    }
    array[array_size] = 0;
    return array;
}
