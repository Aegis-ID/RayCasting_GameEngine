/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** entities structs
*/

#ifndef __ENTITIES__
    #define __ENTITIES__

    #include <SFML/System.h>
    #include <stdint.h>

// ENTITIES INFOS
    #define ENTITIES_TYPES 4

    #define PLAYER_NB 1
    #define NPC_NB 0
    #define MOB_NB 0
    #define OBJ_NB 0

// SETTINGS
    #define COL_DIST 10.0f
    #define INTERACTION_DIST 5

enum entity_type {
    PLAYER,
    NPC,
    MOB,
    OBJ,
};

typedef struct collisions_s {
    int front_wall_pos;
    size_t front_wall;
    float front;
    float back;
    float left;
    float right;
}collisions_t;

typedef struct entity_s {
    uint8_t type;
    // Main components
    sfClock *clock;
    sfSprite *sprite;
    sfTexture **textures;
    // Position
    float angle;
    sfVector2f pos;
    sfVector2f delta;
    collisions_t collisions;
    // Animations
    const char **frames;
    size_t nb_frames;
    size_t current_frame;
    float fps;
}entity_t;

entity_t **init_entities(void);
entity_t init_entity(const char **frames, int entity_type);

collisions_t get_collisions(entity_t *p, map_t *m);

void free_entity(entity_t *entity);

void animate(sfRenderWindow *window, entity_t *sprite, float fps);

#endif /* !__ENTITIES__ */
