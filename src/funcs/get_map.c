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
#include "lib.h"
#include "ray_casting/structs.h"

static void exit_failure(char **file, const char *error_msg)
{
    dprintf(2, "%s", error_msg);
    free_array(file);
    exit(EXIT_FAILURE);
}

static bool check_file_chars(const char **file)
{
    for (size_t y = 0; file[y] != 0; ++y)
        if (!is_strdigit(file[y]))
            return false;
    return true;
}

static bool check_file_lines(const char **file)
{
    size_t size = arraylen(file);
    size_t m_width = atoi(file[1]);
    size_t m_height = atoi(file[0]);

    if ((m_width * m_height * 3) != (size - 2))
        return false;
    return true;
}

static void check_file(char **file)
{
    if (file == NULL) {
        dprintf(2, "Allocation error\n");
        exit(EXIT_FAILURE);
    }
    if (!check_file_chars((const char **)file))
        exit_failure(file, "Only digits and ',' are accepted in the map\n");
    if (!check_file_lines((const char **)file))
        exit_failure(file, "Map lines differ from specified\n");
    return;
}

static int *char_to_int_map(const char **char_map, size_t size)
{
    int *int_map = malloc(sizeof(int) * (size));

    if (int_map == NULL)
        return NULL;
    for (size_t y = 0; y < size; ++y)
        int_map[y] = atoi(char_map[y]);
    return int_map;
}

static void check_map(maps_t *map)
{
    if (map->walls == NULL) {
        dprintf(2, "Allocation error\n");
        exit(EXIT_FAILURE);
    }
    if (map->ceil == NULL) {
        dprintf(2, "Allocation error\n");
        exit(EXIT_FAILURE);
    }
    if (map->floor == NULL) {
        dprintf(2, "Allocation error\n");
        exit(EXIT_FAILURE);
    }
    return;
}

maps_t get_map(const char *filepath, const char *map_name)
{
    maps_t map = {0};
    char **char_map = file_to_array(filepath, " ,\n\t");
    size_t size = 0;

    check_file(char_map);
    map.name = map_name;
    map.height = atoi(char_map[0]);
    map.width = atoi(char_map[1]);
    size = map.height * map.width;
    map.walls = char_to_int_map(
        (const char **)char_map + 2, size);
    map.floor = char_to_int_map(
        (const char **)char_map + 2 + size, size);
    map.ceil = char_to_int_map(
        (const char **)char_map + 2 + size * 2, size);
    free_array(char_map);
    check_map(&map);
    return map;
}
