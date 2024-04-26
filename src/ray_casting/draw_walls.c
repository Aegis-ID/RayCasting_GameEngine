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

static void colorize_wall(rays_t *r, textures_t *t,
    size_t r_iter, const int *texture)
{
    for (size_t y = 0; y < t->wall_ht; ++y) {
        t->color = 
            texture[(int)(t->pos.y) * TEXTURES_S + (int)(t->pos.x)] * r->shade;
        glColor3f(t->color, t->color, t->color);
        glPointSize(DOF);
        glBegin(GL_POINTS);
        glVertex2i(r_iter * DOF + (WIDTH / 2), y + t->wall_ht_off);
        glEnd();
        t->pos.y += t->step.y;
    }
    return;
}

static void display_textures(rays_t *r, textures_t *t)
{
    t->pos.y = t->offset.y * t->step.y;
    if (r->shade == SHADE) {
        t->pos.x = (int)(r->pos.x / 2) % TEXTURES_S;
        if (r->angle > 180)
            t->pos.x = (TEXTURES_S - 1) - t->pos.x;
    } else {
        t->pos.x = (int)(r->pos.y / 2) % TEXTURES_S;
        if (r->angle > 90 && r->angle < 270)
            t->pos.x = (TEXTURES_S - 1) - t->pos.x;
    }
    return;
}

static void calculate_walls(rays_t *r, textures_t *t)
{
    t->wall_ht = (MAP_S * (HEIGHT / 2)) / r->h_dist;
    t->step.y = TEXTURES_S / (float)t->wall_ht;
    t->offset.y = 0;
    if (t->wall_ht > (HEIGHT / 2)) {
        t->offset.y = (t->wall_ht - (HEIGHT / 2)) / 2;
        t->wall_ht = (HEIGHT / 2);
    }
    t->wall_ht_off = (HEIGHT / 4) - (t->wall_ht >> 1);
    return;
}

void draw_walls(player_t *p, rays_t *r, size_t r_iter)
{
    textures_t text = {0};

    r->h_dist *= cos(deg_to_rad(update_angle(p->angle - r->angle)));
    calculate_walls(r, &text);
    display_textures(r, &text);
    colorize_wall(r, &text, r_iter, BRICK);
    return;
}
