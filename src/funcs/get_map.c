/*
** EPITECH PROJECT, 2024
** get_map
** File description:
** CSFML
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>
#include <ctype.h>
#include "global.h"
#include "lib.h"

static off_t get_size(const char *filepath)
{
    struct stat st;

    if (stat(filepath, &st) == -1) {
        dprintf(2, "Invalid file size\n");
        exit(EXIT_FAILURE);
    }
    return st.st_size;
}

static char **file_to_array(const char *filepath, const char *delim)
{
    int fd = 0;
    size_t size = 0;
    off_t file_size = get_size(filepath);
    char *buffer = (char *) malloc(sizeof(char) * (file_size + 1));
    char **array = NULL;

    fd = open(filepath, O_RDONLY);
    if (fd == -1) {
        dprintf(2, "File opening failed\n");
        return NULL;
    }
    size = read(fd, buffer, (file_size - 1));
    buffer[size] = '\0';
    array = str_to_word_array(buffer, delim);
    free(buffer);
    close(fd);
    return array;
}

static bool is_str_digit(const char *str)
{
    for (size_t x = 0; str[x] != '\0'; ++x)
        if (!isdigit(str[x]))
            return false;
    return true;
}

static void check_file(char **file)
{
    bool check = true;
    size_t m_width = 0;
    size_t m_height = 0;
    size_t size = arraylen((const char **)file);

    for (size_t y = 0; file[y] != 0; ++y)
        if (!is_str_digit(file[y]))
            check = false;
    m_height = atoi(file[0]);
    m_width = atoi(file[1]);
    if ((m_height * m_width) != (size - 2))
        check = false;
    if (!check) {
        dprintf(2, "Invalid map given\n");
        free_array(file);
        exit(EXIT_FAILURE);
    }
    return;
}

static int *char_to_int_map(const char **char_map)
{
    int *int_map = malloc(sizeof(int) * arraylen(char_map));

    for (size_t y = 0; char_map[y] != 0; ++y)
        int_map[y] = atoi(char_map[y]);
    return int_map;
}

maps_t get_map(const char *filepath, const char *map_name, size_t cell_size)
{
    maps_t map = {0};
    char **char_map = file_to_array(filepath, ",\n\t");
    int *int_map = NULL;

    check_file(char_map);
    int_map = char_to_int_map((const char **)char_map + 2);
    map.m_name = map_name;
    map.map_ht = atoi(char_map[0]);
    map.map_wd = atoi(char_map[1]);
    map.cell_size = cell_size;
    map.map = int_map;
    map.next = NULL;
    free_array(char_map);
    return map;
}
