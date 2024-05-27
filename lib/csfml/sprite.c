/*
** EPITECH PROJECT, 2023
** usefule_functions_1
** File description:
** CSFML
*/

#include "lib_csfml.h"

sfSprite *set_sprite(const char *filePath)
{
    sfTexture *texture = sfTexture_createFromFile(filePath, NULL);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfTrue);
    center_sprite(sprite);
    return sprite;
}

void destroy_sprite(sfSprite *sprite)
{
    sfTexture *texture = NULL;

    if (sprite == NULL)
        return;
    texture = (sfTexture *)sfSprite_getTexture(sprite);
    if (texture != NULL)
        sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
    return;
}
