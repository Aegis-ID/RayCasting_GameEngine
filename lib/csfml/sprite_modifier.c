/*
** EPITECH PROJECT, 2023
** useful_functions_2
** File description:
** CSFML
*/

#include "lib_csfml.h"

void replace_texture(sfSprite *sprite, const char *filePath)
{
    sfTexture *new_texture = sfTexture_createFromFile(filePath, NULL);
    sfTexture *old_texture = (sfTexture *)sfSprite_getTexture(sprite);

    sfSprite_setTexture(sprite, new_texture, sfTrue);
    sfTexture_destroy(old_texture);
    return;
}

void set_scale(sfSprite *sprite, float scaleNb)
{
    sfVector2f scale = {scaleNb, scaleNb};

    sfSprite_scale(sprite, scale);
    return;
}

void set_pos(sfSprite *sprite, int X, int Y)
{
    sfVector2f pos = {X, Y};

    sfSprite_setPosition(sprite, pos);
    return;
}

void center_sprite(sfSprite *sprite)
{
    sfFloatRect image = sfSprite_getGlobalBounds(sprite);
    sfVector2f origin = {image.width / 2, image.height / 2};

    sfSprite_setOrigin(sprite, origin);
    return;
}
