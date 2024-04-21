/*
** EPITECH PROJECT, 2024
** global
** File description:
** CSFML
*/

#ifndef __GLOBAL__
    #define __GLOBAL__
    #include <SFML/Graphics.h>

    #define M_PI_3 3 * M_PI / 2
    #define DOF 8
    #define FOV 60

typedef struct game_s {
    sfRenderWindow *window;
    sfEvent event;
}game_t;

typedef struct maps_s {
    const char *m_name;
    int *map;
    size_t m_height;
    size_t m_width;
    size_t m_size;
    struct map_s *next;
}maps_t;

typedef struct player_s {
    sfVector2f pos;
    sfVector2f delta;
    float angle;
} player_t;

typedef struct rays_s {
    int dof;
    float angle;
    size_t mp;

    sfVector2f pos;
    sfVector2f offset;

    float h_dist;
    sfVector2f h_pos;

    float v_dist;
    sfVector2f v_pos;

    float dist;
}rays_t;

enum GAME_MODE {
    MAIN_MENU,
    REST,
    EXPLORATION,
    COMBAT
};
//parsing
maps_t get_map(const char *filepath, const char *map_name);
void free_array(char **array);
//walls
sfBool is_wall(int cell);
void colorize_cell(int cell);

void draw2Dmap(maps_t *map);
void draw2Drays(player_t *player, maps_t *map);
void draw3Dwalls(player_t *p, maps_t *m, rays_t *r, int rays);

void events(game_t *game, player_t *player);
void display(game_t *game, player_t *player, maps_t *map);

sfCircleShape *set_circle(sfVector2f p_pos, float radius, sfColor color);
sfRectangleShape *set_rect(sfVector2f pos, sfVector2f size, sfColor color);

#endif /* !__GLOBAL__ */
