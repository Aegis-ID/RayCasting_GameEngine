/*
** EPITECH PROJECT, 2024
** steven
** File description:
** CSFML
*/

#ifndef __STEVEN__
    #define __STEVEN__

typedef struct steven_s {
	float direction;
	float x;
	float y;

	sfSprite *map_steven_sprite;
	sfTexture *map_steven_texture;
} steven_t;

#endif /* !__STEVEN__ */
