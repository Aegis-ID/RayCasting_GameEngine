/*
** EPITECH PROJECT, 2024
** get_map
** File description:
** CSFML
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include "ray_casting.h"
#include "lib.h"

static void exit_failure(char **file, const char *error_msg)
{
    dprintf(2, "%s", error_msg);
    free_array(file);
    exit(EXIT_FAILURE);
}

static bool is_str_digit(const char *str)
{
    for (size_t x = 0; str[x] != '\0'; ++x)
        if (!isdigit(str[x]))
            return false;
    return true;
}

static bool check_file_chars(const char **file)
{
    for (size_t y = 0; file[y] != 0; ++y)
        if (!is_str_digit(file[y]))
            return false;
    return true;
}

static bool check_file_lines(const char **file)
{
    size_t size = arraylen(file);
    size_t m_width = atoi(file[1]);
    size_t m_height = atoi(file[0]);

    if ((m_width * m_height) != (size - 2))
        return false;
    return true;
}

static void check_file(char **file)
{
    if (!check_file_chars((const char **)file))
        exit_failure(file, "Only digits and ',' are accepted in the map\n");
    if (!check_file_lines((const char **)file))
        exit_failure(file, "Map lines differ from specified\n");
    return;
}

static int *char_to_int_map(const char **char_map)
{
    int *int_map = malloc(sizeof(int) * arraylen(char_map));

    for (size_t y = 0; char_map[y] != 0; ++y)
        int_map[y] = atoi(char_map[y]);
    return int_map;
}

maps_t get_map(const char *filepath, const char *map_name)
{
    maps_t map = {0};
    char **char_map = file_to_array(filepath, ",\n\t");
    int *int_map = NULL;

    check_file(char_map);
    int_map = char_to_int_map((const char **)char_map + 2);
    map.m_name = map_name;
    map.map_ht = atoi(char_map[0]);
    map.map_wd = atoi(char_map[1]);
    map.map = int_map;
    map.next = NULL;
    free_array(char_map);
    return map;
}
