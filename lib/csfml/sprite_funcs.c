/*
** EPITECH PROJECT, 2023
** useful_functions_3
** File description:
** CSFML
*/

#include <stdlib.h>

#include "lib_csfml.h"

sfBool sfsprite_issprite_clicked(sfVector2u mouse, sfSprite *sprite,
    sfEvent *event)
{
    sfVector2f sprite_pos = sfSprite_getPosition(sprite);
    sfFloatRect image = sfSprite_getGlobalBounds(sprite);
    sfVector2u hitbox = {
        sprite_pos.y + image.height,
        sprite_pos.x + image.width};

    if (sfmouse_isbutton_released(event, sfMouseLeft)) {
        if ((mouse.y >= sprite_pos.y && mouse.y <= hitbox.y) &&
            (mouse.x >= sprite_pos.y && mouse.x <= hitbox.x)) {
            return sfTrue;
        }
    }
    return sfFalse;
}

void set_rand_pos(sfVector2u res, sfSprite *sprite)
{
    sfSprite_setPosition(sprite, (sfVector2f) {
        (int)(rand() % (int)res.x),
        (int)(rand() % (int)res.y)
    });
    return;
}

sfVector2f get_rand_pos(sfVector2u res)
{
    sfVector2f dest = {
        dest.x = (float)(rand() % res.x),
        dest.y = (float)(rand() % res.y)};

    return dest;
}

void move_rand(sfVector2u res, sfSprite *sprite, float speed)
{
    static sfVector2f dest = {0, 0};
    sfVector2f next_movement = {0, 0};
    sfVector2f cur_pos = sfSprite_getPosition(sprite);
    sfVector2f direction = {dest.x - cur_pos.x, dest.y - cur_pos.y};
    sfVector2f dest_len = {direction.x, direction.y};

    if (dest_len.x != 0)
        direction.x /= dest_len.x;
    if (dest_len.y != 0)
        direction.y /= dest_len.y;
    next_movement = (sfVector2f){direction.x * speed, direction.y * speed};
    sfSprite_move(sprite, next_movement);
    if (dest_len.x < NEAR_DEST && dest_len.y < NEAR_DEST)
        dest = get_rand_pos(res);
    return;
}
