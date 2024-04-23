/*
** EPITECH PROJECT, 2024
** global
** File description:
** CSFML
*/

#ifndef __GLOBAL__
    #define __GLOBAL__

    #include <SFML/Graphics.h>
    #include "settings.h"

    #define M_PI_3 3 * M_PI / 2
    #define DOF 8
    #define FOV 60

    #define MVT 1
    #define ROT 5

typedef struct maps_s {
    const char *m_name;
    int *map;
    size_t map_ht;
    size_t map_wd;
    size_t cell_size;
    struct map_s *next;
}maps_t;

typedef struct player_s {
    float angle;
    sfVector2f pos;
    sfVector2f delta;
} player_t;

typedef struct rays_s {
    int dof;
    //Ray main infos
    float angle;
    sfVector2f pos;
    sfVector2f offset;
    //for horizontal coll
    float h_dist;
    sfVector2f h_pos;
    //for vertical coll
    float v_dist;
    sfVector2f v_pos;
    //for map position
    size_t mp;
}rays_t;

//parsing
maps_t get_map(const char *filepath, const char *map_name, size_t cell_size);
void free_array(char **array);
//2D part
void draw_map(maps_t *map);
void draw_player(player_t *player);
void draw_rays(player_t *player, rays_t *rays);
//Some Maths
float pythagoras(sfVector2f a, sfVector2f b);
float update_angle(float angle);
//3D part
void draw_walls(player_t *player, maps_t *map, rays_t *rays, int r_iter);
void ray_casting(player_t *player, maps_t *map);
//Main functions
void events(game_t *game, player_t *player);
void display(game_t *game, player_t *player, maps_t *map);

#endif /* !__GLOBAL__ */
