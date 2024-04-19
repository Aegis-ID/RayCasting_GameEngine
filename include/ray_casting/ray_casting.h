/*
** EPITECH PROJECT, 2024
** ray_casting
** File description:
** CSFML functions
*/

#ifndef __RAY_CASTING_FUNCTIONS__
    #define __RAY_CASTING_FUNCTIONS__
    #include "player.h"
    #include "steven.h"
    #include "../settings.h"

char **convert_sketch(player_t *player, steven_t *steven);

void draw_map(sf::RenderWindow& window);
void draw_screen(sf::RenderWindow& window, const Steven& steven);
void set_position(float x, float y);

void update(const char **map, const sfRenderWindow *window);

float get_center_x(void);
float get_center_y(void);
float get_direction(void);

#endif /* !__RAY_CASTING_FUNCTIONS__ */
