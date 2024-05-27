/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** entities init
*/

#include <stdlib.h>

#include "lib.h"
#include "lib_csfml.h"
#include "entities.h"
#include "const/entities.h"

void free_entity(entity_t *entity)
{
    if (entity == NULL)
        return;
    if (entity->clock != NULL)
        sfClock_destroy(entity->clock);
    if (entity->sprite != NULL)
        sfSprite_destroy(entity->sprite);
    if (entity->textures != NULL) {
        for (size_t y = 0; y < entity->size; ++y)
            sfTexture_destroy(entity->textures[y]);
        free(entity->textures);
    }
    return;
}

entity_t init_entity(const char **frames, int entity_type)
{
    entity_t entity = {0};

    entity.type = entity_type;
    entity.frames = frames;
    entity.size = arraylen(frames);
    entity.clock = sfClock_create();
    entity.sprite = set_sprite(frames[0]);
    entity.textures = malloc(sizeof(sfTexture *) * (entity.size + 1));
    for (size_t y = 0; y < entity.size; ++y)
        entity.textures[y] = sfTexture_createFromFile(frames[y], NULL);
    entity.textures[entity.size] = NULL;
    return entity;
}


static entity_t init_player_entity(void)
{
    entity_t player = {0};

    player.pos = (sfVector2f){225, 225};
    player.angle = 90;
    player.delta.x = cos(deg_to_rad(player.angle));
    player.delta.y = -sin(deg_to_rad(player.angle));
    return player;
}

entity_t *init_entities(void)
{
    entity_t **entities = malloc(sizeof(entity_t *) * ENTITIES_TYPES);

    return entities;
}
