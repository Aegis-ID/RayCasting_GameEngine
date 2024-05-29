/*
** EPITECH PROJECT, 2023
** useful_functions_3
** File description:
** CSFML
*/

#include <stdlib.h>
#include <SFML/System.h>
#include <SFML/Graphics.h>

sfBool sfSprite_isSpriteClicked(
    sfVector2u mouse, sfSprite *sprite, sfEvent *event)
{
    sfVector2f sprite_pos = sfSprite_getPosition(sprite);
    sfFloatRect image = sfSprite_getGlobalBounds(sprite);
    sfVector2u hitbox = {
        sprite_pos.y + image.height,
        sprite_pos.x + image.width};

    if (sfMouse_isButtonReleased(event, sfMouseLeft)) {
        if ((mouse.y >= sprite_pos.y && mouse.y <= hitbox.y) &&
            (mouse.x >= sprite_pos.y && mouse.x <= hitbox.x)) {
            return sfTrue;
        }
    }
    return sfFalse;
}

void sfSpriteMoveRand(sfSprite *sprite, sfVector2u bounds,
    const float speed, const float near_dist)
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
    if (dest_len.x < near_dist && dest_len.y < near_dist)
        dest = get_rand_pos(bounds);
    return;
}

void sfSprite_centerOrigin(sfSprite *sprite)
{
    sfFloatRect image = sfSprite_getGlobalBounds(sprite);
    sfVector2f origin = {image.width / 2, image.height / 2};

    sfSprite_setOrigin(sprite, origin);
    return;
}
