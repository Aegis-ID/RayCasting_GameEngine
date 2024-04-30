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
#include "game/structs.h"
#include "ray_casting/funcs.h"
#include "settings/structs.h"
#include "textures/structs.h"
#include "textures/textures.h"

bool is_wall(int map_position)
{
    if ((map_position > 0) && (map_position <= TEXTURES_NB))
        return true;
    return false;
}

static void colorize_texture(int wall_type, float color)
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

static void draw_walls(rays_t *r, textures_t *t, display_t *d)
{
    float color = 0;

    for (size_t y = 0; y < t->wall_ht; ++y) {
        color =
            ALL_TEXTURES[r->wall_type][(int)(t->pos.y) *
            TEXTURES_S + (int)(t->pos.x)] * r->shade;
        colorize_texture(r->wall_type, color);
        glPointSize(DOF);
        glBegin(GL_POINTS);
        glVertex2i(r->r_iter * DOF + (d->resolution.x / 2),
            y + t->wall_ht_off);
        glEnd();
        t->pos.y += t->step.y;
    }
    return;
}

static void display_floor(rays_t *r, display_t *d, float color, size_t y)
{
    colorize_texture(BRICK, color);
    glPointSize(DOF);
    glBegin(GL_POINTS);
    glVertex2i(r->r_iter * DOF + (d->resolution.x / 2), y);
    glEnd();
    return;
}

static void draw_floor(player_t *p, rays_t *r, textures_t *t, display_t *d)
{
    enum texture_type;
    float dy = 0;
    float deg = deg_to_rad(r->angle);
    float ra_fix = cos(deg_to_rad(update_angle(p->angle - r->angle)));
    size_t dp_height = (d->resolution.y / 2);
    float color = 0;

    for (size_t y = t->wall_ht_off + t->wall_ht; y < dp_height; ++y) {
        dy = y - (dp_height / 2);
        t->pos.x = (p->pos.x / 2) + cos(deg) * (dp_height / 2) *
            TEXTURES_S / dy / ra_fix;
        t->pos.y = (p->pos.y / 2) - sin(deg) * (dp_height / 2) *
            TEXTURES_S / dy / ra_fix;
        color =
            ALL_TEXTURES[BRICK][((int)(t->pos.y) & (TEXTURES_S - 1)) *
            TEXTURES_S + ((int)(t->pos.x) & (TEXTURES_S - 1))] * 0.7;
        display_floor(r, d, color, y);
    }
    return;
}

static void texture_ceil(rays_t *r, textures_t *t, display_t *d)
{
    return;
}

static void setup_textures(rays_t *r, textures_t *t)
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

static void setup_display(rays_t *r, textures_t *t, display_t *d, int map_s)
{
    t->wall_ht = (map_s * (d->resolution.y / 2)) / r->h_dist;
    t->step.y = TEXTURES_S / (float)t->wall_ht;
    t->offset.y = 0;
    if ((int)t->wall_ht > (d->resolution.y / 2)) {
        t->offset.y = (t->wall_ht - (d->resolution.y / 2)) / 2;
        t->wall_ht = (d->resolution.y / 2);
    }
    t->wall_ht_off = (d->resolution.y / 4) - (t->wall_ht >> 1);
    return;
}

void display_rc(game_t *g, player_t *p, rays_t *r)
{
    textures_t text = {0};

    r->h_dist *= cos(deg_to_rad(update_angle(p->angle - r->angle)));
    setup_display(r, &text, &g->settings.display, g->settings.gameplay.map_s);
    setup_textures(r, &text);
    draw_walls(r, &text, &g->settings.display);
    draw_floor(p, r, &text, &g->settings.display);
    return;
}
