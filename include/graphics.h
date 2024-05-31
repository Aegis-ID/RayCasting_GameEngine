/*
** EPITECH PROJECT, 2024
** ray_casting
** File description:
** CSFML
*/

#ifndef __RAY_CASTING__
    #define __RAY_CASTING__

    #include <stdbool.h>
    #include <SFML/Graphics.h>

    #define DEPTH_BUFFER 100

    #define BRIGHTNESS 1

    #define SHADE_DIST 15

    #define CONST_SHADE 0.1f

enum texture_list {
    FLOOR,
    BRICK,
    BRICK_VAR,
    DOOR,
    FINAL_DOOR
};

typedef struct textures_s {
    int iter;
    int height;
    int offset;
    sfVector2u pos;
    int step;
    float shade;
}textures_t;

typedef struct ray_s {
    // depth buffer
    int depth_buffer;
    // ray infos
    size_t iter;
    float angle;
    // ray direction
    sfVector2f pos;
    sfVector2f offset;
    // ray dist
    sfVector2f v_pos;
    sfVector2f h_pos;
    float v_dist;
    float h_dist;
    float dist;
    // ray hit
    sfVector2i m_pos;
    int wall_pos;
    sfVector2i t_pos;
    int t_type;
}ray_t;

typedef struct graphics_s {
    sfVector2u res;
    ray_t ray;
    textures_t textures;
}graphics_t;

// Inits
graphics_t init_graphics(void);
// Tools
bool is_wall(int m_pos);
// Algorithm
void perform_dda(entity_t *p, map_t *m, ray_t *r);

#endif /* !__RAY_CASTING_STRUCTS__ */
