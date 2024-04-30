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
#include "textures/textures.h"
#include "textures/structs.h"
#include "ray_casting/funcs.h"
#include "settings/structs.h"
#include "game/structs.h"

bool is_wall(int map_position)
{
    if ((map_position > 0) && (map_position <= TEXTURES_NB))
        return true;
    return false;
}

static void colorize_wall(int wall_type, float color)
{
    enum texture_type;

    wall_type += 1;
    if (wall_type == CHECKERBOARD)
        glColor3f(color, color / 2, color / 2);
    if (wall_type == BRICK)
        glColor3f(color, color, color / 2);
    if (wall_type == WINDOW)
        glColor3f(color / 2, color / 2, color);
    if (wall_type == DOOR)
        glColor3f(color / 2, color, color / 2);
    return;
}

static void texture_wall(rays_t *r, walls_t *w, display_t *d, const int *texture)
{
    float color = 0;

    for (size_t y = 0; y < w->wall_ht; ++y) {
        color =
            texture[(int)(w->pos.y) * TEXTURES_S + (int)(w->pos.x)] * r->shade;
        colorize_wall(r->wall_type, color);
        glPointSize(DOF);
        glBegin(GL_POINTS);
        glVertex2i(r->r_iter * DOF + (d->resolution.x / 2), y + w->wall_ht_off);
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

static void calculate_walls(rays_t *r, walls_t *w, display_t *d, int map_s)
{
    w->wall_ht = (map_s * (d->resolution.y / 2)) / r->h_dist;
    w->step.y = TEXTURES_S / (float)w->wall_ht;
    w->offset.y = 0;
    if ((int)w->wall_ht > (d->resolution.y / 2)) {
        w->offset.y = (w->wall_ht - (d->resolution.y / 2)) / 2;
        w->wall_ht = (d->resolution.y / 2);
    }
    w->wall_ht_off = (d->resolution.y / 4) - (w->wall_ht >> 1);
    return;
}

void draw_walls(game_t *g, player_t *p, rays_t *r)
{
    walls_t walls = {0};

    r->h_dist *= cos(deg_to_rad(update_angle(p->angle - r->angle)));
    calculate_walls(r, &walls, &g->settings.display,
        g->settings.gameplay.map_s);
    display_textures(r, &walls);
    texture_wall(r, &walls, &g->settings.display, ALL_TEXTURES[r->wall_type]);
    return;
}
