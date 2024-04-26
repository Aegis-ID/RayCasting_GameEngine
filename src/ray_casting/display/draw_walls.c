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
#include "lib.h"
#include "ray_casting.h"
#include "settings/settings.h"
#include "textures/textures.h"

static void colorize_wall(rays_t *r, walls_t *w,
    size_t r_iter, const int *texture)
{
    float color = 0;

    for (size_t y = 0; y < w->wall_ht; ++y) {
        color =
            texture[(int)(w->pos.y) * TEXTURES_S + (int)(w->pos.x)] * r->shade;
        glColor3f(color, color, color);
        glPointSize(DOF);
        glBegin(GL_POINTS);
        glVertex2i(r_iter * DOF + (WIDTH / 2), y + w->wall_ht_off);
        glEnd();
        w->pos.y += w->step.y;
    }
    return;
}

static void display_textures(rays_t *r, walls_t *w)
{
    w->pos.y = w->offset.y * w->step.y;
    if (r->shade == SHADE) {
        w->pos.x = (int)(r->pos.x / 2) % TEXTURES_S;
        if (r->angle > 180)
            w->pos.x = (TEXTURES_S - 1) - w->pos.x;
    } else {
        w->pos.x = (int)(r->pos.y / 2) % TEXTURES_S;
        if (r->angle > 90 && r->angle < 270)
            w->pos.x = (TEXTURES_S - 1) - w->pos.x;
    }
    return;
}

static void calculate_walls(rays_t *r, walls_t *w)
{
    w->wall_ht = (MAP_S * (HEIGHT / 2)) / r->h_dist;
    w->step.y = TEXTURES_S / (float)w->wall_ht;
    w->offset.y = 0;
    if (w->wall_ht > (HEIGHT / 2)) {
        w->offset.y = (w->wall_ht - (HEIGHT / 2)) / 2;
        w->wall_ht = (HEIGHT / 2);
    }
    w->wall_ht_off = (HEIGHT / 4) - (w->wall_ht >> 1);
    return;
}

void draw_walls(player_t *p, rays_t *r, size_t r_iter)
{
    walls_t walls = {0};

    r->h_dist *= cos(deg_to_rad(update_angle(p->angle - r->angle)));
    calculate_walls(r, &walls);
    display_textures(r, &walls);
    colorize_wall(r, &walls, r_iter, BRICK);
    return;
}
