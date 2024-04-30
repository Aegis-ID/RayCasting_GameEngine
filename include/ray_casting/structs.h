/*
** EPITECH PROJECT, 2024
** ray_casting
** File description:
** CSFML
*/

#ifndef __RAY_CASTING_STRUCTS__
    #define __RAY_CASTING_STRUCTS__

    #include <SFML/Graphics.h>

// Main ray casting structs

typedef struct maps_s {
    const char *name;
    size_t height;
    size_t width;
    int *walls;
    int *floor;
    int *ceil;
    struct map_s *next;
}maps_t;

typedef struct player_s {
    float angle;
    sfVector2f pos;
    sfVector2f delta;
} player_t;

typedef struct rays_s {
    // depth of field
    int dof;
    // rays infos
    size_t r_iter;
    float angle;
    sfVector2f pos;
    sfVector2f offset;
    // rays wall collisions infos
    float h_dist;
    sfVector2f h_pos;
    float v_dist;
    sfVector2f v_pos;
    // map position
    size_t m_pos;
    // walls infos
    float shade;
    sfVector2i w_text_pos;
    size_t wall_type;
}rays_t;

// For rays functions && calculations 

typedef struct collisions_s {
    sfVector2i pos;
    sfVector2i offset_add;
    sfVector2i offset_sub;
}collisions_t;

// Global struct for ray casting "EXPLORATION GAME MODE" also named rc_mode

typedef struct ray_casting_s {
    maps_t maps;
    player_t player;
    rays_t rays;
}ray_casting_t;

#endif /* !__RAY_CASTING_STRUCTS__ */
