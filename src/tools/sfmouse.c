/*
** EPITECH PROJECT, 2024
** sfmouse
** File description:
** CSFML
*/

#include <SFML/Graphics.h>

sfBool sfMouse_isButtonReleased(sfEvent *event, sfMouseButton button)
{
    if (event->type == sfEvtMouseButtonReleased &&
        event->mouseButton.button == button)
        return sfTrue;
    return sfFalse;
}
