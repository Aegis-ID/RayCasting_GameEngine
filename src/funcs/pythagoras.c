/*
** EPITECH PROJECT, 2024
** fix angle
** File description:
** CSFML
*/

#include <SFML/Graphics.h>
#include <math.h>

float pythagoras(sfVector2f a, sfVector2f b)
{
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}
