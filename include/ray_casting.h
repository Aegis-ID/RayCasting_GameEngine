/*
** EPITECH PROJECT, 2024
** ray_casting
** File description:
** CSFML
*/

#ifndef __RAY_CASTING__
    #define __RAY_CASTING__

    #include <SFML/Graphics.h>
    #include <stdbool.h>

    //View settings
    #define DOF 8
    #define SHADE 0.8f
    #define COL_DIST 20

    //Player settings --> Temporary (in player_stats)
    #define MVT 1

// Main ray casting structs

typedef struct maps_s {
    const char *m_name;
    size_t map_ht;
    size_t map_wd;
    int *map;
    int *map_floor;
    int *map_ceil;
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

typedef struct walls_s {
    size_t wall_ht;
    size_t wall_ht_off;
    sfVector2f pos;
    sfVector2f offset;
    sfVector2f step;
}walls_t;

// Global struct for ray casting "EXPLORATION GAME MODE" also named rc_mode

typedef struct ray_casting_s {
    maps_t maps;
    player_t player;
    rays_t rays;
}ray_casting_t;

//Parsing
maps_t get_map(const char *filepath, const char *map_name);
void free_array(char **array);
//2D part
void draw_map(maps_t *map);
void draw_player(player_t *player);
void draw_rays(player_t *player, rays_t *rays);
//3D part
float update_angle(float angle);
void draw_walls(player_t *p, rays_t *r, size_t r_iter);
void ray_casting(player_t *player, maps_t *map);
//Gameplay
void player_movement(player_t *player, maps_t *map);
// Walls
bool is_wall(int map_position);

#endif /* !__RAY_CASTING__ */
