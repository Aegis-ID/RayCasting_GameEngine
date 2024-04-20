/*
** EPITECH PROJECT, 2024
** set_shape
** File description:
** CSFML
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>

sfCircleShape *set_circle(sfVector2f p_pos, float radius, sfColor color)
{
    sfCircleShape *circle = sfCircleShape_create();

    sfCircleShape_setRadius(circle, radius);
    sfCircleShape_setFillColor(circle, color);
    sfCircleShape_setPosition(circle, p_pos);
    return circle;
}

sfRectangleShape *set_rect(sfVector2f pos, sfVector2f size, sfColor color)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setSize(rect, size);
    sfRectangleShape_setFillColor(rect, color);
    sfRectangleShape_setPosition(rect, pos);
    return rect;
}
