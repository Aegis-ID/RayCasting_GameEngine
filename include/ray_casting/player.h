/*
** EPITECH PROJECT, 2024
** player
** File description:
** CSFML
*/

#ifndef __PLAYER__
    #define __PLAYER__
    #include <SFML/Graphics.h>

typedef struct Player_s {
	float direction_horizontal;
	float direction_vertical;
	float x;
	float y;

	float **view_rays;

	sfSprite *map_player_sprite;
	sfSprite *steven_sprite;
	sfSprite *wall_sprite;

	sfTexture *map_player_texture;
	sfTexture *steven_texture;
	sfTexture *wall_texture;
} player_t;

#endif /* !__PLAYER__ */
