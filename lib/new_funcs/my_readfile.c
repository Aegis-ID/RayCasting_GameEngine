/*
** EPITECH PROJECT, 2023
** functions
** File description:
** file size
*/

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "include/my.h"

long get_size(const char *filename)
{
    struct stat st;

    if (stat(filename, &st) == -1)
        return 84;
    return st.st_size;
}

int my_readfile(char *filepath)
{
    int fd = 0;
    int size = 0;
    int file_size = get_size(filepath);
    char *buffer = (char *) malloc(sizeof(char) * file_size);

    fd = open(filepath, O_RDONLY);
    if (fd == -1)
        return 84;
    size = read(fd, buffer, (file_size - 1));
    buffer[size] = '\0';
    my_putstr(buffer);
    free(buffer);
    close(fd);
    return 0;
}
