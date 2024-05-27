/*
** EPITECH PROJECT, 2024
** useful_funcs
** File description:
** CSFML
*/

#ifndef __MY_CSFML_FUNCS__
    #define __MY_CSFML_FUNCS__

    #include <SFML/Graphics.h>
    #include <stdbool.h>

    #define NEAR_DEST 5.0f

// Sprite.c
sfSprite *set_sprite(const char *filePath);
void destroy_sprite(sfSprite *sprite);

// Sprite_modifier.c
void set_scale(sfSprite *sprite, float scaleNb);
void set_pos(sfSprite *sprite, int X, int Y);
void center_sprite(sfSprite *sprite);
void replace_texture(sfSprite *sprite, const char *filePath);

// Sprite_funcs.c
sfBool sfsprite_issprite_clicked(
    sfVector2u mouse, sfSprite *sprite, sfEvent *event);
void set_rand_pos(sfVector2u res, sfSprite *sprite);
void move_rand(sfVector2u res, sfSprite *sprite, float speed);

// funcs.c
sfBool sfmouse_isbutton_released(sfEvent *event, sfMouseButton button);
sfCircleShape *set_circle(float radius, float thickness);
sfRectangleShape *set_rect(float height, float width);
sfText *display_text(sfRenderWindow *window, const char *fontPath,
    const char *message, int characterSize);

#endif /* !__MY_CSFML_FUNCS__ */
