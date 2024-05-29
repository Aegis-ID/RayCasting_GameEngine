/*
** EPITECH PROJECT, 2024
** get rand pos
** File description:
** CSFML
*/

#include <SFML/System.h>

sfVector2f get_rand_pos(sfVector2u vector)
{
    sfVector2f dest = {
        dest.x = (float)(rand() % vector.x),
        dest.y = (float)(rand() % vector.y)};

    return dest;
}
