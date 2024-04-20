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
#include "global.h"

void free_array(char **array)
{
    for (size_t y = 0; array[y] != 0; ++y)
        free(array[y]);
    free(array);
}

static off_t get_size(const char *filename)
{
    struct stat st;

    if (stat(filename, &st) == -1) {
        dprintf(2, "Invalid map size\n");
        exit(EXIT_FAILURE);
    }
    return st.st_size;
}

char **get_map(const char *filepath)
{
    int fd = 0;
    size_t size = 0;
    off_t file_size = get_size(filepath);
    char *buffer = (char *) malloc(sizeof(char) * file_size);
    char **map = NULL;

    fd = open(filepath, O_RDONLY);
    if (fd == -1) {
        dprintf(2, "Map opening failed\n");
        return NULL;
    }
    size = read(fd, buffer, (file_size - 1));
    buffer[size] = '\0';
    map = str_to_word_array(buffer, " \n\t");
    free(buffer);
    close(fd);
    return map;
}
