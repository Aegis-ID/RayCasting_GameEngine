/*
** EPITECH PROJECT, 2024
** myradar
** File description:
** CSFML
*/

#include "lib_csfml.h"

sfCircleShape *set_circle(float radius, float thickness)
{
    sfCircleShape *circle = sfCircleShape_create();
    sfVector2f origin = {radius / 2, radius / 2};

    sfCircleShape_setOutlineThickness(circle, thickness);
    sfCircleShape_setRadius(circle, radius);
    sfCircleShape_setOrigin(circle, origin);
    sfCircleShape_setOutlineColor(circle, sfWhite);
    sfCircleShape_setFillColor(circle, sfTransparent);
    return circle;
}

sfRectangleShape *set_rect(float height, float width)
{
    sfRectangleShape *rect = sfRectangleShape_create();
    sfVector2f origin = {height / 2, width / 2};

    sfRectangleShape_setOrigin(rect, origin);
    return rect;
}

sfText *display_text(sfRenderWindow *window, const char *fontPath,
    const char *message, int characterSize)
{
    sfText* text = sfText_create();
    sfFont* font = sfFont_createFromFile(fontPath);

    sfText_setString(text, message);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, characterSize);
    sfRenderWindow_drawText(window, text, NULL);
    return text;
}

sfBool sfmouse_isbutton_released(sfEvent *event, sfMouseButton button)
{
    if (event->type == sfEvtMouseButtonReleased &&
        event->mouseButton.button == button)
        return sfTrue;
    return sfFalse;
}
