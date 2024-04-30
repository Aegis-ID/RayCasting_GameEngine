/*
** EPITECH PROJECT, 2024
** ray_casting functions
** File description:
** CSFML
*/

#ifndef __RAY_CASTING__
    #define __RAY_CASTING__

    #include <stdbool.h>
    #include "ray_casting/structs.h"
    #include "game/structs.h"

    //View settings
    #define DOF 8
    #define SHADE 0.8f
    #define COL_DIST 10

    //Player settings --> Temporary (put in player_stats)
    #define MVT 1

//Parsing
maps_t get_map(const char *filepath, const char *map_name);
void free_array(char **array);
//2D part
void draw_map(maps_t *map, int mini_map_size);
void draw_player(player_t *player);
void draw_rays(player_t *player, rays_t *rays);
//3D part
float update_angle(float angle);
void display_rc(game_t *g, player_t *p, rays_t *r);
void ray_casting(game_t *game, player_t *player, maps_t *map);
//Gameplay
collisions_t get_collisions(player_t *p, int map_s);
void player_movement(game_t *game, player_t *player, maps_t *map);
void player_interactions(game_t *game, player_t *player, maps_t *m);
// Walls
bool is_wall(int map_position);

#endif /* !__RAY_CASTING__ */
