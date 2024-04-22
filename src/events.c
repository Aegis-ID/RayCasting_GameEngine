/*
** EPITECH PROJECT, 2024
** events
** File description:
** CSFML
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/OpenGL.h>
#include <math.h>
#include "global.h"
#include "settings.h"

// TO DO
sfBool isKey_pressed(sfEvent *event, int key);
sfBool isKey_released(sfEvent *event, int key);

static void p_movement(player_t *p)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ)) {
        p->pos.x += p->delta.x;
        p->pos.y += p->delta.y;
    }
    if (sfKeyboard_isKeyPressed(sfKeyQ)) {
        p->pos.x += p->delta.y;
        p->pos.y -= p->delta.x;
    }
    if (sfKeyboard_isKeyPressed(sfKeyS)) {
        p->pos.x -= p->delta.x;
        p->pos.y -= p->delta.y;
    }
    if (sfKeyboard_isKeyPressed(sfKeyD)) {
        p->pos.x -= p->delta.y;
        p->pos.y += p->delta.x;
    }
}
// Implement Mouse
static void p_rotation(player_t *p)
{
    if (sfKeyboard_isKeyPressed(sfKeyA)) {
        p->angle -= 0.1;
        if (p->angle < 0)
            p->angle += 2 * M_PI;
        p->delta.x = cos(p->angle) * 5;
        p->delta.y = sin(p->angle) * 5;
    }
    if (sfKeyboard_isKeyPressed(sfKeyE)) {
        p->angle += 0.1;
        if (p->angle > (2 * M_PI))
            p->angle -= 2 * M_PI;
        p->delta.x = cos(p->angle) * 5;
        p->delta.y = sin(p->angle) * 5;
    }
}

void events(game_t *game, player_t *player)
{
    sfRenderWindow *window = game->window;
    sfEvent event = game->event;

    if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape))
        sfRenderWindow_close(window);
    if (event.type == sfEvtResized)
        glViewport(0, 0, event.size.width, event.size.height);
    p_movement(player);
    p_rotation(player);
}
