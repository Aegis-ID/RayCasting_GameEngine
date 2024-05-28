/*
** EPITECH PROJECT, 2024
** entitys
** File description:
** CSFML
*/

#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <stdlib.h>

#include "lib.h"
#include "entities.h"

void animate(sfRenderWindow *window, entity_t *entity, float fps)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(entity->clock)) > fps) {
        entity->current_frame = (entity->current_frame + 1) % entity->size;
        sfSprite_setTexture(
            entity->sprite, entity->textures[entity->current_frame], sfTrue);
        sfClock_restart(entity->clock);
    }
    sfRenderWindow_drawSprite(window, entity->sprite, NULL);
    return;
}
