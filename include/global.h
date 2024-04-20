/*
** EPITECH PROJECT, 2024
** global
** File description:
** CSFML
*/

#ifndef __GLOBAL__
    #define __GLOBAL__
    #include <SFML/Graphics.h>

typedef struct game_s {
    sfRenderWindow *window;
    sfEvent event;
}game_t;

typedef struct maps_s {
    const char *map_name;
    char **map;
    size_t map_size;
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
    sfVector2i m_pos;
    sfVector2f r_pos;
    sfVector2f offset;
}rays_t;

enum GAME_MODE {
    MAIN_MENU,
    REST,
    EXPLORATION,
    COMBAT
};

char **get_map(const char *filepath);
void free_array(char **array);

void draw2Dmap(maps_t *map);
void draw3Drays(player_t *player, maps_t *map);

void events(game_t *game, player_t *player);
void display(game_t *game, player_t *player, maps_t *map);

sfCircleShape *set_circle(sfVector2f p_pos, float radius, sfColor color);
sfRectangleShape *set_rect(sfVector2f pos, sfVector2f size, sfColor color);

#endif /* !__GLOBAL__ */
