/*
** EPITECH PROJECT, 2024
** free_map.c
** File description:
** CSFML
*/

void free_map(maps_t *map)
{
    maps_t tmp = map;

    while (tmp.next != NULL) {
        free(map->map);
        tmp = map->next;
        free(map);
    }
    return;
}