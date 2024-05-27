/*
** EPITECH PROJECT, 2024
** gameplay
** File description:
** CSFML
*/

#ifndef __GAMEPLAY__
    #define __GAMEPLAY__

    #include <stddef.h>

    #define MVT 3.0f

typedef struct map_s {
    int height;
    int width;
    int cell_size;
    int size;
    int *walls;
}map_t;

typedef struct gameplay_s {
    map_t map;
    size_t adventure_state;
    size_t level;
    bool mini_map;
    bool r_hand;
}gameplay_t;

// Inits
gameplay_t init_gameplay(void);
map_t init_map(const char *filepath);

// Gameplay
void player_movement(game_t *game);
void player_interactions(game_t *game);

#endif /* !__GAMEPLAY__ */
