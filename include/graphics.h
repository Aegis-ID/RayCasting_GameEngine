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

    #define RENDER_DIST 15

    #define CONST_SHADE 0.1f

    #define PIXEL_S 1

    #define MAP_RATIO 24

    #define BRIGHTNESS 1

enum texture_list {
    FLOOR,
    BRICK,
    BRICK_VAR,
    DOOR,
    FINAL_DOOR
};

typedef struct textures_s {
    int iter;
    int line_ht;
    int line_off;
    sfVector2f pos;
    float step;
    float shade;
}textures_t;

typedef struct ray_s {
    // fov
    float fov;
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
    // hit position in map
    sfVector2i m_pos;
    int wall_pos;
    // textures infos
    sfVector2i t_pos;
    int t_type;
}ray_t;

typedef struct graphics_s {
    ray_t ray;
    textures_t textures;
}graphics_t;

// Inits
graphics_t init_graphics(void);
// Tools
bool is_wall(int m_pos);
// Algorithm
void perform_dda(entity_t *p, map_t *m, ray_t *r);
// Display
void draw_minimap(graphics_t *);
void draw_ray(graphics_t *rays, sfVector2i res);
void ray_casting(graphics_t *rays, const sfVector2i res, const float fov);
void draw_sky(const sfVector2i res, const float p_angle, const float shade);
void display_exploration(game_t *game);
void display_exploration_hud(game_t *game);

#endif /* !__RAY_CASTING_STRUCTS__ */
