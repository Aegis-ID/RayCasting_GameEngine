/*
** EPITECH PROJECT, 2024
** display
** File description:
** C'est là que commence la vraie magie noire...
** CSFML
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/OpenGL.h>
#include <math.h>
#include "global.h"
#include "settings.h"
#include "lib.h"
#include "textures.h"

static void colorize_wall(rays_t *r, textures_t *t, size_t r_iter)
{
    int space = 8;

    for (size_t y = 0; y < t->wall_ht; ++y) {
        t->color = 
            All_Textures[(int)(t->pos.y) * (MAP_S / 2) + (int)(t->pos.x)] * r->shade;
        glColor3f(t->color, t->color, t->color);
        glPointSize(space);
        glBegin(GL_POINTS);
        glVertex2i(r_iter * space + (WIDTH / 2), y + t->wall_off);
        glEnd();
        t->pos.y += t->step.y;
    }
    return;
}

void draw_walls(maps_t *m, player_t *p, rays_t *r, size_t r_iter)
{
    textures_t text = {0};

    r->h_dist *= cos(deg_to_rad(update_angle(p->angle - r->angle)));    //fix fisheye

    text.wall_ht = (MAP_S * (HEIGHT / 2)) / r->h_dist;
    text.step.y = (MAP_S / 2) / (float)text.wall_ht;

    text.offset.y = 0;
    if (text.wall_ht > (HEIGHT / 2)) {
        text.offset.y = (text.wall_ht - (HEIGHT / 2)) / 2;
        text.wall_ht = (HEIGHT / 2);
    }
    text.wall_off = (HEIGHT / 4) - (text.wall_ht >> 1);

    text.pos.y = text.offset.y * text.step.y;
    text.step.x = (int)(r->pos.x / 2) % (MAP_S / 2);
    if (r->angle > 180)
        text.pos.x = (MAP_S / 2) - text.pos.x;

    colorize_wall(r, &text, r_iter);

    return;
}
 