/*
** EPITECH PROJECT, 2024
** map
** File description:
** CSFML
*/

#ifndef __MAP__
    #define __MAP__

    #define MAP_X 8
    #define MAP_Y 8
    #define MAP_S 64

const int TEST_MAP[] =
{
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 0, 1, 0, 0, 0, 0, 1,
    1, 0, 1, 0, 0, 0, 0, 1,
    1, 0, 1, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 1, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 1,
    1, 1, 1, 1, 1, 1, 1, 1,
};

typedef struct map_s {
    size_t map_x;
    size_t map_y;
    size_t map_s;
    int *map;
}map_t;

#endif /* !__MAP__ */
