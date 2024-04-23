/*
** EPITECH PROJECT, 2024
** file to array
** File description:
** new_funcs
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
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

char **file_to_array(const char *filepath, const char *delim)
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
