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
#include "lib.h"

static off_t get_size(const char *filename)
{
    struct stat st;

    if (stat(filename, &st) == -1) {
        dprintf(2, "Invalid file size\n");
        exit(EXIT_FAILURE);
    }
    return st.st_size;
}

char **get_map(const char *filepath)
{
    int fd = 0;
    size_t size = 0;
    off_t file_size = get_size(filepath);
    char *buffer = (char *) malloc(sizeof(char) * (file_size + 1));
    char **map = NULL;

    fd = open(filepath, O_RDONLY);
    if (fd == -1) {
        dprintf(2, "File opening failed\n");
        return NULL;
    }
    size = read(fd, buffer, (file_size - 1));
    buffer[size] = '\0';
    map = str_to_word_array(buffer, "\n\t");
    free(buffer);
    close(fd);
    return map;
}
